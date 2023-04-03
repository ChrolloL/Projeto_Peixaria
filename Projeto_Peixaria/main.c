#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"
#include "funcoes.h"

int main()
{
    do

    {
//      MENU INICIAL DO PROGRAMA
        printf("\n=====GERENCIA DE PEIXARIA=====\n");
        printf("[1] GERENCIAR FUNCIONARIOS\n");
        printf("[2] GERENCIAR PRODUTOS\n");
        printf("[3] RELATORIOS\n");
        printf("[4] LOGIN NO SISTEMA\n");
        printf("[5] SAIR\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
//          RESTRINGE ACESSO PARA O MENU DE FUNCIONÁRIOS APENAS AO ADM
            system("cls");
            printf("\n==PERMISSAO DE ADMIN NECESSARIA==");
            printf("\nLogin:");
            fflush(stdin);
            gets(loginuser);
            printf("\nSenha:");
            fflush(stdin);
            gets(loginsenha);
            if (!(strcmp(loginADM, loginuser)) &&
                    !(strcmp(senhaADM, loginsenha)))//SE LOGIN E SENHA ESTIVEREM CORRETOS, ACESSA O MENU DE FUNCIONARIOS
            {
                system("cls");
                menu_funcionarios();
            }
            else//LOGIN E SENHA INCORRETOS, BLOQUEIA O ACESSO
            {
                system("cls");
                printf("Permissao Negada!");
            }
            break;
        case 2:
        //RESTRINGE ACESSO PARA O MENU DE PRODUTOS APENAS AO ADM

            system("cls");
            printf("\n==PERMISSAO DE ADMIN NECESSARIA==");
            printf("\nLogin:");
            fflush(stdin);
            gets(loginuser);
            printf("\nSenha:");
            fflush(stdin);
            gets(loginsenha);
            if (!(strcmp(loginADM, loginuser)) &&
                    !(strcmp(senhaADM, loginsenha)))//SE LOGIN E SENHA ESTIVEREM CORRETOS, ACESSA O MENU DE PRODUTOS
            {
                system("cls");
                menu_estoque();
            }
            else//LOGIN E SENHA INCORRETOS, BLOQUEIA O ACESSO
            {
                system("cls");
                printf("Permissao Negada!");
            }
            break;
        case 3:
//        ESTABELECEMOS O MÍNIMO DE 5 VENDAS PARA GERAR RELATORIOS
            system("cls");
            if (num_vendas < 5)//MENOS DE 5 VENDAS, NÃO ACESSA O MENU DE RELATORIOS
            {
                printf("Realize no minimo 5 vendas para gerar relatorios.");
                break;
            }
            menu_relatorios();
            break;
        case 4:

            login_valido = 0;
            if (cadastrados == 0)//BLOQUEIA SE NÃO HOUVER USUARIOS CADASTRADOS
            {
                system("cls");
                printf("Nenhum usuario cadastrado.");
                break;
            }
            else
            {
            //VALIDA O USERNAME E SENHA DO FUNCIONARIO
                system("cls");
                printf("Username: ");
                fflush(stdin);
                gets(loginuser);
                printf("\nSenha: ");
                fflush(stdin);
                gets(loginsenha);
                for (i = 0; i < cadastrados; i++)
                {
                    if (!(strcmp(funcionario[i].user, loginuser)) &&
                            !(strcmp(funcionario[i].senha, loginsenha)))//SE USERNAME E SENHA CORRETOS, ACESSA A ÁREA DE VENDAS
                    {
                        login_valido = 1;
                        system("cls");
                        menu_sistema();
                        break;
                    }
                }
                if (!login_valido)//USERNAME E SENHA INCORRETOS, BLOQUEIA ACESSO
                {
                    system("cls");
                    printf("Username ou senha invalida!");
                }
            }
            break;

        case 5:
            //LIBERA OS ESPAÇOS DE MEMÓRIA E FECHA O PROGRAMA
            free(funcionario);
            free(produto);
            free(vendas);
            return 0;
        default:
            system("cls");
            printf("Opcao Invalida!");
        }
    }
    while (1);
    free(funcionario);
    free(produto);
    free(vendas);
}

