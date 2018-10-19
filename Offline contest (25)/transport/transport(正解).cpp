#include<bits/stdc++.h>
using namespace std;
#define M 300005
void Max(int &x,int y){
	if(x<y)x=y;
}
void Min(int &x,int y){
	if(x>y)x=y;
}
struct edge{
	int to,cost;
};
vector<edge>E[M];
int fa[M][2],dis[M],dep[M];
int sz[M],top[M],son[M],n,m;
int S[M],T[M],A[M],ID,mx,my;
int pre[M],nxt[M],val[M];
int pos[M];
bool mark[M];
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
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to,z=E[x][i].cost;
		if(y==fa[x][0]||y==son[x])continue;
		dfs_top(y,y);
	}
}
void dfs_init(int x){
	sz[x]=1;
	dep[x]=dep[fa[x][0]]+1;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to,z=E[x][i].cost;
		if(y==fa[x][0])continue;
		fa[y][0]=x;
		dis[y]=dis[x]+z;
		dfs_init(y);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs_get(int x,int f){
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to,z=E[x][i].cost;
		if(y==f)continue;
		fa[y][1]=z;fa[y][0]=x;
		dfs_get(y,x);
	}
}
void dfs_cover(int x,int f,int p){
	pos[x]=p;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to;
		if(y==f||mark[y])continue;
		dfs_cover(y,x,p);
	}
}
void Init(){
	int y=my;
	A[++ID]=y;
	mark[y]=1;
	do{
		y=fa[y][0];
		mark[y]=1;
		A[++ID]=y;
	}while(y!=mx);
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y,z,i;
	for(i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		E[x].push_back((edge){y,z});
		E[y].push_back((edge){x,z});
	}
	dfs_init(1);
	dfs_top(1,1);
	int t=0,mxd;
	for(i=1;i<=m;i++){
		scanf("%d%d",&S[i],&T[i]);
		val[i]=dis[S[i]]+dis[T[i]]-2*dis[LCA(S[i],T[i])];
		if(val[i]>t){
			t=val[i];
			mxd=i;
		}
	}
	mx=S[mxd],my=T[mxd];
	dfs_get(mx,0);
	Init();
	int p=0;
	for(i=1;i<=ID;i++)
		dfs_cover(A[i],0,++p);
	for(i=1;i<=m;i++){
		if(i==mxd)continue;
		int x=S[i],y=T[i];
		int t1=pos[x],t2=pos[y];
		if(t1>t2)swap(t1,t2);
		Max(pre[t2],val[i]);
		Max(nxt[t1],val[i]);
	}
	for(i=ID;i>=1;i--)
		Max(nxt[i],nxt[i+1]);
	for(i=1;i<=ID;i++)
		Max(pre[i],pre[i-1]);
	int ans=2e9;
	for(i=1;i<ID;i++){
		int x=A[i],y=A[i+1],z=fa[x][1];
		int mx=t-z;
		Max(mx,max(pre[i],nxt[i+1]));
		Min(ans,mx);
	}
	if(ans==2e9)ans=0;
	printf("%d\n",ans);
	return 0;
}
