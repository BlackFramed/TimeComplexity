/*
	Dezhi Gao
	CSCE 3530
	Programming Assignment 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define webPort 80

int main(int argc, char const* argv[])
{
	int server_fd, client_fd, serverPort;
	struct sockaddr_in server_addr;
	int server_len = sizeof(server_addr);
	char buffer[1024] = { 0 }, hostname[1024] = { 0 };
	pid_t pid;


	if(argc < 1)
	{
    	perror("Parameter Error: ");
		exit(EXIT_FAILURE);
	}

	// Get port number on Linux
	serverPort = atoi(argv[1]);

	// Create a socket for proxy server
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket Failed: ");
		exit(EXIT_FAILURE);
	}

	// Initialize and enter the value for the server_fd needed
	bzero((char *) &server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(serverPort);

	// Bind the socket with the port
	if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
	{
		perror("Bind Failed: ");
		exit(EXIT_FAILURE);
	}

	// Listen to the process of requesting connection
	if (listen(server_fd, 5) < 0)
	{
		perror("Listen Error: ");
		exit(EXIT_FAILURE);
	}

	// Loop accept client request
	do
	{
		int sockweb_fd;
		struct sockaddr_in webser_addr;
		struct hostent *webhost;
		char webbuf[1024] = { 0 };

		// Accept the client's connection on server socket
		if ((client_fd = accept(server_fd, (struct sockaddr *) &server_addr, (socklen_t *) &server_len)) < 0)
		{
			perror("Accept Error: ");
			exit(EXIT_FAILURE);
		}

		// Create new processes and get blocking
		pid = fork();

		if (pid < 0)
		{
			perror("Fork Error: ");
			exit(EXIT_FAILURE);
		}

		else if (pid == 0)
		{
			bzero(buffer, sizeof(buffer));

			// Recevie hostname from client
			if (recv(server_fd, buffer, sizeof(buffer), 0) < 0)
			{
				perror("Recv Error from host: ");
				exit(EXIT_FAILURE);
			}

			// Check the hostname if it is vailed




			// Get the hostname from client and put into the buffer
			strcpy(hostname, buffer);
			printf("Hostname: %s\n", hostname);

			//Create socket to Web
			if ((sockweb_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
			{
				perror("Web Socket Failed: ");
				exit(EXIT_FAILURE);
			}

			// Get a host entry
			webhost = gethostbyname(hostname);
			printf("%s", webhost->h_name);

			// Initialize and enter the value for the sockweb_fd needed
			bzero((char *) &webser_addr, sizeof(webser_addr));
			webser_addr.sin_family = AF_INET;
			bcopy((char *) webhost->h_addr, (char *) &webser_addr.sin_addr.s_addr, webhost->h_length);
			webser_addr.sin_port = htons(webPort);

			// Connect to the website
			if (connect(sockweb_fd, (struct sockaddr *) &webser_addr, sizeof(webser_addr)) < 0)
			{
				perror("Connect Error: ");
				exit(EXIT_FAILURE);
			}

			// Initialize the buffer and use to get request from http
			bzero(webbuf, sizeof(webbuf));
			//memset(webbuf, 0, sizeof(webbuf));

			strcat(webbuf, "GET / HTTP/1.1 200 OK\r\n");
			strcat(webbuf, "Host: http://");
			strcat(webbuf, hostname);
			strcat(webbuf, ":80\r\n");
			strcat(webbuf, "\r\n");

			// Send to web
			if (send(sockweb_fd, webbuf, strlen(webbuf), 0) < 0)
			{
				perror("Send Error to Web: ");
				exit(EXIT_FAILURE);
			}

			// Initialize the buffer to load data on web
			bzero(webbuf, sizeof(webbuf));

			// Receive from web
			if (recv(sockweb_fd, webbuf, sizeof(webbuf), 0) < 0)
			{
				perror("Recv Error from web: ");
				exit(EXIT_FAILURE);
			}

			// Send the data loaded from web back to client
			if (send(server_fd, webbuf, strlen(webbuf), 0) < 0)
			{
				perror("Send Error to client: ");
				exit(EXIT_FAILURE);
			}

			// Close the connected socket
			close(client_fd);
		}

		else
		{
			wait(NULL);
		}

	} while (1);

	return 0;
}
