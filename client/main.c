/* Copyright (C) 2015 OpenVirus by Jared Burrows <jaredsburrows@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ov/client/network.h> // Windows/Linux/Unix compatible headers

#define MESSAGE_LENGTH 100

static const int NUMBER_ARGS = 3;
static const size_t COMMAND_EXIT_LENGTH = 4;
static const char* COMMAND_EXIT = "exit";

int main(const int argc, const char **argv) {

    struct sockaddr_in server;
    char clientmessage[MESSAGE_LENGTH + 1] = {'\0'};
    char servermessage[MESSAGE_LENGTH + 1] = {'\0'};
    int socketDescriptor = 0;

    if (argc != NUMBER_ARGS) {
        printf("%s [IP or Hostname] [Port]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create socket
    if ((socketDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }
    puts("Socket created\n");

    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons((u_short)atoi(argv[2]));

    if (connect(socketDescriptor, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect failed");
        return EXIT_FAILURE;
    }
    puts("Connected\n");

    // Communicate with Virus Nodes
    for(;;) {
        printf("Enter command: ");
        fgets(clientmessage, MESSAGE_LENGTH, stdin);

        // Exit the program
        if (! strncmp(clientmessage, COMMAND_EXIT, COMMAND_EXIT_LENGTH)) {
            break;
        }

        // Send command
        if (send(socketDescriptor, clientmessage, strlen(clientmessage), 0) < 0) {
            perror("send failed");
        }

        // Receive a reply from the server
        if (recv(socketDescriptor, servermessage, MESSAGE_LENGTH, 0) < 0) {
            perror("recv failed");
        }

        printf("Reply from [%s]:[%s]: ", argv[1], argv[2]);
        puts(servermessage);
    }

    // Close file descriptors
    closeSockets(socketDescriptor);

    return EXIT_SUCCESS;
}
