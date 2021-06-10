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
void mostraLocacoes(Locacao *locacoes, int quantidade);

int main()
{
  Locacao locacoesIsadora[5]; 
  Endereco endereco = cadastraEndereco();
  Endereco endereco2 = cadastraEndereco();
  Endereco endereco3 = cadastraEndereco();
  Cliente isadora = cadastraCliente(endereco);
  Dvd gladiador = cadastraDvd();
  Dvd avatar = cadastraDvd();
  Dvd alien = cadastraDvd();
  Dvd tubarao = cadastraDvd();
  Locacao locacao1 = cadastraLocacao(&isadora, &gladiador);
  locacoesIsadora[0] = locacao1;
  Locacao locacao2 = cadastraLocacao(&isadora, &avatar);
  locacoesIsadora[1] = locacao2;
  Locacao locacao3 = cadastraLocacao(&isadora, &alien);
  locacoesIsadora[2] = locacao3;
  Locacao locacao4 = cadastraLocacao(&isadora, &tubarao);
  locacoesIsadora[3] = locacao4;
  int quantidadeLocacoesIsadora = (sizeof(locacoesIsadora)/sizeof(locacoesIsadora[0])) - 1;
  mostraLocacoes(locacoesIsadora, quantidadeLocacoesIsadora);
}

Endereco cadastraEndereco()
{
  Endereco endereco;
  endereco.numero = posicaoEnderecosPreGerados + 1;
  endereco.cep = cepsPreGerados[posicaoCepsPreGerados];
  strcpy(endereco.nomeRua, enderecosPreGerados[posicaoEnderecosPreGerados]);
  posicaoEnderecosPreGerados++;
    // printf("endereco.numero: %d\n", endereco.numero);
    // printf("posicaoEnderecosPreGerados: %d\n", posicaoEnderecosPreGerados);

  return endereco;
}

void mostraEndereco(Endereco endereco)
{
  printf("********** Endereco **********\n");
  printf("Nome da rua: %s\n", endereco.nomeRua);
  printf("Número da residência: %d\n", endereco.numero);
  printf("CEP: %d\n", endereco.cep);
}

Cliente cadastraCliente(Endereco endereco)
{
  Cliente cliente;
  cliente.cod = posicaoClientesPreGerados + 1;
  strcpy(cliente.nome, clientesPreGerados[posicaoClientesPreGerados]);
  cliente.end = endereco;
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
  dvd.cod = posicaoDvsPreGerados + 1;
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
  locacao.cod = posicaoLocacoesPreGeradas + 1;
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

void mostraLocacoes(Locacao *locacoes, int quantidade)
{
  for (int index = 0; index < quantidade; index++)
  {
    printf("*****************************\n");
    mostraLocacao(locacoes[index]);
    printf("*****************************\n\n");
  }
  
}
