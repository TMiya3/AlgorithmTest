#include<stdio.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
// aとbをファイルストリームに出力する
// ファイル名は prefix_num.in (ex: 00_sample_00.in)
int d[100010],q[100010][5];
void out(int n,int m,char *s){
  FILE *f;
  int i,j;
  f=fopen(s,"w");
  fprintf(f,"%d\n",n);
  for(i=0;i<n-1;i++)fprintf(f,"%d ",d[i]);
  fprintf(f,"%d\n",d[i]);
  fprintf(f,"%d\n",m);
  for(i=0;i<m;i++){
    for(j=0;j<3-q[i][0];j++)fprintf(f,"%d ",q[i][j]);
    fprintf(f,"%d\n",q[i][j]);
  }
  fclose(f);
}
void make(int n,int m,int D,char *name){
  int i,k;
  for(i=0;i<n;i++)d[i]=rnd.next(-D,D);
  for(i=0;i<m;i++){
    q[i][0]=rnd.next(0,1);
    if(q[i][0]==0){
      q[i][1]=rnd.next(0,n-1);
      q[i][2]=rnd.next(q[i][1]+1,n);
      q[i][3]=rnd.next(-D,D);
    }
    else{
      q[i][1]=rnd.next(0,n-1);
      q[i][2]=rnd.next(q[i][1]+1,n);
    }
  }
  out(n,m,name);
}
void challenge00(){
  int i,j,n=MAX_N,m=MAX_Q;
  char name[100]={"Challenge00.in"};
  for(i=0;i<n;i++)d[i]=rnd.next(MIN_D,MAX_D);
  for(i=0;i<m;i++){
    q[i][0]=0;
    q[i][1]=0;
    q[i][2]=n;
    q[i][3]=rnd.next(MIN_D,MAX_D);
  }
  out(n,m,name);
}
void challenge01(){
  int i,n=MAX_N,m=MAX_Q;
  char name[100]={"Challenge01.in"};
  for(i=0;i<n;i++)d[i]=rnd.next(MIN_D,MAX_D);
  for(i=0;i<m;i++){
    q[i][0]=1;
    q[i][1]=0;
    q[i][2]=n;
  }
  out(n,m,name);
}
int main(){
  int n,m,i,c;
  char s[100];
  // 乱数のシードを設定
  //1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
  rnd.setSeed(time(0)+getpid());

  for(i=0;i<100;i++){
    n=rnd.next(MIN_N,8);
    m=rnd.next(MIN_Q,10);
    c=10;
    sprintf(s,"50_small_%02d.in",i);
    make(n,m,c,s);
  }

  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MAX_N);
    m=rnd.next(MIN_Q,MAX_Q);
    c=MAX_D;
    sprintf(s,"51_large%02d.in",i);
    make(n,m,c,s);
  }
  
  for(i=0;i<5;i++){
    n=MIN_N;
    m=rnd.next(MIN_Q,MAX_Q);
    c=MAX_D;
    sprintf(s,"52_MIN_%02d.in",i);
    make(n,m,c,s);
  }
   
  for(i=0;i<10;i++){
    n=MAX_N;
    m=MAX_Q;
    c=MAX_D;
    sprintf(s,"53_MAX_%02d.in",i);
    make(n,m,c,s);
  }
  challenge00();
  challenge01();
  return 0;
}
