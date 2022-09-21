/*
• Cadastro de Alunos (Matrícula, Nome, Sexo, Data Nascimento, CPF) .
• Cadastro de Professores (Matrícula, Nome, Sexo, Data Nascimento, CPF).
• Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
◦ Inserir/Excluir aluno de uma disciplina
• Relatórios
◦ Listar Alunos
◦ Listar Professores
◦ Listar Disciplinas (dados da disciplina sem os alunos)
◦ Listar uma disciplina (dados da disciplina e os alunos matriculados)
◦ Listar Alunos por sexo (Masculino/Feminino)
◦ Listar Alunos ordenados por Nome
◦ Listar Alunos ordenados por data de nascimento
◦ Listar Professores por sexo (Masculino/Feminino)
◦ Listar Professores ordenados por Nome
◦ Listar Professores ordenados por data de nascimento

  
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct reg_cadastro
{
  char matricula[13];
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
  cad cliente[999];
  int j, i=1;
  
  printf("Nome (no máximo 20 caracteres): ");
  fgets(cliente[i].nome, 256, stdin);
  for(j=0; cliente[i].nome[j]!='\n'; j++);
  cliente[i].nome[j]='\0';
  
  cliente[i].validaNome = validarNome(cliente[i].nome);
  
  printf("Data de nascimento\n");
  printf("Dia: ");
  scanf("%d", &cliente[i].nascDia);
  printf("Mes: ");
  scanf("%d", &cliente[i].nascMes);
  printf("Ano (formato aaaa): ");
  scanf("%d", &cliente[i].nascAno);

  cliente[i].validaData = validarNascimento(cliente[i].nascDia, cliente[i].nascMes, cliente[i].nascAno);

  getchar();
  printf("CPF (somente numeros): ");
  fgets(cliente[i].cpf, 30, stdin);
  for(j=0; cliente[i].cpf[j]!='\n'; j++);
  cliente[i].cpf[j]='\0';
  
  cliente[i].validaCPF = validarCPF(cliente.cpf);

  printf("Sexo (m: masculino, f: feminino, o: outro): ");
  scanf("%c", &cliente.sexo);

  cliente[i].validaSexo = validarSexo(cliente.sexo);

  return cliente[i];
}

void main()
{
  cad cadast[5];
  int validacao, i;

  printf("\n====== Cadastro de cliente ======\n");

  for(i=0; i<5; i++)
  {
    cadast[i] = cadastrarCliente();

    validacao = cadast[i].validaNome*cadast[i].validaData*cadast[i].validaCPF*cadast[i].validaSexo;
  
    if(validacao == 1)
    {
      printf("\nDados registrados com sucesso!");
      
      printf("\n\n====== Registro ======");
  
      printf("\nNome: %s", cadast.nome);
    
      printf("\nData de nascimento: %02d/%02d/%d", cadast[i].nascDia, cadast[i].nascMes, cadast[i].nascAno);
    
      printf("\nCPF: ");
      imprimeCPF(cadast[i].cpf);
    
      printf("\nSexo: %c\n", cadast[i].sexo);
    }
  
    else
    {
      printf("\nCadastro não realizado. Favor, verificar os dados:\n");
      if(cadast[i].validaNome==0)
        printf("\t-O nome declarado é inválido!\n");
      if(cadast[i].validaData==0)
        printf("\t-A data declarada é inválida!\n");
      if(cadast[i].validaCPF==0)
        printf("\t-O CPF declarado é inválido!\n");
      if(cadast[i].validaSexo==0)
        printf("\t-Informe somente uma das opções de sexo apresentadas no formulário!\n");
      i--;
    }
  }


}