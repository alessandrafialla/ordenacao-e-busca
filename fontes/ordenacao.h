
#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>

// Definições de tamanho
#define TAM 1024
#define TAMTESTE 1000

// Prototipação de funções
int aleat(int min, int max);

/*Imprime as primeiras 5 e ultimas 6 posicoes do vetor*/
void imprimeVetor(int *v);

/*Inicializa vetor com valores aleatorios de 0 ate 2048*/
void inicializaVetor(int *v);

/*Copia todos os valores de vet1 para vet2*/
void copiaVetor(int *vet1, int *vet2);

/*Imprime as opcoes de acoes*/
void menuPrincipal();

/*Implementa os algoritmos de busca*/
int buscaSequencial(int vetor[], int valor, int *comp);
int pesquisaBinaria(int vetor[], int chave, int *comp);

/*Variacao de implementacao do quicksort utilizando pivo no inicio do vetor*/
void particionarInicio(int *v, int esq, int dir, int *pos_pivo, int *comp, int *trocas);
void quickSortPivoInicio(int *v, int esq, int dir, int *comp, int *troca);

/*Variacao de implementacao do quicksort utilizando pivo no final do vetor*/
void particionarFim(int *v, int esq, int dir, int *pos_pivo, int *comp, int *trocas);
void quickSortPivoFim(int *v, int esq, int dir, int *comp, int *trocas);

/*Implementa o algoritmo Insertion Sort*/
void insertionSort(int *v, int n, int *comp, int *troca);

/*Variacao do Shell sort com gap em potencia de 2*/
void shellSortPot2(int *v, int n, int *comp, int *troca);

/*Variacao do Shell sort com gap em sequencia de Knuth*/
void shellSort(int *v, int n, int *comp, int *troca);

float desvio_padrao(int *v, int n);
float media(int *v, int n);

#endif // ORDENACAO_H
