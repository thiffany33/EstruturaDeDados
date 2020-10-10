#include "stdio.h"
#include "stdlib.h"
#include "termios.h"
#include "unistd.h"
#include "fcntl.h"
//#include "windows.h"

#define SIZE 25

typedef struct
{
  int x;
  int y;
} Point;

typedef struct deck
{
  Point p;
  struct deck *next;
  struct deck *prev;
} Deck;

Deck* createDeck ()
{
  return NULL;
}

Point getFront (Deck *d)
{
   if (d != NULL)
   {
   	    d->p;
   }
}

Point getRear (Deck *d)
{
   if (d != NULL)
   {
	    Deck *aux = d;
	    while (aux->next != NULL)
 		{
 			aux = aux -> next;
	    }
	    return aux -> p;
   }
}

Deck* insertFront (Deck *d, Point p, char field[][SIZE])
{
   Deck *novo = (Deck *)malloc(sizeof(Deck));
   novo->p = p;
   novo->next = d;
   novo->prev = NULL;   
   field[p.x][p.y] = '#';
   
   if (d != NULL)
   {
   	    d->prev = novo;	   
   }
   return novo;
}

Deck* insertRear (Deck *d, Point p, char field[][SIZE]) 
{
   Deck *novo = (Deck *)malloc(sizeof(Deck));
   novo->p = p;
   novo->next = NULL;
   field[p.x][p.y] = '*';  
   if (d != NULL)
   {
   	     Deck *aux = d;
   		 while (aux->next != NULL)
   		{
             aux = aux->next;
        }
		 aux->next = novo;
         novo->prev = aux;
		 return d;
   }
   else
   {
   	    novo->prev = NULL;	   
   		return novo; 	   
   }
}

Deck* deleteFront (Deck *d, char field[][SIZE])
{
	if (d != NULL)
	{	
 		 Deck *proximo = d->next;	   
      	 field[d->p.x][d->p.y] = ' ';
      	 free (d);
      	 proximo->prev = NULL;
      	 return proximo;
    }
   else
   {
         return NULL;
   }   
}

Deck* deleteRear (Deck *d, char field[][SIZE])
{
	if (d != NULL)
	{	
         Deck *aux = d;
         while (aux->next != NULL)
		 {
	      	    aux = aux->next;      
         }      
         aux->prev->next = NULL;
         field[aux->p.x][aux->p.y] = ' '; 
         free(aux);
         return d;
   }
   else
   {
      return NULL;
   }
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}

void initialize_field (char field[SIZE][SIZE])
{
   int i, j;
   
   for (i = 0; i < SIZE; i++)
   {
        for (j = 0; j < SIZE; j++)
		{
  		 	field[i][j] = ' ';
        } 
   }
}

void print_field (char field[SIZE][SIZE])
{
   int i, j;
   printf("  ");
   
   for (i = 0; i < SIZE; i++)
   {
   	    printf(" #");
   }
   printf("\n");
   
   for (i = 0; i < SIZE; i++)
   {
   	    printf(" # ");
        for (j = 0; j < SIZE; j++)
		{
  		 	printf("%c ", field[i][j]);
        } 
        printf("#\n");
   }
   printf("  ");
   for (i = 0; i < SIZE; i++)
   {
   	    printf(" #");
   }
   printf("\n");
}

int finish (Deck *d)
{
   Point p1 = getFront (d);
   Point p2 = getRear (d);
   
   if (p1.x < 1 || p1.x > SIZE-2 || p1.y < 1 || p1.y > SIZE-1)
   {
   	    return 1;
   }
      
   else if (p2.x < 1 || p2.x > SIZE-2 || p2.y < 1 || p2.y > SIZE-1)
   {
   	    return 1;
   }  
   else
   {
   	    return 0;
   }   
}

int main ()
{

   char field[SIZE][SIZE];
   initialize_field (field); 
   int center = SIZE/2;
   int snake_size = 5;
   Deck *d = createDeck ();


   int i;
   for (i = center-snake_size/2; i <= center+snake_size/2; i++)
   {
   	    d = insertFront (d, (Point){center, i}, field);
   }

   char pressionou_prv = ' ';
   char pressionou_act = 'l';
   int reverse = 0; 
   
   while (!finish(d)) {
   		 while((!kbhit()) && (!finish(d)))
		 {
	       if (reverse) {
	           Point p = getFront (d);
	           if (pressionou_act ==  'u') { d = insertFront (d, (Point){p.x-1, p.y}, field); }
	           else if (pressionou_act ==  'd') { d = insertFront (d, (Point){p.x+1, p.y}, field); }
	           else if (pressionou_act ==  'l') { d = insertFront (d, (Point){p.x, p.y-1}, field); }
	           else { d = insertFront (d, (Point){p.x, p.y+1}, field); }
	           d = deleteRear (d, field);
	        }
	        else {
	           Point p = getRear (d);
	           if (pressionou_act ==  'u') { d = insertRear (d, (Point){p.x-1, p.y}, field); }
	           else if (pressionou_act ==  'd') { d = insertRear (d, (Point){p.x+1, p.y}, field); }
	           else if (pressionou_act ==  'l') { d = insertRear (d, (Point){p.x, p.y-1}, field); }
	           else { d = insertRear (d, (Point){p.x, p.y+1}, field); }
	           d = deleteFront (d, field);
	        }  
	        print_field (field);
	        usleep(250000); //Velocidade, só diminuir o número que aumenta a velocidade.
	        system("clear");
        }
     if (!finish(d))
	 {
        /*Cada vez que uma tecla é pressionada o controle executa esse trecho: */
        pressionou_prv = pressionou_act;
        pressionou_act = getchar();
        if ((pressionou_act ==  'd') && (pressionou_prv ==  'u')) { reverse = !reverse; }
        else if ((pressionou_act ==  'u') && (pressionou_prv ==  'd')) { reverse = !reverse; }
        else if ((pressionou_act ==  'l') && (pressionou_prv ==  'r')) { reverse = !reverse; }
        else if ((pressionou_act ==  'r') && (pressionou_prv ==  'l')) { reverse = !reverse; }
     }
   }
   printf ("VOCÊ PERDEU TURURURURURUR");
   return 0;
}
