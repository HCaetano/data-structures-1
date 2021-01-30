/* 5. O valor de Pi pode ser obtido usando a série abaixo. Escreva um programa para ler um valor N que representa a quantidade de termos da série, calcule e imprima o valor de Pi. PI = (4 - 4/3) + (4/5 - 4/7) + 4/9 */

#include <stdio.h>

int main()
{
  int numerator = 4, denominator = 1, pi, sequenceSize, i;

  printf("Enter a sequence size for pi: ");
  scanf("%d", &sequenceSize);

  for (i = 1; i <= sequenceSize; i++)
  {
    temp = numerator/denominator;
    denominator += 2
    temp -= numerator/denominator;

    pi += temp;
  }

  // pi = 4 - pi;

  printf("The pi sequence is: %d\n", pi);

  return 0;
}