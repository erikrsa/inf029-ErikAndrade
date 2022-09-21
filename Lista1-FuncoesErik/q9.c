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
  int validaNome;
  int validaData;
  int validaCPF;
  int validaSexo;
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

  return 1;
}


int validarCPF(char cpf[])
{
  int i;
  
  for(i=0; cpf[i]!='\0'; i++)
  {
    if(cpf[i]<'0'||cpf[i]>'9')
      return 0;
  }
  
  if(i!=11)
    return 0;
  
  return 1;
}

void imprimeCPF(char cpf[])
{
  printf("%c%c%c.%c%c%c.%c%c%c-%c%c", cpf[0], cpf[1], cpf[2], cpf[3], cpf[4], cpf[5], cpf[6], cpf[7], cpf[8], cpf[9], cpf[10]);

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
  int j;
  
  printf("Nome (no máximo 20 caracteres): ");
  fgets(cliente.nome, 256, stdin);
  for(j=0; cliente.nome[j]!='\n'; j++);
  cliente.nome[j]='\0';
  
  cliente.validaNome = validarNome(cliente.nome);
  
  printf("Data de nascimento\n");
  printf("Dia: ");
  scanf("%d", &cliente.nascDia);
  printf("Mes: ");
  scanf("%d", &cliente.nascMes);
  printf("Ano (formato aaaa): ");
  scanf("%d", &cliente.nascAno);

  cliente.validaData = validarNascimento(cliente.nascDia, cliente.nascMes, cliente.nascAno);

  getchar();
  printf("CPF (somente numeros): ");
  fgets(cliente.cpf, 30, stdin);
  for(j=0; cliente.cpf[j]!='\n'; j++);
  cliente.cpf[j]='\0';
  
  cliente.validaCPF = validarCPF(cliente.cpf);

  printf("Sexo (m: masculino, f: feminino, o: outro): ");
  scanf("%c", &cliente.sexo);

  cliente.validaSexo = validarSexo(cliente.sexo);

  return cliente;
}

void main()
{
  cad cadast;
  int validacao;

  printf("\n====== Cadastro de cliente ======\n");

  cadast = cadastrarCliente();

  validacao = cadast.validaNome*cadast.validaData*cadast.validaCPF*cadast.validaSexo;

  if(validacao == 1)
  {
    printf("\nDados registrados com sucesso!");
    
    printf("\n\n====== Registro ======");

    printf("\nNome: %s", cadast.nome);
  
    printf("\nData de nascimento: %02d/%02d/%d", cadast.nascDia, cadast.nascMes, cadast.nascAno);
  
    printf("\nCPF: ");
    imprimeCPF(cadast.cpf);
  
    printf("\nSexo: %c\n", cadast.sexo);
  }

  else
  {
    printf("\nCadastro não realizado. Favor, verificar os dados:\n");
    if(cadast.validaNome==0)
      printf("\t-O nome declarado é inválido!\n");
    if(cadast.validaData==0)
      printf("\t-A data declarada é inválida!\n");
    if(cadast.validaCPF==0)
      printf("\t-O CPF declarado é inválido!\n");
    if(cadast.validaSexo==0)
      printf("\t-Informe somente uma das opções de sexo apresentadas no formulário!\n");
  }

}