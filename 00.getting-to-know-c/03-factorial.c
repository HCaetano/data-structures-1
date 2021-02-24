/* 3. Ler um valor (só deve aceitar valores positivos validar através de repetição), calcular e escrever seu respectivo fatorial. OBS: O fatorial de 0 é igual a 1. Fatorial de n = n *(n1)*(n2)*(n3)*...*1. Ex: Fatorial de 4 = 4*3*2*1 = 24 */

#include <stdio.h>

int main()
{
  int index, number, factorial = 1;

  printf("Enter a number to calculate its factorial: ");
  scanf("%d", &number);

  for (index = 1; index <= number; index++)
    factorial = factorial * index;

  printf("Factorial of %d is %d\n", number, factorial);

  return 0;
}