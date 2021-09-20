#include <stdio.h>
long int decimal_to_binary(int decimal)
{
    long int binary = 0;
    int remainder, place;

    for(place = 1; decimal != 0; place = place * 10)
    {
      remainder = decimal % 2;
      decimal /= 2;
      binary += remainder * place;
    }

    return binary;
}

int main()
{
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("%d in binary: %li\n", decimal, decimal_to_binary(decimal));

    return 0;
}