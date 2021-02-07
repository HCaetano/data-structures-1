#include <stdio.h>
#include <string.h>

struct Aluno {
  int  matricula;
  int anoDeIngresso;
  char nome[100];
  char nomePai[100];
  char nomeMae[100];
  int  matriculadoEm[5];
} aluno;  

struct Disciplina {
  int codDisciplina;
  char nome[100];
  int ano;
  int quantidadeDeAlunos;
  struct Aluno matriculados[50];
} disciplina;  

struct Aluno cadastroDeAluno(int matriculaInformada) 
{
  struct Aluno aluno;
  int matricula = matriculaInformada;
  int anoDeIngresso;
  char nome[100];
  char nomePai[100];
  char nomeMae[100];
  int matriculadoEm[5];

  printf("Digite o ano de ingresso deste aluno: ");
  scanf("%d", &anoDeIngresso);
  printf("Digite o nome do aluno: ");
  scanf("%s", &nome);
  printf("Digite o nome do pai do aluno: ");
  scanf("%s", &nomePai);
  printf("Digite o nome da mãe do aluno: ");
  scanf("%s", &nomeMae);

  aluno.matricula = matricula;
  aluno.anoDeIngresso = anoDeIngresso;
  strcpy(aluno.nome, nome);
  strcpy(aluno.nomePai, nomePai);
  strcpy(aluno.nomeMae, nomeMae);

  return aluno;
}

struct Disciplina cadastroDeDisciplina(int codigoInformado, char nomeDaDisciplina) 
{
  int codDisciplina;
  char nome[100];
  int ano;
  int quantidadeDeAlunos;
  struct Aluno matriculados[50];

  // printf("Digite o nome da disciplina: ");
  // scanf("%s", &nome);
  // printf("Digite o ano de vigência da disciplina: ");
  // scanf("%d", &ano);

  disciplina.codDisciplina = codigoInformado;
  strcpy(disciplina.nome, nomeDaDisciplina);

  return disciplina;
}

void mostraAluno(struct Aluno *aluno)
{
  printf("************\n");
  printf("Matrícula: %d\n", aluno->matricula);
  printf("Nome: %s\n", aluno->nome);
  printf("Nome do pai: %s\n", aluno->nomePai);
  printf("Nome da mãe: %s\n", aluno->nomeMae);
}

int main()
{
  struct Aluno aluno = cadastroDeAluno(1);
  mostraAluno(&aluno);
  printf("não quebrou");
  char nome[50] = "nome teste";
  printf("quebrou?");
  printf("Nome da disciplina: %s", &nome);
  struct Disciplina disciplina = cadastroDeDisciplina(1, &nome);
  printf("Código da disciplina: %d", disciplina.codDisciplina);
  printf("Título da disciplina: %s", disciplina.nome);

}