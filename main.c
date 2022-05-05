#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhas.h"

/*
PROVA1 AEDS
203
INTEGRANTES:
@Leonardo Prado
@Thales Eduardo
*/

int main(){
	Pilha_vet * pilhas;
	int tam, i=0, j=0;// tamanho da palavra, i conta palavras removidas, j conta palavras inseridas
	char * entrada, * saida; // palavra entrada, palavras saida desejada
	
	scanf(" %d", &tam);
	// encerra o programa
	if(tam == 0) return 0;
	if(tam > N-1){ // se o tam eh maior que 26 existe repeticao de letras
		printf("Tamanho incopativel");
		return 1;
	}
	pilhas = pilha_vet_cria();
	tam++; // tam + '\0'
	entrada = (char *)malloc(tam * sizeof(char));
	saida = (char *)malloc(tam * sizeof(char));
	while(1){
	
	getchar();
	fgets(entrada, tam, stdin);
		for(int c=0;c<tam-1;c++){
			for(int d=0;d<tam-1;d++){
			if(c!=d && entrada[c] == entrada[d]){ // duas letras iguais
				printf("Repetcao de letras");
				return 2;
			}
		}
	}
	getchar();
	fgets(saida, tam, stdin);

	for(int c=0;c<tam-1;c++){
		for(int d=0;d<tam-1;d++){
			if(c!=d && saida[c] == saida[d]){
				printf("Repetcao de letras");
				return 2;
			}
		}
	}
	getchar();
	// enquanto forem inseridas menos letras do que o tam
	while((i < (tam-1)) && j <(tam-1) && (pilhas->n <= tam)){
		
		printf("I ");
		pilha_vet_push(pilhas, entrada[pilhas->n+i]); // insere a letra de entrada
		j++; 
		// enquanto a letra a ser comparada eh igual ao valor no topo da pilha
		while(saida[i] == pilhas->vet[pilhas->n-1] && i <(tam-1)){
			printf("R ");
			pilha_vet_pop(pilhas); // retira o valor no topo da pilha
			i++;
		}
		
	}
	// ainda resta letras na pilha nao retiradas
	if(pilhas->n!= 0){
		printf("impossible"); // impossivel formar a palavra
	}
	printf("\n");
	while(pilhas->n!=0) pilha_vet_pop(pilhas); // esvazia a pilha
	
	scanf(" %d", &tam);
	
	//encerra o programa
	if(tam == 0){
		
		pilha_vet_libera(pilhas);
		free(entrada);
		free(saida);
		 return 0; 
	}
	tam++;
	entrada = (char *)realloc(entrada, tam * sizeof(char));
	saida = (char *)realloc(saida, tam * sizeof(char));
	j = 0; // reinicia j e i
	i = 0;
	} // enquanto tam inserido for != 0
	
	// libera os ponteiros
	pilha_vet_libera(pilhas);
	free(entrada);
	free(saida);
	return 0;

}
