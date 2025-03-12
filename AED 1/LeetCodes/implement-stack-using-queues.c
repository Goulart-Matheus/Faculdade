typedef struct nodo{
    int c;
    struct nodo *prox;
}nodo;

typedef struct lista{
    nodo *inicio;
    nodo *fim;
}lista;

lista* init(){
    lista* c = (lista *) malloc(sizeof(lista));
    c->inicio = NULL;
    c->fim = NULL;
    return c;
}

void enqueue(lista *lista, int c){
    nodo *novoNodo = (nodo *) malloc(sizeof(nodo));
    novoNodo->c = c;
    novoNodo->prox = NULL;
    if(lista->inicio == NULL){
        lista->inicio = novoNodo;
        lista->fim = novoNodo;
    }else{
       lista->fim->prox = novoNodo; 
       lista->fim = novoNodo;
    }
}

int dequeue(lista *lista){
    nodo *temp = lista->inicio;
    int c = temp->c;
    lista->inicio = temp->prox;
    free(temp);
    return c;
}

bool isEmpty(lista *lista){
    return (lista->inicio == NULL);
}

int top(lista *lista){
    return lista->inicio->c;
}

// Estrutura da pilha usando duas filas

typedef struct {
    lista *q1;
    lista *q2;
} MyStack;

// Inicializa a pilha
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = init();
    stack->q2 = init();
    return stack;
}

// Empilha um elemento
void myStackPush(MyStack* pilha, int x) {
    enqueue(pilha->q2, x);
    while (!isEmpty(pilha->q1)) {
        enqueue(pilha->q2, dequeue(pilha->q1));
    }
    lista* temp = pilha->q1;
    pilha->q1 = pilha->q2;
    pilha->q2 = temp;
}

// Desempilha um elemento
int myStackPop(MyStack* pilha) {
    return dequeue(pilha->q1);
}

// Retorna o topo da pilha
int myStackTop(MyStack* pilha) {
    return top(pilha->q1);
}

// Verifica se a pilha está vazia
bool myStackEmpty(MyStack* pilha) {
    return isEmpty(pilha->q1);
}

// Libera memória da pilha
void myStackFree(MyStack* pilha) {
    free(pilha->q1);
    free(pilha->q2);
    free(pilha);
}