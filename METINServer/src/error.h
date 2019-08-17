/*
 * error.h
 *
 *  Created on: Apr 7, 2019
 *      Author: honeybee
 */

#ifndef ERROR_H_
#define ERROR_H_
#include <libssh/libssh.h>
#include "server.h"

void error(ssh_session session, int server_port, char* IP) {
	fprintf(stderr, "Error: %s\n", ssh_get_error(session));
	write(clientSocket, "hata", 4);
	printf("Please Wait");
	sleep(5);
	close(clientSocket);
	free_session(session);
	recursive(server_port, IP);
	exit(-1);
}

#endif /* ERROR_H_ */
