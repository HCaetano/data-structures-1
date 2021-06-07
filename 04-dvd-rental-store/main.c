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

char enderecosPreGerados[5][40] = 
{
  "Avenida Pelotas",
  "Rua Ulysses Guimarães",
  "Avenida Roberto Socowski",
  "Travessa Pereira Lima",
  "Rua Irmão Oliva"
};
int posicaoEnderecosPreGerados = 0;
int cepsPreGerados[5] = {96214251, 96214154, 96214789, 96214963, 96214357};
int posicaoCepsPreGerados = 0;
char clientesPreGerados[5][20] = {"Isadora", "Maria", "Gabriel", "Fernando", "Paulo"};
int posicaoClientesPreGerados = 0;
char dvdsPreGerados[5][20] = {"Gladiador", "Avatar", "Alien", "Tubarão", "Titanic"};
int posicaoDvsPreGerados = 0;
int posicaoLocacoesPreGeradas = 0;

Endereco cadastraEndereco();
void mostraEndereco(Endereco endereco);
Cliente cadastraCliente();
void mostraCliente(Cliente cliente);
Dvd cadastraDvd();
void mostraDvd(Dvd dvd);
Locacao cadastraLocacao(Cliente *cliente, Dvd *dvdRecebido);
void mostraLocacao(Locacao Locacao);

int main()
{
  Endereco endereco = cadastraEndereco();
  mostraEndereco(endereco);
  Cliente cliente = cadastraCliente(&endereco);
  mostraCliente(cliente);
  Dvd dvd = cadastraDvd();
  mostraDvd(dvd);
  Locacao locacao = cadastraLocacao(&cliente, &dvd);
  mostraLocacao(locacao);
}

Endereco cadastraEndereco()
{
  Endereco endereco;
  endereco.numero = posicaoEnderecosPreGerados;
  endereco.cep = cepsPreGerados[posicaoCepsPreGerados];
  strcpy(endereco.nomeRua, enderecosPreGerados[posicaoEnderecosPreGerados]);
  posicaoEnderecosPreGerados++;

  return endereco;
}

void mostraEndereco(Endereco endereco)
{
  printf("********** Endereco **********\n");
  printf("Nome da rua: %s\n", endereco.nomeRua);
  printf("Número da residência: %d\n", endereco.numero);
  printf("CEP: %d\n", endereco.cep);
}

Cliente cadastraCliente(Endereco *endereco)
{
  Cliente cliente;
  cliente.cod = posicaoClientesPreGerados;
  strcpy(cliente.nome, clientesPreGerados[posicaoClientesPreGerados]);
  cliente.end = *endereco;
  posicaoClientesPreGerados++;

  return cliente;
}

void mostraCliente(Cliente cliente)
{
  printf("********** Cliente **********\n");
  printf("Código: %d\n", cliente.cod);
  printf("Nome: %s\n", cliente.nome);
  mostraEndereco(cliente.end);
}

Dvd cadastraDvd()
{
  Dvd dvd;
  dvd.cod = posicaoDvsPreGerados;
  strcpy(dvd.titulo, dvdsPreGerados[posicaoDvsPreGerados]);
  dvd.ano = 2000 + posicaoDvsPreGerados;
  dvd.status = 0;
  posicaoDvsPreGerados++;

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

Locacao cadastraLocacao(Cliente *cliente, Dvd *dvdRecebido)
{
  Locacao locacao;
  locacao.cli = cliente; 
  locacao.dvd = dvdRecebido; 
  locacao.cod = posicaoLocacoesPreGeradas;
  locacao.duracao = 2 + posicaoLocacoesPreGeradas;
  locacao.valor = (2.22 + posicaoLocacoesPreGeradas) * 1.00;
  locacao.total = locacao.valor * locacao.duracao;
  posicaoLocacoesPreGeradas++;

  return locacao;
}

void mostraLocacao(Locacao locacao)
{
  printf("********** Locacao **********\n");
  printf("Código: %d\n", locacao.cod);
  printf("Duração (em dias): %d\n", locacao.duracao);
  printf("Diária: %.2f\n", locacao.valor);
  printf("Custo por %d dias: %.2f\n", locacao.duracao, locacao.total);
  mostraCliente(*locacao.cli);
  mostraDvd(*locacao.dvd);
}
