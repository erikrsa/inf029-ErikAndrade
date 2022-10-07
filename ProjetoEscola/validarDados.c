#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "validarDados.h"

// int validarNome(char nome[]);
// char maiuscula(char nome[]);
// int ehbissexto(int ano);
// int validarNascimento(int dia, int mes, int ano);
// int validarmatricula(int matricula);
// int validarCPF(char cpf[]);
// int validarSexo(char sexo);

// int mainValidarDados()
// {
//   int validarNome(char nome[]);
//   char maiuscula(char nome[]);
//   int ehbissexto(int ano);
//   int validarNascimento(int dia, int mes, int ano);
//   int validarmatricula(int matricula);
//   int validarCPF(char cpf[]);
//   int validarSexo(char sexo);
// }

int validarNome(char nome[])
{
  int i;
  for(i=0; nome[i]!='\0' && i<37; i++);
  if(i>36||i==0)
    return 0;
  else
    return 1;
}

void maiuscula(char nome[])
{
  int i;
  for(i=0; nome[i]!='\0'; i++)
  {
    if(nome[i]>='a' && nome[i]<='z')
      nome[i]+='A'-'a';
  }
}

dt formatarData(char data[])
{
  //ponteiro para struct que armazena data e hora  
  struct tm *data_hora_atual;

  //variável do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  data_hora_atual = localtime(&segundos);
  
  int i, barra, mult;
  dt fdata;

  for(i=0; data[i+1]!='\0'; i++);

  for(i, barra=0, mult=1, fdata.dia=0, fdata.mes=0, fdata.ano=0; data[i]!='\0'; i--)
  {
    if(data[i]=='/')
    {
      barra++;
      mult=1;
      continue;
    }
    switch(barra)
    {
      case 0:
      {
        fdata.ano += (data[i]-'0')*mult;
        // printf("\nAno=%d", fdata.ano);
        mult*=10;
        break;
      }
      
      case 1:
      {
        fdata.mes += (data[i]-'0')*mult;
        // printf("\nMes=%d", fdata.mes);
        mult*=10;
        break;
      }
      
      case 2:
      {
        fdata.dia += (data[i]-'0')*mult;
        // printf("\nDia=%d", fdata.dia);
        mult*=10;
        break;
      }
      default:
      {
        fdata.erro=1;
        return fdata;        
      }
    }
  }

  if(fdata.ano<=(data_hora_atual->tm_year+1900)%100)
    fdata.ano+=((data_hora_atual->tm_year+1900)/1000)*1000;
  else if(fdata.ano<100)
    fdata.ano+=1900;

  fdata.longData= fdata.dia+fdata.mes*100+fdata.ano*10000;
  
  return fdata;
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
  //ponteiro para struct que armazena data e hora  
  struct tm *data_hora_atual;

  //variável do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  data_hora_atual = localtime(&segundos);

  if(ano<1900) //Estabelecendo idade máxima de 122 anos
    return 0;
  if(mes<1||mes>12)
    return 0;
  if(dia<1)
    return 0;
  
  if(ano>data_hora_atual->tm_year+1900)
  {
    printf("Ano maior que o atual!");
    return 0;
  }
   
  if(mes>data_hora_atual->tm_mon+1 && ano==data_hora_atual->tm_year+1900)
  {
    printf("mes maior que o atual!");
    return 0;
  }
  
  if(dia>data_hora_atual->tm_mday && mes==data_hora_atual->tm_mon+1 && ano==data_hora_atual->tm_year+1900)
  {
    printf("dia maior que o atual!");
    return 0;
  }


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

int validarMatricula(int matricula)
{
  if(matricula>99999)
    return 0;
}

long int formatarMatricula(long int matricula)
{
  int ano,  semestre, matriculaCompleta;
  //ponteiro para struct que armazena data e hora  
  struct tm *data_hora_atual;

  //variável do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  data_hora_atual = localtime(&segundos);

  ano = data_hora_atual->tm_year+1900;

  if((data_hora_atual->tm_mon+1)<=6)
    semestre=1;
  else
    semestre=2;

  matriculaCompleta= ano*1000000 + semestre*100000 + matricula;

  return matriculaCompleta;
}

int buscaMatricula(pess pessoal[], int tam, int chave)
{
  for(int i=0; i<tam; i++)
  {
    if(pessoal[i].matricula==chave)
      return i;
  }
  return -1;
}
//FAZER UM GERA CPF - QUE GERE UM CPF VÁLIDO

//MELHORAR O VALIDA CPF CONSIDERANDO AS REGRAS DE FORMAÇÃO DO DÍGITO VERIFICADOR
int validarCPF(char cpf[])
{
  int i, digito1, digito2;
  
  for(i=0; cpf[i]!='\0'; i++)
  {
    if(cpf[i]<'0'||cpf[i]>'9')
      return 0;
  }
  
  if(i!=11)
    return 0;

  for(i=8, digito1=0; i>=0; i--)
    digito1+=(cpf[i]-'0')*(10-i);
  digito1*=10;
  digito1%=11;

  if(digito1==10)
    digito1=0;

  printf("\n\nDigito 1=%d\n\n", digito1);
  if(digito1!=(cpf[9]-'0'))
  {
    printf("\n\nDigito 1 inválido!\n\n");
    return 0;
  }

  for(i=9, digito2=0; i>=0; i--)
    digito2+=(cpf[i]-'0')*(11-i);
  digito2*=10;
  digito2%=11;

  if(digito2==10)
    digito2=0;

  printf("\n\nDigito 2=%d\n\n", digito2);
  if(digito2!=(cpf[10]-'0'))
  {
    printf("Digito 2 inválido!\n\n");
    return 0;
  }
  
  return 1;
}

void gerarCPF(char cpf[])
{
  int i, digito1, digito2;

  srand(time(NULL));
  
  for(i=0, digito1=0, digito2=0; i<9; cpf[i]=('0'+rand()%10), digito1+=(cpf[i]-'0')*(10-i), digito2+=(cpf[i]-'0')*(11-i), i++);
  
  digito1*=10;
  digito1%=11;
  if(digito1==10)
    digito1=0;

  cpf[9]=(digito1+'0');

  digito2+=(cpf[9]-'0')*(11-i);
  digito2*=10;
  digito2%=11;
  if(digito2==10)
    digito2=0;

  cpf[10]=(digito2+'0');
  
  cpf[11]='\0';
}

long int formatNumCPF(char cpf[])
{
  int i=0, mult;
  long int numCPF;
  for(i=0; cpf[i+1]!='\0'; i++);

  for(i, mult=1,numCPF=0; i>=0; numCPF+=(cpf[i]-'0')*10, mult*=10, i--);

  return numCPF;
}

int buscaCPF(pess pessoal[], int tam, int chave)
{
  for(int i=0; i<tam; i++)
  {
    if(pessoal[i].numCPF==chave)
      return i;
  }
  return -1;
}


int validarSexo(char sexo)
{
  if(sexo=='M'||sexo=='m'||sexo=='F'||sexo=='f')
    return 1;
  else
    return 0;
}