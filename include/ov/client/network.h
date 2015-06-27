#ifndef NETWORK_H
#define NETWORK_H

// OS Dependent
#ifdef _WIN32
// Windows
#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")
#else
// BSD Sockets
#include <arpa/inet.h>              // inet_addr
#include <sys/socket.h>             // socket/connect/send/recv
#include <unistd.h>                 // close
#endif

void closeSockets(const int);

#endif // NETWORK_H

