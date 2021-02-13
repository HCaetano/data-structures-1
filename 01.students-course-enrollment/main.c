// struct disciplina Aluno matriculados tem um asterisco

#include <stdio.h>
#include <string.h>

typedef struct Aluno {
  int matricula;
  int anoDeIngresso;
  char nome[100];
  char nomePai[100];
  char nomeMae[100];
  char matriculadoEm[5][100];
} Aluno;  

typedef struct Disciplina {
  int codDisciplina;
  char nome[100];
  int ano;
  int quantidadeDeAlunos;
  struct Aluno matriculados[50];
} Disciplina;  

Aluno cadastroDeAluno(int matriculaInformada);
Disciplina cadastroDeDisciplina(int codigoDisciplina);
void mostraAluno(struct Aluno aluno);
void mostraDisciplina(struct Disciplina disciplina);
// void matriculaAlunoDisciplina(struct Aluno aluno, struct Disciplina codigoDisciplina);
void matriculaAlunoDisciplina(Aluno* aluno, Disciplina* codigoDisciplina);

int main()
{
  // char teste[5][100];
  // strcpy(teste[0], "Pai do Joãozinho");
  // strcpy(teste[1], "Mãe do Joãozinho");
  // strcpy(teste[2], "Tia do Joãozinho");
  // strcpy(teste[3], "Tio do Joãozinho");
  // strcpy(teste[4], "Neto do Joãozinho");
  //   printf("Nome: %s\n", teste[0]);
  //   printf("Nome: %s\n", teste[1]);
  //   printf("Nome: %s\n", teste[2]);
  //   printf("Nome: %s\n", teste[3]);
  //   printf("Nome: %s\n", teste[4]);

  Aluno aluno = cadastroDeAluno(1);
  Aluno aluno2 = cadastroDeAluno(2);
  // mostraAluno(aluno);
  Disciplina disciplina = cadastroDeDisciplina(1);
  // mostraDisciplina(disciplina);
  matriculaAlunoDisciplina(&aluno, &disciplina);
  matriculaAlunoDisciplina(&aluno2, &disciplina);
  printf("**********\n");
  printf("Matrícula: %d\n", disciplina.matriculados[0].matricula);
  printf("Nome: %s\n", disciplina.matriculados[0].nome);
  printf("Nome: %s\n", disciplina.matriculados[0].nomePai);
  printf("Nome: %s\n", disciplina.matriculados[0].nomeMae);
  printf("Posição: %d\n", disciplina.matriculados[0].anoDeIngresso);
  printf("Disciplina: %s\n", aluno.matriculadoEm[0]);
  printf("**********\n");
  printf("Matrícula: %d\n", disciplina.matriculados[1].matricula);
  printf("Nome: %s\n", disciplina.matriculados[1].nome);
  printf("Nome: %s\n", disciplina.matriculados[1].nomePai);
  printf("Nome: %s\n", disciplina.matriculados[1].nomeMae);
  printf("Posição: %d\n", disciplina.matriculados[1].anoDeIngresso);
  printf("Inscritos: %d\n", disciplina.quantidadeDeAlunos);
  printf("Disciplina: %s\n", aluno2.matriculadoEm[0]);
}

void mostraAluno(Aluno aluno)
{
  printf("************\n");
  printf("Matrícula: %d\n", aluno.matricula);
  printf("Nome: %s\n", aluno.nome);
  printf("Nome do pai: %s\n", aluno.nomePai);
  printf("Nome da mamãe: %s\n", aluno.nomeMae);
}

void mostraDisciplina(struct Disciplina disciplina)
{
  printf("************\n");
  printf("Código da disciplina: %d\n", disciplina.codDisciplina);
  printf("Título: %s\n", disciplina.nome);
  printf("Ano: %d\n", disciplina.ano);
  printf("Quantidade de matriculados: %d\n", disciplina.quantidadeDeAlunos);
}

Aluno cadastroDeAluno(int matriculaInformada)
{
  Aluno aluno;
  aluno.matricula = matriculaInformada;
  aluno.anoDeIngresso = 2018;
  strcpy(aluno.nome, "Joãozinho");
  strcpy(aluno.nomePai, "Pai do Joãozinho");
  strcpy(aluno.nomeMae, "Mãe do Joãozinho");

  return aluno;
}

Disciplina cadastroDeDisciplina(int codigoDisciplina)
{
  Disciplina disciplina;
  disciplina.codDisciplina = codigoDisciplina;
  strcpy(disciplina.nome, "Estrutura de Dados I");
  disciplina.ano = 2018;
  disciplina.quantidadeDeAlunos = 0;

  return disciplina;
}

void matriculaAlunoDisciplina(Aluno* aluno, Disciplina* disciplina)
{
  int posicao = disciplina->quantidadeDeAlunos;
  disciplina->matriculados[posicao] = *aluno;
  strcpy(aluno->matriculadoEm[0], disciplina->nome);
  // aluno->matriculadoEm[0] = disciplina->nome;
  disciplina->quantidadeDeAlunos = disciplina->quantidadeDeAlunos + 1;

  // printf("**********\n");
  // printf("Matrícula: %d\n", disciplina.matriculados[posicao].matricula);
  // printf("Nome: %s\n", disciplina.matriculados[posicao].nome);
  // printf("Nome: %s\n", disciplina.matriculados[posicao].nomePai);
  // printf("Nome: %s\n", disciplina.matriculados[posicao].nomeMae);
  // printf("Posição: %d\n", disciplina.matriculados[posicao].anoDeIngresso);
}