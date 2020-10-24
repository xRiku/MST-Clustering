#include <string.h>
#include <strings.h>
#include "../include/fileHandler.h"

/**
 * @brief Lê uma nova linha de um arquivo, retornando em um vetor de caracteres
 * 
 * @param input Arquivo a ser lido
 * @return char* Vetor de caracteres resultante
 */
char *readNewLine(FILE* input){
	char *line = NULL;
	long unsigned int n = 0;
	getline(&line, &n, input);
	return line;
}

/**
 * @brief Conta a dimensão de um ponto dado em um arquivo
 * 
 * @param input Arquivo a ser lido
 * @return int 
 */
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

/**
 * @brief Percorre um arquivo contendo informações de pontos,
 *  convertendo seu conteúdo em uma lista encadeada de ponteiros para struct Ponto
 * 
 * @param input Arquivo a ser lido
 * @return List*
 */
List* fileToPoint(FILE* input){
	rewind(input); // just in case

    int m = countPointDimension(input);

	List *points = createList();

	char *line = NULL;
	while (!feof(input)){
		line = readNewLine(input);
		if(feof(input)){ // Chegou no final do arquivo
			break;
		}
		char *id;
		double *mValues = malloc(sizeof(double) * m);

		id = strtok(line, ",");
		for (int i = 0; i < m; i++){
			mValues[i] = atof(strtok(NULL, ","));
		}
		Point *newPoint = createPoint(id, m, mValues);

		pushToList(points, newPoint);

		free(line);
	}
	free(line);
	
	return points;
}