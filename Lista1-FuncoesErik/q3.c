/*
Q3. Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.
*/

#include<stdio.h>
#include<stdlib.h>

fatorial();

main()
{
  int a;
  printf("\n==== Calculadora de fatorial ====\n");
  printf("\nEntrada: ");
  scanf("%d", &a);

  printf("\n%d! = %d\n", a, fatorial(a));
}

fatorial(int n)
{
  int fat;
  
  if(n<0)
  {
    printf("Erro: entrada inválida!\n");
    exit(-1);
    return -1;
  }
    
  else if(n==0)
    return 1;
  
  else
  {  
    for(n, fat=n; n>1; n--, fat*=n);
    return fat;
  }
}