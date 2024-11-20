 
 
 
 /* Considere um vetor de inteiros com 1024 posições. Preencha este vetor com números aleatórios entre 0 e 2048. Você deve usar recursos da linguagem de programação para gerar os números aleatórios. O programa deve permitir criar um novo vetor a qualquer momento. Deve ser possível imprimir na tela uma pequena parte deste vetor, de forma limpa e compacta.

Ordene este vetor usando três algoritmos: ShellSort, QuickSort e um algoritmo quadrático da sua escolha. Use duas estratégias de escolha do pivô no QuickSort. Use dois espaçamentos distintos no ShellSort. Seu programa deve contar quantas comparações e quantas permutações (trocas) de elementos cada método utiliza para ordenar o vetor.

Permita uma consulta a um elemento neste vetor. O elemento pode ser tanto entrado pelo usuário e também gerado aleatoriamente. Tanto a Pesquisa Sequencial como a Pesquisa Binária devem ser realizadas. A Pesquisa Sequencial deve ser realizada no vetor original não ordenado. O programa deve contar o número de comparações realizadas em cada pesquisa.

Uma opção do menu deve permitir a execução de ordenações e buscas (TODOS os algoritmos) 1000 vezes, calculando a média e o desvio padrão do número de comparações utilizadas em cada caso.

O objetivo do seu programa é comprovar na prática: qual o melhor dos métodos de ordenação? O QuickSort foi melhor ou pior que o ShellSort? Além disso deve demonstrar a eficiência dos demais algoritmos implementados.

Execute testes exaustivos, mostrando que seu programa funciona nas mais diversas situações.*/

struct vetor{
    float media;
    float desvio;
    int *v;
};
