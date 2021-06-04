#include <stdio.h>
#include <string.h>

typedef struct endereco {
  int cep;
  int numero;
  char nomeRua[100];
} Endereco;  

typedef struct cliente {
  int cod;
  int numero;
  char nome[100];
} Cliente;  

typedef struct dvd {
  int cod;
  int ano;
  int status;
  char titulo[100];
} Dvd;  

typedef struct locacao {
  Cliente *cli;
  Dvd *dvd;
  int cod;
  int duracao;
  float valor;
  float total;
} Locacao;  

int main()
{
  
}