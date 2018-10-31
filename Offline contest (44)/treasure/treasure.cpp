#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define bit(x) (1<<x)
int X[M],Y[M],W[M],n,m;//宝藏下标从0开始 
vector<int>E[M];
struct P1{//x=y
	bool check(){
		for(int i=1;i<=m;i++)
			if(X[i]!=Y[i])return 0;
		return 1;	
	}	
	void solve(){
		int ans=0;
		for(int i=1;i<=m;i++)
			if(W[i]>0)ans+=W[i];
		printf("%d\n",ans);
	}
}p1;
struct P2{//x=1
	int val[M];
	bool check(){
		for(int i=0;i<m;i++)
			if(X[i]!=1)return 0;
		return 1;
	}
	void dfs(int x,int f){
		int t=val[x];
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			val[x]=max(val[x],t+val[y]);
		}
	}
	void solve(){
		int ans=0;
		for(int i=0;i<m;i++)
			val[Y[i]]+=W[i];
		dfs(1,0);
		printf("%d\n",max(val[1],0));
	}
}p2;
struct P3{
	vector<int>K[1005],T[1005];
	bool mark[1005];
	int dp[1005];
	void dfs(int x,int f){
		for(int i=0;i<K[x].size();i++)
			mark[K[x][i]]=1;
		int &t=dp[x];t=0;
		for(int i=0;i<T[x].size();i++)
			if(mark[T[x][i]])t+=W[T[x][i]];
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			dp[x]=max(dp[x],t+dp[y]);
		}
		for(int i=0;i<K[x].size();i++)
			mark[K[x][i]]=0;
	}
	void solve(){
		for(int i=0;i<m;i++){
			K[X[i]].push_back(i);
			T[Y[i]].push_back(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dfs(1,0);
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	
}p3;
int main(){//name memory long long * mod - 切分判断 初值
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout); 
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&X[i],&Y[i],&W[i]);
	if(n<=1000)p3.solve();
	else if(p1.check())p1.solve();
	else if(p2.check())p2.solve();
	return 0;	
}
