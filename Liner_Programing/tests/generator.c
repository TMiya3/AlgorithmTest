#include<stdio.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
int MIN(int a,int b){return a<b?a:b;}
// aとbをファイルストリームに出力する
// ファイル名は prefix_num.in (ex: 00_sample_00.in)
int a[10][10],b[10],c[10];
char op[10][5];
void out(int n,int m,char *s){
  FILE *f;
  int i,j;
  f=fopen(s,"w");
  fprintf(f,"%d %d\n",n,m);
  for(i=0;i<m;i++){
    if(i)fprintf(f," ");
    fprintf(f,"%d",c[i]);
  }
  fprintf(f,"\n");
  
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)fprintf(f,"%d ",a[i][j]);
    fprintf(f,"%s %d\n",op[i],b[i]);
  }
  fclose(f);
}
void make(int n,int m,int D,char *name){
  int i,j,k;
  char s[5][5]={"<=","=",">="};
  for(i=0;i<m;i++)c[i]=rnd.next(MIN_D,D);
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)a[i][j]=rnd.next(MIN_D,D);
    strcpy(op[i],s[rnd.next(MIN_OP,MAX_OP)]);
    b[i]=rnd.next(MIN_D,D);
  }
  out(n,m,name);
}

int main(){
  int n,m,d,i;
  char s[100];
  // 乱数のシードを設定
  //1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
  rnd.setSeed(time(0)+getpid());

  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MIN(3,MAX_N));
    m=rnd.next(n,MIN(5,MAX_M));
    d=10;
    sprintf(s,"50_small_%02d.in",i);
    make(n,m,d,s);
  }

  for(i=0;i<100;i++){
    n=rnd.next(MIN_N,MAX_N);
    m=rnd.next(n,MAX_M);
    d=MAX_D;
    sprintf(s,"51_large%02d.in",i);
    make(n,m,d,s);
  }
  
  for(i=0;i<5;i++){
    n=MIN_N;
    m=n;
    d=MAX_D;
    sprintf(s,"52_MIN_%02d.in",i);
    make(n,m,d,s);
  }
   
  for(i=0;i<10;i++){
    n=MAX_N;
    m=MAX_M;
    d=MAX_D;
    sprintf(s,"53_MAX_%02d.in",i);
    make(n,m,d,s);
  }
  return 0;
}
