// Copyright (c) 2014, Smart Projects Holdings Ltd
// All rights reserved.
// See LICENSE file for license details.

/*
 * platform_sockets.h
 *
 * Defines platform specific parts of socket implementation.
 */

#ifndef __unix__
#error "This header should be included only in linux build."
#endif

#ifndef VSTREAMER_PLATFORM_SOCKETS_H_
#define VSTREAMER_PLATFORM_SOCKETS_H_

#include <sys/socket.h>
#include <arpa/inet.h>  // inet_ntoa
#include <netdb.h>      // addrinfo
#include <unistd.h>
#define INVALID_SOCKET (-1)
#define SOCKET_ERROR (-1)

namespace ugcs
{
namespace vstreamer
{
namespace sockets
{
// Linux specific socket handle
typedef int Socket_handle;

// Linux uses MSG_NOSIGNAL to avoid SIGPIPE generation on send().
#ifdef MSG_NOSIGNAL
const int SEND_FLAGS = MSG_NOSIGNAL;
#else
const int SEND_FLAGS = 0;
#warning "SIGPIPE can get generated by send/write calls"
#endif

}
}
}

#endif /* VSTREAMER_PLATFORM_SOCKETS_H_ */
