#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<vector>

using namespace std;

#define NUM_THREADS 10

vector<int>::iterator arr[NUM_THREADS];



int main(int argc,char *argv[]){
  
  if (argc !=2 ){
    printf("Require 1 argument : \n");
    return 0;
  }
  
  vector<int> v;
  unsigned int i=0,n,k=0;
  n=atoi(argv[1]);

  for(i=0;i<n;i++){
    v.push_back(i);
     }

  vector<int>::iterator it = v.begin();
  while(it!=v.end()){
    arr[k++]=it;
    it+=10;
  }


  omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
{
  #pragma omp for
  for(int j=0;j<k;j++){
    vector<int>::iterator start = arr[j];
    int count = 10;
    while(count--){
      printf("<%d,%d>\n",omp_get_thread_num(),*start);
      start++;
    }

  }

 }

  return 0;
}