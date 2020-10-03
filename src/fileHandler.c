#include "../include/fileHandler.h"

Point* fileToPoint(FILE* input){
    char *line;
	long unsigned int n = 0;
	getline(&line, &n, input);
	int m = 0;
	strtok(line, ","); // Ignorar o identificador
	while(strtok(NULL, ",") != NULL){
		m++;
	}
	printf("%d\n", m);
	free(line);
	rewind(input);
	//while (!feof(input)){
		
	//}
	return NULL;
}