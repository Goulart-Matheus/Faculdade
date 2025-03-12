int calPoints(char** operations, int operationsSize) {
    
    typedef struct nodo{
        int valores;
        struct nodo *prox;
    }nodo;

    typedef struct pilha{
        nodo *topo;
        int quantidade;
    }pilha;

    void init(pilha *pilha){
        pilha->topo = NULL;
        pilha->quantidade = 0;
    }

    void push(pilha *pilha, int c){
        nodo *novoNodo = (nodo *)malloc(sizeof(nodo));
        novoNodo->valores = c;
        novoNodo->prox = pilha->topo;
        pilha->topo = novoNodo;
        pilha->quantidade++;
    }

    int pop(pilha *pilha){
         if (pilha->topo == NULL) {
            printf("Erro: pilha vazia!\n");
            exit(1);
        }
        nodo *temp = pilha->topo;
        int c = temp->valores;
        pilha->topo = temp->prox;
        pilha->quantidade--;

        free(temp);
        return c;
    }

     int top(pilha *pilha) {
        if (pilha->topo == NULL) {
            printf("Erro: pilha vazia!\n");
            exit(1);
        }
        return pilha->topo->valores;
    }

    pilha p;
    init(&p);
   
    for(int i = 0; i < operationsSize; i++){
        if(strcmp(operations[i], "+") == 0){
            if(p.quantidade >= 2){
            int resposta1 = pop(&p);
            int resposta2 = pop(&p);
            push(&p, resposta2);
            push(&p, resposta1);
            push(&p, resposta1 + resposta2);
            } 
        }else if(strcmp(operations[i], "D") == 0){
           if (p.quantidade >= 1) {
                int valor = top(&p);
                push(&p, 2 * valor);
            }

        }else if(strcmp(operations[i], "C") == 0){
          if (p.quantidade >= 1) {
                pop(&p);
            }
        }else{
         int value = atoi(operations[i]);
        push(&p, value);
        }

    }
   int soma = 0;
    while (p.quantidade > 0) {
        soma += pop(&p);
    }

    return soma;
}