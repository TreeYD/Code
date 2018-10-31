#include<bits/stdc++.h>
using namespace std;
#define M 1000005
char str[M];
int stk[M],val[M];
int top,n;
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	long long ans=0;
	stk[++top]=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='(')stk[++top]=i;
		else{
			if(top>1){
				val[top--]=0;
				val[top]++;
				ans+=val[top];
			}else val[top]=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
