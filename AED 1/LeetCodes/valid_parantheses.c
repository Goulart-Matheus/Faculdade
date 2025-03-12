typedef struct nodo{
    char letra;
    struct nodo *prox;
}nodo;

typedef struct pilha{
    nodo *topo;
}pilha;

pilha* init(){
    pilha* p = (pilha *) malloc (sizeof(pilha));
    p->topo = NULL;
    return p;
}

void push(pilha *pilha, char letra){
    nodo *novoNodo = (nodo *) malloc (sizeof(nodo));
    novoNodo->letra = letra;
    novoNodo->prox = pilha->topo;
    pilha->topo = novoNodo;
}

char pop(pilha *pilha){
    nodo *temp = pilha->topo;
    char c = temp->letra;
    pilha->topo = temp->prox;

    free(temp);
    return c;
}
bool isempty(pilha *pilha){
    return pilha->topo == NULL;
}
char top(pilha *pilha){
    if (pilha->topo == NULL) {
    return '\0'; // Retorno seguro caso a pilha esteja vazia
}
return pilha->topo->letra;
}
void clear(pilha *pilha){
    nodo *temp = pilha->topo;
    nodo *temp2;
    while(temp != NULL){
        temp2 = temp;
        temp = temp->prox;
        free(temp2);
    }
   pilha->topo=NULL;

}

bool isValid(char* s) {
pilha *p = init();
int flag = 0;

for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        push(p, s[i]);
        flag++;
    } else {
        if (isempty(p)) {  
            clear(p);
            free(p);
            return false;
        }

        if ((top(p) == '(' && s[i] == ')') || 
            (top(p) == '{' && s[i] == '}') || 
            (top(p) == '[' && s[i] == ']')) {
            pop(p);
            flag--;
        } else { 
            clear(p);
            free(p);
            return false;
        }
    }
}

bool resultado = isempty(p) && flag == 0;
return resultado;
}