#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarCPF(char cpf[]);
int validarCPF(char cpf[]);
  
int main()
{
  char cpf[12];
  int validacao;

  gerarCPF(cpf);

  printf("\n\n%s\n", cpf);

  validacao=validarCPF(cpf);

  if(validacao==1)
    printf("CPF válido!");
  else
    printf("CPF inválido!");
  
  return 0;
}

void gerarCPF(char cpf[])
{
  int i, digito1, digito2;

  srand(time(NULL));
  
  for(i=0, digito1=0, digito2=0; i<9; cpf[i]=('0'+rand()%10), digito1+=(cpf[i]-'0')*(10-i), digito2+=(cpf[i]-'0')*(11-i), i++);
  
  digito1*=10;
  digito1%=11;
  if(digito1==10)
    digito1=0;

  cpf[9]=(digito1+'0');

  digito2+=(cpf[9]-'0')*(11-i);
  digito2*=10;
  digito2%=11;
  if(digito2==10)
    digito2=0;

  cpf[10]=(digito2+'0');
  
  cpf[11]='\0';
}

int validarCPF(char cpf[])
{
  int i, digito1, digito2;
  
  for(i=0; cpf[i]!='\0'; i++)
  {
    if(cpf[i]<'0'||cpf[i]>'9')
      return 0;
  }
  
  if(i!=11)
    return 0;

  for(i=8, digito1=0; i>=0; i--)
    digito1+=(cpf[i]-'0')*(10-i);
  digito1*=10;
  digito1%=11;

  if(digito1==10)
    digito1=0;

  printf("\n\nDigito 1=%d\n\n", digito1);
  if(digito1!=(cpf[9]-'0'))
  {
    printf("\n\nDigito 1 inválido!\n\n");
    return 0;
  }

  for(i=9, digito2=0; i>=0; i--)
    digito2+=(cpf[i]-'0')*(11-i);
  digito2*=10;
  digito2%=11;

  if(digito2==10)
    digito2=0;

  printf("\n\nDigito 2=%d\n\n", digito2);
  if(digito2!=(cpf[10]-'0'))
  {
    printf("Digito 2 inválido!\n\n");
    return 0;
  }
  
  return 1;
}
//======================================================================================================================================
// int validarCPF(char cpf[]);

// int main()
// {
//   char cpf[13];
//   int j, validacao;
  
//   printf("CPF: ");
//   fgets(cpf, 13, stdin);
//   for(j=0; cpf[j]!='\n'; j++);
//   cpf[j]='\0';

//   validacao=validarCPF(cpf);

//   if(validacao==1)
//     printf("CPF válido!");
//   else
//     printf("CPF inválido!");
//   return 0;
// }

// int validarCPF(char cpf[])
// {
//   int i, digito1, digito2;
  
//   for(i=0; cpf[i]!='\0'; i++)
//   {
//     if(cpf[i]<'0'||cpf[i]>'9')
//       return 0;
//   }
  
//   if(i!=11)
//     return 0;

//   for(i=8, digito1=0; i>=0; i--)
//     digito1+=(cpf[i]-'0')*(10-i);
//   digito1*=10;
//   digito1%=11;

//   if(digito1==10)
//     digito1=0;

//   printf("\n\nDigito 1=%d\n\n", digito1);
//   if(digito1!=(cpf[9]-'0'))
//   {
//     printf("\n\nDigito 1 inválido!\n\n");
//     return 0;
//   }

//   for(i=9, digito2=0; i>=0; i--)
//     digito2+=(cpf[i]-'0')*(11-i);
//   digito2*=10;
//   digito2%=11;

//   if(digito2==10)
//     digito2=0;

//   printf("\n\nDigito 2=%d\n\n", digito2);
//   if(digito2!=(cpf[10]-'0'))
//   {
//     printf("Digito 2 inválido!\n\n");
//     return 0;
//   }
  
//   return 1;
// }

//====================================================================================================================

// int main()
// {
//   char texto[15];
//   int num, i, mult;

//   printf("texto: ");
//   fgets(texto, 15, stdin);

//   for(i=0; texto[i]!='\n'; i++);
//   texto[i]='\0';

//   for(i=i-1, mult=1, num=0; i>=0; i--)
//   {
//     num += (texto[i]-'0')*mult;
//     mult*=10;
//   }

//   printf("\nNúmero = %d\n", num);

  
//   return 0;
// }
//======================================================================================
// typedef struct formato_data
// {
//   int dia;
//   int mes;
//   int ano;
//   int erro;
//   char data[12];
//   long int longData;
// }dt;

// dt formatarData(char data[]);

// int main()
// {
//   int i;
//   dt data;
//   char dataIn[12];
  
//   printf("Data: ");
//   fgets(dataIn, 12, stdin);

//   for(i=0; dataIn[i]!='\n'; i++);

//   dataIn[i]='\0';

//   printf("\nData:%s<-\n", dataIn);

//   data=formatarData(dataIn);

//   printf("\nSaída = %02d/%02d/%d", data.dia, data.mes, data.ano);
//   printf("\nLongdata = %ld\n", data.longData);
// }

// dt formatarData(char data[])
// {
//   //ponteiro para struct que armazena data e hora  
//   struct tm *data_hora_atual;

//   //variável do tipo time_t para armazenar o tempo em segundos  
//   time_t segundos;
  
//   //obtendo o tempo em segundos  
//   time(&segundos);   
  
//   //para converter de segundos para o tempo local  
//   //utilizamos a função localtime  
//   data_hora_atual = localtime(&segundos);
  
//   int i, barra, mult;
//   dt fdata;

//   for(i=0; data[i+1]!='\0'; i++);

//   for(i, barra=0, mult=1, fdata.dia=0, fdata.mes=0, fdata.ano=0; data[i]!='\0'; i--)
//   {
//     if(data[i]=='/')
//     {
//       barra++;
//       mult=1;
//       continue;
//     }
//     switch(barra)
//     {
//       case 0:
//       {
//         fdata.ano += (data[i]-'0')*mult;
//         printf("\nAno=%d", fdata.ano);
//         mult*=10;
//         break;
//       }
      
//       case 1:
//       {
//         fdata.mes += (data[i]-'0')*mult;
//         printf("\nMes=%d", fdata.mes);
//         mult*=10;
//         break;
//       }
      
//       case 2:
//       {
//         fdata.dia += (data[i]-'0')*mult;
//         printf("\nDia=%d", fdata.dia);
//         mult*=10;
//         break;
//       }
//       default:
//       {
//         fdata.erro=1;
//         return fdata;        
//       }
//     }
//   }

//   if(fdata.ano<=(data_hora_atual->tm_year+1900)%100)
//     fdata.ano+=((data_hora_atual->tm_year+1900)/1000)*1000;
//   else if(fdata.ano<100)
//     fdata.ano+=1900;

//   fdata.longData= fdata.dia+fdata.mes*100+fdata.ano*10000;
  
//   return fdata;
// }


//======================================================================================



// /*
// ====================================== BUSCA BINÁRIA ======================================
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// char maiuscula(char nome[])
// {
//   int i;
//   for(i=0; nome[i]!='\0'; i++)
//   {
//     if(nome[i]>='a' && nome[i]<='z')
//       nome[i]+='A'-'a';
//   }
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
//   //ponteiro para struct que armazena data e hora  
//   struct tm *data_hora_atual;

//   //variável do tipo time_t para armazenar o tempo em segundos  
//   time_t segundos;
  
//   //obtendo o tempo em segundos  
//   time(&segundos);   
  
//   //para converter de segundos para o tempo local  
//   //utilizamos a função localtime  
//   data_hora_atual = localtime(&segundos);

//   if(ano<1900) //Estabelecendo idade máxima de 122 anos
//     return 0;
//   if(mes<1||mes>12)
//     return 0;
//   if(dia<1)
//     return 0;
  
//   if(ano>data_hora_atual->tm_year+1900)
//   {
//     printf("Ano maior que o atual!");
//     return 0;
//   }
   
//   if(mes>data_hora_atual->tm_mon+1 && ano==data_hora_atual->tm_year+1900)
//   {
//     printf("mes maior que o atual!");
//     return 0;
//   }
  
//   if(dia>data_hora_atual->tm_mday && mes==data_hora_atual->tm_mon+1 && ano==data_hora_atual->tm_year+1900)
//   {
//     printf("dia maior que o atual!");
//     return 0;
//   }


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

// int main()
// {
//   // int nascDia, nascMes, nascAno, validaData;
  
//   // printf("Data de nascimento\n");
//   // printf("Dia: ");
//   // scanf("%d", &nascDia);
//   // printf("Mes: ");
//   // scanf("%d", &nascMes);
//   // printf("Ano (formato aaaa): ");
//   // scanf("%d", &nascAno);

//   // validaData = validarNascimento(nascDia, nascMes, nascAno);

//   char nome[33];
//   int i;

//   printf("Nome: ");
//   for(i=0; nome[i-1]!='\n'; scanf("%c", &nome[i]), i++);
//   nome[i-1]='\0';

//   printf("\nNome: ");
//   for(i=0; nome[i]!='\0'; printf("%c", nome[i]), i++);

//   maiuscula(nome);
//   printf("\n\nNOME: ");
//   for(i=0; nome[i]!='\0'; printf("%c", nome[i]), i++);

//   return 0;
// }

  // typedef struct tm {
  // int tm_sec; //representa os segundos de 0 a 59
  // int tm_min; //representa os minutos de 0 a 59
  // int tm_hour; //representa as horas de 0 a 24
  // int tm_mday; //dia do mês de 1 a 31
  // int tm_mon; //representa os meses do ano de 0 a 11
  // int tm_year; //representa o ano a partir de 1900
  // int tm_wday; //dia da semana de 0 (domingo) até 6 (sábado)
  // int tm_yday; // dia do ano de 1 a 365
  // int tm_isdst; //indica horário de verão se for diferente de zero
  // }tempo;

  // int ano, dia, mes;
  
  // //ponteiro para struct que armazena data e hora  
  // struct tm *data_hora_atual;     
  
  // //variável do tipo time_t para armazenar o tempo em segundos  
  // time_t segundos;
  
  // //obtendo o tempo em segundos  
  // time(&segundos);   
  
  // //para converter de segundos para o tempo local  
  // //utilizamos a função localtime  
  // data_hora_atual = localtime(&segundos);  
  
  // //para acessar os membros de uma struct usando o ponteiro
  // //utilizamos o operador -> no nosso caso temos: 
  // //data_hora_atual->membro_da_struct
  
  // //Acessando dados convertidos para a struct data_hora_atual  
  // printf("\nDia..........: %d\n", data_hora_atual->tm_mday);  
  
  // //para retornar o mês corretamente devemos adicionar +1 
  // //como vemos abaixo
  // printf("\nMes..........: %d\n", data_hora_atual->tm_mon+1);
  
  // //para retornar o ano corretamente devemos adicionar 1900 
  // //como vemos abaixo
  
  // printf("\nAno..........: %d\n\n", data_hora_atual->tm_year+1900);
  // printf("\nDia do ano...: %d\n", data_hora_atual->tm_yday);  
  // printf("\nDia da semana: %d\n\n", data_hora_atual->tm_wday);

  // printf("Informe:\n");
  // printf("Dia: ");
  // scanf("%d", &dia);
  // printf("Mês: ");
  // scanf("%d", &mes);
  // printf("Ano: ");
  // scanf("%d", &ano);

  // if(ano<data_hora_atual->tm_year+1900)
  // printf("o ano informado é menor que o atual");
  // else
  // printf("o ano informado é maior que o atual");
  
  // if(mes<data_hora_atual->tm_mon+1)
  // printf("o mês informado é menor que o atual");
  // else
  // printf("o mês informado é maior que o atual");

  // if(dia<data_hora_atual->tm_mday)
  // printf("o dia informado é menor que o atual");
  // else
  // printf("o dia informado é maior que o atual");
  // /* Obtendo os valores da struct data_hora_atual  
  //   e formatando a saída de dados no formato 
  //   hora: minuto: segundo
     
  // Para não ficar um printf muito longo em uma única linha
  // de comando, quebrei a impressão em 3 partes mostrando
  // uma informação em cada linha 
  // */  
  // printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora   
  // printf("%d:",data_hora_atual->tm_min);//minuto
  // printf("%d\n",data_hora_atual->tm_sec);//segundo  
  
  // /* Obtendo os valores da struct data_hora_atual  
  //    e formatando a saída de dados no formato dia/mes/ano 
     
  //    Para não ficar um printf muito longo em uma única 
  //    linha de comando, quebrei a impressão em 3 partes
  //    sendo uma informação em cada linha   
  // */  
  // //dia do mês
  // printf("\nData ........: %d/", data_hora_atual->tm_mday);
  // printf("%d/",data_hora_atual->tm_mon+1); //mês
  // printf("%d\n\n",data_hora_atual->tm_year+1900); //ano