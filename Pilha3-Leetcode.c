#include <stdio.h>
#include <stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize);

int main() {
    int prices[] = {10, 1, 1, 6};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    int returnSize;

    // Chama a função finalPrices
    int* resultado = finalPrices(prices, pricesSize, &returnSize);

    // Exibe o resultado
    printf("Preços com desconto: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    // Libera a memória alocada para o array de resultado
    free(resultado);

    return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
      typedef struct nodo {
        int valor;
        struct nodo *prox;
    }nodo;

     nodo *pilha = NULL;
     nodo *ultimo = NULL;

    void push(nodo **topo, nodo **ultimo, int c)
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
        novoNodo -> valor = c;
        novoNodo -> prox = *topo;
        *topo = novoNodo;
    }

    int pop(nodo **topo){
        if(*topo == NULL)
         {
            return 'z';
         }
        nodo *temp = *topo;
        int c = temp->valor;
        *topo = (*topo)->prox;
        free(temp);
        return c;
    }

      int top(nodo *topo) {
        return topo != NULL ? topo->valor : -1;
    }

    int* resposta = (int *) malloc (sizeof(int) * pricesSize);
    *returnSize = pricesSize;

int j = 1;
  // Itera sobre os preços para calcular os valores finais
  for (int i = 0; i < pricesSize; i++) 
    {

        if (pilha == NULL) 
        {
            push(&pilha, &ultimo, prices[i]);
        }

            
       while (pilha != NULL && top(pilha) >= prices[j] && j < pricesSize) 
        {
            resposta[i] = top(pilha) - prices[j];
            pop(&pilha); // Remove o elemento do topo se for maior ou igual ao preço atual
            j++;
        }

        if(!(pilha != NULL && top(pilha) >= prices[j] && j < pricesSize))
        {
            resposta[i] = prices[i];
        }
                
    }

    return resposta;
}
