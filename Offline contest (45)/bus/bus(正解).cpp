#include<bits/stdc++.h>
using namespace std;
#define M 200005
#define pf(s) printf("%s",s)
#define debug(x) cerr<<#x<<" = "<<x<<endl
int Get[M<<1],mx[M][20];
int Ans[M],n,Rd,m;
bool vis[M];
int dep[M],sz[M],fa[M];
int son[M],top[M];
int L[M],R[M],dfn;
bool mark[M];
void Max(int &x,int y){
	if(dep[x]>dep[y])x=y;
}
struct Node{
	int x,y,a,id;//x表示列 a表示为行 id表示第几个矩阵 id=0时为点 
	void Make(int px,int py,int pa,int pd){
		x=px;y=py;a=pa;id=pd;	
	}
	bool operator<(const Node &x)const{
		if(a==x.a)return (id==0);
		return a<x.a;
	}
}A[M*5];	
int szn;
//----------BIT----------//
struct BIT{
	int C[M];
	void Add(int x,int d){
		while(x<=n){
			C[x]+=d;
			x+=x&-x;
		}
	}
	int Sum(int x){
		int res=0;
		while(x){
			res+=C[x];
			x&=x-1;	
		}
		return res;
	}
}T;
//----------LIST---------//
struct Edge{
	int to,nxt;	
}lt[M<<1];
int head[M],e_tot;
void Add(int u,int v){
	lt[++e_tot].to=v;
	lt[e_tot].nxt=head[u];
	head[u]=e_tot;
}
//----------LCA---------// 
int LCA(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]]){
			b=fa[top[b]];
		}else a=fa[top[a]];
	}
	return dep[a]<dep[b]?a:b;
}
void dfs_top(int x,int tp){
	top[x]=tp;
	if(son[x])dfs_top(son[x],tp);
	for(int i=head[x];i;i=lt[i].nxt){
		int y=lt[i].to;
		if(y==fa[x]||y==son[x])continue;
		dfs_top(y,y);
	}
}
//---------Init---------// dfs序、跳重链 
void dfs(int x,int f){
	fa[x]=f;
	sz[x]=1;
	L[x]=++dfn;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=lt[i].nxt){
		int y=lt[i].to;
		if(y==f)continue;
		dfs(y,x);
		if(sz[y]>sz[son[x]])son[x]=y;
		sz[x]+=sz[y];
	}
	R[x]=dfn;	
}
//---------ST-----------//倍增
void redfs(int x,int f){
	for(int i=head[x];i;i=lt[i].nxt){
		int y=lt[i].to;
		if(y==f)continue;
		redfs(y,x);
		Max(mx[x][0],mx[y][0]);
	}
}
void St_Init(){
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			mx[i][j]=mx[mx[i][j-1]][j-1];
}
void Up(int &x,int lim,int id){
	for(int i=18;i>=0;i--){
		if(dep[mx[x][i]]>dep[lim]){
			Ans[id]+=(1<<i);
			x=mx[x][i];
		}
	}
}
//---------求内部有多少点---------//
void Solve(){
	sort(A+1,A+1+szn);
	for(int i=1;i<=szn;i++){
		if(A[i].id==0){
			T.Add(A[i].x,1);
		}else{
			int f=(vis[A[i].id]?1:-1);
			int l=A[i].x,r=A[i].y;
			vis[A[i].id]=1;
			Get[A[i].id]+=f*(T.Sum(r)-T.Sum(l-1));
		}
	}
}
int main(){
//	freopen("bus1.in","r",stdin);
//	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&Rd,&m);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		Add(x,y);Add(y,x);	
	}
	dfs(1,0);
	dfs_top(1,0);
	for(int i=1;i<=n;i++)mx[i][0]=i;
	for(int i=1;i<=Rd;i++){
		scanf("%d%d",&x,&y);
		int lca=LCA(x,y);
		Max(mx[y][0],lca);
		Max(mx[x][0],lca);
		A[++szn].Make(L[x],L[x],L[y],0);
	}
	redfs(1,0);
	St_Init();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		int lca=LCA(x,y);
		if(y==lca)swap(x,y);
		if(x==lca){
			Up(y,x,i);
			mark[i]=1;
			if(dep[mx[y][0]]>dep[x])Ans[i]=-1;
		}else{
			Up(x,lca,i);
			Up(y,lca,i);
			if(dep[mx[y][0]]>dep[lca]||dep[mx[x][0]]>dep[lca])Ans[i]=-1;
			else{
				A[++szn].Make(L[y],R[y],L[x]-1,i<<1);
				A[++szn].Make(L[y],R[y],R[x],i<<1);
				A[++szn].Make(L[x],R[x],L[y]-1,i<<1|1);
				A[++szn].Make(L[x],R[x],R[y],i<<1|1);
			}
		}
	}
	Solve();
	for(int i=1;i<=m;i++){
		if(Ans[i]!=-1&&!mark[i]&&!Get[i<<1]&&!Get[i<<1|1])Ans[i]++;
		printf("%d\n",Ans[i]);
	}
	return 0;	
}
