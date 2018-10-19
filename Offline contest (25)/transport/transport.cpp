#include<bits/stdc++.h>
using namespace std;
int n,m;
struct P50{
	#define maxn 3005
	struct edge{
		int to,id;
	};
	vector<edge>E[maxn];
	int len[maxn],dis[maxn];
	int S[maxn],T[maxn];
	int dep[maxn],fa[maxn][20];
	void St_Init(){
		for(int j=1;j<=15;j++)
			for(int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	void Up(int &x,int step){
		for(int i=0;i<=15;i++)
			if(step&(1<<i))x=fa[x][i];
	}
	int LCA(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		Up(b,dep[b]-dep[a]);
		if(a==b)return a;
		for(int i=15;i>=0;i--)
			if(fa[a][i]!=fa[b][i])
				a=fa[a][i],b=fa[b][i];
		return fa[a][0];
	}
	void dfs(int x,int f){
		dep[x]=dep[f]+1;
		fa[x][0]=f;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i].to;
			if(y==f)continue;
			dfs(y,x);
		}
	}
	void redfs(int x,int f){
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i].to,d=len[E[x][i].id];
			if(y==f)continue;
			dis[y]=dis[x]+d;
			redfs(y,x);
		}
	}
	void solve(){
		int x,y,z,i,j;
		for(i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			E[x].push_back((edge){y,i});
			E[y].push_back((edge){x,i});
			len[i]=z;
		}
		for(i=1;i<=m;i++)
			scanf("%d%d",&S[i],&T[i]);
		dfs(1,0);St_Init();
		int ans=2e9;
		for(i=1;i<n;i++){
			int t=len[i];
			len[i]=0;
			for(j=1;j<=n;j++)dis[j]=0;
			redfs(1,0);
			int mx=0;
			for(j=1;j<=m;j++){
				int x=S[j],y=T[j];
				mx=max(mx,dis[x]+dis[y]-2*dis[LCA(x,y)]);
			}
			len[i]=t;
			ans=min(ans,mx);
		}
		printf("%d\n",ans);
	}
}p50;
#define M 300005
struct edge{
	int to,cost;
};
vector<edge>E[M];
int A[M],B[M];
struct p10{
	int fa[M][2];
	void dfs(int x,int f){
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i].to,z=E[x][i].cost;
			if(y==f)continue;
			fa[y][0]=x;fa[y][1]=z;
			dfs(y,x);
		}
	}
	void solve(){
		int x=A[1],y=B[1];
		dfs(x,0);
		int sum=0,mx=0;
		while(y!=x){
			sum+=fa[y][1];
			mx=max(mx,fa[y][1]);
			y=fa[y][0];
		}	
		printf("%d\n",sum-mx);
	}
}p10;
struct Pchain{
	#define Ls p<<1
	#define Rs p<<1|1
	int len[M];
	struct node{
		int L,R;
		int mx1,mx2;
		int d1,d2;
	}T[M<<2];
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		if(L==R)return;
		int mid=L+R>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
	}
	void Down(int p){
		int &t1=T[p].d1,&t2=T[p].d2;
		if(t1!=-1){
			T[Ls].mx1=max(T[Ls].mx1,t1);
			T[Rs].mx1=max(T[Rs].mx1,t1);
			t1=-1;
		}
		if(t2!=-1){
			T[Ls].mx2=max(T[Ls].mx2,t2);
			T[Rs].mx2=max(T[Rs].mx2,t2);
			t2=-1;
		}
	}
	void Up(int p){
		T[p].mx1=max(T[Ls].mx1,T[Rs].mx1);
		T[p].mx2=max(T[Ls].mx2,T[Rs].mx2);
	}
	void Update1(int L,int R,int p,int v){
		if(T[p].L==L&&T[p].R==R){
			T[p].mx1=max(T[p].mx1,v);
			T[p].d1=v;
			return;
		}
		Down(p);
		int mid=T[Ls].R;
		if(mid>=R)Update1(L,R,Ls,v);
		else if(mid<L)Update1(L,R,Rs,v);
		else {
			Update1(L,mid,Ls,v);
			Update1(mid+1,R,Rs,v);
		}
		Up(p);
	}
	void Update2(int L,int R,int p,int v){
		if(T[p].L==L&&T[p].R==R){
			T[p].mx2=max(T[p].mx2,v);
			T[p].d2=v;
			return;
		}
		Down(p);
		int mid=T[Ls].R;
		if(mid>=R)Update2(L,R,Ls,v);
		else if(mid<L)Update2(L,R,Rs,v);
		else {
			Update2(L,mid,Ls,v);
			Update2(mid+1,R,Rs,v);
		}
		Up(p);
	}
	int dis[M];
	void dfs(int x,int f){
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i].to,d=E[x][i].cost;
			if(y==f)continue;
			dis[y]=dis[x]+d;
			len[y]=d;
			dfs(y,x);
		}
	}
	int Query(int x,int p){
		if(T[p].L==T[p].R){
			return p;
		}
		Down(p);
		int mid=T[Ls].R;
		if(x<=mid)return Query(x,Ls);
		return Query(x,Rs);
	}
	void solve(){
		dfs(1,0);
		Build(1,n,1);
		int i;
		for(i=1;i<=m;i++){
			int x=A[i],y=B[i];
			int sum=dis[y]-dis[x];
			Update1(x+1,y,1,sum);
			if(x>1)Update2(1,x,1,sum);
			if(y<n)Update2(y+1,n,1,sum);
		}
		int ans=2e9;
		for(i=2;i<=n;i++){
			int t=Query(i,1),mx=0;
			mx=max(T[t].mx1-len[i],T[t].mx2);
			ans=min(ans,mx);
		}
		printf("%d\n",ans);
	}
}pchain;
int main(){
//	freopen("transport.in","r",stdin);
//	freopen("transport.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=3000)p50.solve();
	else{
		int i,x,y,z;
		for(i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			E[x].push_back((edge){y,z});
			E[y].push_back((edge){x,z});
		}
		for(i=1;i<=m;i++){
			scanf("%d%d",&A[i],&B[i]);
			if(A[i]>B[i])swap(A[i],B[i]);
		}
		if(m==1)p10.solve();
		else pchain.solve();
	}
	return 0;
}
