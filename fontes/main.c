#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int main()
{
    int opcao = 0;
    int tipoOrdenacao = 0;
    int tipoBusca = 0;
    int vetorCriado = 0; /* Flag para ver se vetor inicializado antes de realizar busca*/
    int comp, troca, indice;

    /*Cria vetor principal*/
    int *v = malloc(sizeof(int) * (TAM + 1)); /* Aloca vetor principal*/

    if (v == NULL){
        printf("Não foi possivel criar vetor, erro de alocação\n");
        return -1;
    }

    /* Cria vetor auxiliar para executar algoritmos com o mesmo vetor*/
    int *vetAux = malloc((TAM + 1) * sizeof(int)); /* Cria vetor auxiliar incluindo o sentinela*/

    if(vetAux == NULL){
        printf("Não foi possivel criar vetor auxiliar, erro de alocação\n");
        return -1;
    }

    srand(0); /* Inicializa a semente randomica*/

    while (1) 
    {
        menuPrincipal(opcao); /* Define o fluxo de execução do programa*/
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
                inicializaVetor(v);
                vetorCriado = 1; /* flag de controle para checar se alocado*/
                printf("Vetor criado e inicializado com valores de 0 ate 2048\n\n");
    
            break;

        case 2:
            if (vetorCriado == 0)
                printf("Vetor ainda não inicializado, nao eh possivel imprimir\n");
            else 
                imprimeVetor(v);
                
            printf("\n");
            break;
        case 3:
                printf("-----------------------------------\n");
                printf("Escolha o método de ordenação:\n");
                printf("1. Shell Sort\n");
                printf("2. Quick Sort\n");
                printf("3. Insertion Sort\n");
                printf("4. Testar com todos os citados, apenas uma vez cada\n");
                printf("Digite a opção desejada:");

                scanf("%d", &tipoOrdenacao);
                printf("\n");

                /* Garantindo comp e troca como zero */
                comp = 0, troca = 0;

                if (tipoOrdenacao == 1)
                {
                    inicializaVetor(v);
                    printf("Vetor de Teste: \n"); /* Imprime qual sera o vetor executado*/
                    imprimeVetor(v);
                    printf("\n");

                    copiaVetor(v, vetAux); /* copia vetor inicializado para o aux*/

                    shellSort(v, TAM, &comp, &troca);
                    printf("\nShell Sort com espaçamento 1, 4, 13, 40, ... \n");
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("Vetor Ordenado: \n");
                    imprimeVetor(v);
                    printf("\n");

                    comp = 0, troca = 0; /* Zera contadores para a segunda implementacao do shell*/
                    copiaVetor(vetAux, v); /* Copia aux para o principal para ser usado no proximo*/

                    shellSortPot2(v, TAM, &comp, &troca);
                    printf("\nShell Sort em potencia de 2\n");
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("Vetor Ordenado: \n");
                    imprimeVetor(v);
                    printf("\n");
                }

                if (tipoOrdenacao == 2)
                {   
                    comp = 0, troca = 0; /* zerando contadores*/
                    inicializaVetor(v); /* Subscreve o vetor com novos valores aleatorios*/
                    copiaVetor(v, vetAux); /* Copia principal para aux*/

                    printf("Vetor de Teste: \n"); /* Imprime qual sera o vetor executado*/
                    imprimeVetor(v);
                    printf("\n");

                    quickSortPivoFim(v, 1, TAM, &comp, &troca);
                    printf("\nQuick Sort com pivo na ultima posição\n");
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("Vetor Ordenado: \n");
                    imprimeVetor(v);
                    printf("\n");

                    comp = 0, troca = 0; /* zerando contadores*/
                    copiaVetor(vetAux, v); /* Copia aux para principal para testar com mesmo vetor*/
                    
                    quickSortPivoInicio(v, 1, TAM, &comp, &troca);
                    printf("\nQuick Sort com pivo na Primeira Posicao\n");
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("Vetor Ordenado: \n");
                    imprimeVetor(v);
                    printf("\n");

                }

                if(tipoOrdenacao == 3){
                    comp = 0, troca = 0;
                    inicializaVetor(v); /* Para garantir que nao esta com versao 
                    ordenada de acao anterior*/

                    printf("Vetor de Teste: \n"); /* Imprime qual sera o vetor executado*/
                    imprimeVetor(v);
                    printf("\n");

                    insertionSort(v, TAM, &comp, &troca);
                    printf("Insertion Sort\n");
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("Vetor Ordenado: \n");
                    imprimeVetor(v);
                    printf("\n");
                }
                
                if(tipoOrdenacao == 4){
                    
                    printf("Ordenando o mesmo vetor com todos os algoritmos...\n\n");
                    inicializaVetor(v); /* Subescreve o vetor com novos valores*/
                    copiaVetor(v, vetAux); /* Copia o vetor criado para o vetor auxiliar
                    para ser utilizado por todos os algoritmos */

                    comp = 0, troca = 0;
                    printf("Shell Sort com espaçamento 1, 4, 13, 40,... \n");
                    printf("Vetor Inicial: ");
                    imprimeVetor(v);
                    shellSort(v, TAM, &comp, &troca);
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("\n");

                    comp = 0, troca = 0;
                    copiaVetor(vetAux, v); /* Copia o vetor auxiliar para o principal para ser usado pelo prox */

                    printf("\nShell Sort em potencia de 2\n");
                    printf("Vetor Inicial: ");
                    imprimeVetor(v);
                    shellSortPot2(v, TAM, &comp, &troca);
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("\n");

                    comp = 0, troca = 0;
                    copiaVetor(vetAux, v); /* Copia o vetor auxiliar para o principal para ser usado pelo prox */

                    quickSortPivoFim(v, 1, TAM, &comp, &troca);
                    printf("\nQuick Sort com pivo na ultima posição\n");
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("\n");

                    comp = 0, troca = 0; /* zerando contadores*/
                    copiaVetor(vetAux, v); /* Copia o vetor auxiliar para o principal para ser usado pelo prox */

                    quickSortPivoInicio(v, 1, TAM, &comp, &troca);
                    printf("\nQuick Sort com pivo na Primeira Posicao\n");
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("\n");

                    comp = 0, troca = 0; /* zerando contadores*/
                    copiaVetor(vetAux, v); /* Copia o vetor auxiliar para o principal para ser usado pelo prox */

                    insertionSort(v, TAM, &comp, &troca);
                    printf("Insertion Sort\n");
                    printf("Numero de Comparações: %d.\n", comp);
                    printf("Numero de Trocas: %d.\n", troca);
                    printf("\n");

                }
                
            break;
        case 4:
                if(vetorCriado == 0){
                    printf("Vetor ainda nao inicializado, nao eh possivel buscar elemento.\n");
                    break;
                } else {
                printf("-----------------------------------\n");
                printf("Escolha tipo de busca:\n");
                printf("1. Busca por valor aleatório\n");
                printf("2. Busca por valor especifico\n");
                printf("Digite sua escolha: ");

                scanf("%d", &tipoBusca);

                if(tipoBusca == 1){
                    comp = 0;
                    int chave = aleat(0,2048);
                    printf("Buscando valor aleatório: %d\n", chave);
                    indice = buscaSequencial(v,chave, &comp);

                    printf("Pesquisa Sequencial\n");
                    if(indice == 0){
                        printf("Valor não encontrado no vetor. Foram feitas %d comparações\n,", comp);
                    }
                    else {
                        printf("Valor encontrado no indice %d do vetor com %d comparações\n", indice, comp);

                    }

                    printf("Pesquisa Binaria\n");
                    copiaVetor(v,vetAux); /* copia vetor original para o auxiliar*/

                    /*Ordena vetor para usar a busca binaria*/
                    quickSortPivoInicio(v, 1, TAM, &comp, &troca);

                    comp = 0;
                    indice = pesquisaBinaria(v, chave, &comp);

                    if(indice == 0){
                        printf("Valor não encontrado no vetor. Foram feitas %d comparações\n,", comp);
                    }
                    else {
                        printf("Valor encontrado no indice %d do vetor com %d comparações\n", indice, comp);
                    }
                    copiaVetor(vetAux, v); /* Copia vetor aux nao ordenado para o vetor original*/
                    
                } else if (tipoBusca == 2){
                    int chave;
                    comp = 0;
                    printf("Digite o valor a ser procurado: \n");
                    scanf("%d", &chave);
                    indice = buscaSequencial(v,chave, &comp);

                    printf("Pesquisa Sequencial\n");
                    if(indice == 0){
                        printf("Valor não encontrado no vetor. Foram feitas %d comparações\n,", comp);
                    }
                    else {
                        printf("Valor encontrado no indice %d do vetor com %d comparações\n", indice, comp);

                    }

                    copiaVetor(v,vetAux); /* copia vetor original para o auxiliar*/

                    /*Ordena vetor para usar a busca binaria*/
                    quickSortPivoInicio(v, 1, TAM, &comp, &troca);

                    comp = 0;
                    indice = pesquisaBinaria(v, chave, &comp);

                    imprimeVetor(v);
                    printf("Pesquisa Binaria\n");
                    if(indice == 0){
                        printf("Valor não encontrado no vetor. Foram feitas %d comparações\n,", comp);
                    }
                    else {
                        printf("Valor encontrado no indice %d do vetor com %d comparações\n", indice, comp);

                    }
                    copiaVetor(vetAux, v); /* Copia vetor aux nao ordenado para o vetor original*/
                }
                break;
                }

        case 6:
            printf("Encerrando Programa...\n\n\n");
            
            free(v);
            free(vetAux); /* eh alocado logo no inicio*/
            exit(0);
        }
    }
}