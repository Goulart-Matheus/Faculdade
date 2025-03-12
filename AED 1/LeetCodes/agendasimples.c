#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu(void);
void adicionarNome(char **nome);
void listarNome(char **nome);
void excluirNome(char **nome);

int main()
{
    char *nome = NULL;

    int escolha;
    for (;;)
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            adicionarNome(&nome);
            break;
        case 2:
            excluirNome(&nome);
            break;
        case 3:
            listarNome(&nome);
            break;
        case 4:
            free(nome);
            exit(1);
        }
    }
    return 0;
}
int menu()
{
    int c = 0;
    do
    {
        printf("1) ADICIONAR NOME \n");
        printf("2) REMOVER NOME \n");
        printf("3) LISTAR \n");
        printf("4) SAIR \n");
        scanf("%d", &c);
    } while (c <= 0 || c > 4);
    while (getchar() != '\n')
        ;
    return c;
}

void adicionarNome(char **nome)
{
    char buffer[100];
    char *temp;
    static int primeiro_nome = 1;
    int tamanho_atual;

    printf("Digite o seu nome: ");
    scanf("%s", buffer);

    if (*nome)
    {
        tamanho_atual = strlen(*nome);
    }

    int tamanho_novo = tamanho_atual + strlen(buffer) + (primeiro_nome ? 0 : 1) + 1;

    temp = realloc(*nome, tamanho_novo * sizeof(char));
    if (temp == NULL)
    {
        printf("erro ao alocar memória");
        free(*nome);
        exit(1);
    }
    *nome = temp;

    if (primeiro_nome)
    {
        strcpy(*nome, buffer);
        primeiro_nome = 0;
    }
    else
    {
        strcat(*nome, "\n");
        strcat(*nome, buffer);
    }
    printf("Nome adicionado: \n");
}
void listarNome(char **nome)
{
    printf("Nomes: \n");
    printf("%s \n", *nome);
}

void excluirNome(char **nome)
{
    if (*nome == NULL || **nome == '\0')
    {
        printf("A lista está vazia.\n");
        return;
    }

    char tirar[50];
    printf("Digite o nome a ser excluído: ");
    scanf("%s", tirar);

    char *resultado = strstr(*nome, tirar);
    if (!resultado)
    {
        printf("Nome não encontrado.\n");
        return;
    }

    // Calcula o tamanho atual e o tamanho do nome a ser excluído
    int numsSize = strlen(*nome);
    int numsSize2 = strlen(tirar);

    // Remove o nome deslocando manualmente os caracteres
    int i, j;
    for (i = resultado - *nome + numsSize2, j = resultado - *nome - 1; i <= numsSize; i++, j++)
    {
        (*nome)[j] = (*nome)[i];
    }

    // Redimensiona o array para o tamanho correto
    int novoNum = strlen(*nome) + 1;
    char *temp = realloc(*nome, novoNum);
    if (temp == NULL)
    {
        printf("Erro ao alocar memória.\n");
        free(*nome);
        exit(1);
    }
    *nome = temp;

    printf("Nome removido.\n");
}