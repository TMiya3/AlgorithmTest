#include<stdio.h>
long long MIN(long long a,long long b){return a<b?a:b;}
int main(){
  long long d[100010],i,a,b,c,n,q,min;
  scanf("%lld",&n);
  for(i=0;i<n;i++)scanf("%lld",&d[i]);
  scanf("%lld",&n);
  while(n--){
    scanf("%lld",&q);
    if(q){
      scanf("%lld %lld",&a,&b);
      min=1e18;
      for(i=a;i<b;i++)min=MIN(min,d[i]);
      printf("%lld\n",min);
    }
    else{
      scanf("%lld %lld %lld",&a,&b,&c);
      for(i=a;i<b;i++)d[i]+=c;
    }
  }
  return 0;
}
