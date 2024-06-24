#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* vet_cria (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}

void vet_libera (double* v)
{
  free(v);
}

void vet_mults (int n, double* v, double s, double* w)
{
  for (int i=0; i<n; ++i)
    w[i] = v[i]*s;
}

void vet_imprime (int n, double* v)
{
  for (int i=0; i<n; ++i)
    printf("%.16g  ",v[i]);
  printf("\n");
}

double vet_escalar (int n, double *v, double *w){
    double soma = 0;
    for (int i = 0; i<n; i++){
        soma += (*(v+i)) * (*(w+i));
    }
    return soma;
}

double vet_norma2 (int n, double* v){
    double soma = 0;
    for (int i = 0; i<n; i++){
        soma += (*(v+i))*(*(v+i));
    }
    return sqrt(soma);
}

int vet_iguais(int n, double* v, double* w, double tol){
    for (int i = 0; i<n; i++){
        if ( ((*(v+i))-(*(w+i))) * ((*(v+i))-(*(w+i))) > tol*tol)
            return 0;
    }
    return 1;
}

void vet_sub (int n, double* v, double *s, double *w){
    for (int i = 0; i<n; i++){
        *(w+i) = *(v+i) - *(s+i);
    }
}