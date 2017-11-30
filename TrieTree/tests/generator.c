#include<stdio.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
// aとbをファイルストリームに出力する
// ファイル名は prefix_num.in (ex: 00_sample_00.in)
char S[11010][110];
void out(int n,int m,char *s){
  FILE *f;
  int i,j;
  f=fopen(s,"w");
  fprintf(f,"%d %d\n",n,m);
  for(i=0;i<n+m;i++)fprintf(f,"%s\n",S[i]);
  fclose(f);
}
void make(int n,int l){
  int i,j,c;
  for(i=0;i<n;i++){
    c=rnd.next(MIN_L,l);
    for(j=0;j<c;j++)S[i][j]=rnd.next(0,25)+'a';
    S[i][j]=0;
  }
}
int main(){
  int n,m,i,j,l;
  char s[100];
  // 乱数のシードを設定
  //1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
  rnd.setSeed(time(0)+getpid());

  for(i=0;i<100;i++){
    n=rnd.next(MIN_N,8);
    m=rnd.next(MIN_M,8);
    l=10;
    sprintf(s,"50_small_%02d.in",i);
    make(n+m,l);
    for(j=0;j<m;j++){
      if(rnd.next(0,1))strcpy(S[rnd.next(0,n-1)],S[j+n]);
    }
    out(n,m,s);
  }

  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MAX_N);
    m=rnd.next(MIN_M,MAX_M);
    l=MAX_L;
    sprintf(s,"51_large%02d.in",i);
    make(n+m,l);
    for(j=0;j<m;j++){
      if(rnd.next(0,1))strcpy(S[rnd.next(0,n-1)],S[j+n]);
    }
    out(n,m,s);
  }
  
  for(i=0;i<5;i++){
    n=MIN_N;
    m=MIN_M;
    l=MAX_L;
    sprintf(s,"52_MIN_%02d.in",i);
    make(n+m,l);
    out(n,m,s);
  }
   
  for(i=0;i<10;i++){
    n=MAX_N;
    m=MAX_M;
    l=MAX_L;
    sprintf(s,"53_MAX_%02d.in",i);
    make(n+m,l);
    for(j=0;j<m;j++){
      if(rnd.next(0,1))strcpy(S[rnd.next(0,n-1)],S[j+n]);
    }
    out(n,m,s);
  }
  return 0;
}
