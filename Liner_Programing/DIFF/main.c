#include<stdio.h>
double MAX(double a,double b){return a<b?b:a;}
double MIN(double a,double b){return a<b?a:b;}
int main(){
  int n,m,i,j,a[2][2],b[2],c[2];
  char s[2][3];
  double t,x,y,ans=0,eps=1e-9;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++)scanf("%d",&c[i]);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    scanf("%s %d",s[i],&b[i]);
  }
  ans=MAX(ans,MIN(1.0*b[0]/a[0][0],1.0*b[1]/a[1][0])*c[0]);
  ans=MAX(ans,MIN(1.0*b[0]/a[0][1],1.0*b[1]/a[1][1])*c[1]);
  //printf("%lf\n",ans);
  t=a[0][0]*a[1][1]-a[0][1]*a[1][0];
  if(t){
    x=(1.0*a[1][1]*b[0]-a[0][1]*b[1])/t;
    y=(1.0*a[0][0]*b[1]-a[1][0]*b[0])/t;
    if(x+eps>0&&y+eps>0)ans=MAX(ans,x*c[0]+y*c[1]);
  }
  printf("%.10lf\n",ans);
  return 0;
}
			
