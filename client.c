/*
	Dezhi Gao
	CSCE 3530
	Programming Assignment 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

int main(int argc, char const* argv[])
{
	int client_fd, clientPort;
	struct sockaddr_in serv_addr;
	char buffer[1024] = { 0 };

	if(argc < 2)
	{
		perror("Parameter Error: ");
		exit(EXIT_FAILURE);
	}

	// Get port number on Linux
	clientPort = atoi(argv[1]);

	// Create a socket for client
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
		perror("Socket Failed: ");
		exit(EXIT_FAILURE);
	}

	// Get IP address on current client
	struct ifreq ifr;
    char array[] = "eth0";

	// Type of address to retrieve - IPv4 IP address
    ifr.ifr_addr.sa_family = AF_INET;

    // Copy the interface name in the ifreq structure
    strncpy(ifr.ifr_name , array , IFNAMSIZ - 1);
    ioctl(client_fd, SIOCGIFADDR, &ifr);

	// Initialize and enter the value for the client_fd needed
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(clientPort);

	// Get IP address on current client and tranfer to binary form
	if (inet_pton(AF_INET, inet_ntoa(((struct sockaddr_in *) &ifr.ifr_addr )->sin_addr), &(serv_addr.sin_addr)) <= 0)
	{
		perror("IP Error: ");
		exit(EXIT_FAILURE);
	}

	if (connect(client_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("Connect Error: ");
		exit(EXIT_FAILURE);
	}

	// Communicate with the proxy server
	printf("Enter the url link: ");
	bzero(buffer, sizeof(buffer));
	fgets(buffer, sizeof(buffer), stdin);

	// Send to proxy server
	if (send(client_fd, buffer, strlen(buffer), 0) < 0)
	{
		perror("Send Error: ");
		exit(EXIT_FAILURE);
	}

	bzero(buffer, sizeof(buffer));

	// Receive from proxy server
	if (recv(client_fd, buffer, sizeof(buffer), 0) < 0)
	{
		perror("Recv Error: ");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", buffer);

	return 0;
}
