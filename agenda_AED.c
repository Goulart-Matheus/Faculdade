#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    return 0;
}