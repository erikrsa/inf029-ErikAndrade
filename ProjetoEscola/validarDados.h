typedef struct formato_data
{
  int dia;
  int mes;
  int ano;
  int erro;
  char Tdata[12];
  long int longData;
}dt;

typedef struct cadastro_pessoal
{
  long int matricula;
  char nome[256];
  dt data;
  int nascDia;
  int nascMes;
  int nascAno;
  char cpf[30];
  long int numCPF;
  char sexo;
  int validaNome;
  int validaData;
  int validaCPF;
  int validaSexo;
  int validaMatricula;
  char tipo; //'a' para aluno; 'p' para professor
}pess;

int validarNome(char nome[]);
void maiuscula(char nome[]);
dt formatarData(char data[]);
int ehbissexto(int ano);
int validarNascimento(int dia, int mes, int ano);
int validarMatricula(int matricula);
long int formatarMatricula(long int matricula);
int buscaMatricula(pess pessoal[], int tam, int chave);
int validarCPF(char cpf[]);
void gerarCPF(char cpf[]);
long int formatNumCPF(char cpf[]);
int buscaCPF(pess pessoal[], int tam, int chave);
int validarSexo(char sexo);

// int mainValidarDados();