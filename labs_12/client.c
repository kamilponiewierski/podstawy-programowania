#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define PORT 50000

int getSocket(struct sockaddr_in *serwer);

int main()
{
    struct sockaddr_in serwer = {
            .sin_family = AF_INET,
            .sin_port = htons(PORT),
            //.sin_addr = 2130706433,
    };
    int gniazdo = getSocket(&serwer);

    char buffer[1000] = "Hello there!\n";
    printf("Sending: %s\n", buffer);
    send(gniazdo, buffer, strlen(buffer), 0);

    while (recv(gniazdo, buffer, sizeof(buffer), 0) > 0)
    {
        puts("Message from the server:");
        puts(buffer);
    }

    shutdown(gniazdo, 0);
}

int getSocket(struct sockaddr_in *serwer)
{
    const int gniazdo = socket((*serwer).sin_family, SOCK_STREAM, 0);

    int connection_result = connect(gniazdo, (struct sockaddr *) serwer, sizeof((*serwer)));
    if (connection_result == -1)
    {
        perror("Failed to connect");
        exit(1);
    }
    return gniazdo;
}