#include "ddsc/dds.h"
#include "Throughput.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/*
 * The Throughput example measures data throughput in bytes per second. The publisher
 * allows you to specify a payload size in bytes as well as allowing you to specify
 * whether to send data in bursts. The publisher will continue to send data forever
 * unless a time out is specified. The subscriber will receive data and output the
 * total amount received and the data rate in bytes per second. It will also indicate
 * if any samples were received out of order. A maximum number of cycles can be
 * specified and once this has been reached the subscriber will terminate and output
 * totals and averages.
 */

#define MAX_SAMPLES 100

static bool done = false;

/* Forward declarations */
static dds_return_t wait_for_reader(dds_entity_t writer, dds_entity_t participant);
static void start_writing(dds_entity_t writer, ThroughputModule_DataType *sample,
    unsigned int burstInterval, unsigned int burstSize, unsigned int timeOut);
static int parse_args(int argc, char **argv, uint32_t *payloadSize, unsigned int *burstInterval,
    unsigned int *burstSize, unsigned int *timeOut, char **partitionName);
static dds_entity_t prepare_dds(dds_entity_t *writer, const char *partitionName);
static void finalize_dds(dds_entity_t participant, dds_entity_t writer, ThroughputModule_DataType sample);

/* Functions to handle Ctrl-C presses. */
#ifdef _WIN32
#include <Windows.h>
static int CtrlHandler (DWORD fdwCtrlType)
{
  done = true;
  return true; /* Don't let other handlers handle this key */
}
#else
struct sigaction oldAction;
static void CtrlHandler (int fdwCtrlType)
{
  done = true;
}
#endif

int main (int argc, char **argv)
{
  uint32_t payloadSize = 8192;
  unsigned int burstInterval = 0;
  unsigned int burstSize = 1;
  unsigned int timeOut = 0;
  char * partitionName = "Throughput example";
  dds_entity_t participant;
  dds_entity_t writer;
  ThroughputModule_DataType sample;

  /* Register handler for Ctrl-C */
#ifdef _WIN32
  SetConsoleCtrlHandler ((PHANDLER_ROUTINE) CtrlHandler, true);
#else
  struct sigaction sat;
  sat.sa_handler = CtrlHandler;
  sigemptyset (&sat.sa_mask);
  sat.sa_flags = 0;
  sigaction (SIGINT, &sat, &oldAction);
#endif

  if (parse_args(argc, argv, &payloadSize, &burstInterval, &burstSize, &timeOut, &partitionName) == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }

  participant = prepare_dds(&writer, partitionName);

  /* Wait until have a reader */
  if (wait_for_reader(writer, participant) == 0) {
    printf ("=== [Publisher]  Did not discover a reader.\n");
    DDS_ERR_CHECK (dds_delete (participant), DDS_CHECK_REPORT | DDS_CHECK_EXIT);
    return EXIT_FAILURE;
  }

  /* Fill the sample payload with data */
  sample.count = 0;
  sample.payload._buffer = dds_alloc (payloadSize);
  sample.payload._length = payloadSize;
  sample.payload._release = true;
  for (uint32_t i = 0; i < payloadSize; i++) {
    sample.payload._buffer[i] = 'a';
  }

  /* Register the sample instance and write samples repeatedly or until time out */
  start_writing(writer, &sample, burstInterval, burstSize, timeOut);

#ifdef _WIN32
  SetConsoleCtrlHandler (0, false);
#else
  sigaction (SIGINT, &oldAction, 0);
#endif

  /* Cleanup */
  finalize_dds(participant, writer, sample);
  return EXIT_SUCCESS;
}

static int parse_args(
    int argc,
    char **argv,
    uint32_t *payloadSize,
    unsigned int *burstInterval,
    unsigned int *burstSize,
    unsigned int *timeOut,
    char **partitionName)
{
  int result = EXIT_SUCCESS;
  /*
   * Get the program parameters
   * Parameters: publisher [payloadSize] [burstInterval] [burstSize] [timeOut] [partitionName]
   */
  if (argc == 2 && (strcmp (argv[1], "-h") == 0 || strcmp (argv[1], "--help") == 0))
  {
    printf ("Usage (parameters must be supplied in order):\n");
    printf ("./publisher [payloadSize (bytes)] [burstInterval (ms)] [burstSize (samples)] [timeOut (seconds)] [partitionName]\n");
    printf ("Defaults:\n");
    printf ("./publisher 8192 0 1 0 \"Throughput example\"\n");
    return EXIT_FAILURE;
  }
  if (argc > 1)
  {
    *payloadSize = atoi (argv[1]); /* The size of the payload in bytes */
  }
  if (argc > 2)
  {
    *burstInterval = atoi (argv[2]); /* The time interval between each burst in ms */
  }
  if (argc > 3)
  {
    *burstSize = atoi (argv[3]); /* The number of samples to send each burst */
  }
  if (argc > 4)
  {
    *timeOut = atoi (argv[4]); /* The number of seconds the publisher should run for (0 = infinite) */
  }
  if (argc > 5)
  {
    *partitionName = argv[5]; /* The name of the partition */
  }

  printf ("payloadSize: %u bytes burstInterval: %u ms burstSize: %u timeOut: %u seconds partitionName: %s\n",
    *payloadSize, *burstInterval, *burstSize, *timeOut, *partitionName);

  return result;
}

static dds_entity_t prepare_dds(dds_entity_t *writer, const char *partitionName)
{
  dds_entity_t participant;
  dds_entity_t topic;
  dds_entity_t publisher;
  const char *pubParts[1];
  dds_qos_t *pubQos;
  dds_qos_t *dwQos;

  /* A domain participant is created for the default domain. */
  participant = dds_create_participant (DDS_DOMAIN_DEFAULT, NULL, NULL);
  DDS_ERR_CHECK (participant, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* A topic is created for our sample type on the domain participant. */
  topic = dds_create_topic (participant, &ThroughputModule_DataType_desc, "Throughput", NULL, NULL);
  DDS_ERR_CHECK (topic, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* A publisher is created on the domain participant. */
  pubQos = dds_qos_create ();
  pubParts[0] = partitionName;
  dds_qset_partition (pubQos, 1, pubParts);
  publisher = dds_create_publisher (participant, pubQos, NULL);
  DDS_ERR_CHECK (publisher, DDS_CHECK_REPORT | DDS_CHECK_EXIT);
  dds_qos_delete (pubQos);

  /* A DataWriter is created on the publisher. */
  dwQos = dds_qos_create ();
  dds_qset_reliability (dwQos, DDS_RELIABILITY_RELIABLE, DDS_SECS (10));
  dds_qset_history (dwQos, DDS_HISTORY_KEEP_ALL, 0);
  dds_qset_resource_limits (dwQos, MAX_SAMPLES, DDS_LENGTH_UNLIMITED, DDS_LENGTH_UNLIMITED);
  *writer = dds_create_writer (publisher, topic, dwQos, NULL);
  DDS_ERR_CHECK (*writer, DDS_CHECK_REPORT | DDS_CHECK_EXIT);
  dds_qos_delete (dwQos);

  /* Enable write batching */
  dds_write_set_batch (true);

  return participant;
}

static dds_return_t wait_for_reader(dds_entity_t writer, dds_entity_t participant)
{
  printf ("\n=== [Publisher]  Waiting for a reader ...\n");

  dds_return_t ret;
  dds_entity_t waitset;

  ret = dds_set_enabled_status(writer, DDS_PUBLICATION_MATCHED_STATUS);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  waitset = dds_create_waitset(participant);
  DDS_ERR_CHECK (waitset, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  ret = dds_waitset_attach(waitset, writer, (dds_attach_t)NULL);
  DDS_ERR_CHECK (waitset, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  ret = dds_waitset_wait(waitset, NULL, 0, DDS_SECS(30));
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  return ret;
}

static void start_writing(
    dds_entity_t writer,
    ThroughputModule_DataType *sample,
    unsigned int burstInterval,
    unsigned int burstSize,
    unsigned int timeOut)
{
  bool timedOut = false;
  dds_time_t pubStart = dds_time ();
  dds_time_t now;
  dds_time_t deltaTv;
  dds_return_t status;

  if (!done)
  {
    dds_time_t burstStart = pubStart;
    unsigned int burstCount = 0;

    printf ("=== [Publisher]  Writing samples...\n");

    while (!done && !timedOut)
    {
      /* Write data until burst size has been reached */

      if (burstCount < burstSize)
      {
        status = dds_write (writer, sample);
        if (dds_err_nr(status) == DDS_RETCODE_TIMEOUT)
        {
          timedOut = true;
        }
        else
        {
          DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);
          sample->count++;
          burstCount++;
        }
      }
      else if (burstInterval)
      {
        /* Sleep until burst interval has passed */

        dds_time_t time = dds_time ();
        deltaTv = time - burstStart;
        if (deltaTv < DDS_MSECS (burstInterval))
        {
          dds_write_flush (writer);
          dds_sleepfor (DDS_MSECS (burstInterval) - deltaTv);
        }
        burstStart = dds_time ();
        burstCount = 0;
      }
      else
      {
        burstCount = 0;
      }

      if (timeOut)
      {
        now = dds_time ();
        deltaTv = now - pubStart;
        if ((deltaTv) > DDS_SECS (timeOut))
        {
          timedOut = true;
        }
      }
    }
    dds_write_flush (writer);

    if (done)
    {
      printf ("=== [Publisher]  Terminated, %llu samples written.\n", (unsigned long long) sample->count);
    }
    else
    {
      printf ("=== [Publisher]  Timed out, %llu samples written.\n", (unsigned long long) sample->count);
    }
  }
}

static void finalize_dds(dds_entity_t participant, dds_entity_t writer, ThroughputModule_DataType sample)
{
  dds_return_t status = dds_dispose (writer, &sample);
  if (dds_err_nr (status) != DDS_RETCODE_TIMEOUT)
  {
    DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);
  }

  dds_free (sample.payload._buffer);
  status = dds_delete (participant);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);
}
