#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRECO_BASE 2.22
#define ANO_BASE 2000
#define DURACAO_MINIMA 2
#define ALUGADO 0
#define DISPONIVEL 1

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
  "Avenida Roberto Barbosa",
  "Travessa Pereira Lima",
  "Rua Irmão Oliva"
};
int posicaoEnderecosPreGerados = 0;
int posicaoCasas = 0;
int numerosDasCasas[5] = {10, 33, 342, 98, 6};
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
void devolveDvd(Dvd *dvd, Locacao *locacoes, int quantidade);
Locacao cadastraLocacao(Cliente *cliente, Dvd *dvdRecebido);
void mostraLocacao(Locacao Locacao);
void mostraLocacoes(Locacao *locacoes, int quantidade);

int main()
{
  Endereco enderecoIsadora = cadastraEndereco();
  Endereco enderecoMaria = cadastraEndereco();
  Endereco enderecoGabriel = cadastraEndereco();
  Endereco enderecoFernando = cadastraEndereco();
  printf("*********** Endereços cadastrados ***********\n");
  mostraEndereco(enderecoIsadora);
  printf("\n");
  mostraEndereco(enderecoMaria);
  printf("\n");
  mostraEndereco(enderecoGabriel);
  printf("\n");
  mostraEndereco(enderecoFernando);
  printf("\n");

  Cliente isadora = cadastraCliente(enderecoIsadora);
  Cliente maria = cadastraCliente(enderecoMaria);
  Cliente gabriel = cadastraCliente(enderecoGabriel);
  Cliente fernando = cadastraCliente(enderecoFernando);
  printf("*********** Clientes cadastrados ***********\n");
  mostraCliente(isadora);
  printf("\n");
  mostraCliente(maria);
  printf("\n");
  mostraCliente(gabriel);
  printf("\n");
  mostraCliente(fernando);
  printf("\n");

  Dvd gladiador = cadastraDvd();
  Dvd avatar = cadastraDvd();
  Dvd alien = cadastraDvd();
  Dvd tubarao = cadastraDvd();
  printf("*********** DVDs cadastrados ***********\n");
  mostraDvd(gladiador);
  printf("\n");
  mostraDvd(avatar);
  printf("\n");
  mostraDvd(alien);
  printf("\n");
  mostraDvd(tubarao);
  printf("\n");

  Locacao locacao1 = cadastraLocacao(&isadora, &gladiador);
  Locacao locacoes[5]; 
  locacoes[0] = locacao1;
  Locacao locacao2 = cadastraLocacao(&maria, &avatar);
  locacoes[1] = locacao2;
  Locacao locacao3 = cadastraLocacao(&isadora, &alien);
  locacoes[2] = locacao3;
  Locacao locacao4 = cadastraLocacao(&fernando, &tubarao);
  locacoes[3] = locacao4;
  int quantidadeLocacoes = (sizeof(locacoes)/sizeof(locacoes[0])) - 1;
  printf("*********** Locacoes cadastradas ***********\n");
  mostraLocacoes(locacoes, quantidadeLocacoes);
  printf("\n");

  printf("*********** Comprova que os DVDs que serão devolvidos estão com status 'alugado' ***********\n");
  mostraDvd(gladiador);
  printf("\n");
  mostraDvd(tubarao);
  printf("\n");

  printf("*********** Devolve 'Gladiador' e 'Tubarão' ***********\n");
  devolveDvd(&gladiador, locacoes, quantidadeLocacoes);
  devolveDvd(&tubarao, locacoes, quantidadeLocacoes);
  printf("\n");

  printf("*********** Comprova que os DVDs foram devolvidos, pois seu status é 'disponível' ***********\n");
  mostraDvd(gladiador);
  printf("\n");
  mostraDvd(tubarao);
  printf("\n");

  printf("*********** Mostra lista de Locacoes sem os DVDs devolvidos ***********\n");
  mostraLocacoes(locacoes, quantidadeLocacoes);

  printf("*********** Tentar alugar um DVD de status 'alugado' dispara mensagem de erro e o sistema para ***********\n");
  Locacao locacao5 = cadastraLocacao(&isadora, &avatar);
}

Endereco cadastraEndereco()
{
  Endereco endereco;
  endereco.numero = numerosDasCasas[posicaoEnderecosPreGerados];
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
  dvd.ano = ANO_BASE + posicaoDvsPreGerados;
  dvd.status = DISPONIVEL;
  posicaoDvsPreGerados++;

  return dvd;
}

void mostraDvd(Dvd dvd)
{
  printf("********** DVD **********\n");
  printf("Código: %d\n", dvd.cod);
  printf("Título: %s\n", dvd.titulo);
  printf("Ano de lançamento: %d\n", dvd.ano);
  printf("Status: %s\n", dvd.status == 0 ? "alugado" : "disponível" );
}

void devolveDvd(Dvd *dvd, Locacao *locacoes, int quantidade)
{
  for (int index = 0; index < quantidade; index++)
  {
    if (dvd->cod == locacoes[index].cod)
    {
      dvd->status = DISPONIVEL;
      printf("Valor da locação de %s: %.2f\n", locacoes[index].dvd->titulo, locacoes[index].total);
      // era minha intenção passar um NULL para a posição, mas dada a forma que eu fiz, isso não foi possível
      // em função do tempo, não consegui reformular minha lógica com sucesso para usar NULL
      // então coloquei um objeto do tipo esperado pelo array, porém com um código específico para identificar que a posição não é válida, ou seja, está "vazia"
      Locacao locacaoVazia;
      locacaoVazia.cod = -1;
      locacoes[index] = locacaoVazia;
    }
  }
}

Locacao cadastraLocacao(Cliente *cliente, Dvd *dvdRecebido)
{
  if (dvdRecebido->status)
  {
    Locacao locacao;
    locacao.cli = cliente; 
    locacao.dvd = dvdRecebido; 
    locacao.dvd->status = ALUGADO; 
    locacao.cod = posicaoLocacoesPreGeradas + 1;
    locacao.duracao = DURACAO_MINIMA + posicaoLocacoesPreGeradas;
    locacao.valor = (PRECO_BASE + posicaoLocacoesPreGeradas) * 1.00;
    locacao.total = locacao.valor * locacao.duracao;
    posicaoLocacoesPreGeradas++;

      return locacao;
  }

  printf("*********** \"%s\" já foi alugado ***********\n", dvdRecebido->titulo);
  exit(1);
}

void mostraLocacao(Locacao locacao)
{
  if (locacao.cod != -1)
  {
    printf("********** Locacao **********\n");
    printf("Código: %d\n", locacao.cod);
    printf("Duração (em dias): %d\n", locacao.duracao);
    printf("Diária: %.2f\n", locacao.valor);
    printf("Custo por %d dias: %.2f\n", locacao.duracao, locacao.total);
    mostraCliente(*locacao.cli);
    mostraDvd(*locacao.dvd);
  } 
  else 
  {
    printf("******* DVD entregue *******\n");
  }
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
