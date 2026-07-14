#include <iostream>
#include <omp.h>
int main(){
  omp_set_num_threads(5 );
  
  #pragma omp parallel
  {
        int nt = omp_get_num_threads();
        int myid = omp_get_thread_num();
        std::cout<<"Hello DCS --- from " << myid << "of" <<nt<<'\n';
	//printf("Hello DCS --- from %d of %d\n",myid,nt);
  }
  return 0;
}
