/*
Q09. Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
• função validarNacimento: recebe o data digitada, e valida é uma data válida
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct reg_cadastro
{
  char nome[256];
  char data[12];
  int nascDia;
  int nascMes;
  int nascAno;
  char cpf[30];
  char sexo;
}cad;

int validarNome(char nome[])
{
  int i;
  for(i=0; nome[i]!='\0' && i<22; i++);
  if(i>21||i==0)
    return 0;
  else
    return 1;
}

int ehbissexto(int ano)
{
  if((ano%4==0) && ((ano%400==0) || (ano%100!=0)))
		return 1; //O ano é bissexto
	else
	  return 0; //O ano não é bissexto
}

int validarNascimento(int dia, int mes, int ano)
{
  int hojeDia=6, hojeMes=9, hojeAno=2022, bissexto=0;

  if(ano<1700) //Partindo-se da premissa de que não ha conhecimento comum e amplamente divulgado no mundo, até o momento, de uma pessoa tricentenária
    return 0;
  if(mes<1||mes>12)
    return 0;
  if(dia<1)
    return 0;
  
  if(ano>hojeAno)
    return 0;
  if(mes>hojeMes && ano==hojeAno)
    return 0;
  if(dia>hojeDia && mes==hojeMes && ano==hojeAno)
    return 0;

  if(mes==2)
  {
    if(ehbissexto(ano)==1)
    {
      if(dia>29)
      return 0;
    }
      
    else if(dia>28)
      return 0;
  }
	
	else if((mes<=7 && mes%2!=0)||(mes>7 && mes%2==0))
  {
    if(dia>31)
      return 0;
  }
	
	else
  {
    if(dia>30)
      return 0;
  }
}

int validarCPF(char cpf[])
{
  for(int i=0; cpf[i]!='\0'; i++)
  {
    if(cpf[i]<='0'||cpf[i]>='9')
      return 0;
    if(i>11)
      return 0;
  }
  return 1;
}

int validarSexo(char sexo)
{
  if(sexo=='M'||sexo=='m'||sexo=='F'||sexo=='f'||sexo=='o'||sexo=='O')
    return 1;
  else
    return 0;
}


cad cadastrarCliente()
{
  cad cliente;
  int j, barra;
  
  printf("Nome (no máximo 20 caracteres): ");
  fgets(cliente.nome, 256, stdin);
  for(j=0; cliente.nome[j]!='\n'; j++);
  cliente.nome[j]='\0';
  // getchar();

  printf("Data de nascimento\n");
  printf("Dia: ");
  scanf("%d", &cliente.nascDia);
  printf("Mes: ");
  scanf("%d", &cliente.nascMes);
  printf("Ano (formato aaaa): ");
  scanf("%d", &cliente.nascAno);
  
  // printf("Data de nascimento: ");
  // fgets(cliente.data, 12, stdin);
  // for(j=0; cliente.data[j]!='\n'; j++);
  // cliente.data[j]='\0';
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

  printf("CPF (somente numeros): ");
  fgets(cliente.cpf, 30, stdin);
  for(j=0; cliente.cpf[j]!='\n'; j++);
  cliente.cpf[j]='\0'; 
  getchar();

  printf("Sexo (m: masculino, f: feminino, o: outro): ");
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

  printf("\nCPF: %s", cadast.cpf);

  printf("\nSexo: %c\n", cadast.sexo);
}