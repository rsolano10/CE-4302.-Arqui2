#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <arm_neon.h>

int​32_t size[3] ={4*20000000,4*40000000,4*60000000};

int main(){
    int​ i;
    int32_t​ k = rand()%100;
    double​ start_time, run_time;
    for​ ( ​ int​ z=0; z<3;z++){
        int16_t​ *vecA = (​ int16_t​ *) calloc​ (size[z],​ sizeof​ ( int16_t​ ));
        int16_t​ *vecB = (​ int16_t​ *) calloc​ (size[z],​ sizeof​ ( int16_t​ ));
        int16_t​ *vecC = (​ int16_t​ *) calloc​ (size[z],​ sizeof​ ( int16_t​ ));
        
        int16_t​ vecKK[4] = {k,k,k,k};

        for​ (i=0;i<=size[z];i++){
            vecA[i]=rand()%100;
            vecB[i]=rand()%100;
        }

        /*start timer */
        start_time = omp_get_wtime();

        int16x4_t vec1, vec2, vec3;
        int16x4_t vecK = vld1_s16(vecKK);

        #pragma omp for
        for​ (i=0;i<=size[z];i=i+4){
            vec1 = vld1_s16(vecA);
            vecA+=4;
            vec2 = vld1_s16(vecB);
            vecB+=4;
            vec3 = vmla_s16(vec2,vec1,vecK);
            vst1_s16(vecC, vec3);
            vecC+=4;
        }
    }
}