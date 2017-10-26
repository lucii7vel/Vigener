#include <stdio.h>
#include<stdlib.h>
#include"file.h"
#include"vigenere.h"

int main(int argc, char *argv[])
{
	char *message, *cipher, key[64];
	FILE *fmess = fopen("message.txt",  "r+");
	ReadMessage(fmess, &message);
	printf("Key:");
	scanf("%s", key);
	printf("Key accepted\n");
	cipher = malloc(0);
	encrypt(&cipher, message, key);
	free(message);
	fclose(fmess);
	FILE *fcipher = fopen("cipher.txt", "w+");
	printf("Encrypted message: %s", cipher);
	WriteMessage(fcipher, cipher);
	decode(cipher);
	free(cipher);
	fclose(fcipher);
}

