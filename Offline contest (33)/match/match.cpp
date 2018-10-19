#include<bits/stdc++.h>
using namespace std;
#define M 200005
#define Inf 0x7f7f7f7f
void Min(int &x,int y){
	if(x>y)x=y;
}
struct path{
	int len,val;
};
vector<path>mp[M];
vector<int>E[M];
int dep[M],n,m,q;
struct P20{
	int dp[5005][5005];
	void dfs(int x,int f){
		dep[x]=dep[f]+1;
		if(x!=1){
			for(int i=0;i<=dep[x];i++)
				dp[x][i]=Inf;
			for(int i=0;i<mp[x].size();i++){
				int k=mp[x][i].len,v=mp[x][i].val;
				Min(dp[x][dep[x]],v+dp[f][max(dep[x]-k,1)]);
				for(int j=1;j<dep[x];j++){
					Min(dp[x][j],v+dp[f][min(max(dep[x]-k,1),j)]);
				}
			}
		}
		for(int i=1;i<dep[x];i++)
			Min(dp[x][i],dp[f][i]);
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
		}
	}
	void solve(){
		dfs(1,0);
		for(int i=1;i<=q;i++){
			int x;
			scanf("%d",&x);
			printf("%d\n",dp[x][dep[x]]);
		}
	}
}p20;
struct Pall{
	int mi[M],dep[M];
	void dfs(int x,int f){
		dep[x]=dep[f]+1;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
		}
	}
	bool init(){
		memset(mi,-1,sizeof(mi));
		dfs(1,0);
		for(int i=1;i<=n;i++)
			for(int j=0;j<mp[i].size();j++){
				if(mp[i][j].len!=dep[i]-1)return 0;
				if(mi[i]==-1||mi[i]>mp[i][j].val)
					mi[i]=mp[i][j].val;
			}
		return 1;
	}
	void solve(){
		for(int i=1,x;i<=q;i++){
			scanf("%d",&x);
			printf("%d\n",mi[x]);
		}
	}
}pall;
int main(){//name long long memory mod
//	freopen("match.in","r",stdin);
//	freopen("match.out","w",stdout);
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
	if(n<=5000)p20.solve();
	else if(pall.init())pall.solve();
	return 0;
}
