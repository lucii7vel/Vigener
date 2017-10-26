#ifndef FILE_H
#define FILE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ReadMessage(FILE *src, char **dst);
void WriteMessage(FILE *dst, char *src);
#endif
