/*
 * SendHTTPRequest.h
 *
 *  Created on: Apr 17, 2019
 *      Author: honeybee
 */

#ifndef SENDHTTPREQUEST_H_
#define SENDHTTPREQUEST_H_
short int anahtar = 0;
void SendHTTPRequest(char* hostname, char* request_template) {

	request_len = snprintf(request, MAX_REQUEST_LEN, request_template,
			hostname);
	if (request_len >= MAX_REQUEST_LEN) {
		fprintf(stderr, "request length large: %d\n", request_len);
		exit(EXIT_FAILURE);
	}
	/* Send HTTP request. */
	nbytes_total = 0;
	while (nbytes_total < request_len) {
		nbytes_last = write(socket_file_descriptor, request + nbytes_total,
				request_len - nbytes_total);
		if (nbytes_last == -1) {
			perror("write");
			exit(-1);
		}
		nbytes_total += nbytes_last;
	}
	if (anahtar == 1) {
		rec();
	}

}

#endif /* SENDHTTPREQUEST_H_ */
