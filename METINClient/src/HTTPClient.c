/*
 ============================================================================
 Name        : HTTPClient.c
 Author      : Mert PEHLİVANCIK
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Compile	 : gcc -ggdb3 -std=c99 -Wall -Wextra -o client HTTPClient.c
 ============================================================================
 */

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
#include <sodium.h>
#include "ConnectServer.h"
#include "SendHTTPRequest.h"
#include "ReadResponse.h"
#include "rec.h"
#include "CreateSSHSession.h"


int main(int argc, char** argv) {
	char* hostname;
	int server_port = 0;
	if (argc > 1)
		hostname = argv[1];
	if (argc > 2)
		server_port = strtoul(argv[2], NULL, 10);
	ConnetHTTPServer(hostname, server_port);
	CreateSSHSession(hostname);

	/*ConnectHTTPServer*/

//	ConnetHTTPServer("127.0.0.1", 8080);
//	CreateSSHSession("127.0.0.1");



	/*SendAndResponse*/
	rec();

	close(socket_file_descriptor);
	exit(EXIT_SUCCESS);
}

