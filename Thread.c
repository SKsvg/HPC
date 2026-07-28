#include <stdio.h>
#include <omp.h>
#define N 16
int main(){
  omp_set_num_threads(4);
  int ax[N]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  #pragma omp parallel
  {
        int nt = omp_get_num_threads();
        int myid = omp_get_thread_num();
        
        //for(int i=myid*nt;i<(myid+1)*nt;i++){
          //ax[i]+=10;
          //printf("ax[%d] = %d\n",i, ax[i]);
        //}
        for(int i=myid;i<N;i+=nt){
          ax[i]+=10;
          printf("ax[%d] = %d\n",i, ax[i]);
        }
          
  }
  return 0;
}
