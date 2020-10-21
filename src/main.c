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
	clock_t *time = malloc(sizeof(clock_t)*6);
	double *timeConverted = malloc(sizeof(double)*6);
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

	/* Tempo calculado para leitura de dados. */
	time[0] = clock(); 
	List *points = fileToPoint(input);
	time[0] = clock() - time[0];

	int N = listLength(points);
	int distVectorSize = calcDistN(N);
	
	/* Tempo calculado para cálculo das distâncias. */
	time[1] = clock();
	distCell *dists = distanceVector(points);
	time[1] = clock() - time[1];

	/* Tempo calculado para ordenação das distâncias. */
	time[2] = clock();
	sortDists(dists, distVectorSize);
	time[2] = clock() - time[2];

	/* Tempo calculado para obtenção da MST. */
	time[3] = clock();
	kruskalK(dists, distVectorSize, N, k);
	time[3] = clock() - time[3];
	
	// printDistanceVector(dists, N);

	free(dists);

	Point **pointsVector = linkedListToVector(points);

	/* Tempos para agrupamento e escrita (dentro da função). */	
	groupAndPrint(pointsVector, N, k, output, &time[5]);


	/* Conversão de clock_t para double */
	for (int i = 0; i < 6; i++) {
		timeConverted[i] = (double) time[i]/CLOCKS_PER_SEC;
	}

	printf("Tempo de leitura: \t\t\t%.6f\n", timeConverted[0]);
	printf("Tempo de calculo de distancias:\t\t%.6f\n", timeConverted[1]);
	printf("Tempo de ordenação das distancias: \t%.6f\n", timeConverted[2]);
	printf("Tempo de obtenção da MST: \t\t%.6f\n", timeConverted[3]);
	// printf("Tempo de leitura: %.6f\n", timeConverted[4]);
	printf("Tempo de escrita: \t\t\t%.6f\n", timeConverted[5]);

	deletePointVector(pointsVector, N);

	fclose(input);
	fclose(output);
	return (0);
}