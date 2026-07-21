#include <stdio.h>
#include <omp.h>
int main(){
  omp_set_num_threads(4);
  int x=0;
  int tem[16]={0};
  #pragma omp parallel
  {
        int nt = omp_get_num_threads();
        int myid = omp_get_thread_num();
	//printf("Hello DCS --- from %d of %d\n",myid,nt);
	
	//for(int i=0;i<1000000;i++)
	  //tem[myid]++;
	  //x[myid]++; //update my id only
        //printf("Thread %d ---> initial X = %d\n",myid,x[myid]);
        //printf("X=%d\n",x);
        
        for(int i=0;i<4;i++)
          
  }
  /*int Y=0;
  for(int i=0;i<8;i++)
    Y+=tem[i];
  printf("Y=%d\n",Y); //8000000 tread no=8
  */
  return 0;
}
