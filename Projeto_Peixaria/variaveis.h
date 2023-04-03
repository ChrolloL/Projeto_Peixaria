#ifndef VARIAVEIS_H_INCLUDED
#define VARIAVEIS_H_INCLUDED


//STRUCT PARA REGISTRO DAS VENDAS FEITAS
struct venda {
  char produto[100];
  int cod_produto;
  char forma_pgmt[50];
  int qtd;
  char nome_func[100];
  int cod_func;
  float valor_prod;
  float valor_total;
};

//STRUCT PARA ARMAZENAR O CADASTRO DE FUNCIONÁRIOS
struct func {
  char user[50];
  char senha[50];
  char telefone[12];
  char email[100];
  int cod;
  char CPF[12];
  char nome[100];
  int vendas_func;
};

//STRUCT PARA ARMAZENAR O CADASTRO DE PRODUTOS
struct prod {
  char nome[100];
  int qtd;
  char estado[30];
  int vendas;
  int cod;
  float preco;
  char tipo[50];
};

//USAMOS TYPEDEF PARA FACILITAR A MANIPULAÇÃO DAS STRUCTS CRIADAS
typedef struct prod p;
typedef struct func f;
typedef struct venda v;

//VARIAVEIS PARA CONTROLE
int opc, i, login_valido = 0, cadastrados = 0, prod_cadastrados = 0, num_vendas = 0;
char loginuser[100], loginsenha[100], loginADM[] = "admin", senhaADM[] = "coxinha123";

//STRUCTS FUNDAMENTAIS DO PROGRAMA
f *funcionario;
p *produto;
v *vendas;

#endif // VARIAVEIS_H_INCLUDED
