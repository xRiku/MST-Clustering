#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/point.h"
#include "../include/fileHandler.h"

int main(int argc, char **argv)
{
	if(argc != 4){
		fprintf(stderr, "Quantidade de argumentos invalido\n");
		exit(1);
	}
	int k = atoi(argv[2]);
	FILE* input = fopen(argv[1], "r");
	FILE* output = fopen(argv[3], "w");
	if(input == NULL){
		fprintf(stderr, "Erro ao abrir %s\n", argv[1]);
		exit(1);
	}
	fileToPoint(input);
	if(output == NULL){
		fprintf(stderr, "Erro ao criar %s\n", argv[1]);
		exit(1);
	}
	fclose(input);
	fclose(output);

	return (0);
}