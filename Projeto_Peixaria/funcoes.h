#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cad_func(int pos) {
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

void cad_produto(int pos) {
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
}

void mostrar_produtos() {
  int i;
  for (i = 0; i < prod_cadastrados; i++) {
    printf("\n====%i====\nNome: %s", i, produto[i].nome);
    printf("\nQuantidade: %i", produto[i].qtd);
    printf("\nEstado: %s", produto[i].estado);
    printf("\nLocal de origem:  %s", produto[i].local);
    printf("\nCodigo: %i", produto[i].cod);
    printf("\nPreco: R$ %f", produto[i].preco);
    printf("\nTipo: %s", produto[i].tipo);
  }
}

void mostrar_funcionarios() {
  int i;
  for (i = 0; i < cadastrados; i++) {
    printf("\n====%i====\nUsuario: %s", i, funcionario[i].user);
    printf("\nSenha: %s", funcionario[i].senha);
    printf("\nTelefone : %s", funcionario[i].telefone);
    printf("\nEmail:  %s", funcionario[i].email);
    printf("\nCodigo: %i", funcionario[i].cod);
    printf("\nCPF: %s", funcionario[i].CPF);
    printf("\nRG: %s", funcionario[i].RG);
  }
}

void menu_funcionarios() {
  do {
    int opc, cod, i, removeu = 0;
    f aux;
    printf("\n====GERENCIAR FUNCIONARIOS====\n");
    printf("[1] ADICIONAR FUNCIONARIO\n");
    printf("[2] REMOVER FUNCIONARIO\n");
    printf("[3] LISTAR FUNCIONARIOS\n");
    printf("[4] SAIR\n");
    scanf("%i", &opc);
    switch (opc) {
    case 1:
      if (cadastrados == 0) {
        funcionario = (f *)malloc(sizeof(f));
        cad_func(0);
      } else {
        funcionario = (f *)realloc(funcionario, (cadastrados + 1) * sizeof(f));
        cad_func(cadastrados);
      }
      cadastrados++;
      system("cls");
      break;
    case 2:
      if (cadastrados == 0) {
        printf("\nNao ha funcionarios cadastrados!");
        break;
      }
      printf("\nCodigo do funcionario:");
      scanf("%i", &cod);
      for (i = 0; i < cadastrados; i++) {
        if (funcionario[i].cod == cod) {
          aux = funcionario[cadastrados - 1];
          funcionario[cadastrados - 1] = funcionario[i];
          funcionario[i] = aux;
          funcionario =
              (f *)realloc(funcionario, (cadastrados - 1) * sizeof(f));
          cadastrados--;
          removeu = 1;
          break;
        }
      }
      if (!removeu) {
        printf("\nFuncionario nao encontrado.");
      } else {
        printf("\nFuncionario removido com sucesso!");
      }
      break;
    case 3:
      if (cadastrados == 0) {
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
  } while (1);
}

void menu_estoque() {
  do {
    int opc, cod, i, removeu = 0, qtd, adicionado = 0;
    p aux;
    printf("\n========MENU ESTOQUE========\n");
    printf("[1] CADASTRAR PRODUTO\n");
    printf("[2] ADICIONAR PRODUTO NO ESTOQUE\n");
    printf("[3] REMOVER PRODUTO CADASTRADO\n");
    printf("[4] LISTAR PRODUTOS\n");
    printf("[5] SAIR\n");
    scanf("%i", &opc);
    switch (opc) {
    case 1:
      if (prod_cadastrados == 0) {
        produto = (p *)malloc(sizeof(p));
        cad_produto(0);
      } else {
        produto = (p *)realloc(produto, (prod_cadastrados + 1) * sizeof(p));
        cad_produto(prod_cadastrados);
      }
      prod_cadastrados++;
      system("cls");
      break;
    case 2:
      if (prod_cadastrados == 0) {
        system("cls");
        printf("\nNao ha produtos cadastrados!");
        break;
      }
      printf("Codigo do produto:");
      scanf("%i", &cod);
      printf("Quantidade:");
      scanf("%i", &qtd);
      for (i = 0; i < prod_cadastrados; i++) {
        if (produto[i].cod == cod) {
          produto[i].qtd += qtd;
          adicionado = 1;
          break;
        }
      }
      system("cls");
      if (adicionado) {
        printf("\nQuantidade adicionada no estoque.");
      } else {
        printf("\nProduto nao encontrado!");
      }
      break;
    case 3:
      if (prod_cadastrados == 0) {
        system("cls");
        printf("\nNao ha produtos cadastrados!");
        break;
      }
      printf("Codigo do produto:");
      scanf("%i", &cod);
      for (i = 0; i < prod_cadastrados; i++) {
        if (produto[i].cod == cod) {
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

      if (!removeu) {
        printf("\nProduto nao encontrado.");
      } else {
        printf("\nProduto removido com sucesso!");
      }
      break;
    case 4:
      if (prod_cadastrados == 0) {
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
  } while (1);
}

void concluir_venda(char forma_pgmt[50], int pos, int qtd) {
  int i, cod_func, encontrou = 0;
  printf("\nPara confirmar a venda, entre com seu codigo de funcionario (-1 "
         "para sair):");
  scanf("%i", &cod_func);
  if (cod_func == -1) {
    return;
  }
  if (num_vendas == 0) {
    for (i = 0; i < cadastrados; i++) {
      if (funcionario[i].cod == cod_func) {
        vendas = (v *)malloc(sizeof(v));
        strcpy(vendas[num_vendas].produto, produto[pos].nome);
        strcpy(vendas[num_vendas].forma_pgmt, forma_pgmt);
        vendas[num_vendas].cod_produto = produto[pos].cod;
        vendas[num_vendas].qtd = qtd;
        strcpy(vendas[num_vendas].nome_func, funcionario[i].user);
        vendas[num_vendas].cod_func = cod_func;
        vendas[num_vendas].valor_prod = produto[pos].preco;
        vendas[num_vendas].valor_total = produto[pos].preco * qtd;
        encontrou = 1;
        num_vendas++;
        break;
      }
    }
  } else {
    for (i = 0; i < cadastrados; i++) {
      if (funcionario[i].cod == cod_func) {
        vendas = (v *)realloc(vendas, (num_vendas + 1) * sizeof(v));
        strcpy(vendas[num_vendas].produto, produto[pos].nome);
        strcpy(vendas[num_vendas].forma_pgmt, forma_pgmt);
        vendas[num_vendas].cod_produto = produto[pos].cod;
        vendas[num_vendas].qtd = qtd;
        strcpy(vendas[num_vendas].nome_func, funcionario[i].user);
        vendas[num_vendas].cod_func = cod_func;
        vendas[num_vendas].valor_prod = produto[pos].preco;
        vendas[num_vendas].valor_total = produto[pos].preco * qtd;
        encontrou = 1;
        num_vendas++;
        break;
      }
    }
  }
  if (!encontrou) {
    system("cls");
    printf("Codigo nao encontrado no sistema!");
    concluir_venda(forma_pgmt, pos, qtd);
  }
}

void menu_venda() {
  if (prod_cadastrados == 0) {
    system("cls");
    printf("Nenhum produto cadastrado no sistema!");
    return;
  }
  int cod, i, encontrou = 0, opc, pos, qtdv;
  char forma_pgmt[50];
  printf("\n====MENU - VENDA====\n");
  printf("\nCodigo do produto (-1 para sair):");
  scanf("%i", &cod);
  if (cod == -1) {
    return;
  }
  for (i = 0; i < prod_cadastrados; i++) {
    if (produto[i].cod == cod) {
      encontrou = 1;
      pos = i;
      break;
    }
  }
  if (encontrou) {
    printf("\nQuantidade:");
    scanf("%i", &qtdv);

    if (produto[pos].qtd < qtdv) {
      system("cls");
      printf("\nQuantidade insuficiente em estoque!");
      menu_venda();
    }
    do {
      system("cls");
      printf("\n=====FORMA DE PAGAMENTO=====\n");
      printf("[1] A VISTA (10% DE DESCONTO)\n");
      printf("[2] A PRAZO\n");
      printf("[3] CANCELAR VENDA\n");
      scanf("%i", &opc);
      switch (opc) {
      case 1:
        printf("\n[1] PIX\n");
        printf("[2] CARTAO (CREDITO/DEBITO)\n");
        printf("[3] DINHEIRO\n");
        printf("[4] CANCELAR VENDA\n");
        scanf("%i", &opc);
        switch (opc) {
        case 1:
          concluir_venda("PIX", pos, qtdv);
          printf("\nVENDA REALIZADA COM SUCESSO\n");
          produto[pos].vendas += qtdv;
          break;
        case 2:
          concluir_venda("CARTAO", pos, qtdv);
          printf("\nVENDA REALIZADA COM SUCESSO\n");
          produto[pos].vendas += qtdv;
          break;
        case 3:
          concluir_venda("DINHEIRO", pos, qtdv);
          printf("\nVENDA REALIZADA COM SUCESSO\n");
          produto[pos].vendas += qtdv;
          break;
        case 4:
          return;
          break;
        default:
          system("cls");
          printf("\nOpcao Invalida!");
          break;
        }
        break;
      case 2:
        printf("[1] CARTAO DE CREDITO\n");
        printf("[2] BOLETO\n");
        printf("[3] CANCELAR VENDA\n");
        scanf("%i", &opc);
        switch (opc) {
        case 1:
          concluir_venda("CARTAO DE CREDITO", pos, qtdv);
          printf("\nVENDA REALIZADA COM SUCESSO\n");
          produto[pos].vendas += qtdv;
          break;
        case 2:
          concluir_venda("BOLETO", pos, qtdv);
          printf("\nVENDA REALIZADA COM SUCESSO\n");
          produto[pos].vendas += qtdv;
          break;
        case 3:
          return;
          break;
        default:
          system("cls");
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
    } while (1);

  } else {
    system("cls");
    printf("\nProduto nao encontrado!");
    menu_venda();
  }
};

void menu_relatorios() {
  do {
    int opc, cod, cod_produto, vend, mais_vendido, menos_vendido, mais_vendas,
        menos_vendas;
    float caro, barato;
    printf("\n========RELATORIOS========\n");
    printf("[1] VENDAS POR FUNCIONARIO\n");
    printf("[2] VENDAS POR PRODUTO\n");
    printf("[3] INFORMACOES GERAIS\n");
    printf("[4] SAIR\n");
    scanf("%i", &opc);
    switch (opc) {
    case 1:
      printf("\nCodigo do funcionario: ");
      scanf("%i", cod);
      for (i = 0; i < cadastrados;
           i++) { // pega a quantia de vendas de um funcionario
        if (vendas[i].cod_func == cod) {
          encontrou = 1;
          pos = i;
          vend++;
          break;
        }
      }
      else {
        printf("\nFuncionario nao encontrado!\n");
        menu_relatorios();
      }
      printf("\nNome do funcionario: %s",
             vendas[pos].nome_func); // printa o nome, o codigo e a quantia de
                                     // vendas desse funcionario
      printf("\nCodigo do funcionario: %i", vendas[pos].cod_func);
      printf("\nQuantia vendida: %i", vend);
      break;
    case 2:
      printf("\nCodigo do produto: ");
      scanf("%i", cod_produto);
      for (i = 0; i < prod_cadastrados;
           i++) { // pega a quantia de vendas de um produto
        if (produto[i].cod == cod_produto) {
          encontrou = 1;
          pos = i;
          break;
        } else {
          printf("\nProduto nao encontrado!\n");
          menu_relatorios();
        }
      }
      printf("\nNome do produto: %s",
             produto[pos].nome); // printa o nome, o codigo e a quantia de
                                 // vendas desse produto
      printf("\nCodigo do produto: %i", produto[pos].cod);
      printf("\nQuantia vendida: %i", produto[pos].vendas);
      break;
    case 3:
      // produto maximo e minimo
      mais_vendido = produto[0].vendas;
      menos_vendido = produto[0].vendas;
      for (i = 1; i < prod_cadastrados; i++) { // pega o produto mais vendido
        if (produto[i].vendas > mais_vendido) {
          pos = i;
          mais_vendido = produto[pos].vendas;
          break;
        }
      }
      for (i = 1; i < prod_cadastrados; i++) {
        if (produto[i].vendas < menos_vendido) { // pega o produto menos vendido
          pos = i;
          menos_vendido = produto[pos].vendas;
          break;
        }
      }
      for (i = 1; i < prod_cadastrados; i++) {
        if (produto[i].vendas == mais_vendido) { // printa o produto mais
                                                 // vendido
          pos = i;
          printf("\nProduto mais vendido: %s", produto[pos].nome);
          printf("\nCodigo do produto: %i", produto[pos].cod);
          printf("\nQuantidade vendida: %i", produto[pos].vendas);
          break;
        }
      }
      for (i = 1; i < prod_cadastrados; i++) {
        if (produto[i].vendas ==
            menos_vendido) { // printa o produto menos vendido
          pos = i;
          printf("\nProduto menos vendido: %s", produto[pos].nome);
          printf("\nCodigo do produto: %i", produto[pos].cod);
          printf("\nQuantidade vendida: %i", produto[pos].vendas);
          break;
        }
      }
      // produto mais caro e mais barato
      caro = produto[0].preco;
      barato = produto[0].preco;
      for (i = 1; i < prod_cadastrados; i++) { // pega o produto mais caro
        if (produto[i].preco > caro) {
          pos = i;
          caro = produto[pos].preco;
          break;
        }
      }
      for (i = 1; i < prod_cadastrados; i++) { // pega o produto mais barato
        if (produto[i].preco < barato) {
          pos = i;
          barato = produto[pos].preco;
          break;
        }
      }
      for (i = 1; i < prod_cadastrados; i++) { // printa o produto mais caro
        if (produto[i].preco == caro) {
          pos = i;
          printf("\nProduto mais caro: %s", produto[pos].nome);
          printf("\nCodigo do produto: %i", produto[pos].cod);
          printf("\nPreco do produto: %f", produto[pos].vendas);
          break;
        }
      }
      for (i = 1; i < prod_cadastrados; i++) { // printa o produto mais barato
        if (produto[i].preco == barato) {
          pos = i;
          printf("\nProduto menos vendido: %s", produto[pos].nome);
          printf("\nCodigo do produto: %i", produto[pos].cod);
          printf("\nQuantidade vendida: %f", produto[pos].preco);
          break;
        }
      }
      // media de preco
      // funcionario com maior numero de vendas

      break;
    case 4:
      system("cls");
      return;
    default:
      printf("\nOpcao Invalida!");
    }
  } while (1);
}

void menu_sistema() {
  do {
    int opc;
    printf("\n========SISTEMA========\n");
    printf("[1] VENDA\n");
    printf("[2] RELATORIOS\n");
    printf("[3] SAIR\n");
    scanf("%i", &opc);
    switch (opc) {
    case 1:
      menu_venda();
      break;
    case 2:
      printf("\n===MENU - RELATORIOS===\n");
      break;
    case 3:
      system("cls");
      return;
    default:
      printf("\nOpcao Invalida!");
    }
  } while (1);
}

#endif // FUNCOES_H_INCLUDED
