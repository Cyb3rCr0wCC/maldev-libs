#include <stdio.h>
#include <string.h>

void encryptDecrypt(char *input, char *output) {
	char key[] = {'K', 'C', 'Q', 'B', 'H'}; //Can be any chars, and any size array
	
	int i;
	for(i = 0; i < strlen(input); i++) {
		output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];
	}
}

char* Encrypt(char* input){
    char *output = NULL;
    char *ciphertext = NULL;

    size_t input_length = strlen(input);
    
    // Allocate memory for the XORed output. In a simple XOR, the output size is the same as the input.
    output = (char *)malloc(input_length + 1);
    encryptDecrypt(input, output);

    // Base64 encode the ciphertext
    ciphertext = base64_encode((const unsigned char *)output, input_length);
    free(output);
    return ciphertext;
    //free(ciphertext);

}

char* Decode(char* input){
    char *plaintext = NULL;

    size_t decoded_length;
    unsigned char *decoded_output = base64_decode(input, &decoded_length);

    // Allocate memory for the plaintext (after XOR decryption).
    plaintext = (char *)malloc(decoded_length + 1);
    encryptDecrypt((char *)decoded_output, plaintext);

    free(decoded_output);

    return plaintext;
}