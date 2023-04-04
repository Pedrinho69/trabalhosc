#include "auxiliares.h"
#include "sorting.h"
#include <string.h>

// inverte o vetor[0..i]
void flip(struct produto *vet, int fim) {
  int temp, ini = 0;
  while (ini < fim) {
    troca(vet, ini, fim);
    ini++;
    fim--;
  }
}

int acha_maior_num(struct produto *vet, int tam) {
  int maior, i;
  for (maior = 0, i = 0; i < tam; i++)
    if (vet[i].num > vet[maior].num)
      maior = i;
  return maior;
}

void pancakesort_num(struct produto *vet, int tam) {
  for (int tam_atual = tam; tam_atual > 1; tam_atual--) {
    int maior = acha_maior_num(vet, tam_atual);

    // move o maior elemento para o fim do vetor
    if (maior != tam_atual - 1) {
      // para mover para o fim, primeiro move o maior para o início
      flip(vet, maior);
      flip(vet, tam_atual - 1);
    }
  }
}

int acha_maior_STR(struct produto *vet, int tam) {
  int maior, i;
  for (maior = 0, i = 0; i < tam; i++)
    if (strcmp(vet[i].STR, vet[maior].STR) > 0)
      maior = i;
  return maior;
}

void pancakesort_STR(struct produto *vet, int tam) {
  for (int tam_atual = tam; tam_atual > 1; tam_atual--) {
    int maior = acha_maior_STR(vet, tam_atual);

    // move o maior elemento para o fim do vetor
    if (maior != tam_atual - 1) {
      // para mover para o fim, primeiro move o maior para o início
      flip(vet, maior);
      flip(vet, tam_atual - 1);
    }
  }
}

int acha_maior_valor(struct produto *vet, int tam) {
  int maior, i;
  for (maior = 0, i = 0; i < tam; i++)
    if (vet[i].valor > vet[maior].valor)
      maior = i;
  return maior;
}

void pancakesort_valor(struct produto *vet, int tam) {
  for (int tam_atual = tam; tam_atual > 1; tam_atual--) {
    int maior = acha_maior_valor(vet, tam_atual);

    // move o maior elemento para o fim do vetor
    if (maior != tam_atual - 1) {
      // para mover para o fim, primeiro move o maior para o início
      flip(vet, maior);
      flip(vet, tam_atual - 1);
    }
  }
}