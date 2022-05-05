#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhas.h"

int main(){
	Pilha_vet * pilhas;
	int tam, i=0, j=0;
	char * entrada, * saida;
	
	pilhas = pilha_vet_cria();
	scanf(" %d", &tam);
	if(tam > N-1){
		printf("Tamanho incopativel");
		return 1;
	}
	tam++;
	entrada = (char *)malloc(tam * sizeof(char));
	saida = (char *)malloc(tam * sizeof(char));
	do{
	
	getchar();
	fgets(entrada, tam, stdin);
		for(int c=0;c<tam-1;c++){
			for(int d=0;d<tam-1;d++){
			if(c!=d && entrada[c] == entrada[d]){
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
	while((i < (tam-1)) && j <(tam-1) && (pilhas->n <= tam)){
		
		printf("I ");
		pilha_vet_push(pilhas, entrada[pilhas->n+i]);
		j++;
		//printf("\n%c %c\n", saida[i], pilhas->vet[pilhas->n-1]);
		while(saida[i] == pilhas->vet[pilhas->n-1] && i <(tam-1)){
			printf("R ");
			pilha_vet_pop(pilhas);
			i++;
			//printf("\n%d %d\n", i, tam-2);
			//printf("\n%d\n", (i < tam-2));
		}
		//printf("\n%d\n", pilhas->n);
		
	}
	if(pilhas->n!= 0){
		printf("impossible");
	}
	printf("\n");
	while(pilhas->n!=0) pilha_vet_pop(pilhas);
	
	scanf(" %d", &tam);
	tam++;
	entrada = (char *)realloc(entrada, tam * sizeof(char));
	saida = (char *)realloc(saida, tam * sizeof(char));
	j = 0;
	i = 0;
	}while(tam != 1);
	
	pilha_vet_libera(pilhas);
	free(entrada);
	free(saida);
	return 0;

}
