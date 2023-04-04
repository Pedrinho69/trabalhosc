#include "auxiliares.h"
#include "sorting.h"
#include <stdlib.h>

void bucketsort(struct produto *prod, int tamanho) {
    int i, j;
    struct produto *bucket;
    int num_buckets = 10; // número de buckets, neste exemplo, é 10
    double valor_min = prod[0].num;
    double valor_max = prod[0].num;

    // Encontra o menor e o maior valor de preço na lista
    for (i = 1; i < tamanho; i++) {
        if (prod[i].num < valor_min) {
            valor_min = prod[i].num;
        }
        if (prod[i].num > valor_max) {
            valor_max = prod[i].num;
        }
    }

    // Aloca memória para os buckets
    bucket = (struct produto*) malloc(num_buckets * sizeof(struct produto));

    // Inicializa cada bucket com 0 elementos
    for (i = 0; i < num_buckets; i++) {
        bucket[i].num = 0;
        bucket[i].valor = 0.0;
    }

    // Divide os produtos em buckets com base no valor de preço
    for (i = 0; i < tamanho; i++) {
        int index = (int) ((prod[i].valor - valor_min) / ((valor_max - valor_min) / num_buckets));
        bucket[index].num = prod[i].num;
        bucket[index].valor = prod[i].valor;
    }

    // Ordena cada bucket usando insertion sort
    for (i = 0; i < num_buckets; i++) {
        for (j = 1; j < num_buckets; j++) {
            if (bucket[j-1].num > bucket[j].num) {
                struct produto temp = bucket[j-1];
                bucket[j-1] = bucket[j];
                bucket[j] = temp;
            }
        }
    }
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < num_buckets; j++) {
            if (bucket[j].num != 0) {
                prod[index++] = bucket[j];
            }
        }
    }
    
    free(bucket);
}