#include "auxiliares.h"
#include "sorting.h"
#include <string.h>

void cocktailsort_num(struct produto *vet, int tam) {
  int trocado = 1; // flag
  int ini = 0;
  int fim = tam - 1;

  while (trocado == 1) {

    trocado = 0;

    for (int i = ini; i < fim; ++i)
      if (vet[i].num > vet[i + 1].num) {
        troca(vet, i, i + 1);
        trocado = 1;
      }

    // se não houve trocas, então o vetor está ordenado
    if (trocado == 0)
      break;

    trocado = 0;
    fim--;

    // percorre da direita para a esquerda
    for (int i = fim - 1; i >= ini; --i)
      if (vet[i].num > vet[i + 1].num) {
        troca(vet, i, i + 1);
        trocado = 1;
      }
    ini++;
  }
}

void cocktailsort_STR(struct produto *vet, int tam) {
  int trocado = 1; // flag
  int ini = 0;
  int fim = tam - 1;

  while (trocado == 1) {

    trocado = 0;

    // percorre da esquerda para a direita, igual ao bubblesort
    for (int i = ini; i < fim; ++i)
      if (strcmp(vet[i].STR, vet[i + 1].STR) > 0) {
        troca(vet, i, i + 1);
        trocado = 1;
      }

    // se não houve trocas, então o vetor está ordenado
    if (trocado == 0)
      break;

    trocado = 0;
    fim--;

    // percorre da direita para a esquerda
    for (int i = fim - 1; i >= ini; --i)
      if (strcmp(vet[i].STR, vet[i + 1].STR) > 0) {
        troca(vet, i, i + 1);
        trocado = 1;
      }
    ini++;
  }
}

void cocktailsort_valor(struct produto *vet, int tam) {
  int trocado = 1; // flag
  int ini = 0;
  int fim = tam - 1;

  while (trocado == 1) {

    // reseta o flag antes de entrar no loop, pois ele pode ser 1 de uma
    // iteração anterior
    trocado = 0;

    // percorre da esquerda para a direita, igual oa bubblesort
    for (int i = ini; i < fim; ++i)
      if (vet[i].valor > vet[i + 1].valor) {
        troca(vet, i, i + 1);
        trocado = 1;
      }

    // se não houve trocas, então o vetor está ordenado
    if (trocado == 0)
      break;

    trocado = 0;
    fim--;

    // percorre da direita para a esquerda
    for (int i = fim - 1; i >= ini; --i)
      if (vet[i].valor > vet[i + 1].valor) {
        troca(vet, i, i + 1);
        trocado = 1;
      }
    ini++;
  }
}
