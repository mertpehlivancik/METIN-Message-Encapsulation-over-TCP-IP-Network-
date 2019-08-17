/*
 * rec.h
 *
 *  Created on: Apr 18, 2019
 *      Author: honeybee
 */

#ifndef REC_H_
#define REC_H_

int yyy = 0;

void rec() {
//	char command[2048];
//	memset(command, 0, 2048);
	if (yyy == 1){
		close(socket_file_descriptor);
		exit(0);
	}
	ReadResponse();

//		scanf("%[^\n]%*c", &command);
//		/* Send HTTP request. */
//		SendHTTPRequest("localhost", command);
//		/* Read the response. */

}

#endif /* REC_H_ */
