#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/point.h"
#include "../include/fileHandler.h"
#include "../include/linkedlist.h"
#include "../include/kruskal.h"

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
	List *points = fileToPoint(input);
	int N = points->length;

	if(output == NULL){
		fprintf(stderr, "Erro ao criar %s\n", argv[1]);
		exit(1);
	}

	int distVectorSize = calcDistN(points->length);
	
	distCell *dists = distanceVector(points);

	sortDists(dists, distVectorSize);

	kruskalK(dists, distVectorSize, k);
	
	printDistanceVector(dists, N);

	free(dists);

	deleteList(points);

	fclose(input);
	fclose(output);
	return (0);
}