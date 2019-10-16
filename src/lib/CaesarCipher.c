#include <stdio.h>
#include "headers/CaesarCipherH.h"

TCipher *init_TCipher(char *alphabet_lowcase, char *alphabet_uppercase, unsigned offset, char *input_filename, char *output_filename)
{
	TCipher *tmp = NULL;
	tmp = (TCipher*)malloc(sizeof(TCipher));

	if (tmp != NULL) {
		//блять, не помню, правильно ли выделил память и инициализировал структуру, строки же
		tmp -> alphabet_lowcase = (char*)malloc((strlen(alphabet_lowcase)+1)*sizeof(char));
		tmp	-> alphabet_uppercase = (char*)malloc((strlen(alphabet_uppercase) + 1) * sizeof(char));
		tmp -> input_filename = (char*)malloc((strlen(input_filename) + 1) * sizeof(char));
		tmp-> output_filename = (char*)malloc((strlen(output_filename) + 1) * sizeof(char));
		if ((tmp->alphabet_lowcase != NULL) && (tmp	-> alphabet_uppercase != NULL) && (tmp->input_filename != NULL) && (tmp->output_filename != NULL)){
			strcpy(tmp->alphabet_lowcase, alphabet_lowcase);
			strcpy(tmp->alphabet_uppercase = alphabet_uppercase);
			tmp->offset = offset;
			strcpy(tmp->input_filename, input_filename);
			strcpy(tmp->output_filename, output_filename);
		}
		else {
			free(tmp);
			tmp = NULL;
		}
	}
	return tmp;
};

int encrypt(TCipher *user_input)
{
	return 1;
};

int decrypt(TCipher *user_input)
{
	return 1;
};
