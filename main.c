#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include <ctype.h>

#define SUCESSO 0
#define NUM 100

// FUNCAO COMPARA LISTAS ENCADEADAS
int listaCompara(Lista * lista, Lista * lista_){
    while(lista != NULL && lista_ != NULL){
        if(lista->info != lista_->info){
            return 0;
        }
        lista = lista->prox;
        lista_ = lista_->prox;
    }
    if((lista == NULL && lista_ != NULL) || (lista != NULL && lista_ == NULL)){
        return 0;
    }
        else return 1;
}

Lista *josephus(Lista * l){
        int info;

        while(l->info != (l->prox)->info){

                for(int i=1;i<3;i++) l = l->prox;
                info = l->info;
                l = l->prox;
                l = lst_retira(l, info);
        }

        return l;

}


void ex2(){
    Lista * lista1;
    Lista * lista_2;
    int i = 1, num, con = 1;
    char yn = ' ';

    lista1 = lst_cria();
    lista_2 = lst_cria();

    printf("Lista 1:\n");
    while(con==1){
        printf("Digite o elemento %i da lista: ", i);
        scanf("%i", &num);
        getchar();
        lista1 = lst_insere(lista1, num);
        printf("Deseja digitar mais numeros?");
        yn = ' ';
        while(yn != 'y' && yn != 'n'){
            fflush(stdin);
            printf("[Y/n]: ");
            scanf("%c", &yn);
            yn = tolower(yn);
        }
        i++;
        printf("%c", yn);
        if(yn == 'n'){
            con = 0;
        }
    }
    con = 1;
    i = 1;
    printf("Lista 2:\n");
    while(con){
        printf("Digite o elemento %i da lista: ", i);
        scanf("%i", &num);
        getchar();
        lista_2 = lst_insere(lista_2, num);
        printf("Deseja digitar mais numeros? ");
	yn = ' '; 
       while(yn != 'y' && yn != 'n'){
            fflush(stdin);
            printf("[Y/n]:");
            scanf("%c", &yn);
            yn = tolower(yn);
        }
	i++;
        if(yn == 'n') con = 0;
    }

    if(listaCompara(lista1, lista_2) == 1){
        printf("As listas sao iguais\n");
    }
    else printf("As listas sao difentes\n");


}

void ex3(){
	Lista * lista;
	lista = lst_cria();
	Lista * joe;

	for(int i=1;i<=41;i++){
		lista = lst_insere_ordenado(lista, i);
	}

	lcirc_transforma(lista);

	joe = josephus(lista);
	printf("\nO soldado na posicao  %d sobrevive\n", joe->info);

}

int main(int argc, char ** argv){
	
	ex2();
	ex3();

	return SUCESSO;
}
