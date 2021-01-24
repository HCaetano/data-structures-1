/* 6. Escreva um programa para ler um valor N que representa a quantidade de termos da série abaixo. Calcular e escrever o valor da série para N termos. S = 1000/1 - 997/2 + 994/3 - 991/4 ... */

#include <stdio.h>

int main()
{
  int numerator = 1000, denominator, sum = 0, sequenceSize;

  printf("Enter a sequence size for sum: ");
  scanf("%d", &sequenceSize);

  for (denominator = 1; denominator <= sequenceSize; denominator++)
  {
  printf("num: %d, den: %d \n", numerator, denominator);
    numerator -= 3;
    int shouldAdd = denominator % 2 != 0;

    if (shouldAdd) {
      sum += numerator/denominator;
    } else {
      sum -= numerator/denominator;
    }
  }

  printf("The sum is: %d\n", sum);

  return 0;
}