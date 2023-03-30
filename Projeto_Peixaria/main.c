#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"
#include "funcoes.h"

int main()
{
    do
    {
        printf("\n=====GERENCIA DE PEIXARIA=====\n");
        printf("[1] GERENCIAR FUNCIONARIOS\n");
        printf("[2] GERENCIAR PRODUTOS\n");
        printf("[3] LOGIN NO SISTEMA\n");
        printf("[4] SAIR\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            system("cls");
            printf("\n==PERMISSAO DE ADMIN NECESSARIA==");
            printf("\nLogin:");
            fflush(stdin);
            gets(loginuser);
            printf("\nSenha:");
            fflush(stdin);
            gets(loginsenha);
            if (!(strcmp(loginADM, loginuser)) &&
                    !(strcmp(senhaADM, loginsenha)))
            {
                system("cls");
                menu_funcionarios();
            }
            else
            {
                system("cls");
                printf("Permissao Negada!");
            }
            break;
        case 2:
            system("cls");
            printf("\n==PERMISSAO DE ADMIN NECESSARIA==");
            printf("\nLogin:");
            fflush(stdin);
            gets(loginuser);
            printf("\nSenha:");
            fflush(stdin);
            gets(loginsenha);
            if (!(strcmp(loginADM, loginuser)) &&
                    !(strcmp(senhaADM, loginsenha)))
            {
                system("cls");
                menu_estoque();
            }
            else
            {
                system("cls");
                printf("Permissao Negada!");
            }
            break;
        case 3:
            login_valido = 0;
            if (cadastrados == 0)
            {
                system("cls");
                printf("\nNenhum usuario cadastrado.");
                break;
            }
            else
            {
                system("cls");
                printf("Digite o nome de usuario: ");
                fflush(stdin);
                gets(loginuser);
                printf("\nDigite a senha: ");
                fflush(stdin);
                gets(loginsenha);
                for (i = 0; i < cadastrados; i++)
                {
                    if (!(strcmp(funcionario[i].user, loginuser)) &&
                            !(strcmp(funcionario[i].senha, loginsenha)))
                    {
                        login_valido = 1;
                        system("cls");
                        menu_sistema();
                        break;
                    }
                }
                if (!login_valido)
                {
                    printf("User ou senha invalida");
                }
            }
            break;

        case 4:
            return 0;
        default:
            printf("\nOpcao Invalida!");
        }
    }
    while (1);
    free(funcionario);
    free(produto);
    free(vendas);
}

