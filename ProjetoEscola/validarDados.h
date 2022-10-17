typedef struct formato_data
{
  int dia;
  int mes;
  int ano;
  int erro;
  char Tdata[256];
  long int longData;
}dt;

typedef struct cadastro_pessoal
{
  long int matricula;
  char Tmatricula[256];
  char nome[256];
  dt data;
  int nascDia;
  int nascMes;
  int nascAno;
  char cpf[256];
  long int numCPF;
  char sexo;
  int validaNome;
  int validaData;
  int validaCPF;
  int validaSexo;
  int validaMatricula;
  char tipo; //'a' para aluno; 'p' para professor
}pess;

typedef struct cadastro_disciplina
{
  char nome[256];
  char codigo[256];
  int semestre;
  int validaNome;
  int validaCodigo;
  int validaSemestre;
}disci;

typedef struct planilhao_base
{
  
}plan;

char lerChar(char texto[], int tam);
int validarNome(char nome[]);
void maiuscula(char nome[]);
dt formatarData(char data[]);
int ehbissexto(int ano);
int validarNascimento(int dia, int mes, int ano);
long int formatNumMatricula(char Tmatricula[]);
int validarMatricula(long int matricula);
long int formatarMatricula(long int matricula, char tipo);
int buscaMatricula(pess pessoal[], int tam, long int chave);
int validarCPF(char cpf[]);
void gerarCPF(char cpf[]);
int charint(char entrada[]);
long int formatNumCPF(char cpf[]);
int buscaCPF(pess pessoal[], int tam, long int chave);
int comparaNome(char nome1[], char nome2[], int j);
int buscaNome(pess pessoal[], int tam, char chave[]);
int buscaDisciplina(disci disciplina[], int tam, char chave[]);
int validarSexo(char sexo);
int validarNum(char entrada[]);
int charint(char entrada[]);

// int mainValidarDados();