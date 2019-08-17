/*
 * new_session.h
 *
 *  Created on: Apr 7, 2019
 *      Author: honeybee
 */

#ifndef NEW_SESSION_H_
#define NEW_SESSION_H_
#include <libssh/libssh.h>
#include "error.h"

ssh_session session;
int port = 22;
char buffer[1024];
unsigned int nbytes;
int new_session(char* username, char* password, char* hostname, int server_port,
		char* IP) {

	printf("Session...\n");
	session = ssh_new();
	if (session == NULL)
		exit(-1);

	ssh_options_set(session, SSH_OPTIONS_HOST, hostname);
	ssh_options_set(session, SSH_OPTIONS_PORT, &port);
	ssh_options_set(session, SSH_OPTIONS_USER, username);

	printf("Connecting...\n");
	rc = ssh_connect(session);
	if (rc != SSH_OK)
		error(session, server_port, IP);

	printf("Password Autentication...\n");
	rc = ssh_userauth_password(session, NULL, password);
	if (rc != SSH_AUTH_SUCCESS)
		error(session, server_port, IP);

	return 1;
}

#endif /* NEW_SESSION_H_ */
