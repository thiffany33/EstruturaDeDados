#include "stdio.h"
#include "stdlib.h"

typedef struct node {
   int info;
   struct node* next;
} Lista;

Lista* criar (void) {
   return NULL;
}

Lista* inserir (Lista *lista, int elem) {
   Lista *novo =(Lista*)malloc(sizeof(Lista));
   novo->info = elem;
   novo->next = lista;
   return novo;
}

void imprimir (Lista *lista) {
   Lista *v; /*var. para percorrer a lista*/
   for (v = lista; v != NULL; v = v->next) {
      printf("Valor: %d\n", v->info);
   }
}

Lista *remover (Lista *l, int elem) {
   Lista *prev = NULL, *aux = l;
   while ( (aux != NULL) && (aux->info != elem) ) {
      prev = aux;
      aux = aux->next;
   }
   if (aux == NULL) {
      return l;
   }
   else if (prev == NULL) {
      l = l->next;
   }
   else {
      prev->next = aux->next;
   }
   free (aux);
   return l;
}

void liberar (Lista *l) {
  Lista *aux;
  while (l != NULL) {
    aux = l->next;
    free(l);
    l = aux;
  }
}
int main () {
	Lista *lista;
	lista = criar ();
	lista = inserir (lista, 45);
	lista = inserir (lista, 23);
	return 0;
}

/*int main () {
   Lista *lista;
   lista = criar ();
   lista = inserir (lista, 1);
   lista = inserir (lista, 2);
   lista = inserir (lista, 4);
   printf("Lista:\n");
   imprimir (lista);
   lista = remover (lista, 2);
   printf("Lista:\n");
   imprimir (lista);
   liberar (lista);
   return 0;
}*/

