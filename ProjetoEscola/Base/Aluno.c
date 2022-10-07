#include <stdio.h>
#include "Aluno.h"

// int menuAluno()
// {
//   int opcao=1;
//   printf("====> Ambiente do aluno");

//   while(opcao!=0)
//   {
//     printf("Digite a opção desejada:\n");
//     printf("0. Voltar\n");
//     printf("1. Listar alunos\n");
//     printf("2. Cadastrar aluno\n");
//     printf("3. Atualizar dados\n");
//     printf("4. Excluir dados\n");
//   }
// }

int cadastrarAluno(alu alu[], int i, int imprimeTitulo);
void imprimesexo(char sexo, int pulalin);
void imprimeCPF(char cpf[], int pulalin);
void listarAluno(alu aluno[], int qtd);
int menuAluno();
void atualizarAluno(alu alu[], int i);
int excluirDados(alu alu[], int i);


int mainAluno(alu aluno[], int qtdAluno)
{
  int opcao=1;

  //printf("\n====> Ambiente do aluno\n\n");
  while(opcao!=0)
  {
    printf("\n====> Ambiente do aluno\n\n");
    
    opcao = menuAluno();
  
    switch (opcao)
    {
      case 0:
      break;
      case 1:
      //printf("Aqui ficará o módulo listar alunos...\n");
      listarAluno(aluno, qtdAluno);
      break;
      case 2:
      //printf("Aqui ficará o módulo cadastrar alunos...\n");
      qtdAluno=cadastrarAluno(aluno, qtdAluno, 1);
      break;
      case 3:
      //printf("Aqui ficará o módulo atualizar dados...\n");
      atualizarAluno(aluno, qtdAluno);
      break;
      case 4:
      //printf("Aqui ficará o módulo de excluir dados...\n");
      qtdAluno=excluirDados(aluno, qtdAluno);
      break;
      default:
      printf("Opção inválida!");
    }
  }
  
  return qtdAluno;
}

int cadastrarAluno(alu alu[], int i, int imprimeTitulo)
{
  int j;

  if(imprimeTitulo==1)
    printf("\n\n=========== CADASTRO DE ALUNOS ===========\n\n");

  getchar();
  printf("Nome (no máximo 35 caracteres): ");
  fgets(alu[i].nome, 256, stdin);
  for(j=0; alu[i].nome[j]!='\n'; j++);
  alu[i].nome[j]='\0';
  
  //cliente.validaNome = validarNome(cliente.nome);

  printf("Matrícula (somente números): ");
  scanf("%d", &alu[i].matricula);

  //criar um valida matrícula
  
  printf("Data de nascimento\n");
  printf("Dia: ");
  scanf("%d", &alu[i].nascDia);
  printf("Mes: ");
  scanf("%d", &alu[i].nascMes);
  printf("Ano (formato aaaa): ");
  scanf("%d", &alu[i].nascAno);

  //cliente.validaData = validarNascimento(cliente.nascDia, cliente.nascMes, cliente.nascAno);

  getchar();
  printf("CPF (somente numeros): ");
  fgets(alu[i].cpf, 30, stdin);
  for(j=0; alu[i].cpf[j]!='\n'; j++);
  alu[i].cpf[j]='\0';
  
  //alu[i].validaCPF = validarCPF(alu[i].cpf);

  printf("Sexo (m: masculino, f: feminino, o: outro): ");
  scanf("%c", &alu[i].sexo);

  //alu[i].validaSexo = validarSexo(cliente.sexo);

  printf("\n\nDados cadastrados com sucesso!\n");
  printf("*********************************************\n\n");
  i++;
  return i;

  // int j;
  
  // printf("Nome (no máximo 20 caracteres): ");
  // fgets(alu[i].nome, 256, stdin);
  // for(j=0; alu[i].nome[j]!='\n'; j++);
  // alu[i].nome[j]='\0';

  // printf("Matrícula (somente números): ");
  // scanf("%d", &alu[i].matricula);
  // i++;

  // return i;
}

void imprimesexo(char sexo, int pulalin)
{
  switch (sexo)
  {
    case 'f':
    case 'F':
    printf("feminino");
    break;
    case 'm':
    case 'M':
    printf("masculino");
    break;
  }

  if (pulalin==1)
    printf("\n");
}

void imprimeCPF(char cpf[], int pulalin)
{
  printf("%c%c%c.%c%c%c.%c%c%c-%c%c", cpf[0], cpf[1], cpf[2], cpf[3], cpf[4], cpf[5], cpf[6], cpf[7], cpf[8], cpf[9], cpf[10]);
  if (pulalin==1)
    printf("\n");
}

void listarAluno(alu aluno[], int qtd)
{

  int i;
  
  printf("\n\n=========== RELAÇÃO DE ALUNOS ===========\n\n");
  
  if(qtd==0)
  {
    printf("\n-------------------------------------------\n");
    printf("\nNão há dados cadastrados!\n");
    printf("\n-------------------------------------------\n");
    printf("\n*********************************************\n\n");
    return;
  }

  for(int i=0; i<qtd; i++)
  {
    printf("-------------------------------------------\n");
    printf("ID:%d\n", i);
    printf("Nome: %s\n", aluno[i].nome);
    printf("Matrícula: %d\n", aluno[i].matricula);
    printf("Data de nascimento: %02d/%02d/%d\n", aluno[i].nascDia, aluno[i].nascMes, aluno[i].nascAno);
    printf("CPF: ");
    imprimeCPF(aluno[i].cpf, 1);
    printf("Sexo: ");
    imprimesexo(aluno[i].sexo, 1);
    printf("-------------------------------------------\n");
  }
  printf("\n\n*********************************************\n\n");
}

//=======================================================================================
//PROSSEGUIR COM O ALGORITMO DE ATUALIZAR DADOS!!!!
//=======================================================================================
void atualizarAluno(alu alu[], int i)
{
  int j, id, opcao;
  
  printf("\n\n=========== ATUALIZAR DADOS - ALUNOS ===========\n\n");
  switch (i)
  {
    case 0:
    {
    printf("\n-------------------------------------------\n");
    printf("\nNão há dados cadastrados!\n");
    printf("\n-------------------------------------------\n");
    printf("\n*********************************************\n\n");
    return; //VERIFICAR FORMA DE ENCERRAR A FUNÇÃO AQUI!!!
    }
    case 1:
    break;
    default:
    {
      printf("Informe o ID do aluno que deseja atualizar os dados: ");
      scanf("%d", &id);
      if(id<0||id>=i)
      {
        printf("\n-------------------------------------------\n");
        printf("Não há cadastros com o ID informado!");
        printf("\n-------------------------------------------\n");
        printf("\n*********************************************\n\n");
        return;
      }
    }
  }

  printf("\n\n-------------------------------------------\n");
  printf("Informe qual dado deseja atualizar:\n\n");

  printf("0. Cancelar\n");
  printf("1. Nome\n");
  printf("2. Matrícula\n");
  printf("3. Data de nascimento\n");
  printf("4. Sexo\n");
  printf("5. CPF\n");
  printf("6. Todos os dados\n");

  printf("\n\nSua opção: ");
  scanf("%d", &opcao);
  printf("\n-------------------------------------------\n\n");

  switch (opcao)
  {
    case 0:
    return;
    
    case 1:
    {
      getchar();
      printf("Nome (no máximo 20 caracteres): ");
      fgets(alu[id].nome, 256, stdin);
      for(j=0; alu[id].nome[j]!='\n'; j++);
      alu[id].nome[j]='\0';
      break;
      //cliente.validaNome = validarNome(cliente.nome);
    }

    case 2:
    {
      printf("Matrícula (somente números): ");
      scanf("%d", &alu[id].matricula);
      break;
    }
    
    case 3:
    {
      printf("Data de nascimento\n");
      printf("Dia: ");
      scanf("%d", &alu[id].nascDia);
      printf("Mes: ");
      scanf("%d", &alu[id].nascMes);
      printf("Ano (formato aaaa): ");
      scanf("%d", &alu[id].nascAno);
      break;
      //cliente.validaData = validarNascimento(cliente.nascDia, cliente.nascMes, cliente.nascAno);
    }

    case 4:
    {
      printf("Sexo (m: masculino, f: feminino): ");
      scanf("%c", &alu[id].sexo);
      break;
      //alu[i].validaSexo = validarSexo(cliente.sexo);
    }

    case 5:
    {
      getchar();
      printf("CPF (somente numeros): ");
      fgets(alu[id].cpf, 30, stdin);
      for(j=0; alu[id].cpf[j]!='\n'; j++);
      alu[id].cpf[j]='\0';
      break;
      //alu[i].validaCPF = validarCPF(alu[i].cpf);
    }

    case 6:
    {
      cadastrarAluno(alu, id, 0);
      break;
    }
  }

  printf("\n\nDados atualizados com sucesso!\n");
  printf("*********************************************\n\n");
  return;
}

int excluirDados(alu alu[], int i)
{
  int id;
  int deletar;

  printf("\n\n=========== EXCLUIR DADOS - ALUNOS ===========\n\n");
  
  switch (i)
  {
    case 0:
    {
    printf("\n-------------------------------------------\n");
    printf("\nNão há dados cadastrados!\n");
    printf("\n-------------------------------------------\n");
    printf("\n*********************************************\n\n");
    return i;
    }
    case 1:
    id=i-1;
    break;
    default:
    {
      printf("Informe o ID do aluno que cujo dados deseja exluir: ");
      scanf("%d", &id);
      if(id<0||id>=i)
      {
        printf("\n-------------------------------------------\n");
        printf("Não há cadastros com o ID informado!");
        printf("\n-------------------------------------------\n");
        printf("\n*********************************************\n\n");
        return i;
      }
    }
  }

  printf("\n\n=========== DADOS PARA EXCLUIR ===========\n\n");
  printf("-------------------------------------------\n");
  printf("ID:%d\n", id);
  printf("Nome: %s\n", alu[id].nome);
  printf("Matrícula: %d\n", alu[id].matricula);
  printf("Data de nascimento: %02d/%02d/%d\n", alu[id].nascDia, alu[id].nascMes, alu[id].nascAno);
  printf("CPF: ");
  imprimeCPF(alu[id].cpf, 1);
  printf("Sexo: ");
  imprimesexo(alu[id].sexo, 1);
  printf("-------------------------------------------\n");

  printf("\nConfirma exclusão? (1 para confirmar): ");
  scanf("%d", &deletar);

  if(deletar==1)
  {
    for(int j=id; j<i-1; alu[j]=alu[j+1], j++);
    printf("\n\nExclusão realizada com êxito!");
    i--;
    printf("\n*********************************************\n\n");
    return i;
  }

  else
  {
    printf("\n\nExclusão cancelada.");
    printf("\n*********************************************\n\n");
    return i;
  }
}

int menuAluno()
{
  int opcao;
  
  printf("Digite a opção desejada:\n");
  printf("0. Voltar\n");
  printf("1. Listar alunos\n");
  printf("2. Cadastrar aluno\n");
  printf("3. Atualizar dados\n");
  printf("4. Excluir dados\n\n");

  printf("Sua opção: ");
  scanf("%d", &opcao);

  return opcao;
}