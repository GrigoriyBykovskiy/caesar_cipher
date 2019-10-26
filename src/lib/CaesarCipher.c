#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "headers/CaesarCipherH.h"

TCipher *init_TCipher(char *alphabet_lowcase, char *alphabet_uppercase, unsigned offset, char *input_filename, char *output_filename)
{
	TCipher *tmp = NULL;
	tmp = (TCipher*)malloc(sizeof(TCipher));

	if (tmp != NULL)
	{
		//блять, не помню, правильно ли выделил память и инициализировал структуру, строки же
		tmp -> alphabet_lowcase = (char*)malloc((strlen(alphabet_lowcase)+1)*sizeof(char));
		tmp	-> alphabet_uppercase = (char*)malloc((strlen(alphabet_uppercase) + 1) * sizeof(char));
		tmp -> input_filename = (char*)malloc((strlen(input_filename) + 1) * sizeof(char));
		tmp -> output_filename = (char*)malloc((strlen(output_filename) + 1) * sizeof(char));

		if ((tmp->alphabet_lowcase != NULL) && (tmp	-> alphabet_uppercase != NULL) 
			&& (tmp->input_filename != NULL) && (tmp->output_filename != NULL))
		{
			strcpy(tmp->alphabet_lowcase, alphabet_lowcase);
			strcpy(tmp->alphabet_uppercase, alphabet_uppercase);
			tmp->offset = offset;
			strcpy(tmp->input_filename, input_filename);
			strcpy(tmp->output_filename, output_filename);
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
	/*printf("encrypt\n");
	printf("%s\n", user_input->alphabet_lowcase);
	printf("%s\n", user_input->alphabet_uppercase);
	printf("%d\n", user_input->offset);
	printf("%s\n", user_input->input_filename);
	printf("%s\n", user_input->output_filename);*/
	FILE *input_text, *output_text;

	if (((input_text = fopen(user_input->input_filename, "r")) != NULL) 
		&& (output_text = fopen(user_input->output_filename, "w+") != NULL))
	{
		char symbol;
		while ((symbol = fgetc(input_text))&&(!feof(input_text))) 
		{
			for (int i = 0; i < strlen(user_input->alphabet_lowcase); i++)
			{
				unsigned final_offset = (i + user_input->offset) % strlen(user_input->alphabet_lowcase);
				//printf("%d\n", final_offset);
				if (symbol == user_input->alphabet_lowcase[i])
				{
					printf("%c %c\n", symbol, user_input->alphabet_lowcase[final_offset]);
					//fprintf(output_text, "%c", symbol,user_input->alphabet_lowcase[final_offset]);
				}
				if (symbol == user_input->alphabet_uppercase[i])
				{

				}
			}
		}
	}
	else {
		printf("Can not open IO file!\n");
		return NULL;
	}
	return 1;
};

int decrypt(TCipher *user_input)
{
	printf("decrypt");
	return 1;
};

void output()
{
	printf("output");
};

