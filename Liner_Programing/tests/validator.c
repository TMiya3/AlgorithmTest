#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
int main(){
  int i,j,x,y;
  char c;
  registerValidation();
  // read first line
  int N = inf.readInt(MIN_N, MAX_N);
  inf.readSpace();
  int M = inf.readInt(N, MAX_M);
  inf.readEoln();
  for(i=0;i<M;i++){
    if(i)inf.readSpace();
    inf.readInt(MIN_D,MAX_D);
  }
  inf.readEoln();
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      inf.readInt(MIN_D, MAX_D);
      inf.readSpace();
    }
    inf.readWord("<=|=|>=");
    inf.readSpace();
    inf.readInt();
    inf.readEoln(); 
  }
  inf.readEof();
}
