#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cad_func(int pos)
{
    printf("\nUsuario: ");
    fflush(stdin);
    gets(funcionario[pos].user);
    printf("\nSenha: ");
    fflush(stdin);
    gets(funcionario[pos].senha);
    printf("\nTelefone (apenas numeros): ");
    fflush(stdin);
    gets(funcionario[pos].telefone);
    printf("\nEmail: ");
    fflush(stdin);
    gets(funcionario[pos].email);
    funcionario[pos].cod = rand() % 30001;
    printf("\nCPF: ");
    fflush(stdin);
    gets(funcionario[pos].CPF);
    printf("\nRG: ");
    fflush(stdin);
    gets(funcionario[pos].RG);
}

void mostrar_funcionarios()
{
    int i;
    for (i = 0; i < cadastrados; i++)
    {
        printf("\n====%i====\nUsuario: %s", i, funcionario[i].user);
        printf("\nSenha: %s", funcionario[i].senha);
        printf("\nTelefone (apenas numeros): %s", funcionario[i].telefone);
        printf("\nEmail:  %s", funcionario[i].email);
        printf("\nCodigo: %i", funcionario[i].cod);
        printf("\nCPF: %s", funcionario[i].CPF);
        printf("\nRG: %s", funcionario[i].RG);
    }
}

void menu_funcionarios()
{
    do
    {
        int opc, cod, i, removeu = 0;
        f aux;
        printf("\n==========\n");
        printf("[1] ADICIONAR FUNCIONARIO\n");
        printf("[2] REMOVER FUNCIONARIO\n");
        printf("[3] LISTAR FUNCIONARIOS\n");
        printf("[4] SAIR\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            if (cadastrados == 0)
            {
                funcionario = (f *)malloc(sizeof(f));
                cad_func(0);
            }
            else
            {
                funcionario = (f *)realloc(funcionario, (cadastrados + 1) * sizeof(f));
                cad_func(cadastrados);
            }
            cadastrados++;
            break;
        case 2:
            if (cadastrados == 0)
            {
                printf("\nNao ha funcionarios cadastrados!");
                break;

            }
            printf("\nCodigo do funcionario:");
            scanf("%i", &cod);
            for (i = 0; i < cadastrados; i++)
            {
                if (funcionario[i].cod == cod)
                {
                    aux = funcionario[cadastrados - 1];
                    funcionario[cadastrados - 1] = funcionario[i];
                    funcionario[i] = aux;
                    funcionario = (f *)realloc(funcionario, (cadastrados - 1) * sizeof(f));
                    cadastrados--;
                    removeu = 1;
                    break;
                }
            }
            if (!removeu)
            {
                printf("\nFuncionario não encontrado.");
            }
            else
            {
                printf("\nFuncionario removido com sucesso!");
            }
            break;
        case 3:
            if (cadastrados == 0)
            {
                printf("\nNao ha funcionarios cadastrados!");
                break;
            }
            mostrar_funcionarios();
            break;
        case 4:
            system("cls");
            return;
        default:
            printf("\nOpcao Invalida!");
        }
    }
    while(1);

}


void menu_sistema()
{
    do
    {
        int opc, cod, i, removeu = 0;
        f aux;
        printf("\n======SISTEMA======\n");
        printf("[1] GERENCIAR PRODUTOS\n");
        printf("[2] VENDA\n");
        printf("[3] RELATORIOS\n");
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
                //system("cls");
                //menu_estoque();
                printf("\nMENU - ESTOQUE\n");

            }
            else
            {
                system("cls");
                printf("Permissao Negada!");
            }
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            system("cls");
            return;
        default:
            printf("\nOpcao Invalida!");
        }
    }
    while(1);

}



#endif // FUNCOES_H_INCLUDED
