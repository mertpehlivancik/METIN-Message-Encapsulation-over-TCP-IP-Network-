/*
 * CreateSSHSession.h
 *
 *  Created on: Apr 19, 2019
 *      Author: honeybee
 */

#ifndef CREATESSHSESSION_H_
#define CREATESSHSESSION_H_
#include "aes256.h"

void CreateSSHSession(char* hostname) {
	//username,password,hostname
	//honeybee Mert12- 127.0.0.1
	char username[50];
	memset(username,0,50);
	char password[50];
	memset(password,0,50);
	char ip[50];
	memset(ip,0,50);
	char request[255];
	memset(request,0,255);
	int a=0;
	printf("Please Enter Username: ");
	scanf("%[^\n]%*c", &username);
	printf("Please Enter Password: ");
	scanf("%[^\n]%*c", &password);
	printf("Please Enter IP_Address of SSH Server: ");
	scanf("%[^\n]%*c", &ip);

	for(;a<strlen(username);a++){
		request[a] = username[a];
	}
	request[a] = ' ';
	a++;
	for(int i=0;i<strlen(password);i++){
			request[a] = password[i];
			a++;
		}
	request[a] = ' ';
	a++;
	for(int i=0;i<strlen(ip);i++){
			request[a] = ip[i];
			a++;
		}
	request[a] = '\0';
//	char request[] = "honeybee Mert12- 127.0.0.1";
	char SendReq[255];
	aes256_context ctx;
	uint8_t key[32] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10',
			'11', '12', '13', '14', '15', '16', '17', '18', '19',
			'20', '21', '22', '23', '24', '25', '26', '27', '28',
			'29', '30', '31' };
	uint8_t enc[255], i;
	memset(enc,0,255);
	memset(SendReq,0,255);


	for (i = 0; i < strlen(request); i++) {
		enc[i] = request[i];
	}
	aes256_init(&ctx, key);
	aes256_encrypt_ecb(&ctx, enc);

	for (i = 0; i < sizeof(enc); i++) {
			SendReq[i] = enc[i];
		}

	SendHTTPRequest(hostname, SendReq);
//	anahtar == 1;
}

#endif /* CREATESSHSESSION_H_ */
