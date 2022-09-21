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
#include "Aluno.h" //Por não ser biblioteca padrão do C, se declara entre aspas duplas

// typedef struct reg_cadastro
// {
//   char matricula[13];
//   char nome[256];
//   char data[12];
//   int nascDia;
//   int nascMes;
//   int nascAno;
//   char cpf[30];
//   char sexo;
//   int validaNome;
//   int validaData;
//   int validaCPF;
//   int validaSexo;
// }cad;


// int questao74()
// {
// /*
// Q74. Escreva um programa em C que armazene um vetor de até 30 inteiros. O programa deve
// fornecer as seguintes operações:
// a. Inserir um elemento no final do vetor
// b. Inserir um elemento em uma dada posição
// c. Remover um elemento de uma posição indicada
// d. Remover todos elementos iguais a um valor indicado
// */
//     char op;
//     int limite=7, i, j, k, tam=1, tamnovo, array[limite], novo[limite], valor, repetido;
    
//     do
//     {
//         printf("\nInforme o que deseja:\n");
//         printf("\n\t<a> Inserir elemento no final do vetor");
//         printf("\n\t<b> Inserir elemento em uma dada posicao");
//         printf("\n\t<c> Remover elemento de uma posicao indicada");
//         printf("\n\t<d> Remover todos elementos iguais a um valor indicado");
//         printf("\n\t<e> Gerar um novo vetor sem duplicidades");
//         printf("\n\t<f> Sair do programa");
//         printf("\n\tSua opcao: ");
//         scanf(" %c", &op);
        
//         switch(op)
//         {
//             case 'a':
//             {
//                 i=tam-1;
//                 printf("\nInforme o elemento: ");
//                 scanf("%d", &array[i]);
//                 break;
//             }
            
//             case 'b':
//             {
//                 printf("\nINSERIR: informe a posicao <de 0 a %d>: ", tam-1);
//                 scanf("%d", &i);
//                 j=tam-1;
//                 for(j; j>=i; array[j+1]=array[j], j--);
                
//                 printf("Elemento da posicao %d = ", i);
//                 scanf("%d", &array[i]);
//                 break;
//             }
            
//             case 'c':
//             {
//                 printf("\nDELETAR: informe a posicao <de 0 a %d>: ", tam-1);
//                 scanf("%d", &i);
//                 if(i>tam)
//                 printf("Erro: essa posicao nao existe no vetor!!!");
//                 else
//                 {
//                     tam--;
//                     for(j=i; j<tam; array[j]=array[j+1], j++);
//                     array[j]=-1;
//                 }
//                 break;
//             }
            
//             case 'd':
//             {
//                 printf("\nInforme o valor que deseja deletar: ");
//                 scanf("%d", &valor);
                
//                 for(i=0; i<tam; i++)
//                 {
//                     if(array[i]==valor)
//                     {
//                         tam--;
//                         for(j=i; j<tam; array[j]=array[j+1], j++);
//                         array[j]=-1;
//                         i--;
//                     }
//                 }
//                 break;
//             }
            
//             case 'e':
//             {
//                 novo[0]=array[0];
                
//                 for(i=1, j=1; i<tam; i++)
//                 {
//                     for(k=i-1, repetido=0; k>=0; k--)
//                     {
//                         if(array[k]==array[i])
//                         repetido=1;
//                     }
                    
//                     if(repetido==0)
//                     {
//                         novo[j]=array[i];
//                         j++;
//                     }
//                 }
//                 break;
//             }
            
           
            
//             case 'f':
//             continue;
            
//             default:
//             printf("\nErro: opcao invalida!!!");
//         }
    
//         printf("\nResultado:\nVetor =");
//         for(i=0; i<tam; i++)
//         {
//             if(array[i]!=-1)
//             printf(" %d", array[i]);
//         }

                
//         if(op=='e')
//         {
//             printf("\nNovo vetor =");
//             for(i=0; i<j; printf(" %d", novo[i]), i++);
//         }
        
//         if(tam<limite)
//             tam++;
//         printf("\n\n");
//     }while(op!='f');
    
//     return 0;
// }

// int validarNome(char nome[])
// {
//   int i;
//   for(i=0; nome[i]!='\0' && i<22; i++);
//   if(i>21||i==0)
//     return 0;
//   else
//     return 1;
// }

// int ehbissexto(int ano)
// {
//   if((ano%4==0) && ((ano%400==0) || (ano%100!=0)))
// 		return 1; //O ano é bissexto
// 	else
// 	  return 0; //O ano não é bissexto
// }

// int validarNascimento(int dia, int mes, int ano)
// {
//   int hojeDia=6, hojeMes=9, hojeAno=2022, bissexto=0;

//   if(ano<1700) //Partindo-se da premissa de que não ha conhecimento comum e amplamente divulgado no mundo, até o momento, de uma pessoa tricentenária
//     return 0;
//   if(mes<1||mes>12)
//     return 0;
//   if(dia<1)
//     return 0;
  
//   if(ano>hojeAno)
//     return 0;
//   if(mes>hojeMes && ano==hojeAno)
//     return 0;
//   if(dia>hojeDia && mes==hojeMes && ano==hojeAno)
//     return 0;

//   if(mes==2)
//   {
//     if(ehbissexto(ano)==1)
//     {
//       if(dia>29)
//       return 0;
//     }
      
//     else if(dia>28)
//       return 0;
//   }
	
// 	else if((mes<=7 && mes%2!=0)||(mes>7 && mes%2==0))
//   {
//     if(dia>31)
//       return 0;
//   }
	
// 	else
//   {
//     if(dia>30)
//       return 0;
//   }

//   return 1;
// }


// int validarCPF(char cpf[])
// {
//   int i;
  
//   for(i=0; cpf[i]!='\0'; i++)
//   {
//     if(cpf[i]<'0'||cpf[i]>'9')
//       return 0;
//   }
  
//   if(i!=11)
//     return 0;
  
//   return 1;
// }

// void imprimeCPF(char cpf[])
// {
//   printf("%c%c%c.%c%c%c.%c%c%c-%c%c", cpf[0], cpf[1], cpf[2], cpf[3], cpf[4], cpf[5], cpf[6], cpf[7], cpf[8], cpf[9], cpf[10]);

// }

// int validarSexo(char sexo)
// {
//   if(sexo=='M'||sexo=='m'||sexo=='F'||sexo=='f'||sexo=='o'||sexo=='O')
//     return 1;
//   else
//     return 0;
// }

// cad cadastrarCliente()
// {
//   cad cliente;
//   int j, i=1;
  
//   printf("Nome (no máximo 20 caracteres): ");
//   fgets(cliente.nome, 256, stdin);
//   for(j=0; cliente.nome[j]!='\n'; j++);
//   cliente.nome[j]='\0';
  
//   cliente.validaNome = validarNome(cliente.nome);
  
//   printf("Data de nascimento\n");
//   printf("Dia: ");
//   scanf("%d", &cliente.nascDia);
//   printf("Mes: ");
//   scanf("%d", &cliente.nascMes);
//   printf("Ano (formato aaaa): ");
//   scanf("%d", &cliente.nascAno);

//   cliente.validaData = validarNascimento(cliente.nascDia, cliente.nascMes, cliente.nascAno);

//   getchar();
//   printf("CPF (somente numeros): ");
//   fgets(cliente.cpf, 30, stdin);
//   for(j=0; cliente.cpf[j]!='\n'; j++);
//   cliente.cpf[j]='\0';
  
//   cliente.validaCPF = validarCPF(cliente.cpf);

//   printf("Sexo (m: masculino, f: feminino, o: outro): ");
//   scanf("%c", &cliente.sexo);

//   cliente.validaSexo = validarSexo(cliente.sexo);

//   return cliente;
// }

// void main()
// {
//   cad cadast[5];
//   int validacao, i, opcao=1;

//   printf("========== SISTEMA ESCOLA ========== ");

//   while(opcao!=0)
//   {
//     printf("Digite ")
//   }

//   printf("\n====== Cadastro de cliente ======\n");

//   for(i=0; i<5; i++)
//   {
//     cadast[i] = cadastrarCliente();

//     validacao = cadast[i].validaNome*cadast[i].validaData*cadast[i].validaCPF*cadast[i].validaSexo;
  
//     if(validacao == 1)
//     {
//       printf("\nDados registrados com sucesso!");
      
//       printf("\n\n====== Registro ======");
  
//       printf("\nNome: %s", cadast[i].nome);
    
//       printf("\nData de nascimento: %02d/%02d/%d", cadast[i].nascDia, cadast[i].nascMes, cadast[i].nascAno);
    
//       printf("\nCPF: ");
//       imprimeCPF(cadast[i].cpf);
    
//       printf("\nSexo: %c\n", cadast[i].sexo);
//     }
  
//     else
//     {
//       printf("\nCadastro não realizado. Favor, verificar os dados:\n");
//       if(cadast[i].validaNome==0)
//         printf("\t-O nome declarado é inválido!\n");
//       if(cadast[i].validaData==0)
//         printf("\t-A data declarada é inválida!\n");
//       if(cadast[i].validaCPF==0)
//         printf("\t-O CPF declarado é inválido!\n");
//       if(cadast[i].validaSexo==0)
//         printf("\t-Informe somente uma das opções de sexo apresentadas no formulário!\n");
//       i--;
//     }

//     getchar();
    
//   }


// }

int main(void)
{
  int opcao=1;
  int qtdAluno=0;
  alu aluno[50];
  
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
      qtdAluno = mainAluno(aluno, qtdAluno);
      break;
      case 2:
      printf("Módulo professor...\n");
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