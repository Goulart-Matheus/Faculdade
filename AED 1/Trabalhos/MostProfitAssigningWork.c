/*
    -------  COMPLEXIDADE  -------

    A complexidade do algoritmo pode ser analisada da seguinte forma:
    
    - A criação do array de trabalhos leva O(n), onde n é difficultySize.
    - A ordenação dos trabalhos pelo qsort tem complexidade O(n log n).
    - A ordenação dos trabalhadores pelo qsort tem complexidade O(m log m), onde m é trabalhadorSize.
    - O loop principal percorre os trabalhadores O(m) vezes.
    - O loop interno percorre os trabalhos no pior caso O(n) vezes.
    
    Assim, a complexidade geral é O(n log n + m log m + m * n). No pior caso, se m for próximo de n, temos O(n^2).

 */

typedef struct {
    int dif;
    int prof;
} trabalho;

// Uso da função COMPARE usada no qsort

// Função que compara e ordena os trabalhos por dificuldade crescente para uso no qsort
int compTrabalho(const void* a, const void* b) {
    return ((trabalho*)a)->dif - ((trabalho*)b)->dif;   //
}

// Função que compara e ordena os trabalhadores por habilidade crescente para uso no qsort
int compTrabalhador(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);                     //      
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    
    // Cria array de trabalhos
    trabalho* trabalhos = (trabalho*)malloc(difficultySize * sizeof(trabalho));
    for (int i = 0; i < difficultySize; i++) {
        trabalhos[i].dif = difficulty[i];
        trabalhos[i].prof = profit[i];
    }
 
    // Ordena os trabalho por dificuldade crescente 
    qsort(trabalhos, difficultySize, sizeof(trabalho), compTrabalho);

    // Ordena os trabalhadores por habilidade crescente
    qsort(worker, workerSize, sizeof(int), compTrabalhador);

    int totProf = 0;         // Inicializa o totLucro em 0
    int maxProf = 0;         // Inicializa o maxProf em 0

    // Percorrer cada trabalhador
    for(int i = 0; i < workerSize; i++){

        int j = 0; //Inicizaliza o contador pro percorrer o trabalho

        // Continua enquanto o trabalhador puder realizar o trabalho
        while(j < difficultySize && trabalhos[j].dif <= worker[i]){
            if (trabalhos[j].prof > maxProf) {     // Se o lucro do trabalho for menor que o maxProf
                maxProf = trabalhos[j].prof;       // maxProf recebe o lucro do trabalhador
            }
            j++;                                   // Se o lucro do trabalho não for menor que o maxProf, vai pro próximo
        }
        // Adiciona o melhor lucro para esse trabalhador
        totProf += maxProf;
    }

    free(trabalhos);

    return totProf;
}