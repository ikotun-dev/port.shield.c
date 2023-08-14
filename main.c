#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Define the target address
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = 0; // We'll scan all ports
    inet_pton(AF_INET, ip_address, &target_addr.sin_addr);

    // Loop to check ports
    for (int port = 1; port <= 65535; port++) {
        target_addr.sin_port = htons(port);

        // Attempt to connect to the port
        int connect_result = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));

        if (connect_result == 0) {
            printf("Port %d is open.\n", port);
        }

        // Close the socket
        close(sockfd);
        
        // Create a new socket for the next iteration
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
    }

    return 0;
}
