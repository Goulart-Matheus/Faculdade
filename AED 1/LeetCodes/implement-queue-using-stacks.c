typedef struct nodo{
    int c;
    struct nodo *prox;
}nodo;

typedef struct pilha{
    nodo *inicio;
}pilha;

pilha* init(){
    pilha* c = (pilha *) malloc(sizeof(pilha));
    c->inicio = NULL;
    return c;
}

void push(pilha *pilha, int c){
    nodo *novoNodo = (nodo *) malloc(sizeof(nodo));
    novoNodo->c = c;
    novoNodo->prox = pilha->inicio;
    pilha->inicio = novoNodo;
}

int pop(pilha *pilha){
    nodo *temp = pilha->inicio;
    int c = temp->c;
    pilha->inicio = temp->prox;
    free(temp);
    return c;
}

bool isEmpty(pilha *pilha){
    return (pilha->inicio == NULL);
}

int top(pilha *pilha){
    return pilha->inicio->c;
}


typedef struct {
    pilha *q2;
    pilha *q1;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue *) malloc (sizeof(MyQueue));
    queue->q1 = init();
    queue->q2 = init();
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj->q1, x);
    
}

int myQueuePop(MyQueue* obj) {
    if(isEmpty(obj->q2)){
        while(!isEmpty(obj->q1)){
            push(obj->q2, pop(obj->q1));
        }
    }
    return pop(obj->q2);    
}

int myQueuePeek(MyQueue* obj) {
    if (!isEmpty(obj->q2)) {
        return top(obj->q2);
    } else if (!isEmpty(obj->q1)) {
        // Se q2 estiver vazia, movemos os elementos para q2 e pegamos o topo
        while (!isEmpty(obj->q1)) {
            push(obj->q2, pop(obj->q1));
        }
        return top(obj->q2);
    }
    return -1; // Retorna -1 se a fila estiver vazia
}

bool myQueueEmpty(MyQueue* obj) {
     return isEmpty(obj->q1) && isEmpty(obj->q2);
}

void myQueueFree(MyQueue* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/