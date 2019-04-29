#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <arm_neon.h>

const int Vector = 1000000;

void saxpy(int n, int16_t a, int16_t * restrict x, int16_t * restrict y)
{
    int16_t aVect[4] = {a,a,a,a};
    int16x4_t a1 = vld1_s16(aVect);

    omp_set_num_threads(omp_get_num_threads());
    #pragma omp parallel
    #pragma omp for
    for (int i = 0; i < n; i = i+4){
        int16x4_t x1 = vld1_s16(x[i]);
        int16x4_t y1 = vld1_s16(y[i]);
        int16x4_t res = vmla_s16(y1,x1,a1);
    }
}

int main()
{
    double start_time, run_time;

    //Reserva memoria del arreglo
   int16_t *num1, *num2, *num3;
   num1= malloc(sizeof(int16_t) * Vector);
   num2= malloc(sizeof(int16_t) * Vector);
  
   for (int i = 0; i < Vector; i++)
   {
      num1[i] = (int16_t) rand() % 4096;
      num2[i] = (int16_t) rand() % 4096;
   }

    start_time = omp_get_wtime(); // start time 
    
    saxpy(Vector, 12, num1, num2); // call func

   run_time = omp_get_wtime() - start_time;
   printf("Tiempo: %f\nVector: %i\n", run_time, Vector);
}
