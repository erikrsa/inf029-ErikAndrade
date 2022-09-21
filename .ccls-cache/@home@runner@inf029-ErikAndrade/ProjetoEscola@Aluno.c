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

int cadastrarAluno(alu alu[], int i);
void imprimesexo(char sexo, int pulalin);
void listarAluno(alu aluno[], int qtd);
int menuAluno();
void imprimesexo(char sexo, int pulalin);
alu atualizarAluno(alu Aluno, int qtd);


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
      qtdAluno=cadastrarAluno(aluno, qtdAluno);
      break;
      case 3:
      printf("Aqui ficará o módulo atualizar dados...\n");
      break;
      case 4:
      printf("Aqui ficará o módulo de excluir dados...\n");
      break;
      default:
      printf("Opção inválida!");
    }
  }
  
  return qtdAluno;
}

int cadastrarAluno(alu alu[], int i)
{
  int j;

  printf("\n\n=========== CADASTRO DE ALUNOS ===========\n\n");
  getchar();
  printf("Nome (no máximo 20 caracteres): ");
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
    default:
    printf("outro");
  }

  if (pulalin==1)
    printf("\n");
}

void listarAluno(alu aluno[], int qtd)
{
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
    printf("Sexo: ");
    imprimesexo(aluno[i].sexo, 1);
    printf("-------------------------------------------\n");
  }
  printf("\n\n*********************************************\n\n");
}

//=======================================================================================
//PROSSEGUIR COM O ALGORITMO DE ATUALIZAR DADOS!!!!
//=======================================================================================
alu atualizarAluno(alu Aluno, int qtd)
{
  switch (qtd)
  {
    case 0:
    {
    printf("\n-------------------------------------------\n");
    printf("\nNão há dados cadastrados!\n");
    printf("\n-------------------------------------------\n");
    printf("\n*********************************************\n\n");
    break; //VERIFICAR FORMA DE ENCERRAR A FUNÇÃO AQUI!!!
    }
    // case 1:
    // {}
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