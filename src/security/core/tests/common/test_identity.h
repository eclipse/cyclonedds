/*
 * Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */

#ifndef PLUGIN_SECURITY_CORE_TEST_IDENTITY_H_
#define PLUGIN_SECURITY_CORE_TEST_IDENTITY_H_

#define TEST_IDENTITY_CERTIFICATE_DUMMY "testtext_IdentityCertificate_testtext"
#define TEST_IDENTITY_PRIVATE_KEY_DUMMY "testtext_PrivateKey_testtext"
#define TEST_IDENTITY_CA_CERTIFICATE_DUMMY "testtext_IdentityCA_testtext"

#define TEST_IDENTITY_CERTIFICATE "data:,-----BEGIN CERTIFICATE-----\n\
MIIEDTCCAvUCFHZ4yXyk/9yeMxgHs6Ib0bLKhXYuMA0GCSqGSIb3DQEBCwUAMIHA\n\
MQswCQYDVQQGEwJOTDELMAkGA1UECAwCT1YxFjAUBgNVBAcMDUxvY2FsaXR5IE5h\n\
bWUxEzARBgNVBAsMCkV4YW1wbGUgT1UxIzAhBgNVBAoMGkV4YW1wbGUgSUQgQ0Eg\n\
T3JnYW5pemF0aW9uMRYwFAYDVQQDDA1FeGFtcGxlIElEIENBMTowOAYJKoZIhvcN\n\
AQkBFithdXRob3JpdHlAY3ljbG9uZWRkc3NlY3VyaXR5LmFkbGlua3RlY2guY29t\n\
MB4XDTIwMDIyNzE5MjQwMVoXDTMwMDIyNDE5MjQwMVowgcQxCzAJBgNVBAYTAk5M\n\
MQswCQYDVQQIDAJPVjEWMBQGA1UEBwwNTG9jYWxpdHkgTmFtZTEhMB8GA1UECwwY\n\
T3JnYW5pemF0aW9uYWwgVW5pdCBOYW1lMR0wGwYDVQQKDBRFeGFtcGxlIE9yZ2Fu\n\
aXphdGlvbjEWMBQGA1UEAwwNQWxpY2UgRXhhbXBsZTE2MDQGCSqGSIb3DQEJARYn\n\
YWxpY2VAY3ljbG9uZWRkc3NlY3VyaXR5LmFkbGlua3RlY2guY29tMIIBIjANBgkq\n\
hkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA5mEhLZIP2ko1bRJyJCwbnvhIpXFv6GOh\n\
nvuS5v8tsTju40O62NNQmKT/my1QVKiUu7OoWZtLNBebgxgJ851eQ4TBRXy/f2jG\n\
kLPYM22dohLTblVCpGutn+Itw3QRM3nkne7Sk8O6FP6NH6Y+7gkjxy5kI3GvhuIC\n\
uBIzAV4dHK+hPlCn/Z+W33W71/ZAmnmI+2GaWiu5tjAQyFcmqWbi0BD7TWqBqidZ\n\
2n7LTImUtp8NrYLfhzvgNLr9BZe7uf+T3mgdwcHtfi98GA94Lo6lqGeygiwig746\n\
Y5uW4c6whsbd6riJ8FG1l8O86Ump4bSKChxjeoTLj4M4KX615kYa4QIDAQABMA0G\n\
CSqGSIb3DQEBCwUAA4IBAQAM2g7v3FaA+d1zDkvDF5emCRL+R9H8pgimEOENrZTV\n\
iK/kl8Hm7xkO7/LZ3y/kXpQpth8FtFS6LsZBAXPYabfADeDFVImnOD6UbWewwHQR\n\
01gxkmYL/1nco/g3AsX/Ledh2ihwClGp+d6vNm5xF+Gw8Ux0YvH/aHy4RKg7mE/S\n\
nonfHWRlT2tw1OtohTVhmBn00Jvj0IzSAiNvpmZHVRLYL9JRb5awYSX5XGetpoFM\n\
VwzWIaZ06idvCtPKTfP71jJypV3+I2g5PNqranbuMv5nNAKZq1QlSB07f2Z1VIu6\n\
6jeSZSADfm73qnE2Kj1PiZkPn0Wu+K24GXCvdILATcUS\n\
-----END CERTIFICATE-----"

#define TEST_IDENTITY_PRIVATE_KEY "data:,-----BEGIN RSA PRIVATE KEY-----\n\
MIIEpQIBAAKCAQEA5mEhLZIP2ko1bRJyJCwbnvhIpXFv6GOhnvuS5v8tsTju40O6\n\
2NNQmKT/my1QVKiUu7OoWZtLNBebgxgJ851eQ4TBRXy/f2jGkLPYM22dohLTblVC\n\
pGutn+Itw3QRM3nkne7Sk8O6FP6NH6Y+7gkjxy5kI3GvhuICuBIzAV4dHK+hPlCn\n\
/Z+W33W71/ZAmnmI+2GaWiu5tjAQyFcmqWbi0BD7TWqBqidZ2n7LTImUtp8NrYLf\n\
hzvgNLr9BZe7uf+T3mgdwcHtfi98GA94Lo6lqGeygiwig746Y5uW4c6whsbd6riJ\n\
8FG1l8O86Ump4bSKChxjeoTLj4M4KX615kYa4QIDAQABAoIBAAtNMoJ4ytxLjaln\n\
IUBTBZvb1DyBfxroYFJbRw6b8BLklxuBBBaE70w9s+hZ5bnxdzJqEtUqgBrzGYbp\n\
0/smeixXw99zyjUm367Tk8SaGQSNZd/gwN8uBRt1zgbrl7htv2BcCeqDzIohHq0x\n\
y56DxkSMKw9uEU1NoxKCmgv0IPt6LlvjCwFhDv8iLu4lvu61F+ovVYIM6UXJJH0G\n\
bHcJ1XnFBj5jCJFAWZRq7KxBgc4K3DlG+J7JcGEz89ZnZfGwcIiLqJ4rbU7E0ZE8\n\
LslIHOwodtMDReIRWl6wEYmvd3mQizTXj2EWlRywQ/P3yFlxuHsGxPtRxdWoyXDc\n\
Ii7GZK0CgYEA9KA+uEAMA5jZK0h1EMFoTiOIRe0x8CjlrHg4l0zU0ElcMeUXwoci\n\
XqM0sjARiNgqkcMaONCb5bKgyxncWyWcamUxgp+bi2FUQIlBKHb56TCioPP0zzc6\n\
yCiQ2cA8QW9PjL0WScJz3bCzeXrQceGZenDpPyphYE7SIUaRAOlMTMMCgYEA8RdP\n\
QfYbOrcwgZB8ZycFE7lpZibe7Wh4UI1b/ipNZKcncr2pOZR+gVNv6eDQbV4z9xZY\n\
5K6oU3rUcFHf0ZAi9xIpNzcq9q4+qOGO2OCEZX5tewXjKw9rwyDPUbv3yToFyZ9w\n\
YwEKLfUgnYzpd5qn2NXa/pAZIoTh5ILF+EezD4sCgYEAr2lg0BoNA19NCn5wg01M\n\
kAtmok3Nq1qIJr4mRkfvqlOQaq7N9M2V1arOFJ/nUus+yzrNyMO9pl4Kctjea/Vy\n\
TdC2SeZNUQq/sW86a9u0pIQdebC1cQk3e2OrSplQG9PHhTHpk4Z+Mw+MAqYQZjjR\n\
Jz1j48lt/fNHNlk1jSO9dKUCgYEAuYkJuqZuMBJ4Zs1Nn4ic1KAUp8N0Pdnu9XbD\n\
++aMJtCogBnLWH+Zl2chsigL3o7niNiO0nZDHfNh94pap4i4D9HPHCn9i1du60Ki\n\
Tu8BlKXmFQ3j0+iLMuBWC/2O5DId8BseP2K2dcW2MukVZrEDSNDTNqKoZTNEMDof\n\
pkFvYJ8CgYEA6du9DFFZzIp5tuSIfVqCq5oxiNrRGJ/EpJEneBexrX56cC90sqLM\n\
ecxDkgEVC592b004K1mjak3w6O0jYozQM1uvve38nZyMgtbMo3ORCtAO6Xszj8Oj\n\
yNw1+km1Zy6EWdFEMciEFlbRwWVmDfE/um9LZsSWbmuWAOTww9GBDhc=\n\
-----END RSA PRIVATE KEY-----"


#define TEST_IDENTITY_CA_CERTIFICATE "data:,-----BEGIN CERTIFICATE-----\n\
MIIEYzCCA0ugAwIBAgIUOp5yaGGuh0vaQTZHVPkX5jHoc/4wDQYJKoZIhvcNAQEL\n\
BQAwgcAxCzAJBgNVBAYTAk5MMQswCQYDVQQIDAJPVjEWMBQGA1UEBwwNTG9jYWxp\n\
dHkgTmFtZTETMBEGA1UECwwKRXhhbXBsZSBPVTEjMCEGA1UECgwaRXhhbXBsZSBJ\n\
RCBDQSBPcmdhbml6YXRpb24xFjAUBgNVBAMMDUV4YW1wbGUgSUQgQ0ExOjA4Bgkq\n\
hkiG9w0BCQEWK2F1dGhvcml0eUBjeWNsb25lZGRzc2VjdXJpdHkuYWRsaW5rdGVj\n\
aC5jb20wHhcNMjAwMjI3MTkyMjA1WhcNMzAwMjI0MTkyMjA1WjCBwDELMAkGA1UE\n\
BhMCTkwxCzAJBgNVBAgMAk9WMRYwFAYDVQQHDA1Mb2NhbGl0eSBOYW1lMRMwEQYD\n\
VQQLDApFeGFtcGxlIE9VMSMwIQYDVQQKDBpFeGFtcGxlIElEIENBIE9yZ2FuaXph\n\
dGlvbjEWMBQGA1UEAwwNRXhhbXBsZSBJRCBDQTE6MDgGCSqGSIb3DQEJARYrYXV0\n\
aG9yaXR5QGN5Y2xvbmVkZHNzZWN1cml0eS5hZGxpbmt0ZWNoLmNvbTCCASIwDQYJ\n\
KoZIhvcNAQEBBQADggEPADCCAQoCggEBALKhk7JXUpqJphyOC6oOI00LH49WTtO2\n\
GCgDyJhcRYYAm7APMtmEDH+zptvd34N4eSu03Dc65cB/XN4Lbi2TjolVvKz0hHjz\n\
tzmQT5jTgb1UkJX4NjKGw+RrYe9Ls0kfoAL2kvb12kmd1Oj4TIKMZP9TCrz7Vw8m\n\
cZKQxZ56bLys6cU2XdiTp3v+Ef/vMll4+DINj4ZAMWL3CkT+q1G6ZxHRpFlsIyhc\n\
Q1wX6gxUoY6cQdBA7TehKCCEWz4L1KM1A18ZmCHmjTniU0ssLoiAzsQs4b6Fnw8Z\n\
MLFj8ocwzN5g66gJJWGofakXqX/V24KbGl54WX2X7FYU0tGzR234DXcCAwEAAaNT\n\
MFEwHQYDVR0OBBYEFGeCcK8B74QWCuuCjlSUzOBBUTF5MB8GA1UdIwQYMBaAFGeC\n\
cK8B74QWCuuCjlSUzOBBUTF5MA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEL\n\
BQADggEBAJQeMc4XzMFnpQKCb58rzRs3Wt9FmZZS4O596sHxMEewTkEHm5gLYMzF\n\
9JYEdUiLoTurQuIr0KgPi+Q3kliQdLfrVPbdWTmlUDZARR5ir5d1gGHST6qnb3Xi\n\
mG+7nwle9R/hLrtPio+gYRgwJEiS55f6p0/E1wDcc+6numvjCRQ/CGIiJfwD/R+d\n\
pv93YLEfuliZttfBc/apIu6OL4chxF+3QgSw1ltV5nXXqDTGHMRZENkp3Yiolumc\n\
6smL4uA7Q812pVcENi3MLjdJgBS/8DcSBQHspVuXugaKKPDMkJnD0IyLWc8vLXh4\n\
O7JdDrmusJAZA9RsTkinl3DuPfF34Sk=\n\
-----END CERTIFICATE-----"


#define TEST_IDENTITY2_CERTIFICATE "data:,-----BEGIN CERTIFICATE-----\n\
MIIEDjCCAvYCFDEZQzcfGKK8IKNyH+AdNSjdyVgnMA0GCSqGSIb3DQEBCwUAMIHF\n\
MQswCQYDVQQGEwJOTDELMAkGA1UECAwCT1YxFjAUBgNVBAcMDUxvY2FsaXR5IE5h\n\
bWUxEzARBgNVBAsMCkV4YW1wbGUgT1UxJTAjBgNVBAoMHEV4YW1wbGUgSUQgQ0Eg\n\
MiBPcmdhbml6YXRpb24xGDAWBgNVBAMMD0V4YW1wbGUgSUQgQ0EgMjE7MDkGCSqG\n\
SIb3DQEJARYsYXV0aG9yaXR5MkBjeWNsb25lZGRzc2VjdXJpdHkuYWRsaW5rdGVj\n\
aC5jb20wHhcNMjAwMjI3MTkyNjIwWhcNMzAwMjI0MTkyNjIwWjCBwDELMAkGA1UE\n\
BhMCTkwxCzAJBgNVBAgMAk9WMRYwFAYDVQQHDA1Mb2NhbGl0eSBOYW1lMSEwHwYD\n\
VQQLDBhPcmdhbml6YXRpb25hbCBVbml0IE5hbWUxHTAbBgNVBAoMFEV4YW1wbGUg\n\
T3JnYW5pemF0aW9uMRQwEgYDVQQDDAtCb2IgRXhhbXBsZTE0MDIGCSqGSIb3DQEJ\n\
ARYlYm9iQGN5Y2xvbmVkZHNzZWN1cml0eS5hZGxpbmt0ZWNoLmNvbTCCASIwDQYJ\n\
KoZIhvcNAQEBBQADggEPADCCAQoCggEBAMAQM9eN0zjTTdZALCTijog0oqx/kqnW\n\
VtVWjV/c34OyPvUuH/DNRH6Cr0fI76UiooLD9nfvHe52X8oZH8WqNW7m7g7dMliu\n\
DJD3yVpdLRmTTgl40ES8MTqmdb2y8ut70MJf5nUz0EQs9lXvnT0ru0B2CfyubiPt\n\
aLSfyDoVBkRLbfzeqaNEQe7Ta6mQKZOckb6BHcaInb9GYEsU+OyOHuf2tCVNnRIH\n\
ALiTPbA7rRS/J7ICS904/qz7w6km9Ta/oYQI5n0np64L+HqgtYZgIlVURW9grg2p\n\
BuaX+xnJdRZbLQ0YYs+Gpmc1Vnykd+c2b0KP7zyHf8WFk9vV5W1ah2sCAwEAATAN\n\
BgkqhkiG9w0BAQsFAAOCAQEA1RHDhLZf/UOR+azuH2lvD7ioSGRtdaOdJchSPdMk\n\
v1q74PsHgm4/QAadVPdzvaIVV9kDfo6kGMzh+dCtq69EqVOavw1WUDo/NfuVSbgA\n\
W7yeA39o3ROMO9UgbE5T3BPLq/XSXdIisP9OA4uXCnt22JELJaSv4m59FHg5gnQ7\n\
2qOWRM7hi/+cQwescE+lDRw7PUzW8SS1HkQA1DmdtIIpWVuvYj7EPUNQX3jIetn8\n\
AuPUgPJObxJhxJSC4p5qy37pYZHiNH1wG/+BDHgZo3wNwFsWqxabKziGB8XU3INc\n\
USI3GDWM2jjElMSnDCj4ChM5wFbwWrqwdOEzeGWBWbo3hQ==\n\
-----END CERTIFICATE-----"

#define TEST_IDENTITY2_PRIVATE_KEY "data:,-----BEGIN RSA PRIVATE KEY-----\n\
MIIEpQIBAAKCAQEAwBAz143TONNN1kAsJOKOiDSirH+SqdZW1VaNX9zfg7I+9S4f\n\
8M1EfoKvR8jvpSKigsP2d+8d7nZfyhkfxao1bubuDt0yWK4MkPfJWl0tGZNOCXjQ\n\
RLwxOqZ1vbLy63vQwl/mdTPQRCz2Ve+dPSu7QHYJ/K5uI+1otJ/IOhUGREtt/N6p\n\
o0RB7tNrqZApk5yRvoEdxoidv0ZgSxT47I4e5/a0JU2dEgcAuJM9sDutFL8nsgJL\n\
3Tj+rPvDqSb1Nr+hhAjmfSenrgv4eqC1hmAiVVRFb2CuDakG5pf7Gcl1FlstDRhi\n\
z4amZzVWfKR35zZvQo/vPId/xYWT29XlbVqHawIDAQABAoIBAFNm9cw15zI2+AcA\n\
yOqfgzt8d+OmZl7gF8b+lde6B0meHp7Dj9U2nfa98zWd+QrhtmZIiH/eU0YZG1Gc\n\
hWKFnjxxhZDo1xMRSZ2uLD7UVWBUyj9suiwO+OW6IUjmK3y8wJOXp3DftiHU0IfS\n\
zJoiombEm2Ohr2xkjOJavE0UkisXQauc3K5AKv9coW9W6hzZf330Sm4sokmC5D3B\n\
GcO/Keof2k2sFuv56wXPi9eGuXCEB2trhHhrxqncvb/fbRwpG1ELQsvZBnyuNNnY\n\
FQcLYl52gkttP6EGvRPw1DFbQwsAJKnXBC7ddJaAl+JoKYAcGTt0+mRm0Z8ltzWl\n\
c6uZQsECgYEA4NGiUMNq9kSn/6tQyPcsrphJ5uobu/svLaBipZ0vv2yQP3wQ5NPA\n\
06KjwSm8gg8BLi0LCKplSxY09TwgUsc9unRkDTQ/eflgjdGA76lFKOjvLQdutxn7\n\
eYNbx81WMY6E6n4y6K+2szpqW+Ds1At4ORRvweJWdFyc01bTqWNeuYsCgYEA2rOO\n\
Ye6H2VixUfXzXwevBd4QyFJITW46WqnbYDFcUzf9pYBZfZoHU0YJqolDIhHhtHnG\n\
soRi0Uk5P9D7Lvu+ZHAGQJrdmNELOMoqMNOqXcAdvK44qLLMwaLC8PS2zDIATrhZ\n\
nc0TbeZJC8MynfIpxDsBVVMOa8u4eHRFdpk8ZaECgYEAlzuuCtJKQ7vPn2dpAqdz\n\
gUekfxeA7KV+CR1Y/ruMgSLQrkQRQT1I+5Tuv2QKERty2dMnFv85AJfBrC50N/sb\n\
hTAClfdNtAmTcBM8vvuJMInxSsMzMSzjQ8yfkvqIPvH2a5/VMz3wkwR6w6+84K+O\n\
gidDPpO5QLGENY6097+G2x0CgYEAk7cdX0YGGaZPNiWiOLhu3c6slTEGRs5BucTq\n\
OGF+k3LI7kTvrOchNXyjwLyvTE65nPV3YFIMkIEdmt3jGkvMv/fuMSqoq7PeGYBq\n\
2MnOUz4Ul8Ew4bjKlasCck9HPEo1bPYVCYFfMyaMhdZU1NugnDqiXugXYHWb5jfa\n\
Rw2e/qECgYEA3PvLLHklsRts6P37iSwUmDnkiopSSPfVdGXpDDGD/RbLpG6cSLRm\n\
uh5n9+nxa2YXi0+LMLQvGpCSWk2k2qaRPpe2mahy9yAYrLhfDDcuGpSvw5BBJ3qw\n\
mi1HgIUzXZTRBNamYCltJWYnN0hOlSL6vcHgeJ9y1gSDh0QqB2BG8HY=\n\
-----END RSA PRIVATE KEY-----"


#define TEST_IDENTITY_CA2_CERTIFICATE "data:,-----BEGIN CERTIFICATE-----\n\
MIIEbTCCA1WgAwIBAgIUL0mSpPRgzveYTJ8UHSmOIwkIjjYwDQYJKoZIhvcNAQEL\n\
BQAwgcUxCzAJBgNVBAYTAk5MMQswCQYDVQQIDAJPVjEWMBQGA1UEBwwNTG9jYWxp\n\
dHkgTmFtZTETMBEGA1UECwwKRXhhbXBsZSBPVTElMCMGA1UECgwcRXhhbXBsZSBJ\n\
RCBDQSAyIE9yZ2FuaXphdGlvbjEYMBYGA1UEAwwPRXhhbXBsZSBJRCBDQSAyMTsw\n\
OQYJKoZIhvcNAQkBFixhdXRob3JpdHkyQGN5Y2xvbmVkZHNzZWN1cml0eS5hZGxp\n\
bmt0ZWNoLmNvbTAeFw0yMDAyMjcxNjI3MjRaFw0zMDAyMjQxNjI3MjRaMIHFMQsw\n\
CQYDVQQGEwJOTDELMAkGA1UECAwCT1YxFjAUBgNVBAcMDUxvY2FsaXR5IE5hbWUx\n\
EzARBgNVBAsMCkV4YW1wbGUgT1UxJTAjBgNVBAoMHEV4YW1wbGUgSUQgQ0EgMiBP\n\
cmdhbml6YXRpb24xGDAWBgNVBAMMD0V4YW1wbGUgSUQgQ0EgMjE7MDkGCSqGSIb3\n\
DQEJARYsYXV0aG9yaXR5MkBjeWNsb25lZGRzc2VjdXJpdHkuYWRsaW5rdGVjaC5j\n\
b20wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDk+ewDf871kPgBqXkm\n\
UEXdf/vqWWoKx3KfJ4N3Gq4vt/cDOMs0xakpqr5uxm787AvbOui4P8QmT8naLhAA\n\
TvHtNGg2LV0ZQtLcVVFsXXsBYDUEbLJYmCBtJU8zSfLLzgtN+z9nVqLthAcVyGhZ\n\
iEkCfXKS4XzwjFUxgrXUM1VSiHHz8DbreQFDTF8mVavZ75HjieuHz1OcSaoIHCIF\n\
mhPDlxRR/qZpc3Y52NZMNRHVPj4Tmc3N4H2eneeoG7nVn0MgNuqbssezeQtUOOoH\n\
DgPGp3xzd8XQxaF5hVIM9E7aL77kw5v4gwccjL5xWC72zzxC3c1ltmbaEcwhHGsu\n\
MR4lAgMBAAGjUzBRMB0GA1UdDgQWBBTTpmGTY5teWrZBA8Sd7kL5Lg/JmjAfBgNV\n\
HSMEGDAWgBTTpmGTY5teWrZBA8Sd7kL5Lg/JmjAPBgNVHRMBAf8EBTADAQH/MA0G\n\
CSqGSIb3DQEBCwUAA4IBAQCbelDJr9sVsYgQSp4yzSOSop5DSOWCweBF56NatcbY\n\
3HUYc4iaH4NcB04WFkUl2XmqVCAM0zbmV0q4HoQikTK5PBHmwxuuD2HhPDWtMeFR\n\
W96BjzGVpV27yaNIPvLwjTVV+A72r4vRvufiFhrMCovRwlWgHY6+gXKfrtyljTZ0\n\
m1mENHOJOQWDXFAXP5yiehSMKy/izKvQ1G1hLErYMMc+sdgF/9X2KaudnTakTW0d\n\
44kXUFKSU7mqV44D12unxCNODclznd31tiJ+70U39AXlR2BzwBzyFzPCh5JYtMog\n\
TwbdLY3LN40gpkDUxIIH115D7ujUKNd8s2gmSHOCm1ar\n\
-----END CERTIFICATE-----"


#endif /* PLUGIN_SECURITY_CORE_TEST_IDENTITY_H_ */
