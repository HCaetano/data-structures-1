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

Cliente cadastraCliente();
void mostraCliente(Cliente cliente);

int main()
{
  Cliente cliente = cadastraCliente();
  mostraCliente(cliente);
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
  printf("********************************************\n");
  printf("Código: %d\n", cliente.cod);
  printf("Nome: %s\n", cliente.nome);
}