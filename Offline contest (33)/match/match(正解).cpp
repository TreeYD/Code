#include<bits/stdc++.h>
using namespace std;
#define M 200005
#define LL long long
#define Inf 0x7f7f7f7f7f
LL dp[M],mi[M][20];
int dep[M],n,m,q;
vector<int>E[M];
struct path{
	int k,v;
};
vector<path>mp[M];
int fa[M][20];
void Min(LL &x,LL y){
	if(x>y)x=y;
}
LL Up(int x,int step){
	LL res=dp[x];
	for(int i=18;i>=0;i--){
		if(step&(1<<i)){
			Min(res,mi[x][i]);
			x=fa[x][i];
		}
	}
	return res;
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	mi[x][0]=dp[f];
	dp[x]=(x>1)*Inf;
	for(int i=0;i<mp[x].size();i++){
		int k=mp[x][i].k,v=mp[x][i].v;
		Min(dp[x],v+Up(f,min(dep[f]-1,k-1)));
	}
	for(int i=1;i<=18;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		mi[x][i]=min(mi[x][i-1],mi[fa[x][i-1]][i-1]);
	}
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		dfs(y,x);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	int x,y,z;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		mp[x].push_back((path){y,z});
	}
	dfs(1,0);
	for(int i=1;i<=q;i++){
		scanf("%d",&x);
		printf("%lld\n",dp[x]);
	}
	return 0;
}
