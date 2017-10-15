#include<stdio.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
// aとbをファイルストリームに出力する
// ファイル名は prefix_num.in (ex: 00_sample_00.in)
int d[1010][1010],q[100010][5];
void out(int h,int w,int n,char *s){
  FILE *f;
  int i,j;
  f=fopen(s,"w");
  fprintf(f,"%d %d\n",h,w);
  for(i=0;i<h;i++){
    for(j=0;j<w-1;j++)fprintf(f,"%d ",d[i][j]);
    fprintf(f,"%d\n",d[i][j]);
  }
  fprintf(f,"%d\n",n);
  for(i=0;i<n;i++){
    for(j=0;j<3+q[i][0];j++)fprintf(f,"%d ",q[i][j]);
    fprintf(f,"%d\n",q[i][j]);
  }
  fclose(f);
}
void make(int h,int w,int D,int m,char *name){
  int i,j,k;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)d[i][j]=rnd.next(MIN_D,D);
  }
  for(i=0;i<m;i++){
    q[i][0]=rnd.next(0,1);
    if(q[i][0]==0){
      q[i][1]=rnd.next(0,h-1);
      q[i][2]=rnd.next(0,w-1);
      q[i][3]=rnd.next(MIN_D,D);
    }
    else{
      q[i][1]=rnd.next(0,h-1);
      q[i][2]=rnd.next(0,w-1);
      q[i][3]=rnd.next(q[i][1]+1,h);
      q[i][4]=rnd.next(q[i][2]+1,w);
    }
  }
  out(h,w,m,name);
}
void challenge00(){
  int i,j,h=MAX_H,w=MAX_W,m=MAX_Q;
  char name[100]={"Challenge00.in"};
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)d[i][j]=rnd.next(MIN_D,MAX_D);
  }
  for(i=0;i<m;i++){
    q[i][0]=0;
    q[i][1]=h-1;
    q[i][2]=w-1;
    q[i][3]=rnd.next(MIN_D,MAX_D);
  }
  out(h,w,m,name);
}
void challenge01(){
  int i,j,h=MAX_H,w=MAX_W,m=MAX_Q;
  char name[100]={"Challenge01.in"};
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)d[i][j]=rnd.next(MIN_D,MAX_D);
  }
  for(i=0;i<m;i++){
    q[i][0]=1;
    q[i][1]=0;
    q[i][2]=0;
    q[i][3]=h;
    q[i][4]=w;
  }
  out(h,w,m,name);
}
int main(){
  int h,w,n,m,i;
  char s[100];
  // 乱数のシードを設定
  //1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
  rnd.setSeed(time(0)+getpid());

  for(i=0;i<100;i++){
    h=rnd.next(MIN_H,8);
    w=rnd.next(MIN_W,8);
    n=10;
    m=rnd.next(MIN_Q,10);
    sprintf(s,"50_small_%02d.in",i);
    make(h,w,n,m,s);
  }

  for(i=0;i<10;i++){
    h=rnd.next(MIN_H,MAX_H);
    w=rnd.next(MIN_W,MAX_W);
    n=MAX_D;
    m=rnd.next(MIN_Q,MAX_Q);
    sprintf(s,"51_large%02d.in",i);
    make(h,w,n,m,s);
  }
  
  for(i=0;i<5;i++){
    h=MIN_H;
    w=MIN_W;
    n=MAX_D;
    m=rnd.next(MIN_Q,MAX_Q);
    sprintf(s,"52_MIN_%02d.in",i);
    make(h,w,n,m,s);
  }
   
  for(i=0;i<10;i++){
    h=MAX_H;
    w=MAX_W;
    n=MAX_D;
    m=MAX_Q;
    sprintf(s,"53_MAX_%02d.in",i);
    make(h,w,n,m,s);
  }
  challenge00();
  challenge01();
  return 0;
}
