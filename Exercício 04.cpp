#include "stdio.h"
#include "stdlib.h"

typedef struct _Stack {
   int top;
   int size;
   int *vector;
} Stack;

int empty (Stack *p) {
   return (p->top == 0);
}

int full (Stack *p) {
   return (p->top == p->size);
}

Stack* create_stack (int size) {
   Stack *p = (Stack *)malloc(sizeof(Stack));
   p->top = 0;
   p->size = size;
   p->vector = (int *)malloc(size * sizeof(int));
   return p;
}

void push (Stack *p, int elem) {
   if (full(p)) {
      printf("pilha cheia: capacidade esgotada\n");
      exit(1); /*aborta programa*/
   }
   p->vector[p->top] = elem; /*insere elemento*/
   p->top++; /*incrementa o topo*/
}

int pop (Stack *p) {
   if (empty(p)) {
      printf("pilha vazia!\n");
      exit(1); /*aborta programa*/
   }
   p->top--; /*decrementa o ndice do topo.*/
   return p->vector[p->top]; /*retorna o ele. do topo*/
}

void free_stack (Stack *p) {
   free(p->vector);
   free(p);
}

int main () 
{
	
	char *seq = "[ [ ( ) ] [ ] ]";
	int i = 0; 
	Stack *pilha = create_stack(100);
	
	while (seq[i] != '\0')
	{
		if ( (seq[i] == '(' ) || (seq[i] == '[' ) )
		{
			push(pilha, seq[i]);
		} 
		
		else if (seq[i] == ')' )
		{
			if ( empty(pilha) || pop(pilha) != '(' )
			{
				printf("Pilha Inválida \n");
				exit (1);
			}
		}
		
		else if (seq[i] == ')' )
		{
			if ( empty(pilha) || pop(pilha) != '(' )
			{
				printf("Pilha Inválida \n");
				exit (1);
			}
		}
		i++;
	}
	if (empty(pilha))
	{
		printf ("Bem formada \n");
	}else
	{
		printf("Mal formada \n");
	}
}

