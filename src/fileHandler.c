#include "../include/fileHandler.h"
#include <string.h>
#include <strings.h>
char *readNewLine(FILE* input){
	char *line = NULL;
	long unsigned int n = 0;		
	getline(&line, &n, input);
	return line;
}

int countPointDimension(FILE *input){
	char *line = readNewLine(input);
	// printf("%s", line);
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

	char *line = NULL;
	while (!feof(input)){
		line = readNewLine(input);
		if(strcmp(line, "") == 0){ // Chegou no final do arquivo
			break;
		}
		char *id;
		double *mValues = malloc(sizeof(double) * m);

		id = strtok(line, ",");
		for (int i = 0; i < m; i++){
			mValues[i] = atof(strtok(NULL, ","));
		}

		free(mValues); // Remover esse free dps
		free(line);
	}
	free(line);
	
	return NULL;
}