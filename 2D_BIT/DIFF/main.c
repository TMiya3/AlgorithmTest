#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int d[1010][1010],i,j,a,b,c,e,n,w,h,q;
  long long sum;
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)scanf("%d",&d[i][j]);
  }
  scanf("%d",&n);
  while(n--){
    scanf("%d",&q);
    if(q){
      scanf("%d %d %d %d",&a,&b,&c,&e);
      sum=0;
      for(i=a;i<c;i++){
	for(j=b;j<e;j++)sum+=d[i][j];
      }
      printf("%lld\n",sum);
    }
    else{
      scanf("%d %d %d",&a,&b,&c);
      d[a][b]+=c;
    }
  }
  return 0;
}
