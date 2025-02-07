
#define pai(ind) ((ind - 1) >> 1)
#define filho_esquerda(ind) ((ind << 1) + 1)
#define filho_direita(ind) ((ind << 1) + 2)

struct dado{
    double value;
    int ind;
};

void troca(struct dado* a, struct dado* b){
    struct dado temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct dado* stack, int* tam, int ind){
    // Pra cima
    int parent = pai(ind);
    while(ind && stack[parent].value < stack[ind].value){
        troca(stack + parent, stack + ind);
        ind = parent;
        parent = pai(ind);
    }

    // Desce
    int left = filho_esquerda(ind);
    int right = filho_direita(ind);

    while(left < *tam && (stack[left].value > stack[ind].value || (right < *tam && stack[right].value > stack[ind].value))){
        if (*tam <= right) right = left;
        if (stack[left].value > stack[right].value) right = left;
        troca(stack + right, stack + ind);
        ind = right;
        left = filho_esquerda(ind);
        right = filho_direita(ind);
    }
}

void insert(struct dado* stack, int* tam, struct dado input){
    stack[*tam] = input;
    sort(stack, tam, *tam);
    ++(*tam);
}

struct dado remover(struct dado* stack, int* tam){
    struct dado result = stack[0];
    stack[0] = stack[*tam - 1];
    --(*tam);
    sort(stack, tam, 0);
    return result;
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) 
{
    struct dado armazena[classesSize];
    int armazena_tam = 0;
    for(int i = 0; i < classesSize; i++){
        struct dado current;
        current.value = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
        current.value -= (double)(classes[i][0]) / (classes[i][1]);
        current.ind = i;
        insert(armazena, &armazena_tam, current);
    }
    
    while(extraStudents > 0){
        struct dado current = remover(armazena, &armazena_tam);
        ++classes[current.ind][0];
        ++classes[current.ind][1];

        current.value = (double)(classes[current.ind][0] + 1) / (classes[current.ind][1] + 1);
        current.value -= (double)(classes[current.ind][0]) / (classes[current.ind][1]);

        insert(armazena, &armazena_tam, current);
        --extraStudents;
    }

    double total = 0;
    for(int i = 0; i < classesSize; ++i){
        total += (double)classes[i][0] / classes[i][1];
    }
    return total / classesSize;
}
