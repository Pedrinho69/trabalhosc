#include "auxiliares.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP 5 // quantidade de repetições para realizar a média

void copia_vetor_struct(struct produto destino[], struct produto origem[],
                        int tam)
{
  for (int i = 0; i < tam; i++)
    destino[i] = origem[i];
}

void geraSTR(char var[])
{
  int i, j, tamanho_string_aleatoria, posicao_char;
  char caracteres[] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopgrstuvwxyz0123456789",
       temp[STR_MAX];
  tamanho_string_aleatoria = (rand() % 25) + 5;
  for (i = 0; i < tamanho_string_aleatoria; i++)
  {
    posicao_char = rand() % 63;
    temp[i] = caracteres[posicao_char];
  }
  temp[i] = '\0';
  strcpy(var, temp);
}

void ordena(struct produto v[], float **t, int teste, int tam)
{

  struct produto aux[tam];
  double soma = 0;
  int metodo;
  clock_t begin;
  // controla em qual coluna do vetor de tempos o tempo será colocado
  // 0 = num, 1 = STR, 2 = valor
  if (teste == 0)
    metodo = 0;
  else if (teste < 4)
    metodo = 1;
  else if (teste < 7)
    metodo = 2;
  else if (teste < 10)
    metodo = 3;
  else if (teste < 13)
    metodo = 4;
  else if (teste < 16)
    metodo = 5;
  else
    metodo = 6;

  for (int q = 0; q < REP; q++)
  {
    copia_vetor_struct(aux, v, tam);

    begin = clock();
    switch (teste)
    {
    case 0:
      bucketsort(aux, tam);//segmentetion fault para 10000 elementos
      break;
    case 1:
      cocktailsort_num(aux, tam);
      break;
    case 2:
      cocktailsort_STR(aux, tam);
      break;
    case 3:
      cocktailsort_valor(aux, tam);
      break;
    case 4:
      heapsort_num(aux, tam);
      break;
    case 5:
      heapsort_STR(aux, tam);
      break;
    case 6:
      heapsort_valor(aux, tam);
      break;
    case 7:
      oddevensort_num(aux, tam);//ordena 100000 produtos
      break;
    case 8:
      oddevensort_STR(aux, tam);
      break;
    case 9:
      oddevensort_valor(aux, tam);
      break;
    case 10:
      pancakesort_num(aux, tam);// ordena 100000 produtos
      break;
    case 11:
      pancakesort_STR(aux, tam);
      break;
    case 12:
      pancakesort_valor(aux, tam);
      break;
    case 13:
      quicksort_m3_num(aux, 0, tam - 1);//segmentation fault com 90000 elementos
      break;
    case 14:
      quicksort_m3_valor(aux, 0, tam - 1);
      break;
    case 15:
      quicksort_m3_STR(aux, 0, tam - 1);
      break;
    case 16:
       shellsort_STR(aux, tam);// ordena 100000 produtos
      break;
    case 17:
      shellsort_valor(aux, tam);
      break;
    case 18:
      shellsort_num(aux, tam);
    }
    soma += (double)(clock() - begin) / CLOCKS_PER_SEC;
  }
  if (teste == 0)
    t[0][0] = soma / REP;
  else
    t[metodo][((teste + 2) % 3)] = soma / REP;
}

void printa_tempos(float **t, int l, int c)
{
  int i, j;
  printf("\t\t  NUM\t");
  printf("\t\t  STR\t\t");
  printf("\t VALOR\n");

  for (j = 0; j < l; j++)
  {
    switch (j)
    {
    case 0:
      printf("bucketsort: ");
      break;
    case 1:
      printf("cocktailsort: ");
      break;
    case 2:
      printf("heapsort: ");
      break;
    case 3:
      printf("odd-evensort: ");
      break;
    case 4:
      printf("pancakesort: ");
      break;
    case 5:
      printf("quicksort M3: ");
      break;
    case 6:
      printf("shellsort: ");
      break;
    }
    for (int a = 0; a < c; a++)
    {
      printf("\t%f\t", t[j][a]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  srand(time(NULL));
  /*for(int j = 0;j < 1000; j++) 
  for(int i = 0; i<1000; i++){
    printf("%d ", rand()%31);
  }*/
  int vetTam[qntFatia] = {10000, 25000, 40000, 55000, 70000}, i, j, k;
  int linha = 7, col = 3;

  float **vetTempo;
  vetTempo = (float **)malloc(linha * sizeof(float *));
  for (int i = 0; i < linha; i++)
    vetTempo[i] = (float *)malloc(col * sizeof(float));

  for (k = 0; k < qntFatia; k++)
  {
    struct produto vet[vetTam[k]];
    printf("\n\n\t\t======= %d ELEMENTOS =======\n", vetTam[k]);
    for (j = 0; j <= 18; j++)
    {
      // randomiza os campos do struct
      for (i = 0; i < vetTam[k]; i++)
      {
        vet[i].num = rand() % NUM_MAX;
        geraSTR(vet[i].STR);
        vet[i].valor = ((float)rand() / (float)(RAND_MAX)) * 4000;
      }
      ordena(vet, vetTempo, j, vetTam[k]);
      /*for (i = 0; i < vetTam[k]; i++)
      {
        printf("cod: %d prod: %s val: %f \n", vet[i].num, vet[i].STR, vet[i].valor );
      
      }*/
    }
    printa_tempos(vetTempo, linha, col);
  }
  return 0;
}
