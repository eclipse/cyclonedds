/*
 * Copyright(c) 2006 to 2018 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef DDSRT_PROCESS_H
#define DDSRT_PROCESS_H

#include "dds/export.h"
#include "dds/ddsrt/time.h"
#include "dds/ddsrt/types.h"
#include "dds/ddsrt/retcode.h"

#if defined(_WIN32)
typedef DWORD ddsrt_pid_t;
#define PRIdPID "u"
#else /* _WIN32 */
#include <unistd.h>
#if defined(_WRS_KERNEL)
typedef RTP_ID ddsrt_pid_t; /* typedef struct wind_rtp *RTP_ID */
#define PRIdPID PRIuPTR
#else
typedef pid_t ddsrt_pid_t;
#define PRIdPID "d"
#endif
#endif /* _WIN32 */


#if defined (__cplusplus)
extern "C" {
#endif

/**
 * @brief Return process ID (PID) of the calling process.
 *
 * @returns The process ID of the calling process.
 */
DDS_EXPORT ddsrt_pid_t
ddsrt_getpid(void);

#ifdef DDSRT_USE_PROCESSCREATION
#define DDSRT_HAVE_PROCESSCREATION 1

/**
 * @brief Create new process.
 *
 * Creates a new process using the provided executable file. It will have
 * default priority and scheduling.
 *
 * Process arguments are represented by argv, which can be null. If argv is
 * not null, then the array must be null terminated. The argv array only has
 * to contain the arguments, the executable filename doesn't have to be in
 * the first element, which is normally the convention.
 *
 * @param[in]   executable     Executable file name.
 * @param[in]   argv           Arguments array.
 * @param[out]  pid            ID of the created process.
 *
 * @returns A dds_retcode_t indicating success or failure.
 *
 * @retval DDS_RETCODE_OK
 *             Process successfully created.
 * @retval DDS_RETCODE_BAD_PARAMETER
 *             Provided file is not executable.
 * @retval DDS_RETCODE_ERROR
 *             Process could not be created.
 */
DDS_EXPORT dds_retcode_t
ddsrt_process_create(
  const char *executable,
  char *const argv[],
  ddsrt_pid_t *pid);

/**
 * @brief Wait for a process to exit.
 *
 * When the process (identified by pid) has exited, the status argument will
 * contain the process exit code.
 *
 * When the process is terminated by a call to ddsrt_process_terminate(), then
 * the return code is uncertain, except that it won't be DDS_RETCODE_TIMEOUT.
 *
 * @param[in]   pid            Process ID (PID) of the process to wait for.
 * @param[in]   timeout        Max timeout to wait for the process to exit.
 * @param[out]  status         The exit code of the process.
 *
 * @returns A dds_retcode_t indicating success or failure.
 *
 * @retval DDS_RETCODE_OK
 *             Process has exited.
 * @retval DDS_RETCODE_TIMEOUT
 *             Process is still alive.
 * @retval DDS_RETCODE_BAD_PARAMETER
 *             Process unknown.
 * @retval DDS_RETCODE_ERROR
 *             Wait failed for an unknown reason.
 */
DDS_EXPORT dds_retcode_t
ddsrt_process_wait_exit(
  ddsrt_pid_t pid,
  dds_duration_t timeout,
  int32_t *status);

/**
 * @brief Terminate a process.
 *
 * This will try to gracefully terminate the process (identified by pid).
 *
 * If the process hasn't terminated within the timeout, the process will
 * be forcefully killed.
 *
 * @param[in]   pid            Process ID (PID) of the process to terminate.
 * @param[in]   timeout        Max timeout to wait for graceful termination.
 *
 * @returns A dds_retcode_t indicating success or failure.
 *
 * @retval DDS_RETCODE_OK
 *             Process has gracefully terminated.
 * @retval DDS_RETCODE_TIMEOUT
 *             Graceful termination failed. Process has been killed.
 * @retval DDS_RETCODE_BAD_PARAMETER
 *             Process unknown.
 * @retval DDS_RETCODE_ERROR
 *             Termination failed for an unknown reason.
 */
DDS_EXPORT dds_retcode_t
ddsrt_process_terminate(
  ddsrt_pid_t pid,
  dds_duration_t timeout);

#endif /* DDSRT_USE_PROCESSCREATION */

#if defined (__cplusplus)
}
#endif

#endif /* DDSRT_PROCESS_H */
