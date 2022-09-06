/*
Q06. Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário e retornar as três letras. A função main deve imprimir essas três letras.
*/

#include<stdio.h>

typedef struct guarda3Letras
{
  char c[3];
}tresLetras;

tresLetras ler3Letras()
{
  tresLetras input;
  char letra;
  
  for(int i=0; i<3; i++)
  {
    scanf("%c", &letra);
    //letra=getchar();
    if((letra>='a' && letra<='z')||(letra>='A' && letra<='Z'))
    input.c[i]=letra;
    else
    i--;
  }

  return input;
}

main()
{
  tresLetras l;

  printf("Informe 3 letras (de 'a' a 'z'): ");

  l=ler3Letras();

  printf("As 3 letras informadas foram:");
  
  for(int i=0; i<3; i++)
  printf(" %c", l.c[i]);
}