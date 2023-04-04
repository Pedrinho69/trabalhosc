#define STR_MAX 31
#define NUM_MAX 10000000
#define qntFatia 5

struct produto {
  int num;
  char STR[STR_MAX];
  float valor;
};

// ordena pelo num
void bucketsort(struct produto *vet, int tam);
void cocktailsort_num(struct produto *vet, int tam);
void heapsort_num(struct produto *vet, int fim);
void oddevensort_num(struct produto *vet, int tam);
void pancakesort_num(struct produto *vet, int n);
void quicksort_m3_num(struct produto *vet, int esq, int dir);
void shellsort_num(struct produto *vet, int tam);

// ordena pelo CPF
void cocktailsort_STR(struct produto *vet, int tam);
void heapsort_STR(struct produto *vet, int fim);
void oddevensort_STR(struct produto *vet, int tam);
void pancakesort_STR(struct produto *vet, int n);
void quicksort_m3_STR(struct produto *vet, int esq, int dir);
void shellsort_STR(struct produto *vet, int tam);

// ordena pelo valor
void cocktailsort_valor(struct produto *vet, int tam);
void heapsort_valor(struct produto *vet, int fim);
void pancakesort_valor(struct produto *vet, int n);
void oddevensort_valor(struct produto *vet, int tam);
void quicksort_m3_valor(struct produto *vet, int esq, int dir);
void shellsort_valor(struct produto *vet, int tam);