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
void matriculaAlunoDisciplina(Aluno* aluno, Disciplina* codigoDisciplina);
int removeAlunoDisciplina(int matricula, Disciplina* disciplina);
int quantidadeDisciplinasAluno(Aluno* aluno);

int main()
{
  // cria 10 alunos
  Aluno aluno = cadastroDeAluno(1);
  Aluno aluno2 = cadastroDeAluno(2);
  Aluno aluno3 = cadastroDeAluno(3);
  Aluno aluno4 = cadastroDeAluno(4);
  Aluno aluno5 = cadastroDeAluno(5);
  Aluno aluno6 = cadastroDeAluno(6);
  Aluno aluno7 = cadastroDeAluno(7);
  Aluno aluno8 = cadastroDeAluno(8);
  Aluno aluno9 = cadastroDeAluno(9);
  Aluno aluno10 = cadastroDeAluno(10);
  // cria 3 disciplinas
  Disciplina disciplina = cadastroDeDisciplina(1);
  Disciplina disciplina2 = cadastroDeDisciplina(2);
  Disciplina disciplina3 = cadastroDeDisciplina(3);

  // cadastra aluno nas três disciplinas
  matriculaAlunoDisciplina(&aluno, &disciplina);
  matriculaAlunoDisciplina(&aluno, &disciplina2);
  matriculaAlunoDisciplina(&aluno, &disciplina3);
  // cadastra aluno2 nas três disciplinas
  matriculaAlunoDisciplina(&aluno2, &disciplina);
  matriculaAlunoDisciplina(&aluno2, &disciplina2);
  matriculaAlunoDisciplina(&aluno2, &disciplina3);
  // cadastra aluno3 nas três disciplinas
  matriculaAlunoDisciplina(&aluno3, &disciplina);
  matriculaAlunoDisciplina(&aluno3, &disciplina2);
  matriculaAlunoDisciplina(&aluno3, &disciplina3);
  // cadastra aluno4 nas três disciplinas
  matriculaAlunoDisciplina(&aluno4, &disciplina);
  matriculaAlunoDisciplina(&aluno4, &disciplina2);
  matriculaAlunoDisciplina(&aluno4, &disciplina3);
  // cadastra aluno5 nas três disciplinas
  matriculaAlunoDisciplina(&aluno5, &disciplina);
  matriculaAlunoDisciplina(&aluno5, &disciplina2);
  matriculaAlunoDisciplina(&aluno5, &disciplina3);
  // cadastra aluno6 nas três disciplinas
  matriculaAlunoDisciplina(&aluno6, &disciplina);
  matriculaAlunoDisciplina(&aluno6, &disciplina2);
  matriculaAlunoDisciplina(&aluno6, &disciplina3);
  // cadastra aluno7 nas três disciplinas
  matriculaAlunoDisciplina(&aluno7, &disciplina);
  matriculaAlunoDisciplina(&aluno7, &disciplina2);
  matriculaAlunoDisciplina(&aluno7, &disciplina3);
  // cadastra aluno8 nas três disciplinas
  matriculaAlunoDisciplina(&aluno8, &disciplina);
  matriculaAlunoDisciplina(&aluno8, &disciplina2);
  matriculaAlunoDisciplina(&aluno8, &disciplina3);
  // cadastra aluno9 nas três disciplinas
  matriculaAlunoDisciplina(&aluno9, &disciplina);
  matriculaAlunoDisciplina(&aluno9, &disciplina2);
  matriculaAlunoDisciplina(&aluno9, &disciplina3);
  // cadastra aluno10 nas três disciplinas
  matriculaAlunoDisciplina(&aluno10, &disciplina);
  matriculaAlunoDisciplina(&aluno10, &disciplina2);
  matriculaAlunoDisciplina(&aluno10, &disciplina3);

  // mostraAluno(aluno10);
  // mostraDisciplina(disciplina);

  // printf("************\n");
  // printf("Disciplina, inscritos: %d\n", disciplina.quantidadeDeAlunos);
  // int address = removeAlunoDisciplina(3, &disciplina);

  // printf("Endereço removido: %X\n", address);
  // printf("Disciplina, inscritos: %d\n", disciplina.quantidadeDeAlunos);
}

void mostraAluno(Aluno aluno)
{
  printf("************\n");
  printf("Matrícula: %d\n", aluno.matricula);
  printf("Nome: %s\n", aluno.nome);
  printf("Nome do pai: %s\n", aluno.nomePai);
  printf("Nome da mãe: %s\n", aluno.nomeMae);

  int quantidade = quantidadeDisciplinasAluno(&aluno);
  for (int posicao = 0; posicao < quantidade; posicao++)
  {
    printf("Título da disciplina %d: %s\n", posicao + 1, aluno.matriculadoEm[posicao]);
  }
  
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
  disciplina.ano = 2021;
  disciplina.quantidadeDeAlunos = 0;

  return disciplina;
}

void matriculaAlunoDisciplina(Aluno* aluno, Disciplina* disciplina)
{
  int quantidadeDisciplinas = quantidadeDisciplinasAluno(aluno);
  
  if (quantidadeDisciplinas < 5)
  {
    int posicao = disciplina->quantidadeDeAlunos;
    disciplina->matriculados[posicao] = *aluno;
    strcpy(aluno->matriculadoEm[quantidadeDisciplinas], disciplina->nome);
    disciplina->quantidadeDeAlunos = disciplina->quantidadeDeAlunos + 1;
  }
  else
  {
    printf("************\n");
    printf("O aluno %s já atingiu o limite de disciplinas.\n", aluno->nome);
    printf("************\n");
  }
}

int removeAlunoDisciplina(int matricula, Disciplina* disciplina)
{
  int posicaoParaDeletar = -1;
  for (int posicao = 0; posicao < 50; posicao++)
  {
    if (disciplina->matriculados[posicao].matricula == matricula)
    {
      posicaoParaDeletar = posicao;
    }
  }

  int memoryAdress = &disciplina->matriculados[posicaoParaDeletar];

  for(int posicao = posicaoParaDeletar - 1; posicao < (50 - 1); posicao++)
    {
      disciplina->matriculados[posicao] = disciplina->matriculados[posicao + 1];
    }

    disciplina->quantidadeDeAlunos = disciplina->quantidadeDeAlunos - 1;

    return memoryAdress;
}

int quantidadeDisciplinasAluno(Aluno* aluno)
{
  int quantidadeDisciplinas = 0;
  for (int posicao = 0; posicao < 5; posicao++)
  {
    if (strcmp(aluno->matriculadoEm[posicao], "") != 0)
    {
      quantidadeDisciplinas++;
    }
  }

  return quantidadeDisciplinas;
}