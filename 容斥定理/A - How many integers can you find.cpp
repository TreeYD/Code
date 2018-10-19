#include<bits/stdc++.h>
using namespace std;
#define M ((1<<10)+5)
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
	if(a==0||b==0)return 0;
	int d=gcd(a,b);
	return a*b/d;
}
int LCM[M],bin[M],cnt[M];
int A[15],n,m,e;
void Init(){
	e=(1<<m);
	LCM[0]=1;
	for(int i=1;i<e;i++){
		LCM[i]=lcm(LCM[i&i-1],A[bin[i&-i]]);
	}
}
int main(){
	for(int i=0;i<=10;i++)bin[1<<i]=i;
	for(int i=1;i<=(1<<10);i++)cnt[i]=cnt[i&i-1]+1;
	while(~scanf("%d%d",&n,&m)){
		//pay attention to clear
		int i;
		for(i=0;i<m;i++)
			scanf("%d",&A[i]);
		Init();
		long long ans=0;
		for(i=1;i<e;i++){
			int mo=-1;
			if(cnt[i]&1)mo=1;
			if(LCM[i])ans+=mo*(n-1)/LCM[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
