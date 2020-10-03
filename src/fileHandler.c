#include "../include/fileHandler.h"

char *readNewLine(FILE* input){
	char *line;
	long unsigned int n = 0;		
	getline(&line, &n, input);
	return line;
}

int countPointDimension(FILE *input){
	char *line = readNewLine(input);
	int m = 0;
	strtok(line, ","); // Ignorar o identificador
	while(strtok(NULL, ",") != NULL){
		m++;
	}
	free(line);
	rewind(input);

	return m;
}


Point* fileToPoint(FILE* input){
	rewind(input); // just in case

    int m = countPointDimension(input);
	printf("%d", m);

	while (!feof(input)){
		char *line = readNewLine(input);
		 // TODO
	}
	return NULL;
}