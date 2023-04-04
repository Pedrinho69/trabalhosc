#include "sorting.h"
#include <string.h>

void troca(struct produto vet[], int i, int j) {
  struct produto temp = vet[i];
  vet[i] = vet[j];
  vet[j] = temp;
}

void insertionsort(int vet[], int tam) {
  int i, j;
  for (i = 1; i < tam; i++) {
    int atual = vet[i];
    for (j = i - 1; j >= 0 && vet[j] > atual; j--)
      vet[j + 1] = vet[j];

    vet[j + 1] = atual;
  }
}

void insertionsort_num(struct produto vet[], int dir, int esq) {
  for (int i = dir; i < esq; i++) {
    if (vet[i].num > vet[i + 1].num) {
      for (int j = i + 1; j != dir && vet[j - 1].num > vet[j].num; j--)
        troca(vet, j, j - 1);
    }
  }
}

void insertionsort_STR(struct produto vet[], int dir, int esq) {
  for (int i = dir; i < esq; i++) {
    if (strcmp(vet[i].STR, vet[i + 1].STR) > 0) {
      for (int j = i + 1; j != dir && strcmp(vet[j - 1].STR, vet[j].STR) > 0;
           j--)
        troca(vet, j, j - 1);
    }
  }
}

void insertionsort_valor(struct produto vet[], int dir, int esq) {
  for (int i = dir; i < esq; i++) {
    if (vet[i].valor > vet[i + 1].valor) {
      for (int j = i + 1; j != dir && vet[j - 1].valor > vet[j].valor; j--)
        troca(vet, j, j - 1);
    }
  }
}
