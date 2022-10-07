typedef struct cadastro_aluno
{
  int matricula;
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
  char tipo;
}alu;

int mainAluno(alu aluno[], int qtdAluno);