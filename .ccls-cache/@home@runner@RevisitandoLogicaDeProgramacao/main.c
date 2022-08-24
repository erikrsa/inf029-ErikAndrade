#include <stdio.h>
#include <stdlib.h>

int questao01()
{
/*
Q1. Faça um programa que imprima o seu nome, sua matrícula, e o seu semestre de ingresso no curso. Cada informação em uma linha
*/
  printf("Erik Renato\n");
  printf("20221160015\n");
  printf("2022.1\n");
  return 0;
}

int questao02()
{
  /*
Q2. Faça um programa que leia a idade de duas pesoas e imprima a soma das idades
  */
  
  int idade01, idade02;
  
  printf("Informe a idade da pessoa 01: ");
  scanf("%d", &idade01);
  printf("Informa a idade da pessoa 02: ");
  scanf("%d", &idade02);
  
  printf("A soma da idade das duas pessoas é: %d\n", idade01+idade02);
  printf("E é só isso mesmo...");
  
  return 0;
}

int questao03()
{
  /*
Q3. Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas
  */
  int A, B, invertis;
  char resp;

  printf("Informe o valor de A: ");
  scanf("%d", &A);

  printf("Informe o valor de B: ");
  scanf("%d", &B);

  if(A==B)
  {
    printf("Aí vc estraga a brincadeira...");
    return 0;
  }

  invertis=A;
  A=B;
  B=invertis;

  printf("Os valores da variáveis informados foram:\nA=%d\nB=%d\n", A, B);
  printf("Estou correto? <s/n>: ");
  scanf(" %c", &resp);

  if(resp=='n')
    printf("Eu inverti!\nVc tá ligado!");
  else
    printf("Se ligue vacilão...");
  
  return 0;
}

int questao04()
{
/*
Q4.Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar
*/
  int A, B;

  printf("Informe o valor de A: ");
  scanf("%d", &A);

  printf("Informe o valor de B: ");
  scanf("%d", &B);

  printf("Executando a mudança...\n");
  A = A-B;
  printf("1ª etapa:\n\tA=%d\n\tB=%d\n", A, B);
  B = B+A;
  printf("2ª etapa:\n\tA=%d\n\tB=%d\n", A, B);
  A = B-A;
  printf("Conclusão:\n\tA=%d\n\tB=%d\n", A, B);
  printf("The end...");
  
  return 0;
}

int questao05()
{
/*
Q5. Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor
*/
  int idade, maior=18;
  
  printf("Informe a idade da pessoa: ");
  scanf("%d", &idade);
  
  if(idade>=maior)
    printf("A pessoa em questão já é maior de idade pela legislação brasileira.");
  else
    printf("Pela legislação brasileira, essa pessoa ainda é considerada de menor.");

  return 0;
}

int questao06()
{
/*
Q6. Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada
*/
  int idade, maior=18;

  printf("Essa é a questão 06\n");

  do{
      printf("\nInforme a idade da pessoa: ");
  scanf("%d", &idade);
  
    if(idade>=maior)
      printf("A pessoa em questão já é maior de idade pela legislação brasileira.");
    else if(idade>=0)
      printf("Pela legislação brasileira, essa pessoa ainda é considerada de menor.");
  }while(idade>=0);

  printf("\nNão existe idade negativa, vacilão!\nEncerrando o programa!\n\n\tVá dormir...");
  return 0;
}

questao07()
{
/*
Q7. Faça um programa que verifique se um número é primo
*/
  int i, n;

  printf("Informe o número: ");
  scanf("%d", &n);

  if(n>1)
    for(i=n/2; n%i!=0; i--);

  if(i==1 && n>1)
    printf("O número %d é primo!", n);
  else
    printf("O número %d não é primo...", n);
  return 0;
}

questao08()
{
/*
Q8. Faça um programa que calcula o fatorial de um número
*/
  int fatorial, n;
  
  printf("Calculadora de fatorial\nInforme o número: ");
  scanf("%d", &n);

  if(n==0)
    printf("0! = 1;");
  else
  {
    printf("%d! = %d", n, n);
  
    for(n, fatorial=n; n>1; n--, printf(" %d", n), fatorial*=n)
    printf(" x");

    printf(" = %d", fatorial);
  }
}

questao09()
{
/*
Q9. Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.
*/
  int j, i, num[10], somaprim;

  for(i=0; i<10; i++)
  {
    printf("Informe o %dº número: ", i+1);
    scanf("%d", &num[i]);
  }

  printf("São primos os números: ");
  for(j=0, somaprim=0; j<10; j++)
  {
    if(num[j]>1)
    for(i=num[j]/2; num[j]%i!=0; i--);

    if(i==1 && num[j]>1)
    {
      printf("%d, ", num[j]);
      somaprim+=num[j];
    }
  }
  printf("e a soma de todos os primos é igual a %d", somaprim);

}

questao10()
{
/*
Q10. Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.
*/

  struct ficha_de_cadastro
  {
    char nome[256], sexo;
    int idade;
    long int cpf;
  }ficha[5];

  for(int i=0; i<5; i++)
  {
    printf("\n======= Cadastro %d =======\n", i+1);
    printf("Nome: ");
    fgets(ficha[i].nome, 256, stdin);
    int j;
    for(j=0; ficha[i].nome[j]!='\n'; j++);
    ficha[i].nome[j]='\0';
    
    printf("Idade: ");
    scanf("%d", &ficha[i].idade);
    getchar();
    
    printf("Sexo (m/f): ");
    scanf("%c", &ficha[i].sexo);
    getchar();

    printf("CPF: ");
    scanf("%ld", &ficha[i].cpf);
    getchar();
  }

  printf("\n======= Lista dos cadastrados =======\n");

  for(int i=0; i<5; i++)
  {
    printf("\n======= Cadastro %d =======\n", i+1);
    printf("Nome: %s\n", ficha[i].nome);
    printf("Idade: %d\n", ficha[i].idade);
    printf("Sexo: %c\n", ficha[i].sexo);
    printf("CPF: %ld\n", ficha[i].cpf);
  }
}


int main()
{
  questao10();
  printf("\n");
  return 0;
}