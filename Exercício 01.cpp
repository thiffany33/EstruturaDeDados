#include "stdio.h"
#include "stdlib.h"

//Função para enfileirar um dado elemento em um vetor:
void enqueue (int vetor[], int elemento, int *fim, int tamanho) {
	if (*fim<tamanho) {
		vetor[*fim]=elemento;
		(*fim)++;
	}else {
		printf("Fila esgotada");
	}
}	
//Função para desenfileirar um dado elemento em um vetor:
int dequeue (int vetor[], int *ini, int tamanho) {
	int elemento = vetor[*ini];
	(*ini)++;
	return elemento;
}
int main () {
	
	int elem;
	int ini = 0;
	int fim = 0;
	int fila_tamanho = 10;
	
	int *fila = (int *)malloc(fila_tamanho * sizeof(int));
	
	elem = 1; 
    enqueue (fila, elem, &fim, fila_tamanho);
    
	elem = 2;
	enqueue (fila, elem, &fim, fila_tamanho);
	
	elem = 3;
	enqueue (fila, elem, &fim, fila_tamanho);
	
	elem = 4;
	enqueue (fila, elem, &fim, fila_tamanho);
	
	printf("%d\n", dequeue (fila, &ini, fila_tamanho));
	
	printf("%d\n", dequeue (fila, &ini, fila_tamanho));
    printf("%d\n", dequeue (fila, &ini, fila_tamanho));
    printf("%d\n", dequeue (fila, &ini, fila_tamanho));
    
	free(fila);
	
	return 0;
}
