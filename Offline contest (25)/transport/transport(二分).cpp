#include<bits/stdc++.h>
using namespace std;
#define M 300005
struct edge{
	int nxt,to,cost;
}E[M<<1];
int head[M],num,mxd;
int n,m,S[M],T[M],lca[M];
int cnt[M],top[M],sz[M];
int son[M],dep[M],dis[M];
int fa[M][2],val[M];
int dfn[M],dfsLine;
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),c<'0'||c>'9');
	do{
		res=(res<<1)+(res<<3)+(c^48);
	}while(c=getchar(),c>='0'&&c<='9');
}
void Add(int u,int v,int w){
	E[++num].to=v;
	E[num].nxt=head[u];
	E[num].cost=w;
	head[u]=num;
}
int LCA(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]]){
			a=fa[top[a]][0];
		}else b=fa[top[b]][0];
	}
	return dep[a]<dep[b]?a:b;
}
void dfs_top(int x,int tp){
	top[x]=tp;
	if(son[x])dfs_top(son[x],tp);
	for(int i=head[x];i;i=E[i].nxt){
		int y=E[i].to,z=E[i].cost;
		if(y==fa[x][0]||y==son[x])continue;
		dfs_top(y,y);
	}
}
void dfs(int x){
	sz[x]=1;dfn[++dfsLine]=x;
	dep[x]=dep[fa[x][0]]+1;
	for(int i=head[x];i;i=E[i].nxt){
		int y=E[i].to,z=E[i].cost;
		if(y==fa[x][0])continue;
		fa[y][0]=x;fa[y][1]=z;
		dis[y]=dis[x]+z;
		dfs(y);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
bool check(int lim){
	int p=0,i,j;
	for(i=1;i<=n;i++)cnt[i]=0;
	for(i=1;i<=m;i++){
		if(val[i]>lim){
			cnt[S[i]]++;cnt[T[i]]++;	
			cnt[lca[i]]-=2;p++;
		}
	}
	for(i=n;i>=1;i--){
		int x=dfn[i];
		for(j=head[x];j;j=E[j].nxt){
			if(E[j].to==fa[x][0])continue;
			cnt[x]+=cnt[E[j].to];
		}
	}
	for(i=2;i<=n;i++)
		if(cnt[i]==p&&val[mxd]-fa[i][1]<=lim)return 1;
	return 0;
}
void Find(){
	int L=0,R=val[mxd],ans;
	while(L<=R){
		int mid=L+R>>1;
		if(check(mid)){
			R=mid-1;
			ans=mid;
		}else L=mid+1;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y,z,i;
	for(i=1;i<n;i++){
		Rd(x);Rd(y);Rd(z);
		Add(x,y,z);Add(y,x,z);
	}
	dfs(1);
	dfs_top(1,1);
	for(i=1;i<=m;i++){
		Rd(S[i]);Rd(T[i]);
		lca[i]=LCA(S[i],T[i]);
		val[i]=dis[S[i]]+dis[T[i]]-2*dis[lca[i]];
		if(val[i]>val[mxd])mxd=i; 
	}
	Find();
	return 0;
}
