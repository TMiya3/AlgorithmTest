#include<stdio.h>
int N,SS[400010],NN=1e9;
int hyouka(int a,int b){return a<b?a:b;}
void ssset(int n,int *d){
    int i,t;
    for(N=1;N<n;N*=2);
    for(i=0;i<n;i++)SS[i+N]=d[i];
    for(   ;i<N;i++)SS[i+N]=NN;
    for(i=N-1;i;i--){
        t=hyouka(SS[i*2],SS[i*2+1]);
        SS[i    ]+=t;
        SS[i*2  ]-=t;
        SS[i*2+1]-=t;
    }
}
//[l,r)区間にxを加算　いまiにいて担当は[a,b)
//ssud(l,r,x,1,0,N);
int ssud(int l,int r,int x,int i,int a,int b){
    int t;
    if(b<=l||r<=a)return SS[i];
    if(l<=a&&b<=r)return SS[i]+=x;
    t=hyouka(ssud(l,r,x,i*2,a,(a+b)/2),ssud(l,r,x,i*2+1,(a+b)/2,b));
    SS[i*2  ]-=t;
    SS[i*2+1]-=t;
    return SS[i]+=t;
}
//[l,r)の値を返す　いまiにいて担当は[a,b)
//ssout(l,r,1,0,N);
int ssout(int l,int r,int i,int a,int b){
    if(r<=a||b<=l)return NN;
    if(l<=a&&b<=r)return SS[i];
    return hyouka(ssout(l,r,i*2,a,(a+b)/2),ssout(l,r,i*2+1,(a+b)/2,b))+SS[i];
}
int main(){
  int n,a,b,c,d[100010],q,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  ssset(n,d);
  scanf("%d",&n);
  while(n--){/*
    for(i=0;i<N*2;i++)printf("%d ",SS[i]);
    printf("\n");//*/
    scanf("%d",&q);
    if(q){
      scanf("%d %d",&a,&b);
      printf("%d\n",ssout(a,b,1,0,N));
    }
    else{
      scanf("%d %d %d",&a,&b,&c);
      ssud(a,b,c,1,0,N);
    }
  }
  return 0;
}
