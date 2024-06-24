#include "findGradient.h"
#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>

double* gradient(double (*f)(double* x), double* x, int n){
    double h = 1e-7;
    double* grad = vet_cria(n);
    for (int i=0; i<n; i++){
        double xOri = *(x+i);
        
        *(x+i) = xOri + h;
        double y1 = f(x);
    
        *(x+i) = xOri - h;
        double y2 = f(x);
        
        *(x+i) = xOri;
        double g = (y1-y2);
        g = g/(2*h);

        *(grad+i) = g;
    }
    return grad;
}