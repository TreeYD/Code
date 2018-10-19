#include<bits/stdc++.h>
using namespace std;
#define M 500005
int fa[M],ans,n;
struct edge{
	int nxt,to;
}E[M<<1];
int head[M],num;
int S[M],T[M],cnt;
int dp[M][2];
void Add(int u,int v){
	E[++num].to=v;               
	E[num].nxt=head[u];
	head[u]=num;
}
int getfa(int v){
	return fa[v]==v?v:fa[v]=getfa(fa[v]);
}
void dfs(int x,int f){
	dp[x][0]=0;dp[x][1]=1;
	for(int i=head[x];i;i=E[i].nxt){
		int y=E[i].to;
		if(y==f)continue;
		dfs(y,x);
		dp[x][0]+=max(dp[y][1],dp[y][0]);
		dp[x][1]+=dp[y][0];
	}
}
void solve(int k){
	int a=S[k],b=T[k],c;
	dfs(a,0);
	c=dp[a][0];
	dfs(b,0);
	c=max(c,dp[b][0]);
	ans+=c;
}
int main(){
	scanf("%d",&n);
	int x,i;
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(getfa(x)==getfa(i)){
			S[++cnt]=i;
			T[cnt]=x;
			continue;
		}
		Add(x,i);Add(i,x);
		fa[fa[x]]=fa[i];
	}
	for(i=1;i<=cnt;i++)solve(i);
	printf("%d\n",ans);
	return 0;
}
