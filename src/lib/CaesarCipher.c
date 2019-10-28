#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "headers/CaesarCipherH.h"

TCipher *init_TCipher(char *alphabet_lowcase, char *alphabet_uppercase, unsigned offset, char *input_filename)
{
	TCipher *tmp = NULL;
	tmp = (TCipher*)malloc(sizeof(TCipher));

	if (tmp != NULL)
	{
		tmp -> alphabet_lowcase = (char*)malloc((strlen(alphabet_lowcase)+1)*sizeof(char));
		tmp	-> alphabet_uppercase = (char*)malloc((strlen(alphabet_uppercase) + 1) * sizeof(char));
		tmp -> input_filename = (char*)malloc((strlen(input_filename) + 1) * sizeof(char));

		if ((tmp->alphabet_lowcase != NULL) && (tmp	-> alphabet_uppercase != NULL) 
			&& (tmp->input_filename != NULL))
		{
			strcpy(tmp->alphabet_lowcase, alphabet_lowcase);
			strcpy(tmp->alphabet_uppercase, alphabet_uppercase);
			tmp->offset = offset;
			strcpy(tmp->input_filename, input_filename);
		}
		else 
		{
			free(tmp);
			tmp = NULL;
		}
	}

	return tmp;
};

int encrypt(TCipher *user_input)
{
	FILE *input_text;

	if ((input_text = fopen(user_input->input_filename, "r")) != NULL) 
	{
		char symbol;

		do 
		{
			symbol = fgetc(input_text);

			for (int i = 0; i < strlen(user_input->alphabet_lowcase); i++)
			{
				unsigned final_offset = (i + user_input->offset) % strlen(user_input->alphabet_lowcase);

				if (symbol == user_input->alphabet_lowcase[i]) 
					fprintf(stdout, "%c", user_input->alphabet_lowcase[final_offset]);

				if (symbol == user_input->alphabet_uppercase[i])
					fprintf(stdout, "%c", user_input->alphabet_uppercase[final_offset]);
			}

		} while (symbol != EOF);

	}
	else {
		fprintf(stderr, "Can not open input file!\n");
		return NULL;
	}

	return 1;
};

int decrypt(TCipher *user_input)
{
	FILE *input_text;

	if ((input_text = fopen(user_input->input_filename, "r")) != NULL)
	{
		char symbol;

		do
		{
			symbol = fgetc(input_text);
			int tmp_offset = user_input->alphabet_lowcase - user_input->offset;
			for (int i = 0; i < strlen(user_input->alphabet_lowcase); i++)
			{
				int final_offset = (abs((user_input->offset - i - strlen(user_input->alphabet_lowcase)))) % strlen(user_input->alphabet_lowcase);
				
				if (symbol == user_input->alphabet_lowcase[i]) 
					fprintf(stdout, "%c", user_input->alphabet_lowcase[final_offset]);

				if (symbol == user_input->alphabet_uppercase[i]) 
					fprintf(stdout, "%c", user_input->alphabet_uppercase[final_offset]);
			}

		} while (symbol != EOF);

	}
	else {
		fprintf(stderr, "Can not open input file!\n");
		return NULL;
	}

	return 1;
};