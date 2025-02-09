#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura de nodo
typedef struct nodo {
    char simbolo;
    struct nodo *prox;
} nodo;

// Função para empilhar
void push(nodo **topo, char c) {
    nodo *novoNodo = (nodo*) malloc(sizeof(nodo));
    if (novoNodo == NULL) {
        return;
    }
    novoNodo->simbolo = c;
    novoNodo->prox = *topo;
    *topo = novoNodo;
}

// Função para desempilhar
char pop(nodo **topo) {
    if (*topo == NULL) {
        return '\0'; // Caso de erro ou pilha vazia
    }
    nodo *temp = *topo;
    char c = temp->simbolo;
    *topo = (*topo)->prox;
    free(temp);
    return c;
}

// Função para resolver o problema
char* removeOuterParentheses(char* s) {
    nodo *pilha = NULL;
    char* resultado = (char*) malloc(strlen(s) + 1);
    int indice = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            // Ignora o parêntese de abertura se não for externo
            if (pilha != NULL) {
                resultado[indice++] = s[i];
            }
            push(&pilha, s[i]);
        } else if (s[i] == ')') {
            pop(&pilha);
            // Ignora o parêntese de fechamento se não for externo
            if (pilha != NULL) {
                resultado[indice++] = s[i];
            }
        }
    }
    resultado[indice] = '\0';  // Finaliza a string
    return resultado;
}

int main() {
    char s1[] = "(()())(())";
    char s2[] = "(()())(())(()(()))";
    char s3[] = "()()";

    // Testando a função
    printf("Resultado 1: %s\n", removeOuterParentheses(s1));  // Esperado: "()()()"
    printf("Resultado 2: %s\n", removeOuterParentheses(s2));  // Esperado: "()()()(())"
    printf("Resultado 3: %s\n", removeOuterParentheses(s3));  // Esperado: ""

    return 0;
}
