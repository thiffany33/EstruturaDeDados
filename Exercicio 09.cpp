#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void troca (int *vetor, int i, int j)
{
	int aux = vetor[j]; 
	vetor[j] = vetor[i];
	vetor[i] = aux;
}


void Ordena1 (int *vetor, int tamanho)
{
 	int i, j; 
 	
	for (i = 0; i < tamanho; i++)
	{
	 	for(j = 0; j < tamanho; j++) 
	 	{
		 	if (vetor[j] > vetor[j+1])
		 	{
		 		troca(vetor, j, j+1);
			}
		}
	}
}
 
// Selection Sort 
void Ordena2 (int *vetor, int tamanho)
{
	int i, j; 
	for (i = 0; i < tamanho; i++)
	{
		int menor = i;
		for (j = menor+1; j < tamanho; j++)
		{
			if(vetor[j] < vetor[menor])
			{
				menor = j;
			}
		}
		troca(vetor, i, menor);
	}
}

void Ordena3 (int *vetor, int tamanho)
{
	int i; 
	
	for (i = 1; i < tamanho; i++)
	{
		int chave = vetor[i];
		int j = i - 1; 
		
		while ((j >= 0) && (chave < vetor[j]))
		{
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = chave;
	}
}

void Imprimir (int *A, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
	{
    	printf("%d, ", A[i]);
	}
	
 	printf("\n");
}

// Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.
int Verifica_Ordenacao (int *A, int tamanho)
{
	int i;
	
	for (i = 0; i < tamanho-1; i++)
	{
     	if (A[i] > A[i+1])
		{
       	    return 0;
        }
	}
	return 1;
}


int main ()
{
 	clock_t start, end;
	double elapsed_time;
	srand(time(NULL));
	
	int i;
	
	int tamanho = 50;
	
	int *v1 = (int *)malloc(tamanho * sizeof(int));
	int *v2 = (int *)malloc(tamanho * sizeof(int));
	int *v3 = (int *)malloc(tamanho * sizeof(int));

	for (i = 0; i < tamanho; i++)
	{
	 	v1[i] = rand() % (tamanho+1);
     	v2[i] = rand() % (tamanho+1);
     	v3[i] = rand() % (tamanho+1);
	}

    start = clock();
    Imprimir(v1, tamanho);
    Ordena1 (v1, tamanho);
    Imprimir(v1, tamanho);
    
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (ordenação 1): %.2f\n", elapsed_time);
   
    if (!Verifica_Ordenacao(v1, tamanho))
	{
		printf("Erro: a ordenação 1 não está correta!\n");
    }

    start = clock();
    Imprimir(v2, tamanho);
    Ordena2 (v2, tamanho);
    Imprimir(v2, tamanho);
    
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (ordenação 2): %.2f\n", elapsed_time);
    
    if (!Verifica_Ordenacao(v2, tamanho))
	{
		printf("Erro: a ordenação 2 não está correta!\n");
    }

    start = clock();
    Imprimir(v3, tamanho);
    Ordena3 (v3, tamanho);
    Imprimir(v3, tamanho);
    
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (ordenação 3): %.2f\n", elapsed_time);
    
    if (!Verifica_Ordenacao(v3, tamanho))
	{
		printf("Erro: a ordenação 3 não está correta!\n");
    }
 
    free (v1);
    free (v2);
    free (v3);

    return 0;
}

