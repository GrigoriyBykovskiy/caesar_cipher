// ñaesar_ñipher.c : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#define OUTPUT_FILENAME "output.txt"
#include <stdio.h>
#include "src/lib/headers/CaesarCipher.h"


int main(int argc, char **argv)
{
	if (argc == 4) {
		char *keys[3] = { "-e","-d" };
		int is_key = 0;
		int(*caesar_cipher)(char *arg1, char *arg2);
		for (int i = 0; i < 2; i++) {
			if (strcmp(keys[i], argv[3]) == 0) {
				switch (i)
				{
				case 0:
					is_key = 1;
					caesar_cipher = encrypt;
					if (caesar_cipher(argv[1], argv[2]) == NULL) printf("Problem with FILE or low memory!\n");
					break;
				case 1:
					is_key = 1;
					caesar_cipher = decrypt;
					if (caesar_cipher(argv[1], argv[2]) == NULL) printf("Problem with FILE or low memory!\n");
					break;
				default:
					break;
				}
			}
		}
		if (is_key == 0) printf("Wrong parameter has been transferred\n");

	}
	else printf("Error! Only 3 parameters are requirted!\n");
	return 0;
}
