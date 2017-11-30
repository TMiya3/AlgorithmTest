#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
int main(){
  int i,j,x,y;
  registerValidation();
  // read first line
  int N = inf.readInt(MIN_N, MAX_N);
  inf.readSpace();
  int M = inf.readInt(MIN_M, MAX_M);
  inf.readEoln();
  for(i=0;i<N+M;i++){
    inf.readToken("[a-z]{1,100}");
    inf.readEoln();
  }
  inf.readEof();
}
