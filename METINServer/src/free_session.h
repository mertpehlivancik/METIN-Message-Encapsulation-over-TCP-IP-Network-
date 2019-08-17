/*
 * free_session.h
 *
 *  Created on: Apr 7, 2019
 *      Author: honeybee
 */

#ifndef FREE_SESSION_H_
#define FREE_SESSION_H_
#include <libssh/libssh.h>

void free_session(ssh_session session) {
	ssh_disconnect(session);
	ssh_free(session);
}

#endif /* FREE_SESSION_H_ */
