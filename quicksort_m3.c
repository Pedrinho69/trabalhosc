#include "auxiliares.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int particao_num(struct produto *vet, int esq, int dir) {
  int i, fim;

  fim = esq;
  for (i = esq + 1; i <= dir; i++)
    if (vet[i].num < vet[esq].num) {
      fim++;
      troca(vet, fim, i);
    }

  // coloca o pivô na sua posição correta
  troca(vet, esq, fim);

  return fim;
}

void quicksort_m3_num(struct produto *v, int esq, int dir) {
  if (dir <= esq)
    return;

  int i;

  srand(time(NULL));

  if ((dir - esq) + 1 > 5) {
    int pos1 = esq + rand() % (dir - esq + 1);
    int pos2, pos3;
    do {
      pos2 = esq + rand() % (dir - esq + 1);
      pos3 = esq + rand() % (dir - esq + 1);
    } while (pos2 == pos1 || pos2 == pos3 || pos3 == pos1);

    troca(v, pos1, esq);
    troca(v, pos2, esq + 1);
    troca(v, pos3, dir);

    troca(v, (esq + dir) / 2, esq + 1);
    if (v[esq].num > v[esq + 1].num)
      troca(v, esq, esq + 1);
    if (v[esq].num > v[dir].num)
      troca(v, esq, dir);
    if (v[esq + 1].num > v[dir].num)
      troca(v, esq + 1, dir);

    i = particao_num(v, esq + 1, dir - 1);
    quicksort_m3_num(v, esq, i - 1);
    quicksort_m3_num(v, i + 1, dir);
  } else
    insertionsort_num(v, esq, dir);
}

int particao_STR(struct produto *vet, int esq, int dir) {
  int i, fim;

  fim = esq;
  for (i = esq + 1; i <= dir; i++)
    if (strcmp(vet[i].STR, vet[esq].STR) < 0) {
      fim++;
      troca(vet, fim, i);
    }

  // coloca o pivô na sua posição correta
  troca(vet, esq, fim);

  return fim;
}

void quicksort_m3_STR(struct produto *v, int esq, int dir) {
  if (dir <= esq)
    return;

  int i;

  srand(time(NULL));

  if ((dir - esq) + 1 > 5) {
    int pos1 = esq + rand() % (dir - esq + 1);
    int pos2, pos3;
    do {
      pos2 = esq + rand() % (dir - esq + 1);
      pos3 = esq + rand() % (dir - esq + 1);
    } while (pos2 == pos1 || pos2 == pos3 || pos3 == pos1);

    troca(v, pos1, esq);
    troca(v, pos2, esq + 1);
    troca(v, pos3, dir);

    troca(v, (esq + dir) / 2, esq + 1);
    if (strcmp(v[esq].STR, v[esq + 1].STR) > 0)
      troca(v, esq, esq + 1);
    if (strcmp(v[esq].STR, v[dir].STR) > 0)
      troca(v, esq, dir);
    if (strcmp(v[esq + 1].STR, v[dir].STR) > 0)
      troca(v, esq + 1, dir);
    i = particao_STR(v, esq + 1, dir - 1);
    quicksort_m3_STR(v, esq, i - 1);
    quicksort_m3_STR(v, i + 1, dir);
  } else
    insertionsort_STR(v, esq, dir);
}

int particao_valor(struct produto *vet, int esq, int dir) {
  int i, fim;

  fim = esq;
  for (i = esq + 1; i <= dir; i++)
    if (vet[i].valor < vet[esq].valor) {
      fim++;
      troca(vet, fim, i);
    }

  // coloca o pivô na sua posição correta
  troca(vet, esq, fim);

  return fim;
}

void quicksort_m3_valor(struct produto v[], int esq, int dir) {
  if (dir <= esq)
    return;

  int i;

  srand(time(NULL));

  if ((dir - esq) + 1 > 5) {
    int pos1 = esq + rand() % (dir - esq + 1);
    int pos2, pos3;
    do {
      pos2 = esq + rand() % (dir - esq + 1);
      pos3 = esq + rand() % (dir - esq + 1);
    } while (pos2 == pos1 || pos2 == pos3 || pos3 == pos1);

    troca(v, pos1, esq);
    troca(v, pos2, esq + 1);
    troca(v, pos3, dir);

    troca(v, (esq + dir) / 2, esq + 1);
    if (v[esq].valor > v[esq + 1].valor)
      troca(v, esq, esq + 1);
    if (v[esq].valor > v[dir].valor)
      troca(v, esq, dir);
    if (v[esq + 1].valor > v[dir].valor)
      troca(v, esq + 1, dir);

    i = particao_valor(v, esq + 1, dir - 1);
    quicksort_m3_valor(v, esq, i - 1);
    quicksort_m3_valor(v, i + 1, dir);
  } else
    insertionsort_valor(v, esq, dir);
}