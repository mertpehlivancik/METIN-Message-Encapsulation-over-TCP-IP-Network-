/*
 * recursive.h
 *
 *  Created on: May 6, 2019
 *      Author: honeybee
 */

#ifndef RECURSIVE_H_
#define RECURSIVE_H_
#include "shell_session.h"

int recursive(int server_port, char* IP) {

	server(server_port, IP);
	ConnectServerAndSSHSession();
	int rv = 0;
	rv = new_session(username, password, hostname, server_port, IP);

	if (shell_session(session, server_port, IP) != SSH_OK) {
		error(session, server_port, IP);
		free_channel(channel);
		return rc;
	}
	interactive_shell_session(session, channel, server_port, IP);
}

#endif /* RECURSIVE_H_ */
