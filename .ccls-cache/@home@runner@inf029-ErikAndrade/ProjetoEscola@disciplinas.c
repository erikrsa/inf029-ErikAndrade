#include <stdio.h>
#include "disciplinas.h"
//#include "validarDados.h"


int cadastrarPessoal(pess pessoal[],  int i, int imprimeTitulo, char tipo, pess pessoal2[], int h, char opcao);
void imprimesexo(char sexo, int pulalin);
void imprimeCPF(char cpf[], int pulalin);
void imprimeDados(pess pessoal[], int i);
void listarDisciplinas(disci disciplina[], int qtd);
char menuDisciplina();
void atualizarPessoal(pess pessoal[], int i, char tipo, pess pessoal2[], int h);
int excluirDados(pess alu[], int i, char tipo);


//int mainDisciplina(disci disciplina[], int qtdDisciplina, pess pessoal2[], int qtdPessoal2)//verificar as entradas
int mainDisciplina(disci disciplina[], int qtdDisciplina)
{
  char opcao='1';
   
  while(opcao!='0')
  {
    opcao = menuDisciplina(opcao);
  
    switch (opcao)
    {
      /*
        printf("Digite a opção desejada:\n");
        printf("0. Voltar\n");
        printf("1. Listar Disciplinas\n");
        printf("2. Cadastrar nova disciplina\n");
        printf("3. Atualizar dados da disciplina\n");
        printf("4. Inserir/excluir alunos\n\n");
        printf("5. Inserir/excluir professores\n\n");
        printf("6. Excluir disciplina\n\n");
      */
      case '0':
      return qtdDisciplina;
      
      case '1':
      printf("Aqui ficará o módulo listar disciplinas...\n");
      // listarDisciplinas(disciplina, qtdDisciplina);
      break;
      
      case '2':
      printf("Aqui ficará o módulo cadastrar nova disciplina...\n");
      // qtdDisciplina=cadastrarDisciplina(pessoal, qtdPessoal, 1, tipo, pessoal2, qtdPessoal2, '6');
      break;
      
      case '3':
      printf("Aqui ficará o módulo atualizar dados da disciplina...\n");
      // atualizarPessoal(pessoal, qtdPessoal, tipo, pessoal2, qtdPessoal2);
      break;
      
      case '4':
      printf("Inserir/excluir alunos em uma disciplina...\n");
      //qtdPessoal=excluirDados(pessoal, qtdPessoal, tipo);
      break;

      case '5':
      printf("Inserir/excluir professores em uma disciplina...\n");

      case '6':
      printf("Escluir disciplina...\n");

      default:
      printf("Opção inválida!\n");
      continue;
    }
  }
  
  return qtdDisciplina;
}


//int cadastrarDisciplina(disci disciplina[],  int i, int imprimeTitulo, char tipo, pess pessoal2[], int h, char opcao)
int cadastrarDisciplina(disci disciplina[],  int i, int imprimeTitulo, char opcao)
{
  int j, existe, outrapessoa;
  char tentativa, entrada[256];
  //char cpfgera[] = {'g', 'e', 'r', 'a', 'c', 'p', 'f', '\0'}, tentativa, entrada[256];

  if(imprimeTitulo==1)
    printf("\n\n========= CADASTRO DE DISCIPLINAS =========\n\n");

  //• Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
  //-------------------------------------------------------------------------------------------------
  //CADASTRO DE NOME
  //-------------------------------------------------------------------------------------------------
  if(opcao=='1' || opcao=='6')
  {
    disciplina[i].validaNome=0;
    existe=0;
  
    while(disciplina[i].validaNome==0)
    {
      //INPUT 
      //getchar();
      printf("Nome (no máximo 35 caracteres): ");
      fgets(disciplina[i].nome, 256, stdin);
      for(j=0; disciplina[i].nome[j]!='\n'; j++);
      disciplina[i].nome[j]='\0';
    
      //VALIDAÇÃO
      disciplina[i].validaNome = validarNome(disciplina[i].nome);
  
      //TORNAR MAIÚSCULAS AS LETRAS
      maiuscula(disciplina[i].nome);

      //VERIFICAR SE A DISCIPLINA JÁ FOI CADASTRADA
      existe=buscaDisciplina(disciplina, i, disciplina[i].nome);
  
      //ERRO-TRY AGAIN
      if(disciplina[i].validaNome==0 && existe!=-1)
      {
        if(disciplina[i].validaNome==0)
          printf("\nEntrada inválida!");
        else
          printf("Disciplina já cadastrada! Verifique a disciplina cadastrada no ID %d", existe);          
        
        printf(" Digite 1 para tentar mais uma vez: ");
        tentativa = lerChar(entrada, 256);
        //scanf("%c", &tentativa);
        if(tentativa!='1')
        {
          if(imprimeTitulo==1)
          {
            printf("\n\nCadastro cancelado!\n");
            printf("*********************************************\n\n");
          }
          return i;
        }
          
      }
    }
  }


  //-------------------------------------------------------------------------------------------------
  //CADASTRO DE CÓDIGO
  //-------------------------------------------------------------------------------------------------

  if(opcao=='2' || opcao=='6')
  {
    pessoal[i].validaMatricula=0;  //Para entrar no loop abaixo

    existe=1;  //Para entrar no loop abaixo
  
    while(pessoal[i].validaMatricula==0 || existe!=-1)
    {
      //INPUT
      printf("Matrícula (máximo 5 últimos números): ");
      fgets(pessoal[i].Tmatricula, 256, stdin);
      for(j=0; pessoal[i].Tmatricula[j]!='\n'; j++);
      pessoal[i].Tmatricula[j]='\0';
  
      //FORMATAR MATRÍCULA EM NÚMERO
      pessoal[i].matricula = formatNumMatricula(pessoal[i].Tmatricula);
      
      //VALIDAÇÃO
      pessoal[i].validaMatricula = validarMatricula(pessoal[i].matricula);
  
      // //FORMATAÇÃO DA MATRÍCULA
      // pessoal[i].matricula=formatarMatricula(pessoal[i].matricula);
  
      // //PROCURAR SE HÁ ALGUM CADASTRO COM A MATRÍCULA INFORMADA
      // existe = buscaMatricula(pessoal, i, pessoal[i].matricula);
      
  
      //ERRO-TRY AGAIN
      if(pessoal[i].validaMatricula==0 || existe!=-1)
      {
        if(pessoal[i].validaMatricula==0)
        printf("\nEntrada inválida!");
  
        else
        {
          //FORMATAÇÃO DA MATRÍCULA
          pessoal[i].matricula=formatarMatricula(pessoal[i].matricula, tipo);
  
          //PROCURAR SE HÁ ALGUM CADASTRO COM A MATRÍCULA INFORMADA
          existe = buscaMatricula(pessoal, i, pessoal[i].matricula);
  
          if(existe!=-1)
            printf("\nMatrícula já cadastrada!");
          else
            continue;
        }
        
        // if(existe!=-1)
        // printf("\nMatrícula já cadastrada!");
        
        printf(" Digite 1 para tentar mais uma vez: ");
        tentativa = lerChar(entrada, 256);
        //scanf("%c", &tentativa);
        //getchar();
        if(tentativa!='1')
        {
          if(imprimeTitulo==1)
          {
            printf("\n\nCadastro cancelado!\n");
            printf("*********************************************\n\n");
          }
          return i;
        }
      }
    }
  }


  //-------------------------------------------------------------------------------------------------
  //CADASTRO SEMESTRE
  //-------------------------------------------------------------------------------------------------
 
  if(opcao=='3' || opcao=='6')
  {
    pessoal[i].validaData=0;  //Para entrar no loop abaixo
  
    while(pessoal[i].validaData==0)
    {
      //INPUT
      //getchar();
      printf("Data de nascimento (dd/mm/aaaa): ");
      fgets(pessoal[i].data.Tdata, 256, stdin);
      for(j=0; pessoal[i].data.Tdata[j]!='\n'; j++);
      pessoal[i].data.Tdata[j]='\0';
  
      //FORMATAÇÃO
      pessoal[i].data=formatarData(pessoal[i].data.Tdata);
      
  
      //VALIDAÇÃO
      if(pessoal[i].data.erro==0)
        pessoal[i].validaData = validarNascimento(pessoal[i].data.dia, pessoal[i].data.mes, pessoal[i].data.ano);
      
      //ERRO-TRY AGAIN
      if(pessoal[i].validaData==0)
      {
        if(pessoal[i].validaData==0)
        printf("\nEntrada inválida!");
        
        printf(" Digite 1 para tentar mais uma vez: ");
        tentativa = lerChar(entrada, 256);
        // scanf("%c", &tentativa);
        // getchar();
        if(tentativa!='1')
        {
          if(imprimeTitulo==1)
          {
            printf("\n\nCadastro cancelado!\n");
            printf("*********************************************\n\n");
          }
          return i;
        }
      }
    }
  }


  //-------------------------------------------------------------------------------------------------
  //CADASTRO CPF
  //-------------------------------------------------------------------------------------------------
  
  //getchar();
  if(opcao=='5' || opcao=='6')
  {
    pessoal[i].validaCPF=0;  //Para entrar no loop abaixo

    existe=1;  //Para entrar no loop abaixo

    outrapessoa=1;
  
    while(pessoal[i].validaCPF==0 || existe!=-1 || outrapessoa!=-1)
    {
      //INPUT
      printf("CPF (somente numeros): ");
      fgets(pessoal[i].cpf, 256, stdin);
      for(j=0; pessoal[i].cpf[j]!='\n'; j++);
      pessoal[i].cpf[j]='\0';
    
      //EASTER EGG - GERARCPF
      if(comparaNome(cpfgera, pessoal[i].cpf, 0))
      {
        gerarCPF(pessoal[i].cpf);
        printf("CPF gerado-> %s\n", pessoal[i].cpf);
      }
        
      //VALIDAÇÃO
      pessoal[i].validaCPF = validarCPF(pessoal[i].cpf);
  
      //CRIA CPF NO FORMATO DE NÚMERO
      pessoal[i].numCPF=formatNumCPF(pessoal[i].cpf);
  
      //PROCURAR SE JÁ EXISTE ALGUM CADASTRO COM O CPF INFORMADO
      existe = buscaCPF(pessoal, i, pessoal[i].numCPF);
      //printf("\n\nexiste(buscaCPF) = %d\n\n", existe);
  
      //PROCURAR SE HÁ ALGUM CADASTRO COM MESMO CPF NO OUTRO MÓDULO, MAS CADASTRADO COM OUTRO NOME
      outrapessoa = buscaCPF(pessoal2, h, pessoal[i].numCPF);    //se houver uma pessoa cadastrada com o cpf na outra base, outra pessoa retorna valor diferente de -1 indo para condição abaixo. Caso negativo, significa que não há outra pessoa com o mesmo cpf na outra base
      //printf("\n\nOutrapessoa(buscaCPF) = %d\n\n", outrapessoa);
      
      
      if(outrapessoa != -1 && comparaNome(pessoal2[outrapessoa].nome, pessoal[i].nome, 0))//se há um cadastro com o mesmo cpf  e os nomes são iguais então não há problema. Aqui, se reconhece a possibilidade de em uma instituição o professor também ser aluno.
        outrapessoa = -1;
      //printf("\n\nOutrapessoa(comparanome) = %d\n\n", outrapessoa);
      
  
      //ERRO-TRY AGAIN
      if(pessoal[i].validaCPF==0 || existe!=-1 || outrapessoa!=-1)
      {
        printf("\nERRO!\n");
        if(pessoal[i].validaCPF==0)
        printf("\nEntrada inválida!");
        
        if(existe!=-1)
        printf("\nCPF já cadastrado (no ID %d)!", existe);
  
        if(outrapessoa!=-1)
        {
          printf("\nCPF cadastrado no nome de outra pessoa! Verifique o ID %d do módulo de ", outrapessoa);
          if(tipo=='a')
            printf("professores.");
          else
            printf("alunos.");
        }
        
        printf(" Digite 1 para tentar mais uma vez: ");
        tentativa = lerChar(entrada, 256);
        // scanf("%c", &tentativa);
        // getchar();
        
        if(tentativa!='1')
        {
          if(imprimeTitulo==1)
          {
            printf("\n\nCadastro cancelado!\n");
            printf("*********************************************\n\n");
          }
          return i;
        }
      }
    }
  }
  
  
  //-------------------------------------------------------------------------------------------------
  //CADASTRO SEXO
  //-------------------------------------------------------------------------------------------------

  if(opcao=='4'||opcao=='6')
  {
    pessoal[i].validaSexo=0;
  
    while(pessoal[i].validaSexo==0)
    {
      //INPUT 
      //getchar();
      printf("Sexo (m: masculino, f: feminino): ");
      pessoal[i].sexo = lerChar(entrada, 256);
      // scanf("%c", &pessoal[i].sexo);
    
      //VALIDAÇÃO
      pessoal[i].validaSexo = validarSexo(pessoal[i].sexo);
  
      //ERRO-TRY AGAIN
      if(pessoal[i].validaSexo==0)
      {
        printf("\nEntrada inválida! Digite 1 para tentar mais uma vez: ");
        tentativa = lerChar(entrada, 256);
        // scanf("%c", &tentativa);
        if(tentativa!='1')
        {
          if(imprimeTitulo==1)
          {
            printf("\n\nCadastro cancelado!\n");
            printf("*********************************************\n\n");
          }
          return i;
        }
      }
    }  
  }
  
  // printf("Sexo (m: masculino, f: feminino): ");
  // scanf("%c", &pessoal[i].sexo);

  //alu[i].validaSexo = validarSexo(cliente.sexo);

  //-------------------------------------------------------------------------------------------------
  //THE END - CADASTRO
  //-------------------------------------------------------------------------------------------------
  if(imprimeTitulo==1)
  {
    printf("\n\nDados cadastrados com sucesso!\n");
    printf("*********************************************\n\n");
  }

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

void imprimeDados(pess pessoal[], int i)
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

  //TRANSFORMAR EM FUNÇÃO imprimeDados(i), COM i SENDO O ID. CASO FOR DESEJÁVEL IMPRIMIR UMA LISTA, USAR A FUNÇÃO imprimeDados(i) DENTRO DE UM FOR;
  for(int i=0; i<qtd; i++)
  {
    imprimeDados(pessoal, i);
    // printf("-------------------------------------------\n");
    // printf("ID:%d\n", i);
    // printf("Nome: %s\n", pessoal[i].nome);
    // printf("Matrícula: %ld\n", pessoal[i].matricula);
    // printf("Data de nascimento: %02d/%02d/%d\n", pessoal[i].data.dia, pessoal[i].data.mes, pessoal[i].data.ano);
    // printf("CPF: ");
    // imprimeCPF(pessoal[i].cpf, 1);
    // printf("Sexo: ");
    // imprimesexo(pessoal[i].sexo, 1);
    // printf("-------------------------------------------\n");
  }
  printf("\n\n*********************************************\n\n");
}

void atualizarPessoal(pess pessoal[], int i, char tipo, pess pessoal2[], int h)
{
  int j, id;
  char opcao, entrada[256];

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
      //MUDAR A ENTRADA PARA TIPO CHAR E DEPOIS CONVERTER EM INT
      printf("Informe o ID do aluno que deseja atualizar os dados(número): ");
      fgets(entrada, 256, stdin);
      for(j=0; entrada[j]!='\n'; j++);
      entrada[j]='\0';
      //scanf("%d", &id);

      if(!validarNum(entrada))
      {
        printf("\n-------------------------------------------\n");
        printf("Entrada inválida!");
        printf("\n-------------------------------------------\n");
        printf("\n*********************************************\n\n");
        return;
      }

      else
        id=charint(entrada);
      
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
  printf("-------------------------------------------\n");

  printf("Sua opção: ");
  opcao = lerChar(entrada, 256);
    //scanf("%d", &opcao);

  if(opcao=='0')
    return;

  else if(opcao>='1' && opcao<='6')
    cadastrarPessoal(pessoal, id, 0, tipo, pessoal2, h, opcao);

  else
  {
    printf("Opção inválida!");
    printf("\n\nAtualização cancelada...\n");
    printf("*********************************************\n\n");
    return;
  }
  
  // switch (opcao)
  // {
  //   case '0':
  //   return;
    
  //   case '1':
  //   {
  //     getchar();
  //     printf("Nome (no máximo 20 caracteres): ");
  //     fgets(pessoal[id].nome, 256, stdin);
  //     for(j=0; pessoal[id].nome[j]!='\n'; j++);
  //     pessoal[id].nome[j]='\0';
  //     break;
  //     //cliente.validaNome = validarNome(cliente.nome);
  //   }

  //   case '2':
  //   {
  //     printf("Matrícula (somente números): ");
  //     scanf("%ld", &pessoal[id].matricula);
  //     break;
  //   }
    
  //   case '3':
  //   {
  //     printf("Data de nascimento\n");
  //     printf("Dia: ");
  //     scanf("%d", &pessoal[id].nascDia);
  //     printf("Mes: ");
  //     scanf("%d", &pessoal[id].nascMes);
  //     printf("Ano (formato aaaa): ");
  //     scanf("%d", &pessoal[id].nascAno);
  //     break;
  //     //cliente.validaData = validarNascimento(cliente.nascDia, cliente.nascMes, cliente.nascAno);
  //   }

  //   case '4':
  //   {
  //     getchar();
  //     printf("Sexo (m: masculino, f: feminino): ");
  //     scanf("%c", &pessoal[id].sexo);
  //     break;
  //     //alu[i].validaSexo = validarSexo(cliente.sexo);
  //   }

  //   case '5':
  //   {
  //     getchar();
  //     printf("CPF (somente numeros): ");
  //     fgets(pessoal[id].cpf, 256, stdin);
  //     for(j=0; pessoal[id].cpf[j]!='\n'; j++);
  //     pessoal[id].cpf[j]='\0';
  //     break;
  //     //alu[i].validaCPF = validarCPF(alu[i].cpf);
  //   }

  //   case '6':
  //   {
  //     cadastrarPessoal(pessoal, id, 0, tipo, pessoal2, h, opcao);
  //     break;
  //   }
  // }

  printf("\n\nDados atualizados com sucesso!\n");
  printf("*********************************************\n\n");
  return;
}

//EM excluirDados(), INSERIR:
//1 ENTRADA DE ID E DELETAR EM FORMATO CHAR
//2 FAZER CONTROLE DE ERROS DE ENTRADA
//3 CONVERTER FORMATO CHAR EM INT

int excluirDados(pess pessoal[], int i, char tipo)
{
  int id, j;
  char deletar, entrada[256];

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
      fgets(entrada, 256, stdin);
      for(j=0; entrada[j]!='\n'; j++);
      entrada[j]='\0';
      // scanf("%d", &id);

      if(!validarNum(entrada))
      {
        printf("\n-------------------------------------------\n");
        printf("Entrada inválida!");
        printf("\n-------------------------------------------\n");
        printf("\n*********************************************\n\n");
        return i;
      }

      else
        id=charint(entrada);
      
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

  //AQUI VAI A FUNÇÃO imprimeDados()
  printf("\n\n=========== DADOS PARA EXCLUIR ===========\n\n");
  imprimeDados(pessoal, id);
  // printf("-------------------------------------------\n");
  // printf("ID:%d\n", id);
  // printf("Nome: %s\n", pessoal[id].nome);
  // printf("Matrícula: %ld\n", pessoal[id].matricula);
  // printf("Data de nascimento: %02d/%02d/%d\n", pessoal[id].nascDia, pessoal[id].nascMes, pessoal[id].nascAno);
  // printf("CPF: ");
  // imprimeCPF(pessoal[id].cpf, 1);
  // printf("Sexo: ");
  // imprimesexo(pessoal[id].sexo, 1);
  // printf("-------------------------------------------\n");

  printf("\nConfirma exclusão? (1 para confirmar): ");
  //scanf("%d", &deletar);
  deletar=lerChar(entrada, 256);

  if(deletar=='1')
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

// • Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
// ◦ Inserir/Excluir aluno de uma disciplina
char menuDisciplina()
{
  char entrada[256], opcao;
  
  printf("Digite a opção desejada:\n");
  printf("0. Voltar\n");
  printf("1. Listar Disciplinas\n");
  printf("2. Cadastrar nova disciplina\n");
  printf("3. Atualizar dados da disciplina\n");
  printf("4. Inserir/excluir alunos em uma disciplina\n\n");
  printf("5. Inserir/excluir professores em uma disciplina\n\n");
  printf("6. Excluir disciplina\n\n");

  printf("Sua opção: ");

  opcao = lerChar(entrada, 256);

  return opcao;
}