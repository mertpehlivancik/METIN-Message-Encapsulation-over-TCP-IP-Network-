/*
 * server.h
 *
 *  Created on: Apr 15, 2019
 *      Author: honeybee
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "setHTTPHeader.h"
#include "report.h"
#include "error.h"
#define BACKLOG 10

char* HtmlFilePath = "/home/honeybee/git/METIN/libssh/src/index.html";
int clientSocket = 0;
char buf[2048];
int serverSocket = 0;

int server(int server_port, char *IP) {
	if (serverSocket != 0) {
		close(clientSocket);
		close(serverSocket);
	}
	memset(buf, 0, 2048);

	serverSocket = socket(
	AF_INET,
	SOCK_STREAM, 0);

	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(server_port);
//	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK); /*Uncomment For Localhost*/
	serverAddress.sin_addr.s_addr = inet_addr(IP);

	bind(serverSocket, (struct sockaddr *) &serverAddress,
			sizeof(serverAddress));

	int listening = listen(serverSocket, BACKLOG);
	if (listening < 0) {
		printf("Error: The server is not listening.\n");
		return 1;
	}
	report(&serverAddress);
	setHttpHeader(HtmlFilePath);

	clientSocket = accept(serverSocket, NULL, NULL);

	return 0;
}

#endif /* SERVER_H_ */
