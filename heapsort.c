#include "auxiliares.h"
#include "sorting.h"
#include <string.h>

void heapify_num(struct produto *vet, int tam, int pos) {
  int maior = pos;
  int esq = 2 * pos + 1;
  int dir = 2 * pos + 2;

  // acha o maior entre a raiz, filho da esq e filho da dir
  if (esq < tam && vet[esq].num > vet[maior].num)
    maior = esq;

  if (dir < tam && vet[dir].num > vet[maior].num)
    maior = dir;

  // troca e continua dando heap se a raiz nao eh o maior
  if (maior != pos) {
    troca(vet, pos, maior);
    heapify_num(vet, tam, maior);
  }
}

void heapsort_num(struct produto vet[], int tam) {
  // Build max heap
  for (int i = tam / 2 - 1; i >= 0; i--)
    heapify_num(vet, tam, i);

  // Heap sort
  for (int i = tam - 1; i >= 0; i--) {
    troca(vet, 0, i);
    heapify_num(vet, i, 0);
  }
}

void heapify_STR(struct produto *vet, int tam, int pos) {
  int maior = pos;
  int esq = 2 * pos + 1;
  int dir = 2 * pos + 2;

  // acha o maior entre a raiz, filho da esq e filho da dir
  if (esq < tam && strcmp(vet[esq].STR, vet[maior].STR) > 0)
    maior = esq;

  if (dir < tam && strcmp(vet[dir].STR, vet[maior].STR) > 0)
    maior = dir;

  // troca e continua dando heap se a raiz nao eh o maior
  if (maior != pos) {
    troca(vet, pos, maior);
    heapify_STR(vet, tam, maior);
  }
}

void heapsort_STR(struct produto *vet, int tam) {
  // Build max heap
  for (int i = tam / 2 - 1; i >= 0; i--)
    heapify_STR(vet, tam, i);

  // Heap sort
  for (int i = tam - 1; i >= 0; i--) {
    troca(vet, 0, i);
    heapify_STR(vet, i, 0);
  }
}

void heapify_valor(struct produto *vet, int tam, int pos) {
  int maior = pos;
  int esq = 2 * pos + 1;
  int dir = 2 * pos + 2;

  // acha o maior entre a raiz, filho da esq e filho da dir
  if (esq < tam && vet[esq].valor > vet[maior].valor)
    maior = esq;

  if (dir < tam && vet[dir].valor > vet[maior].valor)
    maior = dir;

  // troca e continua dando heap se a raiz nao eh o maior
  if (maior != pos) {
    troca(vet, pos, maior);
    heapify_valor(vet, tam, maior);
  }
}

void heapsort_valor(struct produto *vet, int tam) {
  // Build max heap
  for (int i = tam / 2 - 1; i >= 0; i--)
    heapify_valor(vet, tam, i);

  // Heap sort
  for (int i = tam - 1; i >= 0; i--) {
    troca(vet, 0, i);
    heapify_valor(vet, i, 0);
  }
}