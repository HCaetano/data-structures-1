#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
  int dia, mes, ano;
}Data;

typedef struct vacina{
  char nome [20];
  char fabricante [20];
  Data validade;
}Vacina;

typedef struct cao{
  char nome [15]; 
  int idade;
  Data dataDeNascimento;
  Vacina carterinha [10];
  int quantidadeVacinas;
}Cao;

// Dados pré gerados para evitar ter de digitá-los toda vez que rodar o programa
char nomesDeCaes[4][15] = {"Bolinha", "Preta", "Cristal", "Marley"};
int posicaoCao = 0;
int idades[4] = {3, 2, 1, 5};
int posicaoIdades = 0;
char nomesDeVacinas[4][15] = {"V8", "V10", "Antirrábica", "Giárdia"};
int posicaoVacina = 0;
char nomesDeFabricantes[4][15] = {"Nobivac", "Vencomax", "Vanguard", "Neovax"};
int posicaoFabricante = 0;
int dia[4] = {1, 10, 17, 12};
int mes[4] = {1, 3, 9, 9};
int ano[4] = {2018, 2019, 2020, 2017};
int posicaoDataNascimento = 0;
int posicaoDataVacina = 0;

void mostraData(Data data){
  printf("%d/%d/%d (dd/mm/aaaa)\n", data.dia, data.mes, data.ano);
}

void mostraVacina(Vacina vacina){
  printf("***************Vacina***************\n");
  printf("Vacina %s. Fabricante: %s, validade: %d/%d/%d.\n", vacina.nome, vacina.fabricante, vacina.validade.dia, vacina.validade.mes, vacina.validade.ano);
  printf("***********************************\n\n");
}

void mostraDadosCao(Cao cao){
  printf("****************Cão****************\n");
  printf("%s. Idade: %d, data de nascimento: %d/%d/%d, quantidade de vacinas: %d.\n", cao.nome, cao.idade, cao.dataDeNascimento.dia, cao.dataDeNascimento.mes, cao.dataDeNascimento.ano, cao.quantidadeVacinas);
  printf("***********************************\n\n");

  if (cao.quantidadeVacinas > 0)
  {
    printf("***********Vacinas do Cão***********\n");
    for (int iteration = 0; iteration < cao.quantidadeVacinas; iteration++)
    {
      mostraVacina(cao.carterinha[iteration]);
    }
  }
}

Data cadastraData(int dia, int mes, int ano){
  Data data;
  data.dia = dia;
  data.mes = mes;
  data.ano = ano;

  return data;
}

void cadastraVacina(Vacina *vacina){
  strcpy(vacina->nome, nomesDeVacinas[posicaoVacina]);
  strcpy(vacina->fabricante, nomesDeFabricantes[posicaoFabricante]);
  vacina->validade = cadastraData(
    dia[posicaoDataVacina],
    mes[posicaoDataVacina],
    ano[posicaoDataVacina]
  );
  posicaoVacina++;
  posicaoFabricante++;
  posicaoDataVacina++;
}

void cadastraCao(Cao *cao){
  strcpy(cao->nome, nomesDeCaes[posicaoCao]);
  cao->idade = idades[posicaoIdades];
  cao->dataDeNascimento = cadastraData(
    dia[posicaoDataNascimento],
    mes[posicaoDataNascimento],
    ano[posicaoDataNascimento]
  );
  cao->quantidadeVacinas = 0;
  posicaoCao++;
  posicaoDataNascimento++;
  posicaoIdades++;
}

void vacinacao(Cao *cao, Vacina vacina){
  cao->carterinha[cao->quantidadeVacinas] = vacina;
  cao->quantidadeVacinas = cao->quantidadeVacinas + 1;
}

Cao* cruzamento(Cao pai, Cao mae){
  printf("Cruzamento de %s e %s.\n", pai.nome, mae.nome);
  Cao* filhote;
  strcpy(filhote->nome, pai.nome);
  strcat(filhote->nome, mae.nome);
  filhote->idade = 0;
  filhote->dataDeNascimento = cadastraData(7, 10, 2021); //hoje => dia da entrega
  filhote->quantidadeVacinas = 0;

  return filhote;
}

int main()
{
  system("clear");
  setlocale(LC_ALL, "");   

  Cao bolinha, preta, cristal, marley; 
  cadastraCao(&bolinha);
  cadastraCao(&preta);
  cadastraCao(&cristal);
  cadastraCao(&marley);
  // descomentar para conferir os dados iniciais de cada cão
  // mostraDadosCao(bolinha);
  // mostraDadosCao(preta);
  // mostraDadosCao(marley);
  // mostraDadosCao(cristal);

  Vacina vacinas[4];
  cadastraVacina(vacinas);
  cadastraVacina(vacinas+1);
  cadastraVacina(&(vacinas[2])); 
  cadastraVacina(&(vacinas[3]));
  // descomentar para conferir os dados iniciais de cada vacina
  // mostraVacina(vacinas[0]);
  // mostraVacina(vacinas[1]);
  // mostraVacina(vacinas[2]);
  // mostraVacina(vacinas[3]);

  // cães devem tomar no mínimo uma vacina
  vacinacao(&bolinha,vacinas[0]);
  mostraDadosCao(bolinha);

  vacinacao(&preta,vacinas[1]);
  mostraDadosCao(preta);

  vacinacao(&cristal,vacinas[2]);
  mostraDadosCao(cristal);

  // um cão deve tomar todas as vacinas
  vacinacao(&marley,vacinas[0]);  
  vacinacao(&marley,vacinas[1]);
  vacinacao(&marley,vacinas[2]);
  vacinacao(&marley,vacinas[3]);
  mostraDadosCao(marley);

  // no mínimo um cruzamento
  Cao *junior = cruzamento(marley,cristal);    
  mostraDadosCao(*junior);
  vacinacao(junior,vacinas[0]); 
  mostraDadosCao(*junior);

  exit(0);
}
