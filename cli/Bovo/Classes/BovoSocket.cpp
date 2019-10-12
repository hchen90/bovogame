/* ***
 * @ $BovoSocket.cpp
 * 
 * Copyright (C) 2018 Hsiang Chen
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * ***/

/* TIPS: ORIGINALLY, THIS SOURCE IS FROM VSSOCKS. REDISTRIBUTION MUST APPLY GPL LICENSE
 * */

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <cstring>
#include <sstream>
#include <netdb.h>

#include "BovoSocket.h"

using namespace std;

#ifndef MAX
  #define MAX(a1,a2) (a1>a2?a1:a2)
#endif

BovoSocket::BovoSocket() : socket_dm(0), socket_ty(0), socket_fd(-1)
{}

int BovoSocket::socket()
{
  return socket_fd;
}

int BovoSocket::socket(int type)
{
  int domain = 0, soctyp = 0;

  if (type & 0x01) {
    domain = AF_INET;
  } else if (type & 0x02) {
    domain = AF_INET6;
  }

  if (type & 0x10) {
    soctyp = SOCK_STREAM;
  } else if (type & 0x20) {
    soctyp = SOCK_DGRAM;
  }

  return socket(domain, soctyp);
}

int BovoSocket::socket(int domain, int soctyp)
{
  return socket_fd = ::socket(socket_dm = domain, socket_ty = soctyp, 0);
}

int BovoSocket::listen(int backlog)
{
  if (socket_ty == SOCK_STREAM) {
    return ::listen(socket_fd, backlog);
  } else {
    return 0; // always successful
  }
}

int BovoSocket::connect(const struct sockaddr* addr, socklen_t addr_len)
{
  return ::connect(socket_fd, addr, addr_len);
}

int BovoSocket::connect(const char* hostip, int port)
{
  int rev = -1;
  struct addrinfo* addr = NULL;

  if (! resolve(hostip, port, &addr)) {
    rev = connect(addr->ai_addr, addr->ai_addrlen);
    resolve(NULL, 0, &addr);
  }

  return rev;
}

int BovoSocket::bind(const struct sockaddr* addr, socklen_t addr_len)
{
  return ::bind(socket_fd, addr, addr_len);
}

int BovoSocket::bind(const char* hostip, int port)
{
  int rev = -1;
  struct addrinfo* addr = NULL;

  if (! resolve(hostip, port, &addr)) {
    rev = bind(addr->ai_addr, addr->ai_addrlen);
    resolve(NULL, 0, &addr);
  }

  return rev;
}

int BovoSocket::accept(struct sockaddr* addr, socklen_t* addr_len)
{
  return ::accept(socket_fd, addr, addr_len);
}

int BovoSocket::accept(char* hostip, int& port)
{
  int soc;
  struct sockaddr addr;
  socklen_t addr_len = sizeof(addr);

  if ((soc = accept(&addr, &addr_len)) > 0) {
    if (resolve(&addr, hostip, port) != 0) {
      close(soc);
    }
  }

  return soc;
}

ssize_t BovoSocket::recv(void* buf, size_t len, int flags)
{
  return ::recv(socket_fd, buf, len, flags);
}

ssize_t BovoSocket::recv(int cli, void* buf, size_t len, int flags)
{
  return ::recv(cli, buf, len, flags);
}

ssize_t BovoSocket::recvfrom(void* buf, size_t len, struct sockaddr* addr, socklen_t* addr_len, int flags)
{
  return ::recvfrom(socket_fd, buf, len, flags, addr, addr_len);
}

ssize_t BovoSocket::recvfrom(void* buf, size_t len, char* hostip, int& port, int flags)
{
  ssize_t rev = -1;
  struct sockaddr addr;
  socklen_t addr_len = sizeof(addr);

  if ((rev = recvfrom(buf, len, &addr, &addr_len, flags)) > 0) {
    resolve(&addr, hostip, port);
  }

  return rev;
}

ssize_t BovoSocket::send(const void* buf, size_t len, int flags)
{
  return ::send(socket_fd, buf, len, flags);
}

ssize_t BovoSocket::send(int cli, const void* buf, size_t len, int flags)
{
  return ::send(cli, buf, len, flags);
}

ssize_t BovoSocket::sendto(const void* buf, size_t len, const struct sockaddr* addr, socklen_t addr_len, int flags)
{
  return ::sendto(socket_fd, buf, len, flags, addr, addr_len);
}

ssize_t BovoSocket::sendto(const void* buf, size_t len, const char* hostip, int port, int flags)
{
  ssize_t rev = -1;
  struct addrinfo* addr = NULL;

  if (! resolve(hostip, port, &addr)) {
    rev = sendto(buf, len, addr->ai_addr, addr->ai_addrlen, flags);
    resolve(NULL, 0, &addr); // free addrinfo
  }

  return rev;
}

ssize_t BovoSocket::read(void* buf, size_t len)
{
  return ::read(socket_fd, buf, len);
}

ssize_t BovoSocket::write(const void* buf, size_t len)
{
  return ::write(socket_fd, buf, len);
}

int BovoSocket::getsockopt(int soc, int level, int optname, void* optval, socklen_t* optlen)
{
  return ::getsockopt(soc, level, optname, optval, optlen);
}

int BovoSocket::getsockopt(int level, int optname, void* optval, socklen_t* optlen)
{
  return ::getsockopt(socket_fd, level, optname, optval, optlen);
}

int BovoSocket::setsockopt(int soc, int level, int optname, void* optval, socklen_t optlen)
{
  return ::setsockopt(soc, level, optname, optval, optlen);
}

int BovoSocket::setsockopt(int level, int optname, const void* optval, socklen_t optlen)
{
  return ::setsockopt(socket_fd, level, optname, optval, optlen);
}

int BovoSocket::getsockname(int soc, struct sockaddr* addr, socklen_t* addr_len)
{
  return ::getsockname(soc, addr, addr_len);
}

int BovoSocket::getsockname(struct sockaddr* addr, socklen_t* addr_len)
{
  return ::getsockname(socket_fd, addr, addr_len);
}

int BovoSocket::shutdown(int how)
{
  return ::shutdown(socket_fd, how);
}

int BovoSocket::close()
{
  return close(socket_fd);
}

int BovoSocket::close(int& soc)
{
  if (soc != -1) {
    int n = ::close(soc);
    soc = -1;
    return n;
  } else return -1;
}

int BovoSocket::resolve(const char* hostip, int port, struct addrinfo** addr)
{
  if (hostip != NULL) {
    struct addrinfo hints = {
      .ai_flags = AI_PASSIVE,
      .ai_family = AF_UNSPEC,
      .ai_socktype = SOCK_STREAM,
      .ai_protocol = 0
    };

    ostringstream s_port;

    s_port << (unsigned int) port;

    return ::getaddrinfo(hostip, s_port.str().c_str(), &hints, addr);
  } else {
    if (addr != NULL && *addr != NULL) {
      freeaddrinfo(*addr);
      return 0;
    } else return -1;
  }
}

int BovoSocket::resolve(const struct sockaddr* addr, char* hostip, int& port)
{
  if (addr != NULL) {
    const void* src = NULL;

    if (addr->sa_family == AF_INET) {
      struct sockaddr_in* in = (struct sockaddr_in*) addr;
      src = &in->sin_addr.s_addr;
      port = ntohs(in->sin_port);
    } else if (addr->sa_family == AF_INET6) {
      struct sockaddr_in6* in6 = (struct sockaddr_in6*) addr;
      src = &in6->sin6_addr;
      port = ntohs(in6->sin6_port);
    }
    if (src != NULL && inet_ntop(addr->sa_family, src, hostip, MAX(INET_ADDRSTRLEN, INET6_ADDRSTRLEN)) != NULL) {
      return 0;
    }
  }

  return -1;
}

/*end*/
