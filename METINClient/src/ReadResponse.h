/*
 * ReadResponse.h
 *
 *  Created on: Apr 17, 2019
 *      Author: honeybee
 */

#ifndef READRESPONSE_H_
#define READRESPONSE_H_
#include "rec.h"

void ReadResponse() {
	char command[2048];
	memset(command, 0, 2048);

	while (1) {
		sleep(3);
		nbytes_total = read(socket_file_descriptor, buffer, BUFSIZ);
		if (strcmp(buffer, "hata") == 0) {
			yyy = 1;
			rec();
		}
		if (nbytes_total > 0) {
			write(STDOUT_FILENO, buffer, nbytes_total);
		}
		if (nbytes_total < BUFSIZ) {
			scanf("%[^\n]%*c", &command);
			SendHTTPRequest("localhost", command);
		}
	}
	if (nbytes_total == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	rec();

//	while ((nbytes_total = read(socket_file_descriptor, buffer, BUFSIZ)) > 0) {
//		fprintf(stderr, "debug: after a read\n");
//		write(STDOUT_FILENO, buffer, nbytes_total);
//	}

}

#endif /* READRESPONSE_H_ */
