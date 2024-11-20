#include <stdio.h>
#include <stdlib.h>

#define TAM 1024
#define TAMTESTE 1000

int aleat(int min, int max)
{
    return min + rand() % (max - min + 1);
}

/*Função que imprime as primeiras 5 e as ultimas 5 posições do vetor,
 excluindo a posicao reservada do sentinela*/
void imprimeVetor(int *v)
{

    // Imprime as primeiras 5 posições úteis
    for (int i = 1; i <= 5 && i <= TAM; i++)
    {
        printf("%d ", v[i]);
    }
    if (TAM > 10)
    {
        printf("... ");
    }

    // Imprime as últimas 5 posições úteis
    for (int j = TAM-5; j <= TAM ; j++)
    {
        printf("%d ", v[j]);
    }

    printf("\n");
}

/*Inicializa vetor com valores aleatorios de 0 ate 2048*/
void inicializaVetor(int *v)
{
    v[0] = 0; /*inicializa sentinela com zero*/
    for (int i = 1; i <= TAM; i++)
    {
        v[i] = aleat(0, 2048);
    }
}

/*
void menuOperacoes()
{
    printf("---------------- MENU ----------------\n ");
    printf(" Digite a opção desejada: \n");
    printf("1 - Buscar Elemento Aleatorio \n");
    printf("2 - Buscar Elemento Escolhido \n");
    printf("3 - Imprimir Vetor \n");
    printf("4 - Sair \n");
} 

int *cria_vetor()
{
    int *v = malloc(sizeof(int) * TAM + 1);
    return v;
} */

void menuPrincipal()
{
    printf("---------------- MENU ----------------\n");
    printf("1 - Criar vetor \n");
    printf("2 - Imprimir Vetor \n");
    printf("3 - Ordenar vetor \n");
    printf("4 - Buscar elemento \n");
    printf("5 - Executar testes \n");
    printf("6 - Sair\n");
    printf("Digite a opção desejada: ");
}

// Realiza a busca sequencial interativa de um valor em um vetor
// Retorna o indice do elemento encontrado ou -1 se nao encontrado
#define TAM 1024 // Define o tamanho do vetor sem contar a sentinela

// Realiza a busca sequencial interativa de um valor em um vetor
// Retorna o índice do elemento encontrado ou -1 se não encontrado
int buscaSequencial(int vetor[], int valor, int *comp)
{
    int i;

    // Itera sobre o vetor a partir da posição 1 (sentinela está em vetor[0])
    for (i = 1; i <= TAM; i++) // Vai até TAM, considerando a alocação TAM+1
    {
        (*comp)++;// Incrementa a comparação
        if (vetor[i] == valor) // Verifica se encontrou o valor
        {
            return i; // Retorna o índice do elemento encontrado
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}


void particionarInicio(int *v, int esq, int dir, int *pos_pivo, int *comp, int *trocas)
{
    int i, j, pivo, aux;
    pivo = v[esq];
    i = esq;
    j = dir;

    while (i < j)
    {
        while ((v[i] <= pivo) && i < dir)
        {
            i++;
            (*comp)++;
        }
        while (v[j] > pivo)
        {
            j--;
            (*comp)++;
        }

        /*No pior caso para no pivo*/
        if (i < j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            (*trocas)++;
        }
    }
    v[esq] = v[j];
    v[j] = pivo;
    *pos_pivo = j;

    (*comp)++;
}

void quickSortPivoInicio(int *v, int esq, int dir, int *comp, int *troca)
{
    int pos_pivo;
    if (esq < dir)
    {
        particionarInicio(v, esq, dir, &pos_pivo, comp, troca);
        quickSortPivoInicio(v, esq, pos_pivo - 1, comp, troca);
        quickSortPivoInicio(v, pos_pivo + 1, dir, comp, troca);
    }
}

void particionarFim(int *v, int esq, int dir, int *pos_pivo, int *comp, int *trocas)
{
    int i, j, pivo, aux;
    pivo = v[dir]; // O pivô é o último elemento
    i = esq - 1;   // Inicializa o índice menor que a posição inicial

    for (j = esq; j < dir; j++) // Itera até o penúltimo elemento
    {
        (*comp)++; // Incrementa o contador de comparações
        if (v[j] <= pivo) // Se o elemento é menor ou igual ao pivô
        {
            i++;         // Incrementa o índice do menor elemento
            aux = v[i];  // Troca os elementos
            v[i] = v[j];
            v[j] = aux;
            (*trocas)++; // Incrementa o contador de trocas
        }
    }

    // Coloca o pivô na posição correta
    aux = v[i + 1];
    v[i + 1] = v[dir];
    v[dir] = aux;
    (*trocas)++;

    *pos_pivo = i + 1; // Atualiza a posição do pivô
}

void quickSortPivoFim(int *v, int esq, int dir, int *comp, int *trocas)
{
    int pos_pivo;
    if (esq < dir)
    {
        particionarFim(v, esq, dir, &pos_pivo, comp, trocas); // Particiona com o pivô no fim
        quickSortPivoFim(v, esq, pos_pivo - 1, comp, trocas); // Ordena a partição esquerda
        quickSortPivoFim(v, pos_pivo + 1, dir, comp, trocas); // Ordena a partição direita
    }
}


/* Copia todos os valores do vetor 1 para o vetor 2, sentinela incluso*/
/* Assume que os dois vetores tem tamanhos iguais*/
void copiaVetor(int *vet1, int *vet2){
    for(int i = 0; i <= TAM; i++){
        vet2[i] = vet1[i];
    }

}

void insertionSort(int *v, int n, int *comp, int *troca) {
    for (int i = 2; i <= n; i++) { // Começa da posição 2 por causa da sentinela
        int chave = v[i];
        int j = i - 1;
        while (j >= 1 && v[j] > chave) { // Ignora a posição 0
            v[j + 1] = v[j];
            j--;
            (*comp)++;
        }
        v[j + 1] = chave;
        if (j + 1 != i) {
            (*troca)++;
        }
    }
}

void shellSortPot2(int *v, int n, int *comp, int *troca)
{
    int i, j, aux;
    int k = 1;

    /* Calculando o maior valor de k (gap) como potência de 2 */
    do
    {
        k = k * 2; // Incrementa para o próximo valor de potência de 2
    } while (k <= n); /* Continua até k ser maior que n */
    k = k / 2;         /* Ajusta para o maior gap válido menor ou igual a n */

    /* Início da ordenação com o gap reduzido */
    do
    {
        for (i = k + 1; i <= n; i++) // Começa do índice k + 1 devido à sentinela
        {
            aux = v[i]; /* Elemento que será comparado */
            j = i;

            /* Comparação e movimentação dos elementos */
            while ((j > k) && (v[j - k] > aux))
            {                    // Verifica índices válidos
                v[j] = v[j - k]; /* Move os elementos */
                j = j - k;       /* Move a posição */
                (*comp)++;
                (*troca)++;
            }

            /* Coloca o elemento correto na posição */
            if (i != j)
            {
                v[j] = aux;
                (*troca)++;
            }
        }

        k = k / 2; /* Reduz o gap para a próxima potência de 2 */
    } while (k >= 1); /* Continua até que o gap seja 1 */
}

void shellSort(int *v, int n, int *comp, int *troca)
{
    int i, j, aux;
    int k = 1;

    /* Calculando o primeiro valor de k (gap) */
    do
    {
        k = k * 3 + 1;
    } while (k <= n); /* Continua até k ser maior que n */

    /* Início da ordenação com o gap reduzido */
    do
    {
        k = k / 3; /* Reduz o gap a cada iteração */

        for (i = k; i <= n; i++)
        {               // Começa do índice k
            aux = v[i]; /* Elemento que será comparado */
            j = i;

            /* Comparação e movimentação dos elementos */
            while ((j > k) && (v[j - k] > aux))
            {                    // Verifica índices válidos
                v[j] = v[j - k]; /* Troca os elementos */
                j = j - k;       /* Move a posição */
                (*comp)++;
                (*troca)++;

            }

            /* Coloca o elemento correto na posição */
            if (i != j)
            { /* Se houve troca de posição */
            v[j] = aux; 
                (*troca)++;
            }
        }
    } while (k != 1); /* Continua até que o gap seja 1 */
}

/* https://www.todamateria.com.br/desvio-padrao/ */
float desvio_padrao(int *v, int n);

float media(int *v, int n);

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

                    if(indice == 0){
                        printf("Valor não encontrado no vetor\n");
                    }
                    else {
                        printf("Valor encontrado no indice %d do vetor\n", indice);

                    }
                    
                }

        case 6:
            printf("Encerrando Programa...\n\n\n");
            
            free(v);
            free(vetAux); /* eh alocado logo no inicio*/
            exit(0);
        }
    }
}