#include "stdio.h"
int main ()
{	
	Stack *pilha = Create_Stack();
	
	while (v > 0)
	{
		push (pilha, v % 2);
		v = v / 2;
	}
		while (!is_empty(pilha))
	{
		printf ("%d", pop(pilha));
	}
	printf("\n");
}

