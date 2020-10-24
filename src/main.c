#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/point.h"
#include "../include/fileHandler.h"
#include "../include/linkedlist.h"
#include "../include/kruskal.h"
#include "../include/grouping.h"

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
	if(output == NULL){
		fprintf(stderr, "Erro ao criar %s\n", argv[1]);
		exit(1);
	}

	List *points = fileToPoint(input);

	int N = listLength(points);
	int distVectorSize = calcDistN(N);
	
	distCell *dists = distanceVector(points);

	sortDists(dists, distVectorSize);

	kruskalK(dists, distVectorSize, N, k);
	
	free(dists);

	Point **pointsVector = linkedListToVector(points);

	groupAndPrint(pointsVector, N, k, output);

	deletePointVector(pointsVector, N);

	fclose(input);
	fclose(output);
	return (0);
}