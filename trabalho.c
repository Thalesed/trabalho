#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"
#include <string.h>
//Deixar o programa se repetir ate o usuario dizer o contrario
//Nao permitir que o usuario insira uma palavra menor que o esperado

int main(){
Pilha_vet* pilha_entrada, *pilha_intermediaria, *pilha_saida;
    int tam, index = 0, var = 0, bol = 0;
    char *entrada, *saida;

    do{
        pilha_entrada = pilha_vet_cria();
        pilha_intermediaria = pilha_vet_cria();
        scanf(" %d", &tam);
        tam++;

        //A string terá um /0 no final
        //Pega os caracteres de entrada
        entrada = (char *)malloc(tam * sizeof(char));
        getchar();
        fgets(entrada,tam,stdin);

        //Pega os caracteres de saida
        saida = (char *)malloc(tam * sizeof(char));
        getchar();
        fgets(saida, tam, stdin);

        //Coloca os caracteres de entrada na pilha de entrada e saida
        for(index = tam-2;index >= 0; index--){
            pilha_vet_push(pilha_entrada, entrada[index]);
        }



        index = 0;

        //Enquanto ainda há vagões na esquerda, ele faz o processo:
        while(pilha_entrada->n > 0){
            //Insere o vagão na linha do meio
            printf("I ");
            var++;
            pilha_vet_push(pilha_intermediaria, pilha_vet_pop(pilha_entrada));
            //Confere se o vagão inserido é o desejado na linha da direita
            while((pilha_intermediaria->vet[pilha_intermediaria->n-1] == saida[index]) && pilha_intermediaria->n != 0){
                printf("R ");
                var++;
                if(var == ((tam-1) * 2)){
                    bol =1;
                }

                //Move o vagão do meio para a direita
                pilha_vet_push(pilha_saida, pilha_vet_pop(pilha_intermediaria));
                index++;
            }
        }
        if(!bol){
            printf("Impossible\n");
        }
        free(entrada);
        free(saida);
        free(pilha_entrada);
        free(pilha_intermediaria);
        free(pilha_saida);
    }while(tam != 0);
return 0;
}
