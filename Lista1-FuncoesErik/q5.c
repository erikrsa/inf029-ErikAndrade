/*
Q05. Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. Utilize struct para fazer o retorno
*/

#include<stdio.h>

typedef struct guarda_4numeros
{
  //int a, b, c, d;
  int a[4];
}lerInt;


lerInt ler4Numeros()
{
  lerInt num;
  
  for(int i=0; i<4; i++)
  {
    printf("Informe o %do número inteiro: ", i+1);
    scanf("%d", &num.a[i]);
  }

  return num;
}

void main()
{
  lerInt valor;

  valor = ler4Numeros();

  printf("Foram informados os numeros: %d, %d, %d e %d", valor.a[0], valor.a[1], valor.a[2], valor.a[3]);
}
