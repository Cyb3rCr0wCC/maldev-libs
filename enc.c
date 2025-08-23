#include <stdio.h>
#include <string.h>
#include "enc.h"


int main(int argc, char *argv[]){

    if (argc > 2) {
        if (strcmp(argv[1],"encrypt") == 0){
            char* cipherText = Encrypt(argv[2]);
            printf("Original text: %s\n", argv[2]);
            printf("Ciphertext: %s", cipherText);
            return 0;
        }
        else if (strcmp(argv[1],"decrypt") == 0){
            char* plainText = Decrypt(argv[2]);
            printf("Ciphertext: %s\n", argv[2]);
            printf("Plaintext: %s", plainText);
            return 0;
        }
        else{
            printf("Usage: enc <encrypt/decrypt> <plaintext/ciphertext>");
            return 1;
        }
        
    }
    

    return 0;
}