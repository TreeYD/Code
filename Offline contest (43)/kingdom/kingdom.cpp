#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define LL long long
template<class T>void Min(T &x,T y){if(x>y)x=y;}
template<class T>void Max(T &x,T y){if(x<y)x=y;}
template<class T>void Rd(T &x){
	x=0;
	int flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')flag=-1;
		c=getchar();
	}
	do{
		x=(x<<3)+(x<<1)+(c^48);	
	}while(c=getchar(),c>='0'&&c<='9');
	x*=flag;
}
struct Edge{
	int u,v;	
}eg[M];
struct List{
	int to,nxt;	
}lt[M<<1];
int head[M],e_tot,n;
int Rt;
void Add(int u,int v){
	lt[++e_tot].to=v;
	lt[e_tot].nxt=head[u];
	head[u]=e_tot;	
}
struct P60{
	#define N 200005
	int pre[N],fa[N],sz[N];
	LL ans[N];
	int getfa(int v){return pre[v]==v?v:pre[v]=getfa(pre[v]);}
	void dfs_find(int x,int f){
		fa[x]=f;
		for(int i=head[x];i;i=lt[i].nxt){
			int y=lt[i].to;
			if(y==f||y==Rt)continue;
			dfs_find(y,x);
		}
	}
	void dfs_solve(int x,int f){
		sz[x]=1;
		ans[x]=0;
		for(int i=head[x];i;i=lt[i].nxt){
			int y=lt[i].to;
			if(y==f||y==Rt)continue;
			dfs_solve(y,x);
			ans[x]+=ans[y];
			ans[x]+=1LL*(n-sz[y])*sz[y];
			sz[x]+=sz[y];	
		}
	}
	void solve(){
		for(int i=1;i<=n;i++)pre[i]=i;
		int x,y;
		LL res=1e18;
		for(int i=1;i<=n;i++){
			x=eg[i].u,y=eg[i].v;
			if(getfa(x)==getfa(y)){
				Rt=x;
				dfs_find(x,y);
				break;
			}
			pre[pre[x]]=pre[y];
		}
		int t=y;
		do{
			Rt=y;
			dfs_solve(y,fa[y]);
			Min(res,ans[y]);
			y=fa[y];
		}while(y!=t);
		printf("%lld\n",res);
	}	
}p60;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ
//	printf("%.2lf\n",(&cur2-&cur1)/1024.0/1024); 
	freopen("kingdom.in","r",stdin);
	freopen("kingdom.out","w",stdout);
	Rd(n);
	int x,y;
	for(int i=1;i<=n;i++){
		Rd(x);Rd(y);
		eg[i]=(Edge){x,y};
		Add(x,y);Add(y,x);
	}
	p60.solve();
	return 0;
}
