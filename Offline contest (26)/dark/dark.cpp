#include<bits/stdc++.h>
using namespace std;
#define M 100005
int to[M],n;
struct P30{
	bool mark[30];
	int ans;
	void dfs(int x,int c){
		if(x==n+1){
			for(int i=1;i<=n;i++){
				int y=to[i];
				if(mark[i]&&mark[y])return;
			}
			ans=max(ans,c);
			return;
		}
		mark[x]=1;
		dfs(x+1,c+1);
		mark[x]=0;
		dfs(x+1,c);
	}
	void solve(){
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
}p30;
struct P10{
	int dfn[M],low[M],in[M];
	int stk[M],top,T,Bcnt;
	int G[M],sz[M],to[M];
	int nxt[M],dp[M][2],n;
	void Min(int &x,int y){
		if(x>y)x=y;
	}
	void Tarjan(int x){
		dfn[x]=low[x]=++T;
		stk[++top]=x;
		int y=to[x];
		if(!dfn[y]){
			Tarjan(y);
			Min(low[x],low[y]);
		}else if(!G[y])Min(low[x],dfn[y]);
		if(dfn[x]==low[x]){
			Bcnt++;int y;
			do{
				y=stk[top--];
				G[y]=Bcnt;
				sz[Bcnt]++;
			}while(x!=y);
		}
	}
	int Q[M];
	void Topo(){
		int L=1,R=0;
		int ans=0,i;
		for(i=1;i<=Bcnt;i++){
			if(sz[i]>1)dp[i][1]=sz[i]/2;
			else dp[i][1]=1;
			dp[i][0]=sz[i]/2;
			if(in[i]==0)Q[++R]=i;
		}
		while(L<=R){
			int x=Q[L++];
			if(sz[x]>1){
				ans+=max(dp[x][1],dp[x][0]);
				continue;
			}
			int y=nxt[x];
			in[y]--;
			dp[y][1]+=dp[x][0];
			dp[y][0]+=max(dp[x][1],dp[x][0]);
			if(in[y]==0)Q[++R]=y;
		}
		printf("%d\n",ans);
	}
	void solve(){
		int i;
		for(i=1;i<=n;i++)
			if(!dfn[i])Tarjan(i);
		for(i=1;i<=n;i++){
			int x=i,y=to[i];
			if(G[x]!=G[y]){
				nxt[G[x]]=G[y];
				in[G[y]]++;
			}
		}
		Topo();
	}
}p10;
int main(){
//	freopen("dark.in","r",stdin);
//	freopen("dark.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&to[i]);
	if(n<=15)p30.solve();
	else p10.solve();
	return 0;
}
