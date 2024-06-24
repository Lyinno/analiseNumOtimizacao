#ifndef VETOR_H
#define VETOR_H

// cria (aloca) um vetor de dimensão n, retornando seu ponteiro
double* vet_cria (int n);

// libera (a memória) de um vetor previamente criado
void vet_libera (double* v);

// calcula e retorna o produto escalar entre dois vetores de dimensão n
double vet_escalar (int n, double* v, double* w);

// calcula e retorna a norma-2 de um vetor de dimensão n
double vet_norma2 (int n, double* v);

// testa se os vetores v e w são iguais, elemento a elemento
int vet_iguais (int n, double* v, double* w, double tol);

// calcula a produto de um vetor v por um escalar s;
// o resultado deve ser armazenado no vetor w, previamente criado
void vet_mults (int n, double* v, double s, double *w);

void vet_sub (int n, double* v, double *s, double *w);

// imprime elementos do vetor
void vet_imprime (int n, double* v);

#endif
