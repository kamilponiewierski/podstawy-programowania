#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <uv.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 50000
#define SERWER_IP "127.0.0.1"
#define MAX_CONNECTION 10

int getServerSocket(struct sockaddr_in *serwer, socklen_t len);

int main()
{
    struct sockaddr_in serwer = {
            .sin_family = AF_INET,
            .sin_port = htons(PORT),
    };

    if (inet_pton(AF_INET, SERWER_IP, &serwer.sin_addr) <= 0)
    {
        perror("inet_pton() ERROR");
        exit(1);
    }
    socklen_t len = sizeof(serwer);

    int serverSocket = getServerSocket(&serwer, len);

    while (1)
    {
        printf("Waiting for connection...\n");

        struct sockaddr_in client = {};

        const int clientSocket = accept(serverSocket, (struct sockaddr *) &client, &len);
        if (clientSocket < 0)
        {
            perror("accept() ERROR");
            continue;
        }

        char buffer[1000] = {};

        if (recv(clientSocket, buffer, sizeof(buffer), 0) <= 0)
        {
            perror("recv() ERROR");
            exit(5);
        }
        printf("|Message from client|: %serverSocket \n", buffer);

        strcpy(buffer, "General Kenobi!");
        if (send(clientSocket, buffer, strlen(buffer), 0) <= 0)
        {
            perror("send() ERROR");
            exit(6);
        } else
        {
            printf("Sent: \"%serverSocket\" successfully\n\n", buffer);
        }

        shutdown(clientSocket, SHUT_RDWR);
    }
}

int getServerSocket(struct sockaddr_in *serwer, socklen_t len)
{
    const int s = socket((*serwer).sin_family, SOCK_STREAM, 0);

    if (s < 0)
    {
        perror("socket() ERROR");
        exit(2);
    }

    if (bind(s, (struct sockaddr *) serwer, len) < 0)
    {
        perror("bind() ERROR");
        exit(3);
    }

    if (listen(s, MAX_CONNECTION) < 0)
    {
        perror("listen() ERROR");
        exit(4);
    }
    return s;
}
