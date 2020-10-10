#include "stdio.h"
#include "stdlib.h" //usar essa biblioteca para gerar valores aleatórios.

#define TAM 8
int main () {
	
	char vetA[TAM][TAM], vetB[TAM][TAM];
	int linha, coluna, direcao, flag, i; 
	
	for (linha=0;linha<TAM;linha++){
		for(coluna=0;coluna<TAM;coluna++){
			vetA[linha][coluna]='A'; //essa vai ser nossa água.
			vetB[linha][coluna]=' '; //essa vai ser nossa água.
		}
	}
	
	for(i=0;i<3;i++){
		do{
			flag = 1;
		
			linha = rand() % (TAM - 1);  //aleatório para escolher onde vai estar as coisas que vai botar fogo na linha
			coluna = rand() % (TAM - 1); //aleatório para escolher onde vai estar as coisas que vai botar fogo na coluna
			direcao = rand() % 3; //aleatório para escolher a direcao que vai bota fogo.
			
			//submarino tamanho 2
			//0 = cima
			if(direcao == 0){ 
				if((linha - 1) >= 0){// 0 pq não existe indice negativo na matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha-1][coluna] == 'A'){
						vetA[linha][coluna] = 'S';
						vetA[linha-1][coluna] = 'S';
						flag = 0;
					}
				}
			}
				
			//1 = baixo
			if(direcao == 1){
				if((linha + 1) < TAM){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha+1][coluna] == 'A'){
						vetA[linha][coluna] = 'S';
						vetA[linha+1][coluna] = 'S';
						flag = 0;
					}
				}
			}
			//2 = esquerda
			if(direcao == 2){
				if((coluna - 1) >= 0){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha][coluna-1] == 'A'){
						vetA[linha][coluna] = 'S';
						vetA[linha][coluna-1] = 'S';
						flag = 0;
					}
				}
			}
			//3 = direita
			if(direcao == 3){
				if((coluna + 1) < TAM){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha][coluna+1] == 'A'){
						vetA[linha][coluna] = 'S';
						vetA[linha][coluna+1] = 'S';
						flag = 0;
					}
				}
			}
			
		
		}while(flag != 0);
	}
	
	
	for(i=0;i<2;i++){
		do{
			flag = 1;
		
			linha = rand() % (TAM - 1);  //aleatório para escolher onde vai estar as coisas que vai botar fogo na linha
			coluna = rand() % (TAM - 1); //aleatório para escolher onde vai estar as coisas que vai botar fogo na coluna
			direcao = rand() % 3; //aleatório para escolher a direcao que vai bota fogo.
			
			//CARAVELA tamanho 4
			//0 = cima
			if(direcao == 0){ 
				if((linha - 3) >= 0){// 0 pq não existe indice negativo na matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha-1][coluna] == 'A' && vetA[linha-2][coluna] == 'A' && vetA[linha-3][coluna] == 'A'){
						vetA[linha][coluna] = 'C';
						vetA[linha-1][coluna] = 'C';
						vetA[linha-2][coluna] = 'C';
						vetA[linha-3][coluna] = 'C';
						flag = 0;
					}
				}
			}
				
			//1 = baixo
			if(direcao == 1){
				if((linha + 3) < TAM){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha+1][coluna] == 'A' && vetA[linha+2][coluna] == 'A' && vetA[linha+3][coluna] == 'A'){
						vetA[linha][coluna] = 'P';
						vetA[linha+1][coluna] = 'P';
						vetA[linha+2][coluna] = 'P';
						vetA[linha+3][coluna] = 'P';
						vetA[linha+4][coluna] = 'P';
						flag = 0;
					}
				}
			}
			//2 = esquerda
			if(direcao == 2){
				if((coluna - 3) >= 0){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha][coluna-1] == 'A' && vetA[linha][coluna-2] == 'A' && vetA[linha][coluna-3] == 'A'){
						vetA[linha][coluna] = 'C';
						vetA[linha][coluna-1] = 'C';
						vetA[linha][coluna-2] = 'C';
						vetA[linha][coluna-3] = 'C';
						flag = 0;
					}
				}
			}
			//3 = direita
			if(direcao == 3){
				if((coluna + 3) < TAM){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha][coluna+1] == 'A' && vetA[linha][coluna+2] == 'A' && vetA[linha][coluna+3] == 'A'){
						vetA[linha][coluna] = 'C';
						vetA[linha][coluna+1] = 'C';
						vetA[linha][coluna+2] = 'C';
						vetA[linha][coluna+3] = 'C';
						flag = 0;
					}
				}
			}
			
		
		}while(flag != 0);
	}
	
	
	for(i=0;i<1;i++){
		do{
			flag = 1;
		
			linha = rand() % (TAM - 1);  //aleatório para escolher onde vai estar as coisas que vai botar fogo na linha
			coluna = rand() % (TAM - 1); //aleatório para escolher onde vai estar as coisas que vai botar fogo na coluna
			direcao = rand() % 3; //aleatório para escolher a direcao que vai bota fogo.
			
			//PORTA AVIOES tamanho 5
			//0 = cima
			if(direcao == 0){ 
				if((linha - 4) >= 0){// 0 pq não existe indice negativo na matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha-1][coluna] == 'A' && vetA[linha-2][coluna] == 'A' && vetA[linha-3][coluna] == 'A' && vetA[linha-4][coluna] == 'A'){
						vetA[linha][coluna] = 'P';
						vetA[linha-1][coluna] = 'P';
						vetA[linha-2][coluna] = 'P';
						vetA[linha-3][coluna] = 'P';
						vetA[linha-4][coluna] = 'P';
						flag = 0;
					}
				}
			}
				
			//1 = baixo
			if(direcao == 1){
				if((linha + 4) < TAM){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha+1][coluna] == 'A' && vetA[linha+2][coluna] == 'A' && vetA[linha+3][coluna] == 'A' && vetA[linha+4][coluna] == 'A'){
						vetA[linha][coluna] = 'P';
						vetA[linha+1][coluna] = 'P';
						vetA[linha+2][coluna] = 'P';
						vetA[linha+3][coluna] = 'P';
						vetA[linha+4][coluna] = 'P';
						flag = 0;
					}
				}
			}
			//2 = esquerda
			if(direcao == 2){
				if((coluna - 4) >= 0){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha][coluna-1] == 'A' && vetA[linha][coluna-2] == 'A' && vetA[linha][coluna-3] == 'A' && vetA[linha][coluna-4] == 'A'){
						vetA[linha][coluna] = 'P';
						vetA[linha][coluna-1] = 'P';
						vetA[linha][coluna-2] = 'P';
						vetA[linha][coluna-3] = 'P';
						vetA[linha][coluna-4] = 'P';
						flag = 0;
					}
				}
			}
			//3 = direita
			if(direcao == 3){
				if((coluna + 4) < TAM){ // 3 pq é o tamanho da matriz
					if(vetA[linha][coluna] == 'A' && vetA[linha][coluna+1] == 'A' && vetA[linha][coluna+2] == 'A' && vetA[linha][coluna+3] == 'A' && vetA[linha][coluna+4] == 'A'){
						vetA[linha][coluna] = 'P';
						vetA[linha][coluna+1] = 'P';
						vetA[linha][coluna+2] = 'P';
						vetA[linha][coluna+3] = 'P';
						vetA[linha][coluna+4] = 'P';
						flag = 0;
					}
				}
			}
			
		
		}while(flag != 0);
	}
	/*
	for(linha = 0; linha < TAM; linha++){
		for(coluna = 0; coluna < TAM; coluna++){
			printf("%c\t", vetA[linha][coluna]);
		}
		printf("\n");
		
	}*/
	
	do{
		
	flag = 1;
	
	printf("Digite a linha: ");
	scanf("%d", &linha);
	printf("Digite a coluna: ");
	scanf("%d", &coluna);
	
	vetB[linha][coluna]=vetA[linha][coluna]; //essa vai preencher a matriz jogavel
	vetA[linha][coluna]='A';
	 
	for(linha = 0; linha < TAM; linha++){
		for(coluna = 0; coluna < TAM; coluna++){
			printf("%c\t", vetB[linha][coluna]);
		}
		printf("\n");	
	}
	
	for(linha = 0; linha < TAM; linha++)
		for(coluna = 0; coluna < TAM; coluna++)
			if(vetA[linha][coluna]!='A'){
				flag = 0;
				break;
			}
				
	}while(flag==0);
}
