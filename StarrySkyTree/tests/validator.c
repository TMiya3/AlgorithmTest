#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
int main(){
  int i,j,m,N,Q,A;
  registerValidation();
  // read first line
  N=inf.readInt(MIN_N, MAX_N);
  inf.readEoln();
  for(i=0;i<N;i++){
    if(i)inf.readSpace();
    inf.readInt(MIN_D, MAX_D);
  }
  inf.readEoln(); 
  Q=inf.readInt(MIN_Q,MAX_Q);
  inf.readEoln();
 
  for(i=0;i<Q;i++){
    A=inf.readInt(0,1);
    if(A==0){
      inf.readSpace();
      m=inf.readInt(0,N-1);
      inf.readSpace();
      inf.readInt(m+1,N);
      inf.readSpace();
      inf.readInt(MIN_D,MAX_D);
      inf.readEoln();
    }
    if(A==1){
      inf.readSpace();
      m=inf.readInt(0,N-1);
      inf.readSpace();
      inf.readInt(m+1,N);
      inf.readEoln();
    }
  }    
  inf.readEof();
}
