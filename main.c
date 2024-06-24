#include <stdio.h>
#include <stdlib.h>
#include "findGradient.h"
#include "vetor.h"
#include "otimiza.h"

double f1(double* x){
    double x1 = *(x);
    double x2 = *(x+1);
    double x1Ori = x1;
    double x2Ori = x2;
    double r = 1;
    for (int i=0; i<4; i++){
        if (i == 0){
            r += -4*x1 - 4*x2 + 6*x1*x2;
        }else if (i==1){
            r += 2*x1*x2;
        }else if (i==3){
            r += x1+x2;
        }
        x1 *= x1Ori;
        x2 *= x2Ori;
    }
    return r;
}

int main(void) {
    double* x0 = vet_cria(2);
    *(x0) = 0;
    *(x0+1) = 0;
    int* ite = otimiza(f1, x0, 2, 1, 1);
    printf("Número de iterações do método: %d; Número de iterações do IPS: %d\n", ite[0], ite[1]);
    printf("X minimo achado foi:\n");
    vet_imprime(2, x0);
    printf("\n");
    printf("Valor minimo da função achado foi:");
    printf("%.16g\n", f1(x0));
    vet_libera(x0);
    return 0;
}