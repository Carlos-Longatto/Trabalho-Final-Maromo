#include <stdio.h>
#include <stdlib.h>

struct Cand{
    int mat, nota;
    char letras[51];
};


int main(void)
{
  struct Cand cand[10];
  char gabarito[51] = "\0";
  FILE *fq;
  fq = fopen("gabarito.txt", "r");

  if((fq = fopen("gabarito.txt", "r"))==NULL)
  {
     printf("Impossivel abrir arquivo \n");
     exit(1);
  }
  fscanf(fq, "%s", gabarito);
  fclose(fq);



  if((fq = fopen("respostas.txt", "r"))==NULL)
  {
     printf("Impossivel abrir arquivo \n");
     exit(2);
  }
  int i = 0;
  while (fscanf(fq, "%d %s", &cand[i].mat, cand[i].letras)!=EOF){
    i++;
  }

  int acertos;
  int j = 0;
  for(i=0; i<10; i++){
      acertos = 0;
      for(j=0; j<51; j++){
     if(gabarito[j]==cand[i].letras[j]) acertos++;
      }
      cand[i].nota = acertos;
  }

  i=0;
  j=0;
  int maior;
  int aux_nota;
  int aux_mat;
    for (i=0; i<=10; i++){
        maior = i;
        for (j=i+1; j<10; j++){
            if (cand[j].nota > cand[maior].nota)
            maior = j;
        }
        aux_nota = cand[maior].nota;
        aux_mat = cand[maior].mat;
        cand[maior].nota = cand[i].nota;
        cand[maior].mat = cand[i].mat;
        cand[i].nota = aux_nota;
        cand[i].mat = aux_mat;
    }
    printf(" Arquivo gerado com sucesso\n");
    printf(" Verifique a pasta do projeto\n\n");


    FILE *resultado;
    resultado = fopen("resultado.txt", "w");
    for(i=0;i<10;i++){
    fprintf(resultado,"Numero do Candidato:\t %d \tQuantidade de Acertos:\t%d\n", cand[i].mat, cand[i].nota);
    }
    fclose(resultado);

    system("pause");



  return;
}

