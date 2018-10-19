#include<bits/stdc++.h>
using namespace std;
#define M 15
#define LL long long
struct node{
	int from,to,cost;
	bool operator<(const node &x)const{
		return cost<x.cost;
	}
}A[M*M];
int mp[M][M],cnt,rt;
int edge[M][M],fa[M];
int pre[M],sz[M],tsz[M];
int n,m,dep[M];
bool mark[M*M];
LL ans,tmp;
int getfa(int v){
	return pre[v]==v?v:pre[v]=getfa(pre[v]);
}
void Build(){
	int i;
	for(i=1;i<=n;i++)pre[i]=i;
	memset(mark,0,sizeof(mark));
	memset(edge,0,sizeof(edge));
	memset(fa,0,sizeof(fa));
	for(i=1;i<=cnt;i++){
		int x=A[i].from,y=A[i].to;
		if(getfa(x)!=getfa(y)){
			pre[pre[x]]=pre[y];
			mark[i]=1;
			edge[x][y]=edge[y][x]=A[i].cost;
		}
	}
}
void dfs(int x,int f){
	fa[x]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=n;i++){
		if(i==f||i==x||!edge[x][i])continue;
		sz[i]=sz[x]+1;
		ans+=sz[i]*edge[x][i];
		dfs(i,x);
	}
}
void redfs(int x,int f){
	for(int i=1;i<=n;i++){
		if(i==f||i==x||!edge[x][i])continue;
		tsz[i]=tsz[x]+1;
		tmp+=tsz[i]*edge[x][i];
		redfs(i,x);
	}
}
void get(int x){
	tmp=0;
	int t=edge[x][fa[x]];
	edge[x][fa[x]]=edge[fa[x]][x]=0;
	memset(tsz,0,sizeof(tsz));
	redfs(rt,0);
	edge[x][fa[x]]=edge[fa[x]][x]=t;
}
void solve(){
	Build();
	ans=0;
	sz[rt]=tsz[rt]=0;
	fa[rt]=0;
	dep[rt]=1;
	dfs(rt,0);
	int i;
	for(i=1;i<=cnt;i++){
		if(mark[i])continue;
		int x=A[i].from,y=A[i].to,z=A[i].cost;
		int kx=x,ky=y,miID=0;
		LL mi=1e16;
		edge[x][y]=edge[y][x]=z;
		while(kx!=ky){
			if(dep[kx]>dep[ky]){
				get(kx);
				if(tmp<mi){
					mi=tmp;
					miID=kx;
				}
				kx=fa[kx];
			}else{
				get(ky);
				if(tmp<mi){
					mi=tmp;
					miID=ky;
				}
				ky=fa[ky];
			}
		}
		if(mi<ans){
			ans=0;
			edge[fa[miID]][miID]=edge[miID][fa[miID]]=0;
			memset(sz,0,sizeof(sz));
			dfs(rt,0);
		}else{
			edge[x][y]=edge[y][x]=0;	
		}
	}
}
int main(){
//	freopen("treasure.in","r",stdin);
//	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z,i,j;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(mp[x][y]==0||mp[x][y]>z)mp[x][y]=mp[y][x]=z;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(mp[i][j]){
				A[++cnt]=(node){i,j,mp[i][j]};
			}
	memset(mp,0,sizeof(mp));
	sort(A+1,A+1+cnt);
	LL res=1e16;
	for(rt=1;rt<=n;rt++){
		solve();
		res=min(res,ans);
	}
	printf("%lld\n",res);
	return 0;
}
