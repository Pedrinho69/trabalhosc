#include <string.h>
#include <stdbool.h>
#include "sorting.h"

void oddevensort_num(struct produto v[], int tam) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < tam - 1; i += 2) {
            if (v[i].valor > v[i + 1].valor) {
                troca(v, i, i + 1);
                sorted = false;
            }
        }
        for (int i = 0; i < tam - 1; i += 2) {
            if (v[i].valor > v[i + 1].valor) {
                troca(v, i, i + 1);
                sorted = false;
            }
        }
    }
}

void oddevensort_STR(struct produto v[], int tam) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < tam - 1; i += 2) {
            if (strcmp(v[i].STR, v[i + 1].STR) > 0) {
                troca(v, i, i + 1);
                sorted = false;
            }
        }
        for (int i = 0; i < tam - 1; i += 2) {
            if (strcmp(v[i].STR, v[i + 1].STR) > 0) {
                troca(v, i, i + 1);
                sorted = false;
            }
        }
    }
}

void oddevensort_valor(struct produto v[], int tam) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < tam - 1; i += 2) {
            if (v[i].valor > v[i + 1].valor) {
                troca(v, i, i + 1);
                sorted = false;
            }
        }
        for (int i = 0; i < tam - 1; i += 2) {
            if (v[i].valor > v[i + 1].valor) {
                troca(v, i, i + 1);
                sorted = false;
            }
        }
    }
}
