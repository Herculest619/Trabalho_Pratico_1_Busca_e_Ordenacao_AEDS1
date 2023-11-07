#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "funcoes.h"

int main(int argc, char *argv[])
{
    int tam = 30228;//numero de linhas do txt, e tbm o tamanho do vetor
    enem *escolas = (enem*)malloc(tam*sizeof(enem));//inicialização do vetor de structs

    clock_t t;
    t = clock();

    introduir_dados(escolas);//lendo o txt de dados do enem
    argumentos(argc, argv, escolas);//reconhecendo os argumentos e inicializando as funções correspondentes

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nO programa executou em %lf segundos!\n\n", time_taken);

    return 0;
}
