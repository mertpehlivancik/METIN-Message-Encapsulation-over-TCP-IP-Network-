/*
 * setHTTPHeader.h
 *
 *  Created on: Apr 15, 2019
 *      Author: honeybee
 */

#ifndef SETHTTPHEADER_H_
#define SETHTTPHEADER_H_

char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";
void setHttpHeader(char* HtmlFilePath) {

	FILE *htmlData = fopen(HtmlFilePath, "r");
	char line[100];
	char responseData[8000];
	while (fgets(line, 100, htmlData) != 0) {
		strcat(responseData, line);
	}
	strcat(httpHeader, responseData);
}

#endif /* SETHTTPHEADER_H_ */
