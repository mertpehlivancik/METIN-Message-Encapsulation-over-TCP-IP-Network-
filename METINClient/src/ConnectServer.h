/*
 * ConnectServer.h
 *
 *  Created on: Apr 17, 2019
 *      Author: honeybee
 */

#ifndef CONNECTSERVER_H_
#define CONNECTSERVER_H_
#define _XOPEN_SOURCE 700
#include <arpa/inet.h>
#include <assert.h>
#include <netdb.h> /* getprotobyname */
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

char buffer[BUFSIZ];
enum CONSTEXPR {
	MAX_REQUEST_LEN = 1024
};
char request[MAX_REQUEST_LEN];
struct protoent *protoent;
in_addr_t in_addr;
int request_len;
int socket_file_descriptor;
ssize_t nbytes_total, nbytes_last;
struct hostent *hostent;
struct sockaddr_in sockaddr_in;
void ConnetHTTPServer(char* hostname, unsigned short server_port) {
	/* Build the socket. */
	protoent = getprotobyname("tcp");
	if (protoent == NULL) {
		perror("getprotobyname");
		exit(EXIT_FAILURE);
	}
	socket_file_descriptor = socket(AF_INET, SOCK_STREAM, protoent->p_proto);
	if (socket_file_descriptor == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	/* Build the address. */
	hostent = gethostbyname(hostname);
	if (hostent == NULL) {
		fprintf(stderr, "error: gethostbyname(\"%s\")\n", hostname);
		exit(EXIT_FAILURE);
	}
	in_addr = inet_addr(inet_ntoa(*(struct in_addr*) *(hostent->h_addr_list)));
	if (in_addr == (in_addr_t) -1) {
		fprintf(stderr, "error: inet_addr(\"%s\")\n", *(hostent->h_addr_list));
		exit(EXIT_FAILURE);
	}
	sockaddr_in.sin_addr.s_addr = in_addr;
	sockaddr_in.sin_family = AF_INET;
	sockaddr_in.sin_port = htons(server_port);

	/* Actually connect. */
	if (connect(socket_file_descriptor, (struct sockaddr*) &sockaddr_in,
			sizeof(sockaddr_in)) == -1) {
		perror("connect");
		exit(EXIT_FAILURE);
	}
}

#endif /* CONNECTSERVER_H_ */
