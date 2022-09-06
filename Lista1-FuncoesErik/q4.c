/*
Q04. Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.
*/

#include<stdio.h>

void ler3Numeros(int a[]);



main()
{
  int a[3];
  
  ler3Numeros(a);

  for(int i=0; i<3; i++)
    {
      printf("%d\n", a[i]);
     // ler3Numeros(a[i]);
    }
  
}

void ler3Numeros(int a[])
{
  for(int i=0; i<3; i++)
  { 
    printf("Informe o %dº numero: ", i+1);
    scanf("%d", &a[i]);
  }
  
  // a[0]=4;
  // a[1]=13;
  // a[2]=7;
  
}