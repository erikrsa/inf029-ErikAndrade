/*
Q2. Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores (primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o resultado da subtração.
*/

#include <stdio.h>

int subtrai();

main()
{
  int a, b, c;
  
  printf("Informe os três valores: ");
  scanf("%d %d %d", &a, &b,&c);
  printf("Resultado: %d\n", subtrai(a, b, c));
};

int subtrai(int a, int b, int c)
{
  return a-b-c;
}