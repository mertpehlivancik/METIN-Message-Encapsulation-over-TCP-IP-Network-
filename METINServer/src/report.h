/*
 * report.h
 *
 *  Created on: Apr 15, 2019
 *      Author: honeybee
 */

#ifndef REPORT_H_
#define REPORT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h> // for getnameinfo()
// Usual socket headers
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void report(struct sockaddr_in *serverAddress) {
	char hostBuffer[INET6_ADDRSTRLEN];
	char serviceBuffer[NI_MAXSERV]; // defined in `<netdb.h>`
	socklen_t addr_len = sizeof(*serverAddress);
	int err = getnameinfo((struct sockaddr *) serverAddress, addr_len,
			hostBuffer, sizeof(hostBuffer), serviceBuffer,
			sizeof(serviceBuffer),
			NI_NUMERICHOST);

	if (err != 0) {
		printf("It's not working!!\n");
	}
	printf("\n\n\tServer listening on http://%s:%s\n", hostBuffer,
			serviceBuffer);
}


#endif /* REPORT_H_ */
