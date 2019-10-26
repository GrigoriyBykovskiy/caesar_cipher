#ifndef __CaesarCipherH__
#define __CaesarCipherH__

typedef struct {
	char *alphabet_lowcase;
	char *alphabet_uppercase;
	unsigned offset;
	char *input_filename;
	char *output_filename;
}	TCipher;

TCipher *init_TCipher(char *alphabet_lowcase, char *alphabet_uppercase, unsigned offset, char *input_filename, char *output_filename);
int encrypt(TCipher *user_input);
int decrypt(TCipher *user_input);

#endif