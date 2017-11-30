#include<stdio.h>
#include<string.h>
int main(){
  int n,m,i;
  char s[1010][110];
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%s",s[i]);
  while(m--){
    scanf("%s",s[n]);
    for(i=0;strcmp(s[i],s[n]);i++);
    printf("%s\n",i-n?"Yes":"No");
  }
  return 0;
}
