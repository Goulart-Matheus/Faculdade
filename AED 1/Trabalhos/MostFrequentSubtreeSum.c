/*
    ---- COMPLEXIDADE ----

    Função calculateSums

        A função percorre todos os nós da árvore uma vez, pois cada nó chama a função recursivamente para seus filhos.
        Como cada nó é visitado apenas uma vez, a recursão sozinha tem complexidade O(n), onde n é o número de nós da árvore.

        Dentro dessa função, há um laço for que percorre freqMap, cujo tamanho é freqSize.
        No pior caso, cada soma pode ser única, fazendo com que freqSize chegue a O(n).
        Isso significa que o laço pode rodar O(n) vezes em cada chamada recursiva.

        Como esse laço for está dentro da recursão, cada chamada pode executar uma busca linear de O(n), resultando em uma complexidade total de O(n²) no pior cenário.

    Loops para encontrar a frequência máxima e coletar os valores mais frequentes

        Após calcular as somas, há dois loops que percorrem freqMap, que pode ter no máximo n elementos.
        Ambos os loops têm complexidade O(n), pois percorrem uma estrutura de tamanho no máximo n.

    Conclusão

        O código é dominado pela busca linear dentro da função recursiva calculateSums, tornando sua complexidade O(n²) no pior caso.
*/

// Definição da estrutura da árvore binária
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Struct para armazenar a frequência das somas
typedef struct {
    int sum; // Soma da subárvore
    int tot; // Quantidade de vezes que essa soma aparece
} SumFreq;

// Para cada nó, a função calcula a soma da subárvore enraizada nele
int calculateSums(struct TreeNode* root, SumFreq* freqMap, int* freqSize) { 
    // freqMap = Conta quantas vezes cada soma da subárvore aparece
    // freqSize = Quantidade de elementos no freqMap

    if (!root) return 0;  // Se o nó for nulo, retorna 0
    
    int leftSum = calculateSums(root->left, freqMap, freqSize);   // Calcula a soma do filho esquerdo
    int rightSum = calculateSums(root->right, freqMap, freqSize); // Calcula a soma do filho direito
    int totalSum = root->val + leftSum + rightSum;                // Soma total da subárvore
    
    // Verifica se a soma já existe no freqMap
    for (int i = 0; i < *freqSize; i++) {
        if (freqMap[i].sum == totalSum) {   // Se a soma já foi registrada
            freqMap[i].tot++;               // Incrementa a contagem da frequência dessa soma
            return totalSum;                // Retorna a soma da subárvore
        }
    }
    
    // Se não existir, adiciona a soma no freqMap
    freqMap[*freqSize].sum = totalSum; // Armazena a nova soma calculada
    freqMap[*freqSize].tot = 1;        // Inicializa a contagem dessa soma com 1
    (*freqSize)++; // Adiciona uma nova soma no freqMap e aumenta o contador de elementos distintos
    
    return totalSum; // Retorna a soma da subárvore
}

// Encontra a(s) soma(s) de subárvore(s) mais frequente(s) na árvore
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    
    if (!root) {
        *returnSize = 0;  // Se a árvore for vazia, retorna tamanho 0
        return 0;       // Retorna NULL, pois não há somas
    }

    SumFreq* freqMap = (SumFreq*)malloc(10000 * sizeof(SumFreq)); // Aloca memória para armazenar as somas e suas frequências
    int freqSize = 0; // Inicializa o tamanho do freqMap

    calculateSums(root, freqMap, &freqSize); // Calcula todas as somas das subárvores e armazena no freqMap

    // Encontra a maior frequência entre todas as somas calculadas
    int maxFreq = 0;
    for (int i = 0; i < freqSize; i++) {
        if (freqMap[i].tot > maxFreq) { // Se encontrar uma frequência maior, atualiza maxFreq
            maxFreq = freqMap[i].tot;
        }
    }
    
    // Armazena todas as somas que aparecem com a maior frequência
    int* result = (int*)malloc(freqSize * sizeof(int)); // Aloca memória para armazenar as somas mais frequentes
    *returnSize = 0;
    for (int i = 0; i < freqSize; i++) {
        if (freqMap[i].tot == maxFreq) { // Se a soma tem a maior frequência, adiciona ao resultado
            result[(*returnSize)++] = freqMap[i].sum;
        }
    }

    free(freqMap);
    return result; // Retorna o array com as somas mais frequentes
}
