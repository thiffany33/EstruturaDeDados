#include "stdio.h"
#include "stdlib.h"

//tudo certo
typedef struct _fila {
	int ini;
	int fim;
	int tam;
	int *vetor;
} Fila;
	
//coisinhas colocadas na caixinha fila
Fila* criar_fila (int tamanho) {
	Fila *f = (Fila *)malloc(sizeof(Fila)); 
	f-> ini = 0; 
	f-> fim = 0; 
	f-> tam = tamanho;
	f-> vetor = (int *)malloc(tamanho * sizeof(int));
	return f;
}
	
//a gente vaio destruir de dentro para fora, fazer um free para cada um. 
void destruir_fila (Fila *fila) {
	free (fila->vetor); 
	free(fila);
}

void enqueue (Fila *fila, int elemento) {
	if (fila->fim < fila->tam) {
		fila->vetor[fila->fim] = elemento;
		(fila->fim)++;
	}
	else{
		printf("Fila Esgotada");
		exit(1);
	}
}

//Retornar o elemento que ta no inicio da fila pra ela andar.
//por isso da variável
//Mesmo que ande, o elemento ainda fica na fila 
int dequeue (Fila *fila) {
	int elemento = fila->vetor[fila->ini];
	(fila->ini++);
	return elemento;	
}

int main () {
	
	Fila *fila = criar_fila (10);
	
	int elem = 1;
	enqueue (fila, elem);
	
	elem = 2;
	enqueue (fila, elem);
	
	elem = 3;
	enqueue (fila, elem);
	
	elem = 4;
	enqueue (fila, elem);
	
	
	printf("%d\n", dequeue (fila));
	printf("%d\n", dequeue (fila));
	destruir_fila (fila);
return 0;
}
