#include <stdio.h>
#include <stdlib.h>

int opc, cadastrados = 0;

struct func
{
    char user[100];
    char senha[100];
    char telefone[12];
    char email[100];
    int cod;
    char CPF[12];
    char RG[10];
};


typedef struct func f;
f *funcionario, aux;


int main()
{
    do
    {
        printf("\n=====SOFTWARE GERENCIA DE PEIXARIA=====\n");
        printf("[1] CADASTRO DE FUNCIONARIO\n");
        printf("[2] LOGIN NO SISTEMA\n");
        printf("[3] SAIR\n");
        switch (opc)
        {
        case 1:
            if (cadastrados == 0)
            {
                funcionario = (f*)malloc(sizeof(f));
                printf("\nUsuario: ");
                fflush(stdin);
                gets(funcionario[0].user);
                printf("\nSenha: ");
                fflush(stdin);
                gets(funcionario[0].senha);
                printf("\nTelefone (apenas numeros): ");
                fflush(stdin);
                gets(funcionario[0].user);
                printf("\nEmail: ");
                fflush(stdin);
                gets(funcionario[0].user);
                //USAR RANDINT PRA GERAR CODIGO
                printf("\nUsuario: ");
                fflush(stdin);
                gets(funcionario[0].user);
                printf("\nUsuario: ");
                fflush(stdin);
                gets(funcionario[0].user);


            } else {
                funcionario = (f*)realloc(funcionario, (cadastrados+1)*sizeof(f));
            }
            cadastrados++;
            break;
        case 2:
            if (cadastrados == 0)
            {
                printf("\nNenhum usuario cadastrado.");
                break;
            }
            break;
        case 3:
            return 0;
        default:
            printf("\nOpcao Invalida!");
        }
    }
    while(1);


}
