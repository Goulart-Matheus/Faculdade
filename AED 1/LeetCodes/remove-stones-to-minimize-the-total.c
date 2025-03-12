typedef struct {
    int pedra;
} Pedra;

// Estrutura da Heap Máxima
typedef struct {
    Pedra *vetor; 
    int tamanho;
    int capacidade;
} Heap;

// Função para inicializar a heap
Heap *init(int capacidade) {
    Heap *maxHeap = (Heap *)malloc(sizeof(Heap));
    maxHeap->vetor = (Pedra *)malloc(capacidade * sizeof(Pedra));
    maxHeap->tamanho = 0;
    maxHeap->capacidade = capacidade;
    return maxHeap;
}

// Função para trocar dois elementos no vetor
void trocar(Pedra *indice, Pedra *pai) {
    Pedra temp = *indice; //temp recebe o valor de indice
    *indice = *pai; //indice recebe o valor de pai
    *pai = temp; //pai agora recebe o valor de temp que é indice
}

// Ajusta um elemento para cima na heap
void ajustar_cima(Heap *heap, int indice) {
    while (indice > 0) { //enquanto o indice de memoria é menor que o pa;i
        int pai = (indice - 1) / 2; //acha o indice pai
        if (heap->vetor[indice].pedra <= heap->vetor[pai].pedra) //verifica se o pai é maior ou igual
            break; // se é ele para
        trocar(&heap->vetor[indice], &heap->vetor[pai]); // se nao ele troca de posicao
        indice = pai; //o indice agora recebe o pai 
    }
}

// Função para inserir um novo valor na heap
void enfileirar(Heap *heap, int p) {
    if (heap->tamanho >= heap->capacidade) { //verifica se tem espaço na heap
        printf("Heap cheia!\n");
        return;
    }
    heap->vetor[heap->tamanho].pedra = p; //adiciona o valor no final
    ajustar_cima(heap, heap->tamanho); // chama o ajusta acima
    heap->tamanho++; //aumenta o tamanho
}

// Ajusta um elemento para baixo na heap
void ajustar_abaixo(Heap *heap, int indice) { //recebe a heap e o indice pai
    while (1) {
        int maior = indice; //recebe o indice pai
        int esquerda = 2 * indice + 1; //esquerda recebe????
        int direita = 2 * indice + 2; //direita recebe????

        if (esquerda < heap->tamanho && heap->vetor[esquerda].pedra > heap->vetor[maior].pedra)
        //se o indice da esquerda for menor que o tamanho e for maior que o vetor pai
            maior = esquerda;
        if (direita < heap->tamanho && heap->vetor[direita].pedra > heap->vetor[maior].pedra)
        //se o indice da direita for menor que o tamanho e for maior que o vetor pai
            maior = direita;

        if (maior == indice) break; //?????

        trocar(&heap->vetor[indice], &heap->vetor[maior]); //????
        indice = maior; //????
    }
}

// Função para remover o maior elemento do heap
int remover_heap(Heap *heap) {
    if (heap->tamanho == 0) {
        printf("Heap vazia!\n");
        return -1;
    }

    int maiorPedra = heap->vetor[0].pedra;
    heap->vetor[0] = heap->vetor[heap->tamanho - 1];
    heap->tamanho--;
    ajustar_abaixo(heap, 0);
    return maiorPedra;
}



int minStoneSum(int* piles, int pilesSize, int k) {

    Heap *novaHeap = init(pilesSize);
    int somatorio = 0;

    for(int i = 0; i < pilesSize; i++){

        enfileirar(novaHeap, piles[i]);
    }

     for(int i = 0; i < k; i++){

       int valor = remover_heap(novaHeap);

       valor = (valor + 1) / 2;

       enfileirar(novaHeap, valor);
    }

    for(int i = 0; i < pilesSize; i++){

    somatorio = somatorio + remover_heap(novaHeap);
    }


    return somatorio;
}