/*
Q1. Crie um programa que tenha uma função soma e a função main. A função main deve ler dois valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor. A Função main deve imprimir o resultado da soma.
*/

#include <stdio.h>

float soma(float a, float b)
{
  return a + b;
}

int main()
{
  float a, b;
  printf("Informe os valores a somar: ");

  scanf("%f %f", &a, &b);

  printf("Soma = %f\n", soma(a, b));

  return 0;
}