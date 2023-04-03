#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//LÊ OS DADOS DE CADASTRO DE UM NOVO USUÁRIO
void cad_func(int pos, char user[])
{
    char cpf[100], telefone[100];
    strcpy(funcionario[pos].user, user);
    do
    {
        printf("\nTelefone (apenas numeros): ");
        fflush(stdin);
        gets(telefone);
        printf("\nCPF (apenas numeros): ");
        fflush(stdin);
        gets(cpf);
        if ((strlen(cpf) != 11) || (strlen(telefone) != 11))
        {
            system("cls");
            printf("Favor inserir corretamente os dados!");
        }
        else
        {
            break;
        }
    }
    while (1);

    printf("\nSenha: ");
    fflush(stdin);
    gets(funcionario[pos].senha);

    printf("\nEmail: ");
    fflush(stdin);
    gets(funcionario[pos].email);
    funcionario[pos].cod = rand() % 30001;
    printf("\nNome do funcionario: ");
    fflush(stdin);
    gets(funcionario[pos].nome);
    funcionario[pos].vendas_func = 0;
    system("cls");
}


//LÊ OS DADOS DE CADASTRO DE UM NOVO PRODUTO
void cad_produto(int pos)
{
    produto[pos].qtd = 0;
    produto[pos].vendas = 0;
    produto[pos].cod = rand() % 30001;
    printf("\nNome do produto: ");
    fflush(stdin);
    gets(produto[pos].nome);
    printf("\nEstado do produto: ");
    fflush(stdin);
    gets(produto[pos].estado);
    printf("\nTipo: ");
    fflush(stdin);
    gets(produto[pos].tipo);
    printf("\nPreco: ");
    scanf("%f", &produto[pos].preco);
    system("cls");
}


//MOSTRA OS PRODUTOS CADASTRADOS
void mostrar_produtos()
{
    int i;
    for (i = 0; i < prod_cadastrados; i++)
    {
        printf("\n============%i============\nNome: %s", i, produto[i].nome);
        printf("\nQuantidade: %i", produto[i].qtd);
        printf("\nEstado: %s", produto[i].estado);
        printf("\nQuantidade vendida: %i", produto[i].vendas);
        printf("\nCodigo: %i", produto[i].cod);
        printf("\nPreco: R$ %.2f", produto[i].preco);
        printf("\nTipo: %s", produto[i].tipo);
    }
}

//MOSTRA O REGISTRO DE VENDAS FEITAS
void mostrar_vendas()
{
    int i;
    for (i = 0; i < num_vendas; i++)
    {
        printf("\n=========================\nProduto: %s", vendas[i].produto);
        printf("\nCodigo: %i", vendas[i].cod_produto);
        printf("\nForma de pagamento: %s", vendas[i].forma_pgmt);
        printf("\nQuantidade: %i", vendas[i].qtd);
        printf("\nFuncionario: %s", vendas[i].nome_func);
        printf("\nCod. Funcionario: %i", vendas[i].cod_func);
        printf("\nValor do produto: R$ %.2f", vendas[i].valor_prod);
        printf("\nValor total: R$ %.2f", vendas[i].valor_total);
    }
}


//MOSTRA OS FUNCIONARIOS CADASTRADOS
void mostrar_funcionarios()
{
    int i;
    for (i = 0; i < cadastrados; i++)
    {
        printf("\n============%i============\nUsername: %s", i, funcionario[i].user);
        printf("\nSenha: %s", funcionario[i].senha);
        printf("\nNome do funcionario: %s", funcionario[i].nome);
        printf("\nTelefone : %s", funcionario[i].telefone);
        printf("\nEmail:  %s", funcionario[i].email);
        printf("\nCodigo: %i", funcionario[i].cod);
        printf("\nCPF: %s", funcionario[i].CPF);
    }
}

//MENU DA ÁREA DE FUNCIONÁRIOS
void menu_funcionarios()
{
    do
    {
        int opc, cod, i, removeu = 0, invalido = 0;
        char user[50];
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
            //SE NÃO HOUVER FUNCIONÁRIOS CADASTRADOS, ALOCA MEMÓRIA E LÊ OS DADOS DE CADASTRO
            if (cadastrados == 0)
            {
                funcionario = (f *)malloc(sizeof(f));
                system("cls");
                printf("Username do funcionario:");
                fflush(stdin);
                gets(user);
                cad_func(0, user);
            }
            else
            {
                //SE JÁ HOUVEREM FUNCIONÁRIOS CADASTRADOS, VERIFICA O USERNAME DIGITADO PARA QUE NÃO
                //HAJAM USERNAMES REPETIDOS, AFINAL AS VENDAS SERÃO ASSOCIADAS AO USERNAME QUE FEZ LOGIN
                system("cls");
                printf("Username do funcionario:");
                fflush(stdin);
                gets(user);
                for (i = 0; i < cadastrados; i++)
                {
                    if (!(strcmp(user, funcionario[i].user)))//SE O USERNAME FOR REPETIDO, AVISA E PEDE PARA ESCOLHER OUTRO
                    {
                        system("cls");
                        printf("Nome de usuario ja esta em uso. Favor escolher outro!");
                        invalido = 1;
                        break;
                    }
                }
                if (invalido)
                {
                    break;
                }
                //SE O USERNAME FOR VÁLIDO, REALOCA MEMÓRIA E LÊ OS DADOS DE CADASTRO
                funcionario = (f *)realloc(funcionario, (cadastrados + 1) * sizeof(f));
                cad_func(cadastrados, user);
            }
            cadastrados++;//CONTROLE DE FUNCIONÁRIOS CADASTRADOS
            system("cls");
            break;
        case 2:
            if (cadastrados == 0)//SE NÃO HOUVER FUNCIONÁRIOS CADASTRADOS, AVISA E VOLTA AO MENU
            {
                system("cls");
                printf("Nao ha funcionarios cadastrados!");
                break;
            }
            system("cls");
            printf("Codigo do funcionario:");
            scanf("%i", &cod);
            //ENCONTRA O FUNCIONÁRIO NO SISTEMA
            for (i = 0; i < cadastrados; i++)
            {
                if (funcionario[i].cod == cod)//SE ENCONTROU, REALIZA O PROCESSO DE REMOÇÃO
                {

                    aux = funcionario[cadastrados - 1];//JOGA O ÚLTIMO FUNCIONÁRIO CADASTRADO PARA UMA AUXILIAR
                    funcionario[cadastrados - 1] = funcionario[i];//JOGA O FUNCIONÁRIO A SER REMOVIDO PARA A ÚLTIMA POSIÇÃO
                    funcionario[i] = aux;//AUXILIAR VAI PARA O LOCAL ONDE ESTAVA O QUE SERÁ REMOVIDO
                    funcionario = (f *)realloc(funcionario, (cadastrados - 1) * sizeof(f));//REALOCA MEMÓRIA, REMOVENDO A ÚLTIMA POSIÇÃO
                    cadastrados--;
                    removeu = 1;
                    break;
                }
            }
            if (!removeu)
            {
                system("cls");
                printf("Funcionario nao encontrado.");//AVISA CASO NÃO SEJA ENCONTRADO O CÓDIGO NO SISTEMA
            }
            else
            {
                system("cls");
                printf("Funcionario removido com sucesso!");//AVISA SE A REMOÇÃO FOI BEM SUCEDIDA
            }
            break;
        case 3:
            if (cadastrados == 0)//SE NÃO HOUVER FUNCIONÁRIOS CADASTRADOS, AVISA E VOLTA AO MENU
            {
                system("cls");
                printf("Nao ha funcionarios cadastrados!");
                break;
            }
            system("cls");
            mostrar_funcionarios();
            break;
        case 4:
            system("cls");
            return;
        default:
            system("cls");
            printf("Opcao Invalida!");
        }
    }
    while (1);
}


//MENU DE GERÊNCIA DOS PRODUTOS
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
            if (prod_cadastrados == 0)//SE NÃO HOUVER PRODUTOS CADASTRADOS, ALOCA UMA POSIÇÃO E LÊ OS DADOS DO PRODUTO
            {
                produto = (p *)malloc(sizeof(p));
                system("cls");
                cad_produto(0);
            }
            else //HOUVER PRODUTOS CADASTRADOS, REALOCA ADICIONANDO UMA POSIÇÃO E LÊ OS DADOS DO PRODUTO
            {
                produto = (p *)realloc(produto, (prod_cadastrados + 1) * sizeof(p));
                system("cls");
                cad_produto(prod_cadastrados);
            }
            prod_cadastrados++;
            system("cls");
            break;
        case 2:
            if (prod_cadastrados == 0)//SE NÃO HOUVER PRODUTOS CADASTRADOS, AVISA E RETORNA AO MENU
            {
                system("cls");
                printf("Nao ha produtos cadastrados!");
                break;
            }
            system("cls");
            printf("Codigo do produto:");
            scanf("%i", &cod);
            printf("Quantidade:");
            scanf("%i", &qtd);
            //PROCURA O PRODUTO NO SISTEMA
            for (i = 0; i < prod_cadastrados; i++)
            {
                if (produto[i].cod == cod) //SE ENCONTROU, ADICIONA A QUANTIDADE AO ESTOQUE
                {
                    produto[i].qtd += qtd;
                    adicionado = 1;
                    break;
                }
            }
            system("cls");
            if (adicionado)//AVISA ADICIONOU O PRODUTO OU SE NÃO ENCONTROU NO SISTEMA
            {
                printf("Quantidade adicionada no estoque.");
            }
            else
            {
                printf("Produto nao encontrado!");
            }
            break;
        case 3:
            if (prod_cadastrados == 0)//SE NÃO HOUVER PRODUTOS CADASTRADOS, AVISA E RETORNA AO MENU
            {
                system("cls");
                printf("Nao ha produtos cadastrados!");
                break;
            }
            system("cls");
            printf("Codigo do produto:");
            scanf("%i", &cod);
            //AQUI É O MESMO PROCESSO FEITO PARA REMOVER O CADASTRO DOS FUNCIONÁRIOS DO SISTEMA
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

            if (!removeu)//AVISA SE REMOVEU OU SE NÃO ENCONTROU O PRODUTO NO SISTEMA
            {
                printf("Produto nao encontrado.");
            }
            else
            {
                printf("Produto removido com sucesso!");
            }
            break;
        case 4:
            if (prod_cadastrados == 0)//SE NÃO HOUVER PRODUTOS CADASTRADOS, AVISA E RETORNA AO MENU
            {
                system("cls");
                printf("Nao ha produtos cadastrados!");
                break;
            }
            system("cls");
            mostrar_produtos();
            break;
        case 5:
            system("cls");
            return;
        default:
            system("cls");
            printf("Opcao Invalida!");
        }
    }
    while (1);
}

//FUNÇÃO PARA ADICIONAR A VENDA NO REGISTRO DE VENDAS FEITAS
void concluir_venda(char forma_pgmt[], int pos, int qtd, int A_VISTA)
{
    int i;
    if (num_vendas == 0)//SE AINDA NÃO HOUVER VENDAS, SERÁ ALOCADA UMA POSIÇÃO DE MEMÓRIA
    {
        for (i = 0; i < cadastrados; i++)
        {
            if (!(strcmp(funcionario[i].user, loginuser)))//VERIFICA QUAL É O FUNCIONÁRIO QUE FEZ LOGIN
            {
                vendas = (v *)malloc(sizeof(v));
                //ADICIONA OS DADOS NA STRUCT VENDAS
                strcpy(vendas[num_vendas].produto, produto[pos].nome);
                strcpy(vendas[num_vendas].forma_pgmt, forma_pgmt);
                vendas[num_vendas].cod_produto = produto[pos].cod;
                vendas[num_vendas].qtd = qtd;
                strcpy(vendas[num_vendas].nome_func, funcionario[i].nome);
                vendas[num_vendas].cod_func = funcionario[i].cod;
                vendas[num_vendas].valor_prod = produto[pos].preco;
                if (A_VISTA) //SE FOR A VISTA, DESCONTA 10% DO VALOR FINAL
                {
                    vendas[num_vendas].valor_total = (produto[pos].preco * qtd) - (produto[pos].preco * qtd)*0.10;
                }
                else
                {
                    vendas[num_vendas].valor_total = produto[pos].preco * qtd;
                }
                //ATUALIZA OS DADOS DE CONTROLE
                num_vendas++;
                funcionario[i].vendas_func++;
                produto[pos].vendas += qtd;
                produto[pos].qtd -= qtd;
                system("cls");
                //CONFIRMA A VENDA NA TELA
                printf("VENDA REALIZADA COM SUCESSO\n");
                return;
            }
        }
    }
    else //AQUI É A MESMA COISA, PORÉM É REALOCADA A MEMÓRIA PARA ADICIONAR MAIS UMA POSIÇÃO NA STRUCT VENDAS
    {
        for (i = 0; i < cadastrados; i++)
        {
            if (!(strcmp(funcionario[i].user, loginuser)))
            {
                vendas = (v *)realloc(vendas, (num_vendas + 1) * sizeof(v));
                strcpy(vendas[num_vendas].produto, produto[pos].nome);
                strcpy(vendas[num_vendas].forma_pgmt, forma_pgmt);
                vendas[num_vendas].cod_produto = produto[pos].cod;
                vendas[num_vendas].qtd = qtd;
                strcpy(vendas[num_vendas].nome_func, funcionario[i].nome);
                vendas[num_vendas].cod_func = funcionario[i].cod;
                vendas[num_vendas].valor_prod = produto[pos].preco;
                if (A_VISTA)
                {
                    vendas[num_vendas].valor_total = (produto[pos].preco * qtd) - (produto[pos].preco * qtd)*0.10;
                }
                else
                {
                    vendas[num_vendas].valor_total = produto[pos].preco * qtd;
                }
                num_vendas++;
                funcionario[i].vendas_func++;
                produto[pos].vendas += qtd;
                produto[pos].qtd -= qtd;
                system("cls");
                printf("VENDA REALIZADA COM SUCESSO\n");
                return;
            }
        }
    }
}

//MENU DE VENDA
void menu_venda()
{
    if (prod_cadastrados == 0)//SE NÃO HOUVER PRODUTOS CADASTRADOS NÃO PERMITE A VENDA
    {
        system("cls");
        printf("Nenhum produto cadastrado no sistema!");
        return;
    }
    int cod, i, encontrou = 0, opc, pos, qtdv;
    printf("\nCodigo do produto (-1 para sair):");
    scanf("%i", &cod);
    if (cod == -1)//SE DIGITAR -1 SAI DA VENDA
    {
        system("cls");
        return;
    }
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
        system("cls");
        printf("Quantidade:");
        scanf("%i", &qtdv);

        if ((produto[pos].qtd < qtdv) || (qtdv < 1))//VERIFICA SE A QUANTIDADE EXISTE EM ESTOQUE OU SE ELA É VÁLIDA
        {
            system("cls");
            printf("Quantidade invalida ou insuficiente em estoque!");
            menu_venda();
            return;
        }
        do
        {
            //FORMAS DE PAGAMENTO
            system("cls");
            printf("=====FORMA DE PAGAMENTO=====\n");
            printf("[1] A VISTA\n");
            printf("[2] A PRAZO\n");
            printf("[3] CANCELAR VENDA\n");
            scanf("%i", &opc);
            switch (opc)
            {
            case 1:
                system("cls");
                printf("[1] PIX\n");
                printf("[2] CARTAO (CREDITO/DEBITO)\n");
                printf("[3] DINHEIRO\n");
                printf("[4] CANCELAR VENDA\n");
                scanf("%i", &opc);
                switch (opc)
                {
                case 1:
                    system("cls");
                    concluir_venda("A VISTA - PIX", pos, qtdv, 1);
                    return;
                case 2:
                    system("cls");
                    concluir_venda("A VISTA - CARTAO", pos, qtdv, 1);
                    return;
                case 3:
                    system("cls");
                    concluir_venda("A VISTA - DINHEIRO", pos, qtdv, 1);
                    return;
                case 4:
                    system("cls");
                    return;
                default:
                    system("cls");
                    printf("Opcao Invalida!");
                    break;
                }
                break;
            case 2:
                system("cls");
                printf("[1] CARTAO DE CREDITO\n");
                printf("[2] BOLETO\n");
                printf("[3] CANCELAR VENDA\n");
                scanf("%i", &opc);
                switch (opc)
                {
                case 1:
                    system("cls");
                    concluir_venda("A PRAZO - CARTAO DE CREDITO", pos, qtdv, 0);
                    return;
                case 2:
                    system("cls");
                    concluir_venda("A PRAZO - BOLETO", pos, qtdv, 0);
                    return;
                case 3:
                    system("cls");
                    return;
                default:
                    system("cls");
                    printf("\nOpcao Invalida!");
                    break;
                }
                break;
            case 3:
                system("cls");
                return;
            default:
                system("cls");
                printf("Opcao Invalida!");
                break;
            }
        }
        while (1);

    }
    else
    {
        system("cls");
        printf("Produto nao encontrado!");
        menu_venda();
        return;
    }
};

//MENU DE RELATÓRIOS
void menu_relatorios()
{
    do
    {
        int opc, cod, cod_produto, mais_vendido, menos_vendido, mais_vendas, menos_vendas, encontrou = 0, pos, i;
        float caro, barato, soma = 0;
        printf("\n========RELATORIOS========\n");
        printf("[1] VENDAS POR FUNCIONARIO\n");
        printf("[2] VENDAS POR PRODUTO\n");
        printf("[3] INFORMACOES GERAIS\n");
        printf("[4] REGISTRO DE VENDAS FEITAS\n");
        printf("[5] SAIR\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            system("cls");
            printf("Codigo do funcionario: ");
            scanf("%i", &cod);
            for (i = 0; i < cadastrados; i++)
            {
                if (funcionario[i].cod == cod)
                {
                    encontrou = 1;
                    pos = i;
                    break;
                }
            }
            if(!encontrou)
            {
                system("cls");
                printf("Funcionario nao encontrado!\n");
                menu_relatorios();
                return;
            }
            system("cls");
            //QUANTIDADE DE VENDAS QUE O FUNCIONÁRIO FEZ
            printf("Nome do funcionario: %s", funcionario[pos].nome);
            printf("\nCodigo do funcionario: %i", funcionario[pos].cod);
            printf("\nVendas feitas: %i", funcionario[pos].vendas_func);
            break;
        case 2:
            system("cls");
            printf("Codigo do produto: ");
            scanf("%i", &cod_produto);
            for (i = 0; i < prod_cadastrados; i++)
            {
                if (produto[i].cod == cod_produto)
                {
                    encontrou = 1;
                    pos = i;
                    break;

                }
            }
            if (!encontrou)
            {
                system("cls");
                printf("Produto nao encontrado!\n");
                menu_relatorios();
                return;
            }
            system("cls");
            //QUANTIDADE QUE FOI VENDIDA DO PRODUTO
            printf("Nome do produto: %s", produto[pos].nome);
            printf("\nCodigo do produto: %i", produto[pos].cod);
            printf("\nQuantia vendida: %i", produto[pos].vendas);
            break;
        case 3:
            system("cls");
            //ENCONTRA OS PRODUTO MAIS VENDIDO E O MENOS VENDIDO
            mais_vendido = produto[0].vendas;
            menos_vendido = produto[0].vendas;
            for (i = 1; i < prod_cadastrados; i++)
            {
                if (produto[i].vendas > mais_vendido)
                {
                    mais_vendido = produto[i].vendas;
                }
            }
            for (i = 1; i < prod_cadastrados; i++)
            {
                if (produto[i].vendas < menos_vendido)
                {
                    menos_vendido = produto[i].vendas;
                }
            }
            printf("\n===========================================");

            for (i = 0; i < prod_cadastrados; i++)
            {
                if (produto[i].vendas == mais_vendido)
                {

                    printf("\nProduto mais vendido: %s", produto[i].nome);
                    printf("\nCodigo do produto: %i", produto[i].cod);
                    printf("\nQuantidade vendida: %i", produto[i].vendas);
                }

            }

            printf("\n=======================");

            for (i = 0; i < prod_cadastrados; i++)
            {
                if (produto[i].vendas == menos_vendido)
                {
                    printf("\nProduto menos vendido: %s", produto[i].nome);
                    printf("\nCodigo do produto: %i", produto[i].cod);
                    printf("\nQuantidade vendida: %i", produto[i].vendas);
                }
            }


            //ENCONTRA O PRODUTO MAIS CARO E O MAIS BARATO
            caro = produto[0].preco;
            barato = produto[0].preco;

            for (i = 1; i < prod_cadastrados; i++)
            {
                if (produto[i].preco > caro)
                {
                    caro = produto[i].preco;
                }
            }
            for (i = 1; i < prod_cadastrados; i++)
            {
                if (produto[i].preco < barato)
                {
                    barato = produto[i].preco;
                }
            }
            printf("\n=======================");

            for (i = 0; i < prod_cadastrados; i++)
            {
                if (produto[i].preco == caro)
                {
                    printf("\nProduto mais caro: %s", produto[i].nome);
                    printf("\nCodigo do produto: %i", produto[i].cod);
                    printf("\nPreco do produto: R$ %.2f", produto[i].preco);
                }
            }

            printf("\n=======================");

            for (i = 0; i < prod_cadastrados; i++)
            {
                if (produto[i].preco == barato)
                {
                    printf("\nProduto mais barato: %s", produto[i].nome);
                    printf("\nCodigo do produto: %i", produto[i].cod);
                    printf("\nPreco do produto: R$ %.2f", produto[i].preco);
                }
            }
            printf("\n=======================");


            //ENCONTRA O FUNCIONÁRIO COM MAIOR E MENOR NÚMERO DE VENDAS
            mais_vendas = funcionario[0].vendas_func;
            menos_vendas = funcionario[0].vendas_func;
            for (i = 1; i < cadastrados; i++)
            {
                if (funcionario[i].vendas_func > mais_vendas)
                {
                    mais_vendas = funcionario[i].vendas_func;
                }
            }
            for (i = 1; i < cadastrados; i++)
            {
                if (funcionario[i].vendas_func < menos_vendas)
                {
                    menos_vendas = funcionario[i].vendas_func;
                }
            }

            for (i = 0; i < cadastrados; i++)
            {
                if (funcionario[i].vendas_func == mais_vendas)
                {
                    printf("\nFuncionario com mais vendas: %s", funcionario[i].nome);
                    printf("\nCodigo do funcionario: %i", funcionario[i].cod);
                    printf("\nVendas feitas: %i", funcionario[i].vendas_func);
                }
            }

            printf("\n=======================");

            for (i = 0; i < cadastrados; i++)
            {
                if (funcionario[i].vendas_func == menos_vendas)
                {
                    printf("\nFuncionario com menos vendas: %s", funcionario[i].nome);
                    printf("\nCodigo do funcionario: %i", funcionario[i].cod);
                    printf("\nVendas feitas: %i", funcionario[i].vendas_func);
                }
            }

            //FAZ A MÉDIA DO PREÇO DOS PRODUTOS
            for (i = 0; i < prod_cadastrados; i++)
            {
                soma+=produto[i].preco;
            }
            printf("\n=======================");
            printf("\nMedia do preco dos produtos: R$ %.2f", (soma/prod_cadastrados));
            printf("\n===========================================\n");
            break;
        case 4:
            system("cls");
            mostrar_vendas();
            break;
        case 5:
            system("cls");
            return;
        default:
            system("cls");
            printf("Opcao Invalida!");
            break;
        }
    }
    while (1);
}

//MENU ONDE O FUNCIONÁRIO PODE REALIZAR VENDAS
void menu_sistema()
{
    do
    {
        int opc;
        printf("\n========SISTEMA========\n");
        printf("[1] VENDER\n");
        printf("[2] SAIR\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            system("cls");
            menu_venda();
            break;
        case 2:
            system("cls");
            return;
        default:
            system("cls");
            printf("Opcao Invalida!");
            break;
        }
    }
    while (1);
}

#endif // FUNCOES_H_INCLUDED
