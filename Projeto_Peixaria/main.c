#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opc, i, cadastrados = 0, login_valido = 0;
char loginuser[100], loginsenha[100];

f *funcionario;

int main() {
  do {
    printf("\n=====SOFTWARE GERENCIA DE PEIXARIA=====\n");
    printf("[1] GERENCIAR FUNCIONARIOS\n");
    printf("[2] LOGIN NO SISTEMA\n");
    printf("[3] SAIR\n");
    scanf("%i", &opc);
    switch (opc) {
    case 1:
      menu_funcionarios(funcionario, &cadastrados);
      break;
    case 2:
      login_valido = 0;
      if (cadastrados == 0) {
        printf("\nNenhum usuario cadastrado.");
        break;
      } else {
        printf("Digite o nome de usuario: ");
        fflush(stdin);
        gets(loginuser);
        printf("\nDigite a senha: ");
        fflush(stdin);
        gets(loginsenha);

        for (i = 0; i < cadastrados; i++) {
          if (!(strcmp(funcionario[i].user, loginuser)) &&
              !(strcmp(funcionario[i].senha, loginsenha))) {
            // login();
            login_valido = 1;
            printf("\n=====Bem vindo=====\n");
            break;
          }
        }
        if (!login_valido) {
          printf("Email ou senha invalido");
        }
      }
      break;

    case 3:
      return 0;
    default:
      printf("\nOpcao Invalida!");
    }
  } while (1);
  free(funcionario);
}

