/*
 * free_channel.h
 *
 *  Created on: Apr 7, 2019
 *      Author: honeybee
 */

#ifndef FREE_CHANNEL_H_
#define FREE_CHANNEL_H_
#include <libssh/libssh.h>

void free_channel(ssh_channel channel) {
    //ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
}


#endif /* FREE_CHANNEL_H_ */
