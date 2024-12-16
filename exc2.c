int** generate(int numRows, int* returnSize, int** returnColumnSizes) 
{
    int **resultado = malloc(numRows * sizeof(int *));  // Ponteiro para array de ponteiros, cada ponteiro é uma linha
    *returnColumnSizes = malloc(numRows * sizeof(int)); // Array que armazena o numero de elementos por linha

    *returnSize = numRows; // Numero de linhas a ser retornado 

    for (int i = 0; i < numRows; ++i) // Criação do triangulo
    {
        (*returnColumnSizes)[i] = i + 1; // Numero de linhas = i + 1, pq no Tri. Pasc. cada nova linha tem 1 elemento a mais que a anterior
        resultado[i] = malloc((i + 1) * sizeof(int)); // Aloca i + 1 espaços para cada linha
        
        for (int j = 0; j <= i; ++j) 
        {
            if (j == 0 || j == i) 
            {
                resultado[i][j] = 1; // Primeiro e ultimo elemento de de cada linha é sempre 1
            } 
            else 
            {
                resultado[i][j] = resultado[i-1][j-1] + resultado[i-1][j]; // Qualquer elemento é a soma dos dois elementos acima dele
                //                elemento a esquerda      elemento a direita
            }
        }
    }

    return resultado; // retorna o triangulo completo
    free(returnColumnSizes); // Free na memoria
}