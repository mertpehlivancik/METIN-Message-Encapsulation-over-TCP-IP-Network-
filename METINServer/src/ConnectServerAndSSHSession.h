/*
 * ConnectServerAndSSHSession.h
 *
 *  Created on: Apr 19, 2019
 *      Author: honeybee
 */

#ifndef CONNECTSERVERANDSSHSESSION_H_
#define CONNECTSERVERANDSSHSESSION_H_

#include "aes256.h"

char username[50];
char password[50];
char hostname[50];
void ConnectServerAndSSHSession() {
	memset(username, 0, 50);
	memset(password, 0, 50);
	memset(hostname, 0, 50);

	memset(buf, 0, 2048);
	read(clientSocket, buf, 2048);
	uint8_t dec[255];
	memset(dec, 0, 255);
	for (int i = 0; i < strlen(buf); i++) {
		dec[i] = buf[i];
	}

	aes256_context ctx;
	uint8_t key[32] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10',
			'11', '12', '13', '14', '15', '16', '17', '18', '19',
			'20', '21', '22', '23', '24', '25', '26', '27', '28',
			'29', '30', '31' };

	aes256_init(&ctx, key);
	aes256_decrypt_ecb(&ctx, dec);

	for (int i = 0; i < sizeof(buf); i++) {
		buf[i] = dec[i];
	}

	int j = 0;
	int k = 0;
	int l = 0;
	for (int i = 0; i < strlen(buf); i++) {
		if (buf[i] == ' ' && j == 0) {
			for (k = 0; k < i; k++) {
				username[k] = buf[k];
			}
			j++;
		} else if (buf[i] == ' ' && j == 1) {
			for (k; k < i; k++) {
				password[l - 1] = buf[k];
				l++;
			}
			j++;
			l = 0;
		} else if (j == 2) {
			for (k; k < strlen(buf); k++) {
				hostname[l - 1] = buf[k];
				l++;
			}
			j++;
		} else if (j == 3) {
			break;
		}
	}

}

#endif /* CONNECTSERVERANDSSHSESSION_H_ */
