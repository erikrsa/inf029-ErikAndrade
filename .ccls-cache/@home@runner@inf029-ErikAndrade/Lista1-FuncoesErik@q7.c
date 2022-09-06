/*
Q07. Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do usuário e retornar as três palavras. A função main deve imprimir essas três palavras.
*/

#include <stdio.h>
#include <string.h>

typedef struct guardaPalavras
{
  char p[3][256];
}tresPalavras;

tresPalavras ler3Palavras()
{
  tresPalavras input;
  //char palavra[256];
  
  for(int i=0; i<3; i++)
  {
    fgets(input.p[i], 256, stdin);
    int j;
    for(j = 0; input.p[i][j]!='\n'; j++);
    input.p[i][j]='\0';
  }

  return input;
}

main()
{
  tresPalavras l;

  printf("Informe 3 palavras: ");

  l=ler3Palavras();

  printf("As 3 palavras informadas foram:");
  
  for(int i=0; i<3; i++)
  printf(" %s;", l.p[i]);
}