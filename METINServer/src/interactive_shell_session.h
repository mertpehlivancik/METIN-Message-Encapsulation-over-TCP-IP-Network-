/*
 * interactive_shell_session.h
 *
 *  Created on: Apr 7, 2019
 *      Author: honeybee
 */

#ifndef INTERACTIVE_SHELL_SESSION_H_
#define INTERACTIVE_SHELL_SESSION_H_
#include <libssh/libssh.h>
#include "server.h"

int interactive_shell_session(ssh_session session, ssh_channel channel,
		int server_port, char* IP) {
	int rc;
	char buffer[2048];
	int nbytes, nwritten, swritten;
	rc = ssh_channel_request_pty(channel);
	if (rc != SSH_OK)
		return rc;
	rc = ssh_channel_change_pty_size(channel, 80, 24);
	if (rc != SSH_OK)
		return rc;
	rc = ssh_channel_request_shell(channel);
	if (rc != SSH_OK)
		return rc;
	while (ssh_channel_is_open(channel) && !ssh_channel_is_eof(channel)) {
		struct timeval timeout;
		ssh_channel in_channels[2], out_channels[2];
		fd_set fds;
		int maxfd;
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;
		in_channels[0] = channel;
		in_channels[1] = NULL;
		FD_ZERO(&fds);
		FD_SET(0, &fds);
		FD_SET(ssh_get_fd(session), &fds);
		maxfd = ssh_get_fd(session) + 1;
		ssh_select(in_channels, out_channels, maxfd, &fds, &timeout);

		if (out_channels[0] != NULL) {
			nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
			if (nbytes < 0)
				return SSH_ERROR;
			if (nbytes > 0) {
				nwritten = write(1, buffer, nbytes);
				swritten = write(clientSocket, buffer, nbytes);
				if (swritten < 0) { /* "swritten < 0" in disconnection situation */
					error(session, server_port, IP);
					exit(-1);
				}
				if (nwritten != nbytes)
					return SSH_ERROR;
			}
		} else {
			fds.__fds_bits[0] = 1;
		}

		if (FD_ISSET(0, &fds)) {
			memset(buf, 0, 2048);
			read(clientSocket, buf, 2048);
			for (int i = 0; i < strlen(buf); i++) {
				buffer[i] = buf[i];
			}
			buffer[strlen(buf)] = '\n';
			nbytes = strlen(buf) + 1;
			if (nbytes < 0)
				return SSH_ERROR;
			if (nbytes > 0) {
				nwritten = ssh_channel_write(channel, buffer, nbytes);
				if (nbytes != nwritten)
					return SSH_ERROR;
			}
		}
	}
	close(clientSocket);
	return rc;
}

#endif /* INTERACTIVE_SHELL_SESSION_H_ */
