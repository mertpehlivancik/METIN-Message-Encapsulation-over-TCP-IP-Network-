/*
 * shell_session.h
 *
 *  Created on: Apr 7, 2019
 *      Author: honeybee
 */

#ifndef SHELL_SESSION_H_
#define SHELL_SESSION_H_
#include <libssh/libssh.h>
#include "error.h"

ssh_channel channel;
int rc;
int shell_session(ssh_session session, int server_port, char* IP) {

	channel = ssh_channel_new(session);
	if (channel == NULL)
		return SSH_ERROR;
	rc = ssh_channel_open_session(channel);
	if (rc != SSH_OK) {
		error(session, server_port, IP);
		free_channel(channel);
		return rc;
	}

	return SSH_OK;
}

#endif /* SHELL_SESSION_H_ */
