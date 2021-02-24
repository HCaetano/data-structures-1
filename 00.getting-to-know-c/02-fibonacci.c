/* 2. A seguinte sequência de números 0 1 1 2 3 5 8 13 21... é conhecida como série de Fibonacci. Nessa sequência, cada número, depois dos 2 primeiros, é igual à soma dos 2 anteriores. Escreva um programa que mostre os N (informado pelo usuário) primeiros números dessa série. */

#include <stdio.h> 

int fibonacciSequence(int number) 
{ 
  if (number <= 1) 
    return number;
    
  return fibonacciSequence(number - 1) + fibonacciSequence(number - 2); 
} 

int main() 
{ 
  int number;
  
  printf( "Enter a value: ");
  scanf("%d", &number);
  printf("Result: %d\n", fibonacciSequence(number)); 
  getchar(); 
  
  return 0; 
} 