#include <stdio.h>
#include <string.h>

typedef struct endereco {
  char nomeRua[15];
  int numero;
  int cep;
} Endereco;  

typedef struct cliente {
  int cod;
  char nome[10];
  Endereco end;
} Cliente;  

typedef struct dvd {
  int cod;
  char titulo[10];
  int ano;
  int status;
} Dvd;  

typedef struct locacao {
  Cliente *cli;
  Dvd *dvd;
  int cod;
  int duracao;
  float valor;
  float total;
} Locacao;  

char clientesPreGerados[10][100] = {"Rodrigo", "Rafael", "Gabriel", "Fernando", "Paulo"};
int posicaoValoresPreGeradosClientes = 0;
char dvdsPreGerados[10][100] = {"Gladiador", "Avatar", "Alien", "Tubarão", "Titanic"};
int posicaoValoresPreGeradosDvds = 0;

Cliente cadastraCliente();
void mostraCliente(Cliente cliente);
Dvd cadastraDvd();
void mostraDvd(Dvd dvd);

int main()
{
  Cliente cliente = cadastraCliente();
  mostraCliente(cliente);
  Dvd dvd = cadastraDvd();
  mostraDvd(dvd);
}

Cliente cadastraCliente()
{
  Cliente cliente;
  cliente.cod = posicaoValoresPreGeradosClientes;
  strcpy(cliente.nome, clientesPreGerados[posicaoValoresPreGeradosClientes]);
  posicaoValoresPreGeradosClientes++;

  return cliente;
}

void mostraCliente(Cliente cliente)
{
  printf("********** Cliente **********\n");
  printf("Código: %d\n", cliente.cod);
  printf("Nome: %s\n", cliente.nome);
}

Dvd cadastraDvd()
{
  Dvd dvd;
  dvd.cod = posicaoValoresPreGeradosDvds;
  strcpy(dvd.titulo, dvdsPreGerados[posicaoValoresPreGeradosDvds]);
  dvd.ano = 2000 + posicaoValoresPreGeradosDvds;
  dvd.status = 0;
  posicaoValoresPreGeradosDvds++;

  return dvd;
}

void mostraDvd(Dvd dvd)
{
  printf("********** DVD **********\n");
  printf("Código: %d\n", dvd.cod);
  printf("Título: %s\n", dvd.titulo);
  printf("Ano de lançamento: %d\n", dvd.ano);
  printf("Status: %s\n", dvd.status == 0 ? "disponível" : "alugado" );
}