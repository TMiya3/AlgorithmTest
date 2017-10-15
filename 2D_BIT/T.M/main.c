#include<stdio.h>
long long B2[2100][2100],H,W;
void b2add(int h,int w,int a){
  int i,j;
  for(i=h;i<=H;i+=i&-i){
    for(j=w;j<=W;j+=j&-j)B2[i][j]+=a;
  }
}
long long b2sum(int h,int w){
  long long s=0,i,j;
  for(i=h;i;i-=i&-i){
    for(j=w;j;j-=j&-j)s+=B2[i][j];
  }
  return s;
}
int main(){
  int n,a,b,c,d,q,i,j;
  scanf("%d %d",&H,&W);
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      scanf("%d",&a);
      b2add(i+1,j+1,a);
    }
  }
  scanf("%d",&n);
  while(n--){/*
    for(i=0;i<=H;i++){
      for(j=0;j<=W;j++)printf("%2d ",B2[i][j]);
      printf("\n");
      }printf("\n");//*/
    scanf("%d",&q);
    if(q){
      scanf("%d %d %d %d",&a,&b,&c,&d);
      //printf("%d %d %d %d\n",b2sum(c,d),b2sum(a,b),b2sum(a,d),b2sum(c,b));
      printf("%lld\n",b2sum(c,d)+b2sum(a,b)-b2sum(a,d)-b2sum(c,b));
    }
    else{
      scanf("%d %d %d",&a,&b,&c);
      b2add(a+1,b+1,c);
    }
  }
  return 0;
}
