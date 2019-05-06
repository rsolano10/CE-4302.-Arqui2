#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define XINICIAL 0
#define XFINAL 10
#define PASOS 1000000000

float calcularFuncion(float x);

int main(int argc, char *argv[])
{
    double start_time, run_time;

    float resultado = 0.0;
    float incremento = ((float)XFINAL - (float)XINICIAL) / (float)PASOS;
    float semiIncremento = incremento / 2;
    float x = XINICIAL;

    start_time = omp_get_wtime(); // start time
    omp_set_num_threads(omp_get_num_threads());
    #pragma omp parallel
    #pragma omp for
    for (int i = 0; i < PASOS; i++)
    {
        resultado += incremento * (calcularFuncion(x) + calcularFuncion(x + incremento)) / (float)2;
        x += incremento;
    }
    run_time = omp_get_wtime() - start_time;

    printf("El resultado de es %f \n El tiempo es de %f \n", resultado,run_time);
}

float calcularFuncion(float x)
{
    return x * x;
}