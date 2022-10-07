#include <stdio.h>
#include "pessoal.h"
//#include "validarDados.h"

int cadastrarPessoal(pess pessoal[],  int i, int imprimeTitulo, char tipo);
void imprimesexo(char sexo, int pulalin);
void imprimeCPF(char cpf[], int pulalin);
void listarPessoal(pess pessoal[], int qtd, char tipo);
int menuPessoal();
void atualizarPessoal(pess alu[], int i, char tipo);
int excluirDados(pess alu[], int i, char tipo);


int mainPessoal(pess pessoal[], int qtdPessoal, char tipo)
{
  int opcao=1;
 
  while(opcao!=0)
  {
    if(tipo=='a')
      printf("\n====> Ambiente do aluno\n\n");
    else
      printf("\n====> Ambiente do professor\n\n");
    
    opcao = menuPessoal();
  
    switch (opcao)
    {
      case 0:
      break;
      case 1:
      //printf("Aqui ficará o módulo listar alunos...\n");
      listarPessoal(pessoal, qtdPessoal, tipo);
      break;
      case 2:
      //printf("Aqui ficará o módulo cadastrar alunos...\n");
      qtdPessoal=cadastrarPessoal(pessoal, qtdPessoal, 1, tipo);
      break;
      case 3:
      //printf("Aqui ficará o módulo atualizar dados...\n");
      atualizarPessoal(pessoal, qtdPessoal, tipo);
      break;
      case 4:
      //printf("Aqui ficará o módulo de excluir dados...\n");
      qtdPessoal=excluirDados(pessoal, qtdPessoal, tipo);
      break;
      default:
      printf("Opção inválida!");
    }
  }
  
  return qtdPessoal;
}

int cadastrarPessoal(pess pessoal[],  int i, int imprimeTitulo, char tipo)
{
  int j, tentativa, existe, outrapessoa;

  if(imprimeTitulo==1)
  {
    if(tipo=='a')
        printf("\n\n=========== CADASTRO DE ALUNOS ===========\n\n");
    else
      printf("\n\n========= CADASTRO DE PROFESSORES =========\n\n");
  }

  
  //-------------------------------------------------------------------------------------------------
  //CADASTRO DE NOME
  //-------------------------------------------------------------------------------------------------
  pessoal[i].validaNome=0;
  
  while(pessoal[i].validaNome==0)
  {
     //INPUT 
    getchar();
    printf("Nome (no máximo 35 caracteres): ");
    fgets(pessoal[i].nome, 256, stdin);
    for(j=0; pessoal[i].nome[j]!='\n'; j++);
    pessoal[i].nome[j]='\0';
  
    //VALIDAÇÃO
    pessoal[i].validaNome = validarNome(pessoal[i].nome);

    //TORNAR MAIÚSCULAS AS LETRAS
    maiuscula(pessoal[i].nome);

    //ERRO-TRY AGAIN
    if(pessoal[i].validaNome==0)
    {
      printf("\nEntrada inválida! Digite 1 para tentar mais uma vez: ");
      scanf("%d", &tentativa);
      if(tentativa!=1)
      {
        printf("\n\nCadastro cancelado!\n");
        printf("*********************************************\n\n");
        return i;
      }
        
    }
  }

  //-------------------------------------------------------------------------------------------------
  //CADASTRO DE MATRÍCULA
  //-------------------------------------------------------------------------------------------------
  pessoal[i].validaMatricula=0;  //Para entrar no loop abaixo

  existe=1;  //Para entrar no loop abaixo
  
  while(pessoal[i].validaMatricula==0 || existe!=-1)
  {
    //INPUT
    printf("Matrícula (máximo 5 últimos números): ");
    scanf("%ld", &pessoal[i].matricula);
  
    //VALIDAÇÃO
    pessoal[i].validaMatricula = validarMatricula(pessoal[i].matricula);

    //FORMATAÇÃO
    pessoal[i].matricula=formatarMatricula(pessoal[i].matricula);

    //PROCURAR SE HÁ ALGUM CADASTRO COM A MATRÍCULA INFORMADA
    existe = buscaMatricula(pessoal, i, pessoal[i].matricula);

    //ERRO-TRY AGAIN
    if(pessoal[i].validaMatricula==0 || existe!=-1)
    {
      if(pessoal[i].validaMatricula==0)
      printf("\nEntrada inválida!");
      
      if(existe!=-1)
      printf("\nMatrícula já cadastrada!");
      
      printf(" Digite 1 para tentar mais uma vez: ");
      scanf("%d", &tentativa);
      if(tentativa!=1)
      {
        printf("\n\nCadastro cancelado!\n");
        printf("*********************************************\n\n");
        return i;
      }
    }
  }

  //-------------------------------------------------------------------------------------------------
  //CADASTRO DATA DE NASCIMENTO
  //-------------------------------------------------------------------------------------------------
  pessoal[i].validaData=0;  //Para entrar no loop abaixo
  
  while(pessoal[i].validaData==0)
  {
    //INPUT
    getchar();
    printf("Data de nascimento (dd/mm/aaaa): ");
    fgets(pessoal[i].data.Tdata, 12, stdin);
    for(j=0; pessoal[i].data.Tdata[j]!='\n'; j++);
    pessoal[i].data.Tdata[j]='\0';

    //FORMATAÇÃO
    pessoal[i].data=formatarData(pessoal[i].data.Tdata);

    //VALIDAÇÃO
    pessoal[i].validaData = validarNascimento(pessoal[i].data.dia, pessoal[i].data.mes, pessoal[i].data.ano);

    //ERRO-TRY AGAIN
    if(pessoal[i].validaData==0)
    {
      if(pessoal[i].validaData==0)
      printf("\nEntrada inválida!");
      
      printf(" Digite 1 para tentar mais uma vez: ");
      scanf("%d", &tentativa);
      if(tentativa!=1)
      {
        printf("\n\nCadastro cancelado!\n");
        printf("*********************************************\n\n");
        return i;
      }
    }
  }

  //-------------------------------------------------------------------------------------------------
  //CADASTRO CPF
  //-------------------------------------------------------------------------------------------------
  //getchar();
  pessoal[i].validaCPF=0;  //Para entrar no loop abaixo

  existe=1;  //Para entrar no loop abaixo
  
  printf("CPF (somente numeros): ");
  fgets(pessoal[i].cpf, 30, stdin);
  for(j=0; pessoal[i].cpf[j]!='\n'; j++);
  pessoal[i].cpf[j]='\0';
  
  //alu[i].validaCPF = validarCPF(alu[i].cpf);

  pessoal[i].validaMatricula=0;  //Para entrar no loop abaixo

  existe=1;  //Para entrar no loop abaixo

  outrapessoa=1;
  
  while(pessoal[i].validaCPF==0 || existe!=-1 || outrapessoa!=-1)
  {
    //INPUT
    printf("CPF (somente numeros): ");
    fgets(pessoal[i].cpf, 30, stdin);
    for(j=0; pessoal[i].cpf[j]!='\n'; j++);
    pessoal[i].cpf[j]='\0';
  
    //VALIDAÇÃO
    pessoal[i].validaCPF = validarCPF(pessoal[i].cpf);

    //CRIA CPF NO FORMATO DE NÚMERO
    pessoal[i].numCPF=formatNumCPF(pessoal[i].cpf);

    //PROCURAR SE HÁ ALGUM CADASTRO COM A MATRÍCULA INFORMADA
    existe = buscaCPF(pessoal, i, pessoal[i].numCPF);

    //PROCURAR SE HÁ ALGUM CADASTRO NOS PROFESSORES COM NOME DIFERENTE
    outrapessoa = buscaCPF(pessoal, i, pessoal[i].numCPF);
    //Condicionar ao nome ser diferente CRIAR FUNÇÃO PARA BUSCAR NOME

    //ERRO-TRY AGAIN
    if(pessoal[i].validaMatricula==0 || existe!=-1 || outrapessoa!=-1)
    {
      if(pessoal[i].validaMatricula==0)
      printf("\nEntrada inválida!");
      
      if(existe!=-1)
      printf("\nCPF já cadastrado (no ID %d)!", existe);

      if(outrapessoa==!-1)
      printf("\nCPF cadastrado no nome de outra pessoa! Verifique o ID %d do módulo de professores.", outrapessoa);
      
      printf(" Digite 1 para tentar mais uma vez: ");
      scanf("%d", &tentativa);
      if(tentativa!=1)
      {
        printf("\n\nCadastro cancelado!\n");
        printf("*********************************************\n\n");
        return i;
      }
    }
  }
  
  //-------------------------------------------------------------------------------------------------
  //CADASTRO SEXO
  //-------------------------------------------------------------------------------------------------
  printf("Sexo (m: masculino, f: feminino): ");
  scanf("%c", &pessoal[i].sexo);

  //alu[i].validaSexo = validarSexo(cliente.sexo);

  //-------------------------------------------------------------------------------------------------
  //THE END - CADASTRO
  //-------------------------------------------------------------------------------------------------
  printf("\n\nDados cadastrados com sucesso!\n");
  printf("*********************************************\n\n");
  i++;
  return i;
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

void listarPessoal(pess pessoal[], int qtd, char tipo)
{

  int i;

  if(tipo=='a')
    printf("\n\n=========== RELAÇÃO DE ALUNOS ===========\n\n");
  else
    printf("\n\n========= RELAÇÃO DE PROFESSORES =========\n\n");

  
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
    printf("Nome: %s\n", pessoal[i].nome);
    printf("Matrícula: %ld\n", pessoal[i].matricula);
    printf("Data de nascimento: %02d/%02d/%d\n", pessoal[i].data.dia, pessoal[i].data.mes, pessoal[i].data.ano);
    printf("CPF: ");
    imprimeCPF(pessoal[i].cpf, 1);
    printf("Sexo: ");
    imprimesexo(pessoal[i].sexo, 1);
    printf("-------------------------------------------\n");
  }
  printf("\n\n*********************************************\n\n");
}

void atualizarPessoal(pess pessoal[], int i, char tipo)
{
  int j, id, opcao;

  if(tipo=='a')
    printf("\n\n=========== ATUALIZAR DADOS - ALUNOS ===========\n\n");
  else
    printf("\n\n=========== ATUALIZAR DADOS - PROFESSORES ===========\n\n");
  
  switch (i)
  {
    case 0:
    {
    printf("\n-------------------------------------------\n");
    printf("\nNão há dados cadastrados!\n");
    printf("\n-------------------------------------------\n");
    printf("\n*********************************************\n\n");
    return;
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
      fgets(pessoal[id].nome, 256, stdin);
      for(j=0; pessoal[id].nome[j]!='\n'; j++);
      pessoal[id].nome[j]='\0';
      break;
      //cliente.validaNome = validarNome(cliente.nome);
    }

    case 2:
    {
      printf("Matrícula (somente números): ");
      scanf("%ld", &pessoal[id].matricula);
      break;
    }
    
    case 3:
    {
      printf("Data de nascimento\n");
      printf("Dia: ");
      scanf("%d", &pessoal[id].nascDia);
      printf("Mes: ");
      scanf("%d", &pessoal[id].nascMes);
      printf("Ano (formato aaaa): ");
      scanf("%d", &pessoal[id].nascAno);
      break;
      //cliente.validaData = validarNascimento(cliente.nascDia, cliente.nascMes, cliente.nascAno);
    }

    case 4:
    {
      getchar();
      printf("Sexo (m: masculino, f: feminino): ");
      scanf("%c", &pessoal[id].sexo);
      break;
      //alu[i].validaSexo = validarSexo(cliente.sexo);
    }

    case 5:
    {
      getchar();
      printf("CPF (somente numeros): ");
      fgets(pessoal[id].cpf, 30, stdin);
      for(j=0; pessoal[id].cpf[j]!='\n'; j++);
      pessoal[id].cpf[j]='\0';
      break;
      //alu[i].validaCPF = validarCPF(alu[i].cpf);
    }

    case 6:
    {
      cadastrarPessoal(pessoal, id, 0, tipo);
      break;
    }
  }

  printf("\n\nDados atualizados com sucesso!\n");
  printf("*********************************************\n\n");
  return;
}

int excluirDados(pess pessoal[], int i, char tipo)
{
  int id;
  int deletar;

  if(tipo=='a')
    printf("\n\n=========== EXCLUIR DADOS - ALUNOS ===========\n\n");
  else
    printf("\n\n========= EXCLUIR DADOS - PROFESSORES =========\n\n");
  
  
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
  printf("Nome: %s\n", pessoal[id].nome);
  printf("Matrícula: %ld\n", pessoal[id].matricula);
  printf("Data de nascimento: %02d/%02d/%d\n", pessoal[id].nascDia, pessoal[id].nascMes, pessoal[id].nascAno);
  printf("CPF: ");
  imprimeCPF(pessoal[id].cpf, 1);
  printf("Sexo: ");
  imprimesexo(pessoal[id].sexo, 1);
  printf("-------------------------------------------\n");

  printf("\nConfirma exclusão? (1 para confirmar): ");
  scanf("%d", &deletar);

  if(deletar==1)
  {
    for(int j=id; j<i-1; pessoal[j]=pessoal[j+1], j++);
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

int menuPessoal()
{
  int opcao;
   
  printf("Digite a opção desejada:\n");
  printf("0. Voltar\n");
  printf("1. Listar cadastrados\n");
  printf("2. Novo cadastro\n");
  printf("3. Atualizar dados\n");
  printf("4. Excluir dados\n\n");

  printf("Sua opção: ");
  scanf("%d", &opcao);

  return opcao;
}