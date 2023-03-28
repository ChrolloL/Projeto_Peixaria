#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct venda
{
    char produto[100];
    int qtd;
    int cod_func;
    int valor_prod;
    int valor_total;
};

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

struct prod
{
    char nome[100];
    int qtd;
    char estado[30];
    char local[100];
    int cod;
    int preco;
    char tipo[50];
};

typedef struct prod p;
typedef struct func f;
typedef struct venda v;

void cad_func(int pos, f *func)
{
    printf("\nUsuario: ");
    fflush(stdin);
    gets(func[pos].user);
    printf("\nSenha: ");
    fflush(stdin);
    gets(func[pos].senha);
    printf("\nTelefone (apenas numeros): ");
    fflush(stdin);
    gets(func[pos].telefone);
    printf("\nEmail: ");
    fflush(stdin);
    gets(func[pos].email);
    func[pos].cod = rand() % 30001;
    printf("\nCPF: ");
    fflush(stdin);
    gets(func[pos].CPF);
    printf("\nRG: ");
    fflush(stdin);
    gets(func[pos].RG);
}

void mostrar_funcionarios(f *func, int cadastrados)
{
    int i;
    for (i = 0; i < cadastrados; i++)
    {
        printf("\n====%i====\nUsuario: %s", i, func[i].user);
        printf("\nSenha: %s", func[i].senha);
        printf("\nTelefone (apenas numeros): %s", func[i].telefone);
        printf("\nEmail:  %s", func[i].email);
        printf("\nCodigo: %i", func[i].cod);
        printf("\nCPF: %s", func[i].CPF);
        printf("\nRG: %s", func[i].RG);
    }
}

void menu_funcionarios(f *func, int *cadastrados)
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
            if (*cadastrados == 0)
            {
                func = (f *)malloc(sizeof(f));
                cad_func(0, func);
            }
            else
            {
                func = (f *)realloc(func, (*cadastrados + 1) * sizeof(f));
                cad_func(*cadastrados, func);
            }
            (*cadastrados)++;
            break;
        case 2:
            if (*cadastrados == 0)
            {
                printf("\nNao ha funcionarios cadastrados!");
                break;

            }
            printf("\nCodigo do funcionario:");
            scanf("%i", &cod);
            for (i = 0; i < *cadastrados; i++)
            {
                if (func[i].cod == cod)
                {
                    aux = func[*cadastrados - 1];
                    func[*cadastrados - 1] = func[i];
                    func[i] = aux;
                    func = (f *)realloc(func, (*cadastrados - 1) * sizeof(f));
                    (*cadastrados)--;
                    removeu = 1;
                    break;
                }
            }
            if (!removeu)
            {
                printf("\nFuncionario não encontrado.");
            }
            break;
        case 3:
            if (*cadastrados == 0)
            {
                printf("\nNao ha funcionarios cadastrados!");
                break;

            }
            mostrar_funcionarios(func, *cadastrados);
            break;
        case 4:
            return;
        default:
            printf("\nOpcao Invalida!");
        }
    }
    while(1);

}

#endif // FUNCOES_H_INCLUDED
