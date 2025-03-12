#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prototipo da função para evitar erro de compilação
char* reversePrefix(char* word, char ch);

int main() {
    char word[] = "abcdefg"; // Palavra de exemplo
    char ch = 'd';          // Caractere para o prefixo reverso

    // Chama a função e armazena o resultado
    char* result = reversePrefix(word, ch);

    // Imprime o resultado
    printf("Resultado: %s\n", result);

    return 0;
}


char* reversePrefix(char* word, char ch) {

    typedef struct nodo {
        char letra;
        struct nodo *prox;
    }nodo;

    nodo *pilha = NULL;
    nodo *ultimo = NULL;

    void push(nodo **topo, nodo **ultimo, char c)
    {
        nodo *novoNodo = (nodo*) malloc (sizeof (nodo));

         if(novoNodo == NULL)
         {
            return; //verifica se é possivel alocar memoria 
         }
         
         if(*topo == NULL)
         {
            *ultimo = novoNodo;
            //se a pilha estiver vazia atualizar o ponteiro ultimo para esse nodo
         }
        novoNodo -> letra = c;
        novoNodo -> prox = *topo;
        *topo = novoNodo;
    }

    char pop(nodo **topo){
        if(*topo == NULL)
         {
            return 'z';
         }
        nodo *temp = *topo;
        char c = temp->letra;
        *topo = (*topo)->prox;
        free(temp);
        return c;
    }

    int index = -1;


    for(int i = 0; word[i] != '\0'; i++)
{
    if(word[i] == ch){
        index = i;
        break;
    }
}
    if(index == -1){
        return word;
    }

    for(int i = 0; i <= index; i++){
        push(&pilha, &ultimo, word[i]);
    }
    for(int i = 0; i <= index; i++){
        word[i] = pop(&pilha);
    }

    return word;

}