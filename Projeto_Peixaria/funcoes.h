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


void cad_produto(int pos)
{
    produto[pos].qtd = 0;
    produto[pos].cod = rand() % 30001;
    printf("\nNome do produto: ");
    fflush(stdin);
    gets(produto[pos].nome);
    printf("\nEstado do produto: ");
    fflush(stdin);
    gets(produto[pos].estado);
    printf("\nLocal de origem: ");
    fflush(stdin);
    gets(produto[pos].local);
    printf("\nTipo: ");
    fflush(stdin);
    gets(produto[pos].tipo);
    printf("\nPreco: ");
    scanf("%f", &produto[pos].preco);
}



void mostrar_produtos()
{
    int i;
    for (i = 0; i < prod_cadastrados; i++)
    {
        printf("\n====%i====\nNome: %s", i, produto[i].nome);
        printf("\nQuantidade: %i", produto[i].qtd);
        printf("\nEstado: %s", produto[i].estado);
        printf("\nLocal de origem:  %s", produto[i].local);
        printf("\nCodigo: %i", produto[i].cod);
        printf("\nPreco: R$ %f", produto[i].preco);
        printf("\nTipo: %s", produto[i].tipo);
    }
}


void mostrar_funcionarios()
{
    int i;
    for (i = 0; i < cadastrados; i++)
    {
        printf("\n====%i====\nUsuario: %s", i, funcionario[i].user);
        printf("\nSenha: %s", funcionario[i].senha);
        printf("\nTelefone : %s", funcionario[i].telefone);
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
        printf("\n====GERENCIAR FUNCIONARIOS====\n");
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
            system("cls");
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
                printf("\nFuncionario nao encontrado.");
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


void menu_estoque()
{
    do
    {
        int opc, cod, i, removeu = 0, qtd, adicionado = 0;
        p aux;
        printf("\n========MENU ESTOQUE========\n");
        printf("[1] CADASTRAR PRODUTO\n");
        printf("[2] ADICIONAR PRODUTO NO ESTOQUE\n");
        printf("[3] REMOVER PRODUTO CADASTRADO\n");
        printf("[4] LISTAR PRODUTOS\n");
        printf("[5] SAIR\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            if (prod_cadastrados == 0)
            {
                produto = (p *)malloc(sizeof(p));
                cad_produto(0);
            }
            else
            {
                produto = (p *)realloc(produto, (prod_cadastrados + 1) * sizeof(p));
                cad_produto(prod_cadastrados);
            }
            prod_cadastrados++;
            system("cls");
            break;
        case 2:
            if (prod_cadastrados == 0)
            {
                system("cls");
                printf("\nNao ha produtos cadastrados!");
                break;
            }
            printf("Codigo do produto:");
            scanf("%i", &cod);
            printf("Quantidade:");
            scanf("%i", &qtd);
            for (i = 0; i < prod_cadastrados; i++)
            {
                if (produto[i].cod == cod)
                {
                    produto[i].qtd+=qtd;
                    adicionado = 1;
                    break;
                }
            }
            system("cls");
            if (adicionado)
            {
                printf("\nQuantidade adicionada no estoque.");
            }
            else
            {
                printf("\nProduto nao encontrado!");
            }
            break;
        case 3:
            if (prod_cadastrados == 0)
            {
                system("cls");
                printf("\nNao ha produtos cadastrados!");
                break;
            }
            printf("Codigo do produto:");
            scanf("%i", &cod);
            for (i = 0; i < prod_cadastrados; i++)
            {
                if (produto[i].cod == cod)
                {
                    aux = produto[prod_cadastrados - 1];
                    produto[prod_cadastrados - 1] = produto[i];
                    produto[i] = aux;
                    produto = (p *)realloc(produto, (prod_cadastrados - 1) * sizeof(p));
                    prod_cadastrados--;
                    removeu = 1;
                    break;
                }
            }

            system("cls");

            if (!removeu)
            {
                printf("\nProduto nao encontrado.");
            }
            else
            {
                printf("\nProduto removido com sucesso!");
            }
            break;
        case 4:
            if (prod_cadastrados == 0)
            {
                system("cls");
                printf("\nNao ha produtos cadastrados!");
                break;
            }
            mostrar_produtos();
            break;
        case 5:
            system("cls");
            return;
        default:
            printf("\nOpcao Invalida!");
        }
    }
    while(1);
}



void menu_venda()
{
    int cod, i, encontrou = 0, opc, pos, qtdv;
    printf("\nCodigo do produto:");
    scanf("%i", &cod);
    for (i = 0; i < prod_cadastrados; i++)
    {
        if (produto[i].cod == cod)
        {
            encontrou = 1;
            pos = i;
            break;
        }
    }
    if (encontrou)
    {
        printf("\nQuantidade:");
        scanf("%i", &qtdv);
        if (produto[pos].qtd < qtdv)
        {
            system("cls");
            printf("\nQuantidade insuficiente em estoque!");
            menu_venda();
        }
        do
        {
            printf("\n=====FORMA DE PAGAMENTO=====\n");
            printf("[1] A VISTA\n");
            printf("[2] A PRAZO\n");
            printf("[3] CANCELAR VENDA\n");
            scanf("%i", &opc);
            switch(opc)
            {
            case 1:

                printf("[1] PIX\n");
                printf("[2] CARTAO (CREDITO/DEBITO)\n");
                printf("[3] DINHEIRO\n");
                scanf("%i", &opc);
                switch(opc)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    printf("\nOpcao Invalida!");
                    break;
                }


                break;
            case 2:
                printf("[1] CARTAO DE CREDITO\n");
                printf("[2] BOLETO\n");
                printf("[3] CARNE\n");
                scanf("%i", &opc);
                switch(opc)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    printf("\nOpcao Invalida!");
                    break;
                }
                break;
            case 3:
                return;
            default:
                printf("\nOpcao Invalida!");
                break;
            }
        }
        while(1);




    }
    else
    {
        printf("\nProduto nao encontrado!");

    }

};




void menu_sistema()
{
    do
    {
        int opc;
        printf("\n========SISTEMA========\n");
        printf("[1] VENDA\n");
        printf("[2] RELATORIOS\n");
        printf("[3] SAIR\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            printf("\nMENU - VENDA\n");
            break;
        case 2:
            printf("\nMENU - RELATORIOS\n");
            break;
        case 3:
            system("cls");
            return;
        default:
            printf("\nOpcao Invalida!");
        }
    }
    while(1);

}



#endif // FUNCOES_H_INCLUDED
