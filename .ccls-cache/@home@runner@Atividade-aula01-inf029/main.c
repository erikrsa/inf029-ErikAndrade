#include <stdio.h>

int main(void) {

  int n=5, idades[n], i, j;
  float media;
  char nomes[n][256];

  for(i=0, media=0; i<n; i++)
  {
    printf("Informe o nome da %d pessoa: ", i+1);
    //for(j=0; j==0||nomes[i][j-1]!='\n'; scanf("%c", &nomes[i][j]), j++);
    //nomes[i][j-1]='\0';
    fgets(nomes[i], 256, stdin);
    for(j=0; nomes[i][j]!='\n'; j++);
    nomes[i][j]='\0';
    printf("Informe a idade de %s: ", nomes[i]);
    //for(j=0; nomes[i][j]!='\0'; printf("%c", nomes[i][j]), j++);
    scanf("%d", &idades[i]);
    getchar();
    media+=idades[i];
  }
  
  media/=i;

  printf("A media das idades é %.0f e as pessoas com idades maiores que a media foram:\n", media);

  for(i=0; i<n; i++)
  {
    if(idades[i]>media)
    {
      //for(j=0; nomes[i][j]!='\0'; printf("%c", nomes[i][j]), j++);
      printf("%s, com %d anos;\n", nomes[i], idades[i]);
    }
  }
  return 0;
}