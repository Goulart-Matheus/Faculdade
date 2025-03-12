
void inOrder(struct TreeNode* raiz, int* lista, int* tamanho) {
    if (!raiz) return;
    inOrder(raiz->left, lista, tamanho);
    lista[(*tamanho)++] = raiz->val;
    inOrder(raiz->right, lista, tamanho);
}

void buscarMaisProximos(int* lista, int tamanho, int consulta, int* menor, int* maior) {
    int esquerda = 0, direita = tamanho - 1;
    
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (lista[meio] == consulta) {
            *menor = *maior = consulta;
            return;
        } 
        else if (lista[meio] < consulta) {
            *menor = lista[meio];
            esquerda = meio + 1;
        } 
        else {
            *maior = lista[meio];
            direita = meio - 1;
        }
    }
}

int** closestNodes(struct TreeNode* root, int* queries, int queriesSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = queriesSize;
    *returnColumnSizes = (int*) malloc(sizeof(int) * queriesSize);

    int* lista = (int*) malloc(100000 * sizeof(int)); 
    int tamanho = 0;
    inOrder(root, lista, &tamanho);

    int** resultado = (int**) malloc(sizeof(int*) * queriesSize);
    
    for (int i = 0; i < queriesSize; i++) {
        int menor = -1, maior = -1;
        buscarMaisProximos(lista, tamanho, queries[i], &menor, &maior);

        resultado[i] = (int*) malloc(sizeof(int) * 2);
        resultado[i][0] = menor;
        resultado[i][1] = maior;

        (*returnColumnSizes)[i] = 2;
    }

    free(lista);
    return resultado;
}