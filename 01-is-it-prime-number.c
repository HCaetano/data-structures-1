// 1. Ler um número inteiro N (só aceitar valores maiores que zero. Caso o N não seja maior que zero deverá ser lido um novo valor para o N através de uma estrutura de repetição) e escrever se ele é ou não PRIMO. Obs: o número 1 não é primo.

#include <stdio.h>
int main( ) {

  int number;

  do {
    printf( "Enter a value: ");
    scanf("%d", &number);

    if (number < 0) continue;

    int index;
    int prime = 2;

    for(index = 2; index < number; index++) {
      if((number % index) == 0) {
        prime = 0;
      }
    }

    if (prime == 2)
      printf("%d is a prime number.\n", number);
    else
      printf("%d is not a prime number.\n", number);

  } while( number < 0 );

  return 0;
}