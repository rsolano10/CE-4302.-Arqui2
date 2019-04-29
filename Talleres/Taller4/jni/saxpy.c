
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

const int Vector = 10000;

void saxpy(int n, float a, float *restrict x, float *restrict y)
{
   for (int i = 0; i < n; ++i)
      y[i] = a * x[i] + y[i];
}

#include <omp.h>
#include <omp.h>
int main()
{
   double start_time, run_time;

   //Reserva memoria del arreglo
   float *num1, *num2;
   num1 = malloc(sizeof(float) * Vector);
   num2 = malloc(sizeof(float) * Vector);

   for (int i = 0; i < Vector; i++)
   {
      num1[i] = rand() % 4096;
      num2[i] = rand() % 4096;
   }
   start_time = omp_get_wtime(); // start time

   saxpy(Vector, 12.5, num1, num2); // call func

   run_time = omp_get_wtime() - start_time;
   printf("Tiempo: %f\nVector: %i\n", run_time, Vector);
}