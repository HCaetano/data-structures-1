/* Ler um valor N. Escrever os números de 1 a N com seus respectivos divisores. A saída deve ser impressa no seguinte formato (considere no exemplo um N igual a 5):
1: Divisores 1
2: Divisores 1 2
3: Divisores 1 3
4: Divisores 1 2 4
5: Divisores 1 5 */

#include <stdio.h>

int main()
{
  int numberInSequence, divisorsIterations, sequenceSize;
  int divisors[100];

  printf("Enter a sequence size: ");
  scanf("%d", &sequenceSize);

  for (numberInSequence = 1; numberInSequence <= sequenceSize; numberInSequence++)
  {
    int arrayIndex = 0;
    for (divisorsIterations = numberInSequence; divisorsIterations > 0; divisorsIterations--)
    {
      if (numberInSequence % divisorsIterations == 0)
      {
        divisors[arrayIndex] = numberInSequence;
        arrayIndex++;
      }
    printf("%d: Divisors %d: $d\n", arrayIndex, divisors[arrayIndex]);
    }

    // printf("%d: Divisors %d: $d\n", numberInSequence);
  }


  return 0;
}