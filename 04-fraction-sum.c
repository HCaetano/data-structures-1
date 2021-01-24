/* 4. Escreva um programa para calcular e escrever o valor de S. S = 1 + 3/2 + 5/3 + 7/4 ... 99/50 */

#include <stdio.h>

int main()
{
  int numerator = 1, denominator, sum;

  for (denominator = 2; denominator <= 50; denominator++)
  {
    numerator += 2;
    sum += numerator/denominator;
  }

  sum++;

  printf("The sum of this sequence is: %d\n", sum);

  return 0;
}