typedef struct nodoPilha{
    int sanduiche;
    struct nodoPilha *prox;
} nodoPilha;

typedef struct nodoFila{
    int alunos;
    struct nodoFila *prox;
} nodoFila;

typedef struct fila{
    nodoFila *inicio;
    nodoFila *ultimo;
} fila;

typedef struct pilha{
    nodoPilha *topo;
} pilha;

// Funções da pilha
pilha* initPilha(){
    pilha* p = (pilha *) malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

void push(pilha *p, int c){
    nodoPilha *novoNodo = (nodoPilha *) malloc(sizeof(nodoPilha));
    novoNodo->sanduiche = c;
    novoNodo->prox = p->topo;
    p->topo = novoNodo;
}

int pop(pilha *p){   
    if (p->topo == NULL) return -1;
    nodoPilha *temp = p->topo;
    int c = temp->sanduiche;
    p->topo = temp->prox;
    free(temp);
    return c;     
}

int top(pilha *p){
    if (p->topo == NULL) return -1;
    return p->topo->sanduiche;
}

bool IsEmptyP(pilha *p){
    return (p->topo == NULL);
}

// Funções da fila
fila* initFila(){
    fila* f = (fila *) malloc(sizeof(fila));
    f->inicio = NULL;
    f->ultimo = NULL;
    return f;
}

void enqueue(fila *f, int c){
    nodoFila *novoNodo = (nodoFila *) malloc(sizeof(nodoFila));
    novoNodo->alunos = c;
    novoNodo->prox = NULL;

    if (f->inicio == NULL){
        f->inicio = novoNodo;
        f->ultimo = novoNodo;
    } else {
        f->ultimo->prox = novoNodo;
        f->ultimo = novoNodo;
    }
}

int dequeue(fila *f){
    if (f->inicio == NULL) return -1;
    nodoFila *temp = f->inicio;
    int c = temp->alunos;
    f->inicio = temp->prox;
    if (f->inicio == NULL) f->ultimo = NULL;
    free(temp);
    return c;
}

int peek(fila *f){
    if (f->inicio == NULL) return -1;
    return f->inicio->alunos;
}

bool IsEmptyF(fila *f){
    return (f->inicio == NULL);
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    pilha *p = initPilha();
    fila *f = initFila();

    for (int i = sandwichesSize - 1; i >= 0; i--){
        push(p, sandwiches[i]);
    }

   
    for (int i = 0; i < studentsSize; i++){
        enqueue(f, students[i]);
    }

    int tentativas = 0; 
    while (!IsEmptyP(p) && tentativas < studentsSize){
        if (top(p) == peek(f)){
            pop(p);
            dequeue(f);
            tentativas = 0; 
        } else {
            enqueue(f, dequeue(f));
            tentativas++;
        }
    }

    int count = 0;
    while (!IsEmptyF(f)){
        dequeue(f);
        count++;
    }

    return count;
}
