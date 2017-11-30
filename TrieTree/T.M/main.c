#include<stdio.h>
int ta[100010],nt[100010],CA[100010],U[100010],R=0;
void tadd(char *s){
  int n=0,i,j;
  for(i=-1;s[++i];n=j<0?R:j+1){
    for(j=ta[n];j+1&&CA[j]-s[i];j=nt[j]);
    if(j<0){
      nt[R]=ta[n];
      CA[ta[n]=R++]=s[i];
    }
  }
  U[n]=1;
}
int tck(char *s){
  int n=0,i,j;
  for(i=-1;s[++i];n=j+1){
    for(j=ta[n];j+1&&CA[j]-s[i];j=nt[j]);
    if(j<0)return 0;
  }
  return U[n];
}
int main(){
  int n,m,i,j;
  char s[1010];
  scanf("%d %d",&n,&m);
  for(i=0;i<100010;i++)ta[i]=-1;
  for(i=0;i<n;i++){
    scanf("%s",s);
    tadd(s);
  }
  while(m--){
    scanf("%s",s);
    printf("%s\n",tck(s)?"Yes":"No");
  }
  return 0;
}
  
