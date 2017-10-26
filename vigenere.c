#include"vigenere.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ALPH_SIZE 2

#define NORMAL 0
#define DEBUG -1

short vstate = DEBUG;

char lAlph[] = "abcdefghijklmnopqrstuvwxyz";
char hAlph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

typedef struct symbol_info{
	short pos;
	char *alph;
}symbolinf;

char *Alph[ALPH_SIZE] = {
	lAlph, hAlph
};

symbolinf getinf(char symbol){
	char *findstr = NULL;
	symbolinf currsymbol;
	int alphnum = 0;
	for(int i = 0; (i < ALPH_SIZE)&&(findstr==NULL); i++){
		findstr = strchr(Alph[i], symbol);
		currsymbol.alph = Alph[i];
	}
	if(findstr) currsymbol.pos = (short)(strlen(Alph[alphnum]) - strlen(findstr));
	else{
		currsymbol.pos = -1;
		currsymbol.alph = NULL;
	}
	return currsymbol;
}

void encrypt(char **dst, char *src, char *key){
	symbolinf sKey[strlen(key)], currsymbol;
	int pos;
	if(vstate == DEBUG) printf("sKey=");
	for(int i = 0; i<strlen(key); i++){
		sKey[i] = getinf(key[i]);
		if(vstate == DEBUG) printf("%d ", sKey[i].pos);
	}
	pos = 0;
	*dst = (char*)realloc(*dst, (strlen(src))*sizeof(char));
	for(int j = 0; j < strlen(key); j++){
		currsymbol = getinf(src[pos]);
		if(currsymbol.pos!=-1){
			(*dst)[pos] =  currsymbol.alph[((currsymbol.pos+sKey[j].pos+strlen(currsymbol.alph))%strlen(currsymbol.alph))];
		}
		else (*dst)[pos] = src[pos];
		if(vstate == DEBUG) {
			printf("\nSymbol: %c\nCiphered symbol: %c", src[pos], (*dst)[pos]);
			printf("\nKey symbol position: %d", j);
		}
		if(j == strlen(key)-1) j = 0;
		if(pos == strlen(src)-1) break;
		pos++;
	}
}

void decode(char *src){
}
