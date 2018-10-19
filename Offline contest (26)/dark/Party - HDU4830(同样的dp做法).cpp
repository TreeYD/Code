#include<bits/stdc++.h>
using namespace std;
#define M 100005
int fa[M],val[M],n;
int S[M],T[M],cnt,ans;
vector<int>E[M];
int getfa(int v){
	return fa[v]==v?v:fa[v]=getfa(fa[v]);
}
int dp[M][2];
void dfs(int x,int f){
	dp[x][1]=val[x];
	dp[x][0]=0;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		dfs(y,x);
		dp[x][1]+=dp[y][0];
		dp[x][0]+=max(dp[y][1],dp[y][0]);
	}
}
void solve(int k){
	int a=S[k],b=T[k],c;
	dfs(a,0);c=dp[a][0];
	dfs(b,0);c=max(c,dp[b][0]);
	ans+=c;
}
int main(){
	int Ti,Tj=0;
	scanf("%d",&Ti);
	while(Ti--){
		scanf("%d",&n);
		int x,i;
		cnt=ans=0;
		for(i=1;i<=n;i++){
			E[i].clear();
			fa[i]=i;
		}
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			if(getfa(x)==getfa(i)){
				S[++cnt]=i;
				T[cnt]=x;
				continue;
			}
			E[x].push_back(i);
			E[i].push_back(x);
			fa[fa[x]]=fa[i];
		}
		for(i=1;i<=n;i++)
			scanf("%d",&val[i]);
		for(i=1;i<=cnt;i++)solve(i);
		printf("Case #%d:\n%d\n",++Tj,ans);
	}
	return 0;
}
