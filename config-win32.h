#ifndef __ARES_CONFIG_WIN32_H
#define __ARES_CONFIG_WIN32_H

/* $Id$ */

/* Copyright (C) 2004 - 2005 by Daniel Stenberg et al
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of M.I.T. not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  M.I.T. makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 */

/* ================================================================ */
/*    ares/config-win32.h - Hand crafted config file for windows    */
/* ================================================================ */

/* ---------------------------------------------------------------- */
/*                          HEADER FILES                            */
/* ---------------------------------------------------------------- */

/* Define if you have the <getopt.h> header file.  */
#if defined(__MINGW32__)
#define HAVE_GETOPT_H 1
#endif

/* Define if you have the <unistd.h> header file.  */
#if defined(__MINGW32__) || defined(__WATCOMC__) || defined(__LCC__)
#define HAVE_UNISTD_H 1
#endif

/* Define if you have the <windows.h> header file.  */
#define HAVE_WINDOWS_H 1

/* Define if you have the <winsock.h> header file.  */
#define HAVE_WINSOCK_H 1

/* Define if you have the <winsock2.h> header file.  */
#define HAVE_WINSOCK2_H 1

/* Define if you have the <ws2tcpip.h> header file.  */
#define HAVE_WS2TCPIP_H 1

/* ---------------------------------------------------------------- */
/*                             FUNCTIONS                            */
/* ---------------------------------------------------------------- */

/* Define if you have the ioctlsocket function.  */
#define HAVE_IOCTLSOCKET 1

/* ---------------------------------------------------------------- */
/*                          STRUCT RELATED                          */
/* ---------------------------------------------------------------- */

/* Define this if you have struct addrinfo */
#define HAVE_STRUCT_ADDRINFO 1

/* Define this if you have struct sockaddr_storage */
#define HAVE_STRUCT_SOCKADDR_STORAGE 1

/* ---------------------------------------------------------------- */
/*                         IPV6 COMPATIBILITY                       */
/* ---------------------------------------------------------------- */

/* Define this if you have address family AF_INET6 */
#define HAVE_AF_INET6 1

/* Define this if you have protocol family PF_INET6 */
#define HAVE_PF_INET6 1

/* Define this if you have struct in6_addr */
#define HAVE_STRUCT_IN6_ADDR 1

/* Define this if you have struct sockaddr_in6 */
#define HAVE_STRUCT_SOCKADDR_IN6 1

/* Define this if you have sockaddr_in6 with scopeid */
#define HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID 1


#endif  /* __ARES_CONFIG_WIN32_H */