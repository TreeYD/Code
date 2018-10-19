#include<bits/stdc++.h>
using namespace std;
#define MaxL 10003005
int A[105],m;
bool mark[MaxL];
int S,T,Len;
template<typename T>void Min(T &x,T y){if(x>y)x=y;}
struct P70{
	int dp[MaxL],Q[MaxL];
	void solve(){
		int L=0,R=0;
		Q[++R]=0;
		memset(dp,63,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=m;i++)
			mark[A[i]]=1;
		for(int i=S;i<Len+T;i++){
			if(L<=R&&i-Q[L]>T)L++;
			while(L<=R&&dp[i-S]<=dp[Q[L]])L++;
			Q[++R]=i-S;
			Min(dp[i],dp[Q[L]]+mark[i]);
		}
		int ans=2e9;
		for(int i=Len;i<Len+T;i++)
			Min(ans,dp[i]);
		printf("%d\n",ans);
	}
}p70;
int main(){//name memory long long * mod -
//	freopen("river.in","r",stdin);
//	freopen("river.out","w",stdout);
	scanf("%d",&Len);
	scanf("%d%d%d",&S,&T,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&A[i]);
		mark[A[i]]=1;
	}
//	p30.solve();
	p70.solve();
	return 0;
}
