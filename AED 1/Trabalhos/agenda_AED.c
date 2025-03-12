#include <stdio.h>
#include <string.h>
#include <stdlib.h>

<<<<<<< HEAD
int main(void)
{
void *pBuffer = malloc(
sizeof(int) + //option
sizeof(int) + //flag
(50 * sizeof(char)) +  //nomeTemp
(sizeof(int)) + //tempIdade
(100 * sizeof(char)) + //search
(50 * sizeof(char)) + //emailTemp
(100 * sizeof(char)) //var
); 

if(pBuffer == NULL) // Teste se a alocação deu certo
{
    printf("Erro na Alocacao");
}

//Criação dos ponteiros para Apontar pra cada dado no pbuffer

void *option = pBuffer; // Aponta pro inicio do pbuffer
void *flag = option + sizeof(int); //Aponta pro inicio de flag
void *nomeTemp = (char *)flag + sizeof(int); //Aponta pro inicio de nomeTemp
void *idadeTemp = (char *)nomeTemp + (50 * sizeof(char)); //Aponta pro inicio de idadeTemp
void *emailTemp = (char *)idadeTemp + sizeof(int); //Aponta pro inicio de emailTemp
void *search = (char *)emailTemp + (50 * sizeof(char)); //Aponta pro inicio de search
void *var = (char *)search + (100 * sizeof(char)); //Aponta pro inicio de var
void *cont = var; //ponteiro pro inicio de var que vai atualizando sempre pro ultimo caracter

 for (;;)
    {

        printf("1) Adicionar (Nome, Idade, E-mail)\n 2) Remover \n 3) search \n 4) Listar Todos \n 5) Sair \n");
        scanf("%d", (int *)option);

        switch (*(int *)option) {


        case 1:
                    printf("Nome: ");
                    scanf("%s",(char *)nomeTemp); //  Informação armazenada na variavel temporaria

                    printf("Idade: ");
                    scanf("%d", (int *)idadeTemp); //  Informação armazenada na variavel temporaria

                    printf("Email: ");
                    scanf("%s", (char *)emailTemp); //  Informação armazenada na variavel temporaria

                    // Calculo o novo tamanho necessário para o buffer
                    pBuffer = realloc(pBuffer, (cont - pBuffer) + strlen((char *)nomeTemp) + 1 + sizeof(int) + strlen((char *)emailTemp) + 1);

                    if(pBuffer == NULL)
                        {
                            printf("Erro na Alocacao");
                        }

                    // coptionio os var para o buffer realocado
                    memcpy(cont, nomeTemp, strlen((char *)nomeTemp) + 1); // coptionio o nome para meu pBuffer
                    cont = (char *)cont + strlen((char *)nomeTemp) + 1; // muda o cont para o proximo lugar disponivel

                    memcpy(cont, idadeTemp, sizeof(int)); // coptionio a idade
                    cont = (char *)cont + sizeof(int); // muda o cont

                    memcpy(cont, emailTemp, strlen((char *)emailTemp) + 1); // coptionio o email
                    cont = (char *)cont + strlen((char *)emailTemp) + 1; // movo o cont

                    printf("Cadastro Realizado!\n");

                    break;
        case 2:
                {
                    printf("Nome que deseja excluir: ");
                    scanf("%s", (char *)search);

                    void *imprime = (char *)var; // Recebe o primeiro nome de pBuffer
                    void *inicio = NULL;      // Posição inicial para excluir
                    void *fim = NULL;         // Posição final para excluir
                                            

                    while ((char *)imprime < (char *)cont) { //Enquanto posição inicial < posição final

                        if (strcmp((char *)imprime, (char *)search) == 0)//Busca o nome
                        {
                            inicio = imprime;  //Posição inicial do item encontrado

                            *(int *)flag = 1; // Liga a flag

                        void *auxiliar = imprime;
                        //nome
                        auxiliar += strlen((char *)auxiliar) + 1; //imprime a posição do nome
                        //idade
                        auxiliar += sizeof(char) * sizeof(int); //imprime a posição da idade
                        //email
                        auxiliar += strlen((char *)auxiliar) + 1; //imprime a posição do email

                        fim = auxiliar; //Indica o final do cadastro

                        memmove(imprime, auxiliar, (char *)cont - (char *)auxiliar); 
                        //Imprime o auxiliar com a quantidade de bytes, resultado pelo numero total - final de cada da pessoa lida

                        pBuffer = realloc(pBuffer, (char *)cont - (char *)pBuffer);
                        // realloc para diminuir o espaço do pBuffer 

                        cont = (char *)inicio + ((char *)cont - (char *)fim);
                        // valor do cont para apontar para o novo final 

                        if(pBuffer == NULL)
                        {
                            printf("Erro na alocação de memoria\n");
                            exit(1);
                        }

                        printf("Excluido com sucesso\n");
                        
                        }else{
                        imprime += strlen((char *)imprime) + 1 + sizeof(int) + strlen((char *)imprime) + 1; 
                        //Enquanto não achar continua procurando o cadastro até achar o correto

                        }
                    }

                if(*(int *)flag == 1){
                        printf("============================\n");
                    }else{
                        printf("Cadastro nao encontrado\n");
                    }

                }   
                break;
        case 3:
                {
        
                    printf("Digite o nome do cadastro que deseja procurar: ");
                    scanf("%s", (char *)search);

                    void *imprime = (char *)var;  // Imprime recebe o primeiro nome do pBuffer
                    while ((char *)imprime < (char *)cont) { //posição inicial do pBuffer < posição final do pBuffer

                        if(strcmp((char *)imprime, (char *)search) == 0)
                        {
                        
                        printf("Nome: %s\n", (char *)imprime); // Imprime o nome do cadastro
                        imprime += strlen((char *)imprime) + 1; //++ o imprime com a posição do nome

                        
                        printf("Idade: %d\n", *(int *)(char *)imprime); // Imprime a idade
                        imprime += sizeof(int); //++ o imprime com o posição da idade

                        
                        printf("Email: %s\n", (char *)imprime); // Imprime o email
                        imprime += strlen((char *)imprime) + 1; //++ o imprime com a posição do email


                        *(int *)flag = 1; //se o nome foi lido, liga a flag
                        
                        }
                        else{
                        imprime += strlen((char *)imprime) + 1 + sizeof(int) + strlen((char *)imprime) + 1; 
                        // enquanto nao achar continua percorrendo o cadastro até achar o correto

                        }
                    }
                    if(*(int *)flag == 1){
                        printf("============================\n");
                    }else{
                        printf("Cadastro nao encontrado\n");
                    }
                }
                break;
        case 4:
                    {
                    void *imprime = (char *)var;  // imprime recebe o primeiro nome de pBuffer

                    if((char *)imprime == (char *)cont){
                        printf("============================\n");
                        printf("Nao existem pessoas cadastradas\n");
                        printf("============================\n");
                    }


                    while ((char *)imprime < (char *)cont) { //Enquanto a posição inicial do pBuffer < posição final do pBuffer
                        
                        printf("Nome: %s\n", (char *)imprime); // Imprime o nome
                        imprime += strlen((char *)imprime) + 1; //++ o imprime com o posição do nome

                        
                        printf("Idade: %d\n", *(int *)(char *)imprime); // Imprime a idade
                        imprime += sizeof(int); //++ o imprime com o posição da idade

                        
                        printf("Email: %s\n", (char *)imprime); // Imprime o email
                        imprime += strlen((char *)imprime) + 1; //++ o imprime com o posição do email

                        printf("============================\n");
                    }

                }
                break;
        case 5:
            {
                    free(pBuffer);
                    printf("Sucesso ao Finalizar o Programa");
                    exit(0);
            }
        }
}
=======
/*
======================================================================================================
Projeto - Agenda AED

Nome: Matheus Goulart
Curso: Ciência da Computação - UFPEL

======================================================================================================
*/

int main(void) {
    // Aloca um buffer de memória de 312 bytes
    void *Buffer = malloc(312);

    // Verifica se a alocação de memória foi bem-sucedida
    if (Buffer == NULL) {
        printf("Erro na alocação");
        exit(1);
    }

    // Ponteiros para cada dado dentro do Buffer
    int *opera = (int *)Buffer; // Ponteiro para a operação a ser realizada
    int *flag = (int *)((char *)Buffer + sizeof(int)); // Ponteiro para a flag de status
    char *nomeTemp = (char *)flag + sizeof(int); // Ponteiro para o nome temporário
    int *idadeTemp = (int *)(nomeTemp + 50); // Ponteiro para a idade temporária
    char *emailTemp = (char *)idadeTemp + sizeof(int); // Ponteiro para o email temporário
    char *procura = emailTemp + 50; // Ponteiro para o nome a ser procurado
    char *info = procura + 100; // Ponteiro para a área de armazenamento de informações
    char *contador = info; // Ponteiro para controlar o fim da área de informações

    // Inicializa as variáveis
    *opera = 0; // Inicializa a operação com 0
    *flag = 0; // Inicializa a flag com 0
    memset(nomeTemp, 0, 50); // Limpa o buffer do nome temporário
    *idadeTemp = 0; // Inicializa a idade temporária com 0
    memset(emailTemp, 0, 50); // Limpa o buffer do email temporário
    memset(procura, 0, 100); // Limpa o buffer de procura
    memset(info, 0, 100); // Limpa o buffer de informações

    // Loop infinito para o menu de opções
    for (;;) {
        // Exibe o menu de opções
        printf("1- Adicionar Pessoa (Nome, Idade, Email)\n");
        printf("2- Remover Pessoa\n");
        printf("3- Procurar Pessoa\n");
        printf("4- Listar todos\n");
        printf("5- Sair\n");

        *flag = 0; // Reinicializa a flag

        // Lê a operação escolhida pelo usuário
        scanf("%3d", opera);

        // Switch para tratar a operação escolhida
        switch (*opera) {
            case 1: { // Adicionar pessoa
                printf("Escreva o Nome: ");
                scanf("%49s", nomeTemp); // Lê o nome

                printf("Escreva a Idade: ");
                scanf("%d", idadeTemp); // Lê a idade
                getchar(); // Limpa o buffer do teclado

                printf("Escreva seu Email: ");
                scanf("%49s", emailTemp); // Lê o email

                // Calcula o novo fim do buffer para realocar memória
                void *novoFim = (char *)contador
                    + strlen(nomeTemp) + 1 // Tamanho do nome + terminador nulo
                    + sizeof(int) // Tamanho da idade
                    + strlen(emailTemp) + 1; // Tamanho do email + terminador nulo

                // Realoca o buffer para o novo tamanho
                void *novoperaBuffer = realloc(Buffer, (char *)novoFim - (char *)Buffer);

                // Verifica se a realocação foi bem-sucedida
                if (novoperaBuffer == NULL) {
                    printf("Erro na alocação de memória\n");
                    exit(1);
                } else {
                    // Atualiza o contador para o novo buffer
                    contador = (char *)novoperaBuffer + ((char *)contador - (char *)Buffer);
                    Buffer = novoperaBuffer; // Atualiza o buffer
                }

                // Atualiza os ponteiros para o novo buffer
                opera = (int *)Buffer;
                flag = (int *)((char *)Buffer + sizeof(int));
                nomeTemp = (char *)flag + sizeof(int);
                idadeTemp = (int *)(nomeTemp + 50);
                emailTemp = (char *)idadeTemp + sizeof(int);
                procura = emailTemp + 50;
                info = procura + 100;

                // Copia os novos dados para a área realocada
                memcpy(contador, nomeTemp, strlen(nomeTemp) + 1); // Copia o nome
                contador += strlen(nomeTemp) + 1;

                memcpy(contador, idadeTemp, sizeof(int)); // Copia a idade
                contador += sizeof(int);

                memcpy(contador, emailTemp, strlen(emailTemp) + 1); // Copia o email
                contador += strlen(emailTemp) + 1;

                printf("Cadastro adicionado!\n");

                break;
            }

            case 2: { // Remover pessoa
                printf("Qual nome deseja excluir? ");
                scanf("%99s", procura); // Lê o nome a ser excluído

                char *imprime = info; // Ponteiro para percorrer as informações
                void *fim = NULL;

                // Percorre as informações até encontrar o nome
                while ((char *)imprime < (char *)contador) {
                    if (strcmp(imprime, procura) == 0) { // Compara os nomes
                        printf("Cadastro Encontrado! \n");

                        *flag = 1; // Sinaliza que o nome foi encontrado

                        void *auxiliar = NULL;
                        auxiliar = imprime; // Auxiliar aponta para o início do nome
                        auxiliar += strlen((char *)auxiliar) + 1; // Avança para o campo da idade
                        auxiliar += 4; // Avança para o campo do email
                        auxiliar += strlen((char *)auxiliar) + 1; // Avança para o próximo registro

                        fim = auxiliar; // Fim aponta para o início do próximo registro

                        // Move os dados para remover o registro
                        memmove(imprime, fim, (char *)contador - (char *)fim);

                        // Atualiza o contador para o novo tamanho do buffer
                        contador = (char *)contador - ((char *)fim - (char *)imprime);

                        // Realoca o buffer para o novo tamanho
                        void *novoperaBuffer = realloc(Buffer, (char *)contador - (char *)Buffer);

                        if (novoperaBuffer == NULL) {
                            printf("Erro na alocaçao de memória\n");
                            exit(1);
                        }

                        Buffer = novoperaBuffer; // Atualiza o buffer

                        // Atualiza os ponteiros para o novo buffer
                        opera = (int *)Buffer;
                        flag = (int *)((char *)Buffer + sizeof(int));
                        nomeTemp = (char *)flag + sizeof(int);
                        idadeTemp = (int *)(nomeTemp + 50);
                        emailTemp = (char *)idadeTemp + sizeof(int);
                        procura = emailTemp + 50;
                        info = procura + 100;

                        if (contador == info) {
                            contador = info; // Atualiza o contador se necessário
                        }

                        printf("Registro excluído!\n");

                        break;
                    } else {
                        // Avança para o próximo registro
                        imprime += strlen((char *)imprime) + 1; // Avança para o próximo campo (nome)
                        imprime += sizeof(int); // Avança para o próximo campo (idade)
                        imprime += strlen((char *)imprime) + 1; // Avança para o próximo campo (email)
                    }
                }

                if (*flag == 1) {
                    printf("==================================\n");
                } else {
                    printf("==================================\n");
                    printf("Nome não encontrado!\n");
                    printf("==================================\n");
                }

                break;
            }

            case 3: { // Procurar pessoa
                printf("Qual nome deseja procurar? \n");
                scanf("%99s", procura); // Lê o nome a ser procurado

                char *imprime = info; // Ponteiro para percorrer as informações

                // Percorre as informações até encontrar o nome
                while ((char *)imprime < (char *)contador) {
                    if (strcmp(imprime, procura) == 0) { // Compara os nomes
                        printf("Cadastro Encontrado! \n \n");

                        printf("Nome: %s\n", (char *)imprime);
                        imprime += strlen((char *)imprime) + 1; // Avança para o campo da idade

                        printf("Idade: %d\n", *(int *)(char *)imprime);
                        imprime += 4; // Avança para o campo do email

                        printf("Email: %s\n", (char *)imprime);
                        imprime += strlen((char *)imprime) + 1; // Avança para o próximo registro

                        *flag = 1; // Sinaliza que o nome foi encontrado
                    } else {
                        // Avança para o próximo registro
                        imprime += strlen((char *)imprime) + 1; // Avança para o próximo campo (nome)
                        imprime += sizeof(int); // Avança para o próximo campo (idade)
                        imprime += strlen((char *)imprime) + 1; // Avança para o próximo campo (email)
                    }
                }

                if (*flag == 1) { // se foi encontrado termina a formatação, do contrario printa que não foi encontrado
                    printf("==================================\n");
                } else {
                    printf("==================================\n");
                    printf("Nome não encontrado\n");
                    printf("==================================\n");
                }

                break;
            }

            case 4: { // Listar todas as pessoas
                char *imprime = info; // Ponteiro para percorrer as informações

                // Verifica se há pessoas cadastradas
                if (imprime == contador || *imprime == '\0') {
                    printf("==================================\n");
                    printf("Não existem cadastros\n");
                    printf("==================================\n");
                    break;
                }

                // Percorre e exibe todas as pessoas cadastradas
                while (imprime < contador) {
                    printf("Nome: %s\n", (char *)imprime);
                    imprime += strlen((char *)imprime) + 1; // Avança para o campo da idade

                    printf("Idade: %d\n", *(int *)imprime);
                    imprime += sizeof(int); // Avança para o campo do email

                    printf("Email: %s\n", (char *)imprime);
                    imprime += strlen((char *)imprime) + 1; // Avança para o próximo registro

                    printf("==================================\n");
                }

                break;
            }

            case 5: { // Sair do programa
                free(Buffer); // Libera a memória alocada
                printf("Programa Finalizada");
                exit(0);
        }
    }

>>>>>>> 4c9082184d619e402bd6528b62ae160e673a0ef4
    return 0;
}