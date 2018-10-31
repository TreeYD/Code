#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define debug(s,x) cout<<"\tDEBUG:"<<s<<" = "<<(x)<<endl
#define debug2(s1,x1,s2,x2) cout<<"\tDEBUG:"<<s1<<" = "<<(x1)<<" "<<s2<<" = "<<(x2)<<endl
const int Inf=1e9;
template<class T>void Min(T &x,T y){if(x>y)x=y;}
template<class T>void Max(T &x,T y){if(x<y)x=y;}
struct Path{
	int s,t;	
}V[M];
vector<int>E[M];
int n,m,T;
struct P1{//n<=100
	#define Mn 505
	int dis[Mn][Mn];
	int fa[Mn];
	vector<int>pnt;
	void dfs(int x,int f){
		fa[x]=f;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
		}
	}
	void Floyd(){
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					Min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	void solve(){
		memset(dis,63,sizeof(dis));
		for(int i=1;i<=T;i++){
			int x=V[i].s,y=V[i].t;
			dfs(x,0);pnt.clear();
			do{
				pnt.push_back(y);
				y=fa[y];
				for(int j=0;j<pnt.size();j++)
					dis[y][pnt[j]]=dis[pnt[j]][y]=1;
			}while(y!=x);
		}
		Floyd();
		int x,y;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(dis[x][y]>Inf)puts("-1");
			else printf("%d\n",dis[x][y]-1);
		}
	}
}p1;
struct P2{//chain
	int mx[M][20];
	int mp[M];
	bool check(){
		for(int i=1;i<=n;i++)
			if(E[i].size()>2)return 0;
		return 1;	
	}
	void Init(){
		int Rt;
		for(int i=1;i<=n;i++)
			if(E[i].size()==1){
				Rt=i;
				break;	
			}
		int t=0,lst=0;
		mp[Rt]=++t;
		if(n==1)return;
		do{
			int tmp=Rt;
			if(E[Rt][0]==lst)Rt=E[Rt][1];
			else Rt=E[Rt][0];
			lst=tmp;
			mp[Rt]=++t;
		}while(E[Rt].size()!=1);
	}
	void solve(){
		Init();	
		for(int i=1;i<=T;i++){
			int &x=V[i].s,&y=V[i].t;
			x=mp[x];y=mp[y];
			if(x>y)swap(x,y);
			Max(mx[x][0],y);
		}
		for(int i=1;i<=n;i++)
			if(mx[i-1][0]>i)Max(mx[i][0],mx[i-1][0]);
		for(int j=1;j<=18;j++)
			for(int i=1;i<=n;i++){
				mx[i][j]=mx[mx[i][j-1]][j-1];
			}
		for(int i=1;i<=m;i++){
		    int x,y;
			scanf("%d%d",&x,&y);
			x=mp[x],y=mp[y];
			if(x>y)swap(x,y);
			int cnt=0;
			for(int j=18;j>=0;j--){
				if(mx[x][j]==0)continue;
				if(mx[x][j]<y){
					x=mx[x][j];
					cnt+=(1<<j);
				}
			}
			if(mx[x][0]<y)puts("-1");
			else printf("%d\n",cnt);
		}
	}
}p2;
struct P3{
	#define Mm 1005
	int mark[Mm],mp[Mm],top[Mm];
	int fa[Mm],mx[Mm],sz[Mm];
	int pth[Mm],psz,to[Mm];
	int son[Mm],dep[Mm];
	vector<int>L[Mm];
	void dfs(int x,int f){
		fa[x]=f;
		sz[x]=1;
		son[x]=0;
		dep[x]=dep[f]+1;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]])son[x]=y;
		}	
	}
	void dfs_top(int x,int tp){
		top[x]=tp;
		if(son[x])dfs_top(son[x],tp);
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==fa[x]||y==son[x])continue;
			dfs_top(y,y);
		}
	}
	void redfs(int x,int f){
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			redfs(y,x);
			if(dep[to[x]]>dep[to[y]])to[x]=to[y];	
		}
	}
	int LCA(int a,int b){
		while(top[a]!=top[b]){
			if(dep[top[a]]>dep[top[b]]){
				a=fa[top[a]];
			}else b=fa[top[b]];
		}
		return dep[a]<dep[b]?a:b;
	}
	void solve(){
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			dfs(x,0);
			dfs_top(x,0);
			for(int i=1;i<=n;i++)to[i]=i;
			for(int i=1;i<=T;i++){
				int a=V[i].s,b=V[i].t;
				int lca=LCA(a,b);
				if(dep[to[a]]>dep[lca])to[a]=lca;
				if(dep[to[b]]>dep[lca])to[b]=lca;
			}
			redfs(x,0);
			int cnt=0;
			while(y!=x){
				if(to[y]==y){cnt=0;break;}
				y=to[y];cnt++;
			}
			printf("%d\n",cnt-1);
		}
	}
}p3;
int main(){
//	freopen("bus1.in","r",stdin);
//	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&T,&m);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);	
	}
	for(int i=1;i<=T;i++){
		scanf("%d%d",&V[i].s,&V[i].t);	
	}
	if(n<=100)p1.solve();
	else if(p2.check())p2.solve();
	else if(n<=1000)p3.solve();
	return 0;
}

