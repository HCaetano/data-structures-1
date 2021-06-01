// struct disciplina Aluno matriculados tem um asterisco

#include <stdio.h>
#include <string.h>

void menor(int* numeros, int arrayLength, int *numeroComparado);
int maior(int* numeros, int numeroComparado);

int main()
{

  int numeros[5] = { 4, 7, 1, 10, -1 };
  int arrayLength = sizeof(numeros)/sizeof(numeros[0]);
  int menorNumero = 999999;
  menor(numeros, arrayLength, &menorNumero);

  printf("menorNumero: %d\n", menorNumero);

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



  //  Declare smallest as integer
  //  Set smallest to 0
  //  FOR EACH value in A DO
  //     IF A[n] is less than smallest THEN
  //        smallest ← A[n]
  //     ENDIF
  //  END FOR
  //  Display smallest
  
// }