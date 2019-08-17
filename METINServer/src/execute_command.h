/*
 * execute_command.h
 *
 *  Created on: Apr 7, 2019
 *      Author: honeybee
 */

#ifndef EXECUTE_COMMAND_H_
#define EXECUTE_COMMAND_H_
#include <libssh/libssh.h>
#include "error.h"

void execute_command(void* command, int server_port, char* IP) {
	printf("Executing remote command...\n");
	rc = ssh_channel_request_exec(channel, command);
	if (rc != SSH_OK)
		error(session, server_port, IP);

	printf("Received:\n");
	nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	while (nbytes > 0) {
		fwrite(buffer, 1, nbytes, stdout);
		nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	}
}

#endif /* EXECUTE_COMMAND_H_ */
