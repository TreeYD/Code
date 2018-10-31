#include<bits/stdc++.h>
using namespace std;
#define M 400005
#define N 200005
#define Inf 1061109567 //63
int n,m,Kcnt,Qcnt;
int fa[N],Fa[N],V[N];
int K[N],res[N];
int getfa(int v){return fa[v]==v?v:fa[v]=getfa(fa[v]);}
	
struct Edge{
	int u,v,w;
	void read(){scanf("%d%d%d",&u,&v,&w);}
	
	bool operator<(const Edge &x)const{
		return w<x.w;
	}
}eg[M];

struct Tree{
	int to,cost;
};
vector<Tree>E[N];

void Make_tree(){
	sort(eg+1,eg+m+1);
	for(int i=1;i<=m;i++){
		int x=eg[i].u,y=eg[i].v;
		if(getfa(x)==getfa(y))continue;
		fa[fa[x]]=fa[y];
		E[x].push_back((Tree){y,eg[i].w});
		E[y].push_back((Tree){x,eg[i].w});
	}
}

int Lson[M*20],Rson[M*20];
int edge[M*20],Rt[N];
int id[M*20],tot,sz;//tot->tree sz->set

multiset<int>ans,s[M];

void Up(int p){
	edge[p]=min(edge[Lson[p]],edge[Rson[p]]);
}

void Update(int L,int R,int &tid,int x,int v,bool f){
	if(tid==0)tid=++tot,edge[tid]=Inf;
	if(L==R){
		if(!id[tid])id[tid]=++sz;
		int nc=id[tid];
		if(f)s[nc].insert(v);
		else s[nc].erase(s[nc].find(v));
		if(s[nc].size())edge[tid]=*(s[nc].begin());
		else edge[tid]=Inf;
		return;
	}
	int mid=L+R>>1;
	if(x<=mid)Update(L,mid,Lson[tid],x,v,f);
	else Update(mid+1,R,Rson[tid],x,v,f);
	Up(tid);
}

int Query(int L,int R,int l,int r,int tid){
	if(tid==0||l>r)return Inf;
	if(L==l&&R==r)return edge[tid];
	int mid=L+R>>1;
	if(r<=mid)return Query(L,mid,l,r,Lson[tid]);
	if(l>mid)return Query(mid+1,R,l,r,Rson[tid]);
	return min(Query(L,mid,l,mid,Lson[tid]),Query(mid+1,R,mid+1,r,Rson[tid]));
}

void dfs_init(int x,int f){
	Fa[x]=f;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to,z=E[x][i].cost;
		if(y==f)continue;
		V[y]=z;
		Update(1,Kcnt,Rt[x],K[y],z,1);
		dfs_init(y,x);
	}
	int a=Query(1,Kcnt,1,K[x]-1,Rt[x]);
	int b=Query(1,Kcnt,K[x]+1,Kcnt,Rt[x]);
	res[x]=min(a,b);
	ans.insert(res[x]);
}

void Init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		res[i]=Inf;
	}
	memset(edge,63,sizeof(edge));
}

int main(){
	scanf("%d%d%d%d",&n,&m,&Kcnt,&Qcnt);
	int x,k;
	for(int i=1;i<=m;i++){
		eg[i].read();
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&K[i]);
	Init();
	Make_tree();
	dfs_init(1,0);
	for(int i=1;i<=Qcnt;i++){
		scanf("%d%d",&x,&k);
		if(K[x]!=k){
			ans.erase(ans.find(res[x]));
			int a=Query(1,Kcnt,1,k-1,Rt[x]);
			int b=Query(1,Kcnt,k+1,Kcnt,Rt[x]);
			res[x]=min(a,b);
			ans.insert(res[x]);
			if(x!=1){
				ans.erase(ans.find(res[Fa[x]]));
				Update(1,Kcnt,Rt[Fa[x]],K[x],V[x],0);
				Update(1,Kcnt,Rt[Fa[x]],k,V[x],1);
				int a=Query(1,Kcnt,1,K[Fa[x]]-1,Rt[Fa[x]]);
				int b=Query(1,Kcnt,K[Fa[x]]+1,Kcnt,Rt[Fa[x]]);
				res[Fa[x]]=min(a,b);
				ans.insert(res[Fa[x]]); 
			}
			K[x]=k;
		}
		printf("%d\n",*(ans.begin()));
	}
	return 0;
}
