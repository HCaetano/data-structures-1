#include <stdio.h>

void menor(int* numeros, int arrayLength, int *menorNumero);
void maior(int* numeros, int arrayLength, int *maiorNumero);
void menorMaior(int* numeros, int arrayLength, int *menorNumero, int *maiorNumero);

int main()
{

  int numeros[5] = { 4, 7, 1, 10, -1 };
  int arrayLength = sizeof(numeros)/sizeof(numeros[0]);

  int menorNumero = 999999;
  menor(numeros, arrayLength, &menorNumero);
  printf("menor número: %d\n", menorNumero);

  int maiorNumero = -999999;
  maior(numeros, arrayLength, &maiorNumero);
  printf("maior número: %d\n", maiorNumero);

  int outroMenor = 999999;
  int outroMaior = -999999;
  menorMaior(numeros, arrayLength, &outroMenor, &outroMaior);
  printf("outro menor: %d\n", outroMenor);
  printf("outro maior: %d\n", outroMaior);
}

void menor(int* numeros, int arrayLength, int *menorNumero)
{
  for (int i = 0; i < arrayLength; i++) {
    int numeroAtual = numeros[i];
    if (numeroAtual < *menorNumero)
    {
      *menorNumero = numeroAtual;
    }
  }
}

void maior(int* numeros, int arrayLength, int *maiorNumero)
{
  for (int i = 0; i < arrayLength; i++) {
    int numeroAtual = numeros[i];
    if (numeroAtual > *maiorNumero)
    {
      *maiorNumero = numeroAtual;
    }
  }
}

void menorMaior(int* numeros, int arrayLength, int *menorNumero, int *maiorNumero)
{
  menor(numeros, arrayLength, menorNumero);
  maior(numeros, arrayLength, maiorNumero);
}

