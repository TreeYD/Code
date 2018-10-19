#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define M ((1<<10)+5)
LL A,B;
int n,e,mul[M];
int cnt[M],bin[M];
vector<int>son;
void Init(){
	int i;
	son.clear();
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			son.push_back(i);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)son.push_back(n);
	e=(1<<son.size());
	mul[0]=1;
	for(i=1;i<e;i++)
		mul[i]=mul[i&i-1]*son[bin[i&-i]];
}
LL solve(LL x){
	if(x==0)return 0;
	LL ans=0;
	for(int i=1;i<e;i++){
		int mo=-1;
		if(cnt[i]&1)mo=1;
		ans+=mo*x/mul[i];
	}
	return ans;
} 
int main(){
	int T,Ti=0;
	scanf("%d",&T);
	for(int i=0;i<=10;i++)bin[1<<i]=i;
	for(int i=1;i<=(1<<10);i++)cnt[i]=cnt[i&i-1]+1;
	while(T--){
		scanf("%lld%lld%d",&A,&B,&n);
		Init();
		LL ans=solve(B)-solve(A-1);
		printf("Case #%d: %lld\n",++Ti,B-A+1-ans);
	}
}
