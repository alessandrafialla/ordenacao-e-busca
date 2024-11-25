#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

/* Copia todos os valores do vetor 1 para o vetor 2, sentinela incluso*/
/* Assume que os dois vetores tem tamanhos iguais*/
void copiaVetor(int *vet1, int *vet2){
    for(int i = 0; i <= TAM; i++){
        vet2[i] = vet1[i];
    }

}


/* Função para calcular a média */
float calculaMedia(int *v, int n) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma = soma + v[i];
    }
    return soma / n;
}

/* Função para calcular o desvio padrão*/
float calculaDesvioPadrao(int *v, int n, float media) {
    float somaQuadrados = 0.0;
    for (int i = 0; i < n; i++) {
        somaQuadrados = somaQuadrados + pow(v[i] - media, 2);
    }
    return sqrt(somaQuadrados / n);
} 

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

/* pesquisa binaria */
int pesquisaBinaria(int vetor[], int chave, long *comp) {
    int inicio = 1, fim = TAM, meio; // Começa de 1 por causa do sentinela

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;  // Calcula o elemento do meio

        (*comp)++;  // Conta a comparação
        if (vetor[meio] == chave)
            return meio;  // Achou o elemento
        else if (vetor[meio] < chave)
            inicio = meio + 1;  // Vai para a metade direita
        else
            fim = meio - 1;  // Vai para a metade esquerda
    }
    return 0;  // Retorna 0 se não encontrar, posicao do sentinela
}

/* Realiza a busca sequencial interativa de um valor em um vetor
    Retorna o índice do elemento encontrado ou 0 se não encontrado */
int buscaSequencial(int vetor[], int valor, long *comp)
{
    int i;

    // Itera sobre o vetor a partir da posição 1 (sentinela está em vetor[0])
    for (i = 0; i < TAM; i++) // Vai até TAM, considerando a alocação TAM+1
    {
        (*comp)++;// Incrementa a comparação
        if (vetor[i] == valor) // Verifica se encontrou o valor
        {
            return i; // Retorna o índice do elemento encontrado
        }
    }
    return 0; // Retorna 0 se o valor não for encontrado
}


void particionarInicio(int *v, int esq, int dir, int *pos_pivo, long *comp, long *trocas)
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

void quickSortPivoInicio(int *v, int esq, int dir, long *comp, long *troca)
{
    int pos_pivo;
    if (esq < dir)
    {
        particionarInicio(v, esq, dir, &pos_pivo, comp, troca);
        quickSortPivoInicio(v, esq, pos_pivo - 1, comp, troca);
        quickSortPivoInicio(v, pos_pivo + 1, dir, comp, troca);
    }
}

void particionarFim(int *v, int esq, int dir, int *pos_pivo, long *comp, long *trocas)
{
    int i, j, pivo, aux;
    pivo = v[dir]; /* O pivô é o último elemento */
    i = esq - 1;   // Inicializa o índice menor que a posição inicial

    for (j = esq; j < dir; j++) 
    {
        (*comp)++; 
        if (v[j] <= pivo) 
        {
            i++;         
            aux = v[i];  
            v[i] = v[j];
            v[j] = aux;
            (*trocas)++; /* Incrementa o contador de trocas*/
        }
    }

    // Coloca o pivô na posição correta
    aux = v[i + 1];
    v[i + 1] = v[dir];
    v[dir] = aux;
    (*trocas)++;

    *pos_pivo = i + 1; // Atualiza a posição do pivô
}

void quickSortPivoFim(int *v, int esq, int dir, long *comp, long *trocas)
{
    int pos_pivo;
    if (esq < dir)
    {
        particionarFim(v, esq, dir, &pos_pivo, comp, trocas); 
        quickSortPivoFim(v, esq, pos_pivo - 1, comp, trocas); 
        quickSortPivoFim(v, pos_pivo + 1, dir, comp, trocas); 
    }
}

void insertionSort(int *v, int n, long *comp, long *troca) {
    for (int i = 2; i <= n; i++) { /* Começa da posição 2 por causa da sentinela */
        int chave = v[i];
        int j = i - 1;
        while (j >= 1 && v[j] > chave) { /* Ignora a posição 0 */
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

void shellSortPot2(int *v, int n, long *comp, long *troca)
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

void shellSort(int *v, int n, long *comp, long *troca)
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
};