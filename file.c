#include"file.h"

#define NORMAL 0
#define DEBUG 1

short state = NORMAL;

/*
void ReadMessage(FILE *src, char *dst){
	if(!src) printf("File error!\n");
	char symbol;
	int MessageLen = 0;
	if(state == DEBUG) printf("Reading message...\n");
	while(!feof(src)){
		symbol = fgetc(src);
		dst[MessageLen] = symbol;												OUTDATE
		MessageLen++;
		if(state == DEBUG) {
			printf("!-------------------------\n");
			printf("%c\n", symbol);
			printf("Message Length: %d\n", MessageLen);
		}
	}
	dst[MessageLen-1] = '\0';
} 
*/

void ReadMessage(FILE *src, char **dst){
	*dst = malloc(0);
	if(!src) printf("File error!\n");
	char symbol;
	int MessageLen = 0;
	printf("Reading message...\n");
	do{
		symbol = fgetc(src);
		MessageLen++;
		*dst = (char*)realloc((char*)*dst, (MessageLen)*sizeof(char));
		(*dst)[MessageLen-1] = symbol;
		(*dst)[MessageLen] = '\0';
		if(state == DEBUG) {
			printf("!-------------------------\n");
			printf("Message Length: %d\n", MessageLen);
			printf("%s\n", *dst);
			//system("pause");
		}
	}while(!feof(src));
	(*dst)[MessageLen-1] = '\0';
	if(state == DEBUG){
		printf("End Message Length: %d\n", MessageLen);
	}
	//realloc(*dst, (++MessageLen)*sizeof(char));
	printf("Message: %s\n", *dst);
	//rewind(src);
}

void WriteMessage(FILE *dst, char *src){
	if(!dst) printf("Error!\n");
	//fputc('\0', dst);
	//rewind(dst);
	for(int i = 0; i <strlen(src); i++){
		fputc(src[i], dst);
	}
	printf("Ok\n");
}
