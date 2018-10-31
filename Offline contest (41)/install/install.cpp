#include<bits/stdc++.h>
using namespace std;
#define M 105
#define bit(x) (1<<(x-1))
template<class T>void Max(T &x,T y){if(x<y)x=y;}
bool inc[M],vis[M];
int fa[M],W[M],V[M];
int m,n,D[M];
struct Edge{
	int x,y;
}edge[M];
int e_tot,A[M],sz;
vector<int>E[M];
int getfa(int v){
	return fa[v]==v?v:fa[v]=getfa(fa[v]);
}
//----------head----------//
struct P20{
	void solve(){
		int ans=0,e=(1<<n);
		for(int i=1;i<e;i++){
			bool flag=1;
			int tmp=0,sum=0;
			for(int j=1;j<=n;j++){
				if(i&bit(j)){
					if(D[j]&&!(i&bit(D[j]))){
						flag=0;break;
					}
					sum+=W[j];
					if(sum>m){
						flag=0;break;
					}
					tmp+=V[j];
				}
			}
			if(flag)ans=max(ans,tmp);
		}
		printf("%d\n",ans);	
	}
}p20;
struct P100{
	int dp[M][505];
	int Dp[505],tmp[2][505];
	void dfs(int x){
		if(inc[x])return;
		inc[x]=1;
		A[++sz]=x;
		dfs(D[x]);
	}
	void redfs(int x){
		for(int j=W[x];j<=m;j++)
			dp[x][j]=V[x];
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(inc[y])continue;
			redfs(y);
			for(int j=m;j>=W[x];j--)
				for(int k=W[y];k<=j-W[x];k++)
					Max(dp[x][j],dp[x][j-k]+dp[y][k]);
		}
	}
	void solve(){
		for(int i=1;i<=e_tot;i++){
			int x=edge[i].x,y=edge[i].y;
			sz=0;
			dfs(x);
			for(int j=0;j<=m;j++)tmp[0][j]=0;
			int sum=0,cur=0;
			for(int j=1;j<=sz;j++){
				redfs(A[j]);
				sum+=W[A[j]];
				cur=!cur;
				for(int p=sum;p<=m;p++){
					tmp[cur][p]=tmp[!cur][p-W[A[j]]]+V[A[j]];
					for(int k=W[A[j]];k<=p-sum+W[A[j]];k++)
						Max(tmp[cur][p],tmp[!cur][p-k]+dp[A[j]][k]);
				}
			}
			for(int j=m;j>=sum;j--)
				for(int k=sum;k<=j;k++)
					Max(Dp[j],Dp[j-k]+tmp[cur][k]);
		}
		redfs(0);
		for(int j=m;j>=0;j--)
			for(int k=j;k>=0;k--)
				Max(Dp[j],Dp[j-k]+dp[0][k]);
		printf("%d\n",Dp[m]);
	}
}p100;
int main(){//name memory long long * mod - «–∑÷≈–∂œ ≥ı÷µ 
//	printf("%.2lf\n",(sizeof(p100)+sizeof(p20))/1024.0/1024);
//	freopen("install.in","r",stdin);
//	freopen("install.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&W[i]);
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&V[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&D[i]);
		E[D[i]].push_back(i);
		if(getfa(i)==getfa(D[i])){
			edge[++e_tot]=(Edge){i,D[i]};
			continue;
		}
		fa[fa[i]]=fa[D[i]];
	}
	if(n<=20)p20.solve();
	else p100.solve();
	return 0;
}
