/*
Q08. Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente
*/

#include <stdio.h>
#include <string.h>

typedef struct reg_cadastro
{
  char nome[20];
  char data[12];
  int nascDia;
  int nascMes;
  int nascAno;
  long int cpf;
  char sexo;
}cad;

cad cadastrarCliente()
{
  cad cliente;
  int j, barra;
  
  printf("Nome: ");
  fgets(cliente.nome, 20, stdin);
  for(j=0; cliente.nome[j]!='\n'; j++);
  cliente.nome[j]='\0';
  // getchar();

  printf("Data de nascimento: ");
  fgets(cliente.data, 12, stdin);
  for(j=0; cliente.data[j]!='\n'; j++);
  cliente.data[j]='\0';
  // getchar();
  // for(j=0, barra=0, cliente.nascDia=0, cliente.nascMes=0, cliente.nascAno=0, multdia=10, multmes=10, multano=1000; cliente.data[j]!='\0'; j++)
  // {
  //   if(cliente.data[j]=='/')
  //     barra++;
  //   if(barra==0)
  //     cliente.nascDia+=(cliente.data[j]-'0');
  //   else if(barra==1)
  //     cliente.nascMes+=cliente.data[j]-'0';
  //   else
  //     cliente.nascAno+=cliente.data[j]-'0';
  // }
  //getchar();

  printf("CPF: ");
  scanf("%ld", &cliente.cpf);
  getchar();

  printf("Sexo: ");
  scanf("%c", &cliente.sexo);
  getchar();

  return cliente;
}

main()
{
  cad cadast;

  printf("\n====== Cadastro de cliente ======\n");

  cadast = cadastrarCliente();
  
  // printf("Nome: ");
  // cadast.nome = cadastrarCliente();

  // printf("Data de nascimento: ");
  // cadast.data = cadastrarCliente();

  // printf("CPF: ");
  // cadast.cpf = cadastrarCliente();

  // printf("Sexo: ");
  // cadast.sexo = cadastrarCliente();

  printf("\n\n====== Registro ======");

  printf("\nNome: %s", cadast.nome);

  printf("\nData de nascimento: %s", cadast.data);

  printf("\nCPF: %ld", cadast.cpf);

  printf("\nSexo: %c\n", cadast.sexo);
}