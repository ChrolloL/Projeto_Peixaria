#ifndef VARIAVEIS_H_INCLUDED
#define VARIAVEIS_H_INCLUDED

struct venda
{
    char produto[100];
    char forma_pgmt[15];
    int qtd;
    char nome_func[100];
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
    float preco;
    char tipo[50];
};

typedef struct prod p;
typedef struct func f;
typedef struct venda v;

int opc, i, login_valido = 0, cadastrados = 0, prod_cadastrados = 0;
char loginuser[100], loginsenha[100], loginADM[] = "admin", senhaADM[] = "coxinha123";

f *funcionario;
p *produto;
v *vendas;


#endif // VARIAVEIS_H_INCLUDED
