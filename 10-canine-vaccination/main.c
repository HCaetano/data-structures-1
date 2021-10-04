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

void mostraData(Data data){
  printf("%d/%d/%d (dd/mm/aaaa)\n", data.dia, data.mes, data.ano);
}

void mostraVacina(Vacina vacina){
  printf("Vacina %s. Fabricante: %s, validade: %d/%d/%d.\n", vacina.nome, vacina.fabricante, vacina.validade.dia, vacina.validade.mes, vacina.validade.ano);
}

void mostraDadosCao(Cao cao){
  printf("%s. Idade: %d, data de nascimento: %d/%d/%d, quantidade de vacinas: %d.\n", cao.nome, cao.idade, cao.dataDeNascimento.dia, cao.dataDeNascimento.mes, cao.dataDeNascimento.ano, cao.quantidadeVacinas);

  if (cao.quantidadeVacinas > 0)
  {
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
  strcpy(vacina->nome, "antirrábica");
  strcpy(vacina->fabricante, "EMS");
  vacina->validade = cadastraData(1, 6, 2024);
}

void cadastraCao(Cao *cao){
  strcpy(cao->nome, "Bolinha");
  cao->idade = 1;
  cao->dataDeNascimento = cadastraData(1, 1, 2020);
  cao->quantidadeVacinas = 0;
}

void vacinacao(Cao *cao, Vacina vacina){
  cao->carterinha[cao->quantidadeVacinas] = vacina;
  cao->quantidadeVacinas = cao->quantidadeVacinas + 1;
}

Cao* cruzamento(Cao pai, Cao mae){
  // Cao filhote;
}

int main()
{
  system("clear");
  setlocale(LC_ALL, "");   

  // Data data = cadastraData(1, 6, 2020);
  // mostraData(data);

  Cao bolinha, preta, cristal, marley; 
  cadastraCao(&bolinha);
  // mostraDadosCao(bolinha);
  // cadastraCao(&marley);

  Vacina vacinas[4];
  cadastraVacina(vacinas);
  // mostraVacina(vacinas[0]);
  cadastraVacina(vacinas+1);
  // cadastraVacina(&(vacinas[2])); 
  // cadastraVacina(&(vacinas[3]));
  // mostraVacina(vacinas[3]);

  // mostraDadosCao(bolinha);  
  vacinacao(&bolinha,vacinas[0]);
  mostraDadosCao(bolinha);

  // vacinacao(&bolinha,vacinas[2]);
  // mostraDadosCao(bolinha);

  // vacinacao(&bolinha,vacinas[2]);

  // mostraDadosCao(marley);  
  // vacinacao(&marley,vacinas[0]);  
  // vacinacao(&marley,vacinas[1]);
  // vacinacao(&marley,vacinas[2]);
  // vacinacao(&marley,vacinas[3]);
  // mostraDadosCao(marley);

  // Cao *junior = cruzamento(marley,cristal);    
  // vacinacao(junior,vacinas[0]); 
  // mostraDadosCao(*junior);

  exit(0);
}
