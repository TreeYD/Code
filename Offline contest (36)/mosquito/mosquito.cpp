#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define LL long long
const int P=1e9+7;
int leaf[M],n,d,p,q;
vector<int>E[M];
int dep[M],top[M];
int son[M],sz[M],fa[M];
void exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
LL Pow(LL a,int b){
	int base=a,ans=1;
	while(b){
		if(b&1)ans=1LL*ans*base%P;
		base=1LL*base*base%P;
		b>>=1;
	}
	return ans;
}
struct P1{//n<=3000||m<=500
	int LCA(int a,int b){
		while(top[a]!=top[b]){
			if(dep[top[a]]>dep[top[b]]){
				a=fa[top[a]];
			}else b=fa[top[b]];
		}
		return dep[a]<dep[b]?a:b;
	}
	void dfs_top(int x,int tp){
		top[x]=tp;
		if(son[x])dfs_top(son[x],tp);
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==fa[x])continue;
			dfs_top(y,y);
		}
	}
	void dfs(int x,int f){
		sz[x]=1;fa[x]=f;
		dep[x]=dep[f]+1;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			if(sz[y]>sz[son[x]])son[x]=y;
			sz[x]+=sz[y];
		}
	}
	void solve(){
		dfs(1,0);
		dfs_top(1,0);
		int m=0;
		LL res=0;
		for(int i=1;i<=n;i++)
			if(sz[i]==1)leaf[++m]=i;
//		printf("%d\n",m);
		for(int i=1;i<=m;i++)
			for(int j=i+1;j<=m;j++){
				int a=leaf[i],b=leaf[j];
				int lca=LCA(a,b);
				if(dep[lca]>d+1)continue;
				int t=1;
				t+=dep[b]>d+1?d+1-dep[lca]:dep[b]-dep[lca];
				t+=dep[a]>d+1?d+1-dep[lca]:dep[a]-dep[lca];
				res+=2LL*((Pow(q,t)-Pow(p,t))%P+P)%P*Pow(q,n-t)%P;
				res=res%P;
			}
		LL x,y;
		exgcd(Pow(q,n),P,x,y);
		res=x*res%P;
		printf("%lld\n",(res+P)%P);
	}
}p1;
struct P2{
	LL res;
	void dfs(int x,int f){
		if(E[x].size()==1)sz[x]++;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			if(x==1){
				res+=2LL*sz[y]*sz[x]%P*(q-p);
				res%=P;
			}
		}
	}
	void solve(){
		dfs(1,0);
		LL x,y;
		exgcd(q,P,x,y);
		res=1LL*res*x%P;
		printf("%lld\n",res);
	}
}p2;
int main(){//name memory long long * mod -
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
//	freopen("mosquito.in","r",stdin);
//	freopen("mosquito.out","w",stdout);
	scanf("%d",&n);
	int x,y,i;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	scanf("%d%d%d",&d,&p,&q);
	if(n<=3000||n==1000000)p1.solve();
	else if(d==0)p2.solve();
	return 0;
}
