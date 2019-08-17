/*
 ============================================================================
 Name        : libssh.c
 Author      : Mert PEHLİVANCIK
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <libssh/libssh.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sodium.h>
#include "free_channel.h"
#include "free_session.h"
#include "error.h"
#include "shell_session.h"
#include "new_session.h"
#include "execute_command.h"
#include "interactive_shell_session.h"
#include  "setHTTPHeader.h"
#include "report.h"
#include "server.h"
#include "ConnectServerAndSSHSession.h"
#include "recursive.h"
#define SIZE 1024

/*Please control ssh status with this command ---> sudo service ssh status*/

int main(int argc, char** argv) {

	int server_port = 0;
	char IP[15];
	memset(IP, 0, 15);
	printf("Server IP Address: ");
	scanf("%[^\n]%*c", &IP);
	printf("Server Port: ");
	scanf("%d", &server_port);
	recursive(server_port, IP);

	return 0;
}
