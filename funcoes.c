#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "funcoes.h"

void argumentos(int argc, char *argv[], enem escolas[])
{
    int tam = 30228;

    if(argc == 1)
    {
        printf("\nNao foram passados argumentos\n");
    }
    if(argc >= 2)
    {
        if(strcmp(argv[1], "bs") == 0)
        {
            if(strcmp(argv[2], "-b") == 0)
            {
                FILE *arquivo = fopen(argv[3], "r");
                char aux[10];
                while(fgets(aux,10,arquivo) != NULL)
                {
                    int num = busca_sequencial(escolas, atoi(aux));
                    if(num != -1)
                    {
                        if(argc > 4)
                        {
                            if(strcmp(argv[4], "-p") == 0)
                            {
                                imprime_dado(escolas, num, num);
                            }
                        }
                    }
                }
                fclose(arquivo);
            }
            else
            {
                int num = busca_sequencial(escolas, atoi(argv[2]));
                if(num != -1)
                {
                    if(argc > 3)
                    {
                        if(strcmp(argv[3], "-p") == 0)
                        {
                            imprime_dado(escolas, num, num);
                        }
                    }
                }else{
                    printf("\nID nao encontrado!\n");
                }
            }

        }
        else if(strcmp(argv[1], "bb") == 0)
        {
            if(strcmp(argv[2], "-s") == 0)
            {
                if(strcmp(argv[3], "is") == 0)
                {
                    insertion_sort(escolas);
                    if(strcmp(argv[4],"-b") == 0)
                    {
                        ler_indices_txt(escolas, argv, argc);
                    }
                    else
                    {
                        int num = busca_binaria(escolas, atoi(argv[4]));
                        if(num != -1)
                        {
                            if(argc>5)
                            {
                                if(strcmp(argv[5],"-p")==0)
                                {
                                    imprime_dado(escolas, num, num);
                                }
                            }
                        }
                    }
                }
                else if(strcmp(argv[3], "qs") == 0)
                {
                    quick_sort(escolas, 0, tam-1);
                    if(strcmp(argv[4],"-b") == 0)
                    {
                        ler_indices_txt(escolas, argv, argc);
                    }
                    else
                    {
                        int num = busca_binaria(escolas, atoi(argv[4]));
                        if(num != -1)
                        {
                            if(argc>5)
                            {
                                if(strcmp(argv[5],"-p")==0)
                                {
                                    imprime_dado(escolas, num, num);
                                }
                            }
                        }
                    }
                }
                else
                {
                    if(strcmp(argv[3],"hs") == 0)
                    {
                        heap_sort(escolas, tam);
                        if(strcmp(argv[4],"-b") == 0)
                        {
                            ler_indices_txt(escolas, argv, argc);
                        }
                        else
                        {
                            int num = busca_binaria(escolas, atoi(argv[4]));
                            if(num != -1)
                            {
                                if(argc>5)
                                {
                                    if(strcmp(argv[5],"-p")==0)
                                    {
                                        imprime_dado(escolas, num, num);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("\nComando %s nao reconhecido\n", argv[3]);
                    }
                }
            }
            else
            {
                printf("\nComando -s esperado\n");
            }
        }
        else
        {
            printf("\nComando %s nao reconhecido\n", argv[1]);
        }
    }
}

void ler_indices_txt(enem escolas[], char *argv[], int argc)
{
    FILE *arquivo = fopen(argv[5],"r");
    char aux[10];

    while(fgets(aux,10,arquivo) != NULL)
    {
        int num = busca_binaria(escolas, atoi(aux));
        if(num != -1)
        {
            if(argc > 6)
            {
                if(strcmp(argv[6], "-p") == 0)
                {
                    imprime_dado(escolas, num, num);
                }
            }
        }
    }
    fclose(arquivo);
}

void insertion_sort(enem escolas[])
{
    int i, j;
    enem chave;
    for (i = 1; i < 30228; i++)
    {
        chave = escolas[i];
        j = i - 1;
        while(j >= 0 && escolas[j].id > chave.id)
        {
            escolas[j+1] = escolas[j];
            j = j - 1;
        }
        escolas[j+1] = chave;
    }
}

void quick_sort(enem escolas[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(escolas, low, high);

        quick_sort(escolas, low, pi - 1);
        quick_sort(escolas, pi + 1, high);
    }
}

int partition (enem escolas[], int low, int high)
{
    enem pivot = escolas[high];
    enem aux;
    int i = (low - 1);
    int j;

    for (j = low; j <= high- 1; j++)
    {
        if (escolas[j].id < pivot.id)
        {
            i++;
            aux = escolas[i];
            escolas[i] = escolas[j];
            escolas[j] = aux;
        }
    }
    aux = escolas[i+1];
    escolas[i+1] = escolas[high];
    escolas[high] = aux;
    return (i + 1);
}

void swap(enem *a, enem *b)
{
    enem h = *a;
    *a = *b;
    *b = h;

}

void heap_sort(enem escolas[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(escolas, n, i);
    }
    for (i=n-1; i>=0; i--)
    {
        swap(&escolas[0], &escolas[i]);
        heapify(escolas, i, 0);
    }
}

void heapify(enem *escolas, int n, int i)
{
    int maior = i;
    int esquerdo = 2*i + 1;
    int direito = 2*i + 2;

    if(esquerdo < n && escolas[esquerdo].id > escolas[maior].id)
    {
        maior = esquerdo;
    }

    if(direito < n && escolas[direito].id > escolas[maior].id)
    {
        maior = direito;
    }

    if (maior != i)
    {
        swap(&escolas[i], &escolas[maior]);
        heapify(escolas, n, maior);
    }
}

int busca_sequencial(enem escolas[], int chave)
{
    int i = 0, aux = 0;
    for(i = 0; i < 30228; i++)
    {
        if(escolas[i].id == chave)
        {
            aux = 1;
            break;
        }
    }
    if(aux == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int busca_binaria(enem escolas[], int chave)
{
    int direito = 30227, esquerdo = 0, aux = 0;

    while (esquerdo <= direito)
    {
        int media = esquerdo + ((direito - esquerdo) / 2);

        if(escolas[media].id == chave)
        {
            aux = 1;
            return media;
            break;
        }
        else if(escolas[media].id < chave)
        {
            esquerdo = media + 1;
        }
        else
        {
            direito = media - 1;
        }
    }
    if(aux == 0)
    {
        return -1;
    }
}

void introduir_dados(enem escolas[])
{
    FILE *arquivo = fopen("dados-enem.txt","r");
    char aux[150];//usada pra salvar cada linha do txt
    char *ponto_e_virgula;//variavel que vai salvar as frases separadas por ";"
    int cont_topico, cont_escola = 0;//variaveis contadoras

    while(fgets(aux,150,arquivo) != NULL) //lendo cada linha do txt e colocando no aux
    {
        ponto_e_virgula = strtok(aux, ";");//passando aux como argumento pra strtox, e o ";" como elemento para procurar
        cont_topico = 1;
        while(ponto_e_virgula != NULL)
        {
            if(*ponto_e_virgula != '\n')
            {
                introduir_dados_struct(escolas, cont_escola, cont_topico, ponto_e_virgula);//salva efetivmente a string na sua posicao correta na struct
                cont_topico++;
                ponto_e_virgula = strtok(NULL, ";");//introduzindo o NULL pra sair desse while
            }
        }
        cont_escola++;
    }
    fclose(arquivo);
}

void introduir_dados_struct(enem escolas[], int cont_escola, int cont_topico, char *ponto_e_virgula)
{
    switch(cont_topico)
    {
    case 1:
    {
        escolas[cont_escola].id = atoi(ponto_e_virgula);
        break;
    }
    case 2:
    {
        strcpy(escolas[cont_escola].estado, ponto_e_virgula);
        break;
    }
    case 3:
    {
        strcpy(escolas[cont_escola].municipio, ponto_e_virgula);
        break;
    }
    case 4:
    {
        strcpy(escolas[cont_escola].rede, ponto_e_virgula);
        break;
    }
    case 5:
    {
        escolas[cont_escola].media_ciencias_natureza = atof(ponto_e_virgula);
        break;
    }
    case 6:
    {
        escolas[cont_escola].media_ciencias_humanas = atof(ponto_e_virgula);
        break;
    }
    case 7:
    {
        escolas[cont_escola].media_linguagem = atof(ponto_e_virgula);
        break;
    }
    case 8:
    {
        escolas[cont_escola].media_matematica = atof(ponto_e_virgula);
        break;
    }
    case 9:
    {
        escolas[cont_escola].media_redacao = atof(ponto_e_virgula);
        break;
    }
    default:
    {
        break;
    }
    }
}

void imprime_dados_txt()
{
    FILE *arquivo;
    char aux[150];
    arquivo = fopen("dados-enem.txt","r");

    while(fgets(aux,150,arquivo) != NULL)
    {
        puts(aux);
    }

    fclose(arquivo);
}

void imprime_dado(enem escolas[], int x, int tam)
{
    if((x+1) / (tam+1) != 1)
    {
        for( x; x < tam; x++)
        {
            printf("\nID: %d\n", escolas[x].id);
            printf("ESTADO: %s\n", escolas[x].estado);
            printf("MUNICIPIO: %s\n", escolas[x].municipio);
            printf("REDE: %s\n", escolas[x].rede);
            printf("MEDIA CIENCIAS DA NATUREZA: %lf\n", escolas[x].media_ciencias_natureza);
            printf("MEDIA CIENCIAS HUMANA: %lf\n", escolas[x].media_ciencias_humanas);
            printf("MEDIA LINGUAGEM: %lf\n", escolas[x].media_linguagem);
            printf("MEDIA MATEMATICA: %lf\n", escolas[x].media_matematica);
            printf("MEDIA REDACAO: %lf\n", escolas[x].media_redacao);
            printf("\n");
        }
    }
    else
    {
        printf("\nID: %d\n", escolas[x].id);
        printf("ESTADO: %s\n", escolas[x].estado);
        printf("MUNICIPIO: %s\n", escolas[x].municipio);
        printf("REDE: %s\n", escolas[x].rede);
        printf("MEDIA CIENCIAS DA NATUREZA: %lf\n", escolas[x].media_ciencias_natureza);
        printf("MEDIA CIENCIAS HUMANA: %lf\n", escolas[x].media_ciencias_humanas);
        printf("MEDIA LINGUAGEM: %lf\n", escolas[x].media_linguagem);
        printf("MEDIA MATEMATICA: %lf\n", escolas[x].media_matematica);
        printf("MEDIA REDACAO: %lf\n", escolas[x].media_redacao);
        printf("\n");
    }
}
