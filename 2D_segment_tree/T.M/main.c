#include<stdio.h>
int S2[2100][2100],H,W,NN=1e9;
int hyouka(int a,int b){return a<b?a:b;}
void s2set(int h,int w,int d[1050][1050]){
  int i,j;
  for(H=1;H<h;H*=2);
  for(W=1;W<w;W*=2);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)S2[i+H][j+W]=d[i][j];
    for(   ;j<W;j++)S2[i+H][j+W]=NN;
  }
  for(  ;i<H;i++){
    for(j=0;j<W;j++)S2[i+H][j+W]=NN;
  }
  for(i=H;i--;){
    for(j=W;j--;)S2[i+H][j]=hyouka(S2[i+H][j*2],S2[i+H][j*2+1]);
  }
  for(i=H;i--;){
    for(j=0;j<2*W;j++)S2[i][j]=hyouka(S2[i*2][j],S2[i*2+1][j]);
  }
}
int s2wout(int l,int r,int i,int j,int a,int b){
  if(b<=l||r<=a)return NN;
  if(l<=a&&b<=r)return S2[i][j];
  return hyouka(s2wout(l,r,i,j*2,a,(a+b)/2),s2wout(l,r,i,j*2+1,(a+b)/2,b));
}
int s2hout(int u,int d,int l,int r,int i,int a,int b){
  if(b<=u||d<=a)return NN;
  if(u<=a&&b<=d)return s2wout(l,r,i,1,0,W);
  return hyouka(s2hout(u,d,l,r,i*2,a,(a+b)/2),s2hout(u,d,l,r,i*2+1,(a+b)/2,b));
}
int s2out(int u,int d,int l,int r){return s2hout(u,d,l,r,1,0,H);}
void s2ud(int h,int w,int a){
  int i,j;
  for(j=w+W;j;j/=2){
    S2[h+H][j]=(j==w+W)?a:      hyouka(S2[h+H][j*2],S2[h+H  ][j*2+1]);
    for(i=(h+H)/2;i;i/=2)S2[i][j]=hyouka(S2[i*2][j  ],S2[i*2+1][j    ]);
  }
}    
int main(){
  int n,m,h,w,a,b,c,d,q,i,j,e[1050][1050];
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)scanf("%d",&e[i][j]);
  }
  s2set(h,w,e);
  scanf("%d",&n);
  while(n--){/*
    for(i=0;i<H*2;i++){
      for(j=0;j<W*2;j++)printf("%d ",S2[i][j]);
      printf("\n");
      }printf("\n");//*/
    scanf("%d",&q);
    if(q){
      scanf("%d %d %d %d",&a,&b,&c,&d);
      printf("%d\n",s2out(a,c,b,d));
    }
    else{
      scanf("%d %d %d",&a,&b,&c);
      s2ud(a,b,c);
    }
  }
  return 0;
}
