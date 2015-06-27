#include <ov/client/network.h>

void closeSockets(const int socketDescriptor) {
    // Cleanup
#ifdef _WIN32
    closesocket(socketDescriptor);
    WSACleanup();
#else
    close(socketDescriptor);
#endif
}

