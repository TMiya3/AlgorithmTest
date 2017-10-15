#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>

void readIntLine(int len, int min, int max){
    for(int i = 0; i < len; ++i){
        if(i > 0) inf.readSpace();
        inf.readInt(min, max);
    }
    inf.readEoln();
}

int main(){
  int i,j,x,y;
  registerValidation();
  // read first line
  int H = inf.readInt(MIN_H, MAX_H);
  inf.readSpace();
  int W = inf.readInt(MIN_W, MAX_W);
  inf.readEoln();
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(j)inf.readSpace();
      inf.readInt(MIN_D, MAX_D);
    }
    inf.readEoln(); 
  }
  int Q=inf.readInt(MIN_Q,MAX_Q);
  inf.readEoln();
    
  for(i=0;i<Q;i++){
    int A=inf.readInt(0,1);
    if(A==0){
      inf.readSpace();
      inf.readInt(0,H-1);
      inf.readSpace();
      inf.readInt(0,W-1);
      inf.readSpace();
      inf.readInt(MIN_D,MAX_D);
      inf.readEoln();
    }
    if(A==1){
      inf.readSpace();
      y=inf.readInt(0,H-1);
      inf.readSpace();
      x=inf.readInt(0,W-1);
      inf.readSpace();
      inf.readInt(y+1,H);
      inf.readSpace();
      inf.readInt(x+1,W);
      inf.readEoln();
    }
  }    
  inf.readEof();
}
