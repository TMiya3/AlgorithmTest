#include<stdio.h>
double M[10][30]={};
//本体　シンプレックス法
int Simplex(int h,int w,int *ans){
  int i,j,mi,mj,k=w;
  double t,eps=1e-9;
  while(k--){
    mi=mj=-1;
    for(j=0;j<w;j++){
      if(M[h][j]+eps>0)continue;
      if(mj==-1||M[h][j]<M[h][mj])mj=j;
    }
    if(mj==-1)return 0;
    for(i=0;i<h;i++){
      if(M[i][mj]<eps)continue;
      if(mi==-1||M[i][w]/M[i][mj]<M[mi][w]/M[mi][mj])mi=i;
    }
    if(mi==-1)return 2;
    t=M[mi][mj];
    for(j=0;j<=w;j++)M[mi][j]/=t;
    for(i=0;i<=h;i++){
      t=i==mi?0:M[i][mj];
      for(j=0;j<=w;j++)M[i][j]-=M[mi][j]*t;
    }
    ans[mi]=mj;
  }
  return 1;
}
int senkei(int h,int w,double A[10][30],double *b,double *c,int *op,int *ans){
  double t;
  int i,j;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)M[i][j]=A[i][j];
    if(op[i]==0)M[i][w+i]=M[h][w+i]=1;
    if(op[i]==2){
      M[i][w+i]=-1;
      M[i][w+h+i]=M[h][w+h+i]=1;
    }
    M[i][w+h+h]=c[i];
    ans[i]=w+h*(op[i]/2)+i;
  }
  for(i=0;i<h;i++){
    t=ans[i]<h+w?0:M[h][ans[i]];
    for(j=0;j<=w+h+h;j++)M[h][j]-=M[i][j]*t;
  }
  if(i=Simplex(h,w+h+h,ans))return i;
  for(i=0;i<=h;i++)M[i][h+w]=M[i][w+h+h];
  for(j=0;j< w;j++)M[h][j]=-b[j];
  for(j=0;j<=h;j++)M[h][w+j]=0;
  return Simplex(h,h+w,ans);
}
int main(){
  double a[10][30],b[10],c[10];
  int n,m,i,j,op[10],ans[10];
  char s[10];
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++)scanf("%lf",&b[i]);
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)scanf("%lf",&a[i][j]);
    scanf("%s %lf",s,&c[i]);
    if(s[0]=='<')op[i]=0;
    if(s[0]=='=')op[i]=1;
    if(s[0]=='>')op[i]=2;
  }
  senkei(n,m,a,b,c,op,ans);
  printf("%.10lf\n",M[n][n+m]);
  return 0;
}
