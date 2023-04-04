#include "sorting.h"
#include <string.h>

void shellsort_num(struct produto *vet, int tam) {
  int i, j, h = 1;
  struct produto aux;

  do {
    h = h * 3 + 1;
  } while (h < tam);

  do {
    h = (h - 1) / 3;
    for (i = h; i < tam; i++) {
      aux = vet[i];
      j = i;
      while (vet[j - h].num > aux.num) {
        vet[j] = vet[j - h];
        j -= h;
        if (j < h)
          break;
      }
      vet[j] = aux;
    }
  } while (h != 1);
}

void shellsort_STR(struct produto *vet, int tam) {
  int i, j, h = 1;
  struct produto aux;

  do {
    h = h * 3 + 1;
  } while (h < tam);

  do {
    h = (h - 1) / 3;
    for (i = h; i < tam; i++) {
      aux = vet[i];
      j = i;
      // enquanto o vet aparece depois de aux
      while (strcmp(vet[j - h].STR, aux.STR) > 0) {
        vet[j] = vet[j - h];
        j -= h;
        if (j < h)
          break;
      }
      vet[j] = aux;
    }
  } while (h != 1);
}

void shellsort_valor(struct produto *vet, int tam) {
  int i, j, k, h = 1;
  struct produto aux;

  do {
    h = h * 3 + 1;
  } while (h < tam);

  do {
    h = (h - 1) / 3;
    for (i = h; i < tam; i++) {
      aux = vet[i];
      j = i;
      while (vet[j - h].valor > aux.valor) {
        vet[j] = vet[j - h];
        j -= h;
        if (j < h)
          break;
      }
      vet[j] = aux;
    }
  } while (h != 1);
}