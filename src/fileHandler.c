#include "../include/fileHandler.h"
#include <string.h>
#include <strings.h>
char *readNewLine(FILE* input){
	char *line;
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

	while (!feof(input)){
		char *line = readNewLine(input);
		if(strcmp(line, "") == 0){ // Chegou no final do arquivo
			break;
		}
		char *id;
		double *mValues = malloc(sizeof(double) * m);

		// strtok aparentemente modifica a string original, ao invés de retornar a parte dela até a vírgula
		// se não fosse por isso, o código abaixo devia funcionar, mas nem tudo na vida são flores
		// TODO: Arrumar essa aberração abaixo
		id = strtok(line, ",");
		
		for (int i = 0; i < m; i++){
			double buffer;
			if(i != (m-1)){
				buffer = atof(strtok(line, ","));
			}else{
				buffer = atof(strtok(line, "\n"));
			}
			mValues[i] = buffer;
		}

		for (int i = 0; i < m; i++){
			printf("%.2f", mValues[i]);
		}
		free(line);
		free(mValues);
	}
	
	return NULL;
}