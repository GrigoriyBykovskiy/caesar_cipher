// ñaesar_ñipher.c : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#define ALPHABET_LOWCASE "abcdefghijklmnopqrstuvwxyz"	// lenght of this constant must be equal
#define ALPHABET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"// else ... ANTA BAKA?!
#define MAX_ALPHABET_LEN 25 // variative value. if you want you may change it, but remember that it is lenght of alphabet 

#include <stdio.h>
#include <stdlib.h>
#include "src/lib/headers/CaesarCipherH.h"

int main(int argc, char **argv)
{
	if (argc == 5) {

		char *keys[2] = { "-e","-d" };
		int is_key = 0;
		int(*caesar_cipher)(char *arg1, char *arg2);

		for (int i = 0; i < 2; i++) 
		{
			if (strcmp(keys[i], argv[1]) == 0) 
			{
				unsigned tmp_offset = atoi(argv[2]);
				char tmp_alphabet_lowcase[] = ALPHABET_LOWCASE;
				char tmp_alphabet_uppercase[] = ALPHABET_UPPERCASE;
				TCipher *user_input;

				if (tmp_offset && (tmp_offset > 0) && (tmp_offset < MAX_ALPHABET_LEN))
					user_input = init_TCipher(tmp_alphabet_lowcase, tmp_alphabet_uppercase, tmp_offset, argv[3], argv[4]);
				else
					printf("ANTA BAKA?! Offset must be a number and belong [0,%d]!\n", MAX_ALPHABET_LEN);

				switch (i)
				{
					case 0:

						is_key = 1;
						encrypt(user_input);
						//caesar_cipher = encrypt;
						//if (caesar_cipher(argv[1], argv[2]) == NULL) printf("Problem with FILE or low memory!\n");
						break;

					case 1:

						is_key = 1;
						//caesar_cipher = decrypt;
						//if (caesar_cipher(argv[1], argv[2]) == NULL) printf("Problem with FILE or low memory!\n");
						break;

					default:
						break;
				}
			}
		}

		if (is_key == 0) printf("ANTA BAKA?! Wrong parameter has been transferred\n");

	}
	else 
		printf("Error! Only 3 parameters are requirted!\n");

	return 0;
}
