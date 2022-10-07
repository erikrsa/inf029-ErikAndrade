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
#include "pessoal.h" //Por não ser biblioteca padrão do C, se declara entre aspas duplas

int main(void)
{
  int opcao=1;
  int qtdAluno=0, qtdProfessor=0;
  pess aluno[50], professor[50];
  
  printf("====== SISTEMA ESCOLA ======");

  while(opcao!=0)
  {
    printf("\n\n====> Menu Principal\n\n");
    printf("Digite a opção desejada:\n");
    printf("0. Sair do sistema\n");
    printf("1. Acessar módulo aluno\n");
    printf("2. Acessar módulo professor\n");
    printf("3. Acessar módulo disciplina\n");
    printf("4. Acessar relatórios\n\n");
    
    printf("Sua opção: ");
    scanf("%d", &opcao);
    
    switch (opcao)
    {
      case 0:
      printf("Encerrando o sistema...\n");
      break;
      case 1:
      //printf("Módulo aluno...\n");
      qtdAluno = mainPessoal(aluno, qtdAluno, 'a');
      break;
      case 2:
      //printf("Módulo professor...\n");
      qtdProfessor = mainPessoal(professor, qtdProfessor, 'p');
      break;
      case 3:
      printf("Módulo disciplina...\n");
      break;
      case 4:
      printf("Módulo relatórios...\n");
      break;
      default:
      printf("Opção inválida!");
    }
  }

  return 0;
}