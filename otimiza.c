#include "otimiza.h"
#include "findGradient.h"
#include "vetor.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int mips (double r, double delta, double (*f) (double* x), double* xmin, double* v, double* xk, int n){
    double t = r+delta;
    double s = r-delta;

    double* rParam = vet_cria(n);
    vet_mults(n, v, r, rParam);
    vet_sub(n, xk, rParam, rParam);
    double* tParam = vet_cria(n);
    vet_mults(n, v, t, tParam);
    vet_sub(n, xk, tParam, tParam);
    double* sParam = vet_cria(n);
    vet_mults(n, v, s, sParam);
    vet_sub(n, xk, sParam, sParam);
    
    double fr = f(rParam);
    double ft = f(tParam);
    double fs = f(sParam);
    
    vet_libera(rParam);
    vet_libera(tParam);
    vet_libera(sParam);

    int ite = 0;
    double x;
    while (ite < 50){

        if ((ite>2)&&(fabs(fs-ft) < 1e-6)){
            *(xmin) = (s+t)/2.0;
            return ite;
        }


        double denom1 = (s-r)*(ft-fs);
        double denom2 = (fs-fr)*(t-s);
        double denom = 2.0*(denom1-denom2);
        if (fabs(denom) < 1e-10){
            x = (r+s+t)/3.0;
        }else{
            x = (r+s)/2.0;
            double num = (fs-fr)*(t-r)*(t-s);
            x -= (num/denom);
        }

        r = s;
        s = t;
        t = x;
        fr = fs;
        fs = ft;

        double* xParam = vet_cria(n);
        vet_mults(n, v, x, xParam);
        vet_sub(n, xk, xParam, xParam);
        ft = f(xParam);
        vet_libera(xParam);
        ite ++;
    }
    *(xmin) = (s+t)/2.0;
    return 0;
}

int* otimiza(double (*f)(double* x), double* x0, int n, int IPS, double step){
    int* ites = malloc(2*sizeof(int));
    ites[0] = 0;
    ites[1] = 0;
    double f0 = f(x0);
    int totalIteIPS = 0;
    int i = 0;
    while (i < 5000){
        double aVal;
        double* v = gradient(f, x0, n);
        if (IPS){
            double* a = vet_cria(0);
            int ite = mips(0, 0.5, f, a, v, x0, n);
            if (ite == 0){
                printf("Não foi possível achar um valor de a para minimizar a função na iteração %d\n", i);
                return ites;
            }
            totalIteIPS += ite;
            aVal = *a;
            vet_libera(a);
        }else{
            aVal = step;
        }
        vet_mults(n, v, aVal, v);
        vet_sub(n, x0, v, x0);
        i++;
        if (i%10 == 0){
            double f1 = f(x0);
            if (fabs(f1-f0) < 1e-6){
                break;
            }
            f0 = f1;
        }
    }
    ites[0] = i;
    ites[1] = totalIteIPS;
    return ites;
}