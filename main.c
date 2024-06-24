#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "findGradient.h"
#include "vetor.h"
#include "otimiza.h"

double f1(double* x){
    double x1 = *(x);
    double x2 = *(x+1);
    return pow(x1,4) + pow(x2,4)+2*pow(x1*x2,2)+6*x1*x2-4*x1-4*x2+1;
}

double f2(double* x){
    double x1 = *(x);
    double x2 = *(x+1);
    return 100*pow((x2-x1*x1), 2) + pow((x1-1), 2);
}

double f3(double* x){
    double x1 = *(x);
    double x2 = *(x+1);
    double x3 = *(x+2);
    return 100*pow((x2-x1*x1), 2) + pow((x1-1), 2) + 100*pow((x3-x2*x2),2) + pow((x2-1),2);
}

int main(void) {
    double* x0 = vet_cria(3);
    *(x0) = 0;
    *(x0+1) = 0;
    *(x0+2) = 0;
    int* ite = otimiza(f3, x0, 3, 1, 0.0001);
    printf("Número de iterações do método: %d; Número de iterações do IPS: %d\n", ite[0], ite[1]);
    printf("X minimo achado foi:\n");
    vet_imprime(3, x0);
    printf("\n");
    printf("Valor minimo da função achado foi:");
    printf("%.16g\n", f3(x0));
    vet_libera(x0);
    return 0;
}