#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct enem_
{
    int id;
    char estado[3];
    char municipio[33];
    char rede[8];
    float media_ciencias_natureza;
    float media_ciencias_humanas;
    float media_linguagem;
    float media_matematica;
    float media_redacao;
} enem;

void imprime_dados_txt();//imprime o arquivo txt direto
void introduir_dados(enem escolas[]);//fuuncao que inicia o processo de salvar na struct
void introduir_dados_struct(enem escolas[], int cont_escola, int cont_topico, char *ponto_e_virgula);//funcao que esta dentro do while, usada pra efetivamente salvar
void imprime_dado(enem escolas[], int x, int tam);//imprime uma struct, pode ser um elemento ou o vetor completo
int busca_sequencial(enem escolas[], int chave);
int busca_binaria(enem escolas[], int chave);
void insertion_sort(enem escolas[]);
void quick_sort(enem escolas[], int low, int high);
int partition (enem escolas[], int low, int high);
void heap_sort(enem escolas[], int n);
void heapify(enem escolas[], int n, int i);
void swap(enem *a, enem *b);
void ler_indices_txt(enem escolas[], char *argv[], int argc);//usada para ler o arquivo passado por argumrnto
void argumentos(int argc, char *argv[], enem escolas[]);//função que reconhece os comandos passados por parametros

#endif // FUNCOES_H_INCLUDED
