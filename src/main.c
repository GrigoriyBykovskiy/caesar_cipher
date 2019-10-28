// ñaesar_ñipher.c : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#define ALPHABET_LOWCASE "abcdefghijklmnopqrstuvwxyz"	// lenght of this constant must be equal
#define ALPHABET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"// else ... ANTA BAKA?!
#define MAX_ALPHABET_LEN 26 // variative value. if you want you may change it, but remember that it is lenght of alphabet 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/lib/headers/CaesarCipherH.h"

int main(int argc, char **argv)
{
	if (argc == 4) {

		char *keys[2] = { "-e","-d" };
		int is_key = 0;

		for (int i = 0; i < 2; i++) 
		{
			if (strcmp(keys[i], argv[1]) == 0) 
			{
				unsigned tmp_offset = atoi(argv[2]);
				char tmp_alphabet_lowcase[] = ALPHABET_LOWCASE;
				char tmp_alphabet_uppercase[] = ALPHABET_UPPERCASE;
				TCipher *user_input;

				if (tmp_offset && (tmp_offset > 0) && (tmp_offset < MAX_ALPHABET_LEN))
					user_input = init_TCipher(tmp_alphabet_lowcase, tmp_alphabet_uppercase, tmp_offset, argv[3]);
				else
					fprintf(stderr, "ANTA BAKA?! Offset must be an integer number and belong [1,%d]!\n", MAX_ALPHABET_LEN-1);

				switch (i)
				{
					case 0:

						is_key = 1;
						encrypt(user_input);
						break;

					case 1:

						is_key = 1;
						decrypt(user_input);
						break;

					default:
						break;
				}
			}
		}

		if (is_key == 0) fprintf(stderr, "ANTA BAKA?! Wrong parameter has been transferred\n");

	}
	else 
		fprintf(stderr, "ANTA BAKA?! Only 3 parameters are requirted!\n");

	return 0;
}