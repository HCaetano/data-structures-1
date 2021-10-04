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
   
}

void mostraVacina(Vacina vacina){
}

void mostraDadosCao(Cao cao){
}

Data cadastraData(int dia, int mes, int ano){
  Data data;
  data.dia = dia;
  data.mes = mes;
  data.ano = ano;

  return data;
}

// Aluno cadastroDeAluno(int matriculaInformada)
// {
//   Aluno aluno;
//   aluno.matricula = matriculaInformada;
//   aluno.anoDeIngresso = 2018;
//   strcpy(aluno.nome, alunosPreGerados[posicaoValoresPreGeradosAlunos]);
//   strcpy(aluno.nomePai, paisPreGerados[posicaoValoresPreGeradosAlunos]);
//   strcpy(aluno.nomeMae, maesPreGeradas[posicaoValoresPreGeradosAlunos]);
//   posicaoValoresPreGeradosAlunos++;

//   return aluno;
// }

  // char nome [20];
  // char fabricante [20];
  // Data validade;

void cadastraVacina(Vacina *vacina){
  Vacina novaVacina = *vacina;
  strcpy(novaVacina.nome, "antirrábica");
  strcpy(novaVacina.fabricante, "EMS");
  novaVacina.validade = cadastraData(1, 6, 2020);
}

void cadastraCao(Cao *cao){

}

void vacinacao(Cao *cao, Vacina vacina){
}

Cao* cruzamento(Cao pai, Cao mae){
}

int main()
{
  system("clear");
  setlocale(LC_ALL, "");   

  // Data data = cadastraData(1, 6, 2020);
  // printf("dia: %d\n", data.dia); 
  // printf("mês: %d\n", data.mes); 
  // printf("ano: %d\n", data.ano); 

  // Cao bolinha, preta, cristal, marley; 
  // cadastraCao(&bolinha);
  // cadastraCao(&marley);

  Vacina vacinas[4];
  cadastraVacina(vacinas);
  // cadastraVacina(vacinas+1);
  // cadastraVacina(&(vacinas[2])); 
  // cadastraVacina(&(vacinas[3]));
  
  // mostraVacina(vacinas[3]);

  // mostraDadosCao(bolinha);  
  // vacinacao(&bolinha,vacinas[0]);
  // mostraDadosCao(bolinha);

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
