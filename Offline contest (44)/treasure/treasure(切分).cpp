#include<bits/stdc++.h>
using namespace std;
#define M 100005
template<class T>void Max(T &x,T y){if(x<y)x=y;}
template<class T>void Min(T &x,T y){if(x>y)x=y;}
template<class T>void Rd(T &x){
	x=0;
	char c=getchar();
	int flag=1;
	while(c<'0'||c>'9'){
		if(c=='-')flag=-1;
		c=getchar();
	}
	do{
		x=(x<<3)+(x<<1)+(c^48);	
		c=getchar();
	}while(c>='0'&&c<='9');
	x*=flag;
}
vector<int>E[M];
int X[M],Y[M],W[M];
int n,m;
struct P1{//n<=1000 || m<=1000
	vector<int>K[M],T[M];
	bool mark[M],vis[M];
	int dp[M];
	void dfs(int x,int f){
		for(int i=0;i<K[x].size();i++)
			mark[K[x][i]]=1;
		int &t=dp[x];t=0;
		for(int i=0;i<T[x].size();i++)
			if(mark[T[x][i]])t+=W[T[x][i]];
		int tmp=t;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			Max(t,tmp+dp[y]);
		}
		for(int i=0;i<K[x].size();i++)
			mark[K[x][i]]=0;
	}
	void solve(){
		int ans=0;
		for(int i=1;i<=m;i++){
			K[X[i]].push_back(i);
			T[Y[i]].push_back(i);
		}
		for(int i=1;i<=m;i++){
			if(vis[X[i]])continue;
			dfs(X[i],0);
			vis[X[i]]=1;
			Max(ans,dp[X[i]]);
		}
		printf("%d\n",ans);
	}
}p1;
struct P2{//x==y
	#define calc(x) (val[x]+down[x])
	int down[M],up[M];//不包含自己本身 
	int fi[M],se[M];
	int val[M],ans;
	bool check(){
		for(int i=1;i<=m;i++)
			if(X[i]!=Y[i])return 0;
		return 1;	
	}
	void dfs(int x,int f){
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			Max(down[x],val[y]+down[y]);
			if(calc(fi[x])<calc(y)){
				se[x]=fi[x];
				fi[x]=y;	
			}else if(calc(se[x])<calc(y))se[x]=y;
		}
	}
	void redfs(int x,int f){
		Max(ans,max(down[x],up[x])+val[x]);	
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			int t=(y==fi[x])?se[x]:fi[x];
			up[y]=max(up[x],down[t]+val[t])+val[x];
			redfs(y,x);
		}
	}
	void solve(){
		for(int i=1;i<=m;i++)
			val[X[i]]+=W[i];
		dfs(1,0);
		redfs(1,0);
		printf("%d\n",ans);
	}
}p2;
struct P3{//x==1
	int dp[M];
	bool check(){
		for(int i=1;i<=m;i++)
			if(X[i]!=1)return 0;
		return 1;	
	}
	void dfs(int x,int f){
		int t=dp[x];
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			Max(dp[x],t+dp[y]);
		}
	}
	void solve(){
		for(int i=1;i<=m;i++)
			dp[Y[i]]+=W[i];
		dfs(1,0);
		printf("%d\n",max(dp[1],0));
	}
}p3;
struct Tree{
	#define Ls p<<1
	#define Rs p<<1|1
	struct tree{
		int L,R;
		int add,mx;
		void Add(int t){
			mx+=t;
			add+=t;
		}
	}T[M<<2];
	void Up(int p){
		T[p].mx=max(T[Ls].mx,T[Rs].mx);
	}
	void Down(int p){
		int &t=T[p].add;
		if(t==0)return;
		T[Ls].Add(t);
		T[Rs].Add(t);
		t=0;
	}
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		T[p].mx=T[p].add=0;
		if(L==R)return;
		int mid=L+R>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
	}
	void Update(int L,int R,int p,int v){
		if(T[p].L==L&&T[p].R==R){
			T[p].Add(v);
			return;
		}
		Down(p);
		int mid=T[Ls].R;
		if(R<=mid)Update(L,R,Ls,v);
		else if(L>mid)Update(L,R,Rs,v);
		else{
			Update(L,mid,Ls,v);
			Update(mid+1,R,Rs,v);
		} 
		Up(p);
	}
	int Query(int L,int R,int p){
		if(T[p].L==L&&T[p].R==R){
			return T[p].mx;
		}
		Down(p);
		int mid=T[Ls].R;
		if(R<=mid)return Query(L,R,Ls);
		if(L>mid)return Query(L,R,Rs);
		return max(Query(L,mid,Ls),Query(mid+1,R,Rs));
	}
}tree;
struct P4{//chain
	vector<int>ed[M];
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
		for(int i=Rt;;){
			mp[i]=++t;
			if(i!=Rt&&E[i].size()==1)break;
			int tmp=i;
			i=(E[i][0]==lst?E[i][1]:E[i][0]);
			lst=tmp;
		}
	}
	void solve(){
		Init();
		for(int i=1;i<=m;i++){
			X[i]=mp[X[i]],Y[i]=mp[Y[i]];
			if(X[i]<=Y[i])ed[Y[i]].push_back(i);
		}
		tree.Build(1,n,1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<ed[i].size();j++){
				int x=ed[i][j];
				tree.Update(1,X[x],1,W[x]);
			}
			Max(ans,tree.Query(1,i,1));
		}
		for(int i=1;i<=n;i++)ed[i].clear();
		tree.Build(1,n,1);
//		printf("%d\n",ans);
		for(int i=1;i<=m;i++)
			if(X[i]>=Y[i])ed[Y[i]].push_back(i);
		for(int i=n;i>=1;i--){
			for(int j=0;j<ed[i].size();j++){
				int x=ed[i][j];
				tree.Update(X[x],n,1,W[x]);
			}
			Max(ans,tree.Query(i,n,1));
		}
		printf("%d\n",ans);
	}
}p4;
int main(){
	Rd(n);Rd(m);
	int x,y;
	for(int i=1;i<n;i++){
		Rd(x);Rd(y);
		E[x].push_back(y);
		E[y].push_back(x);	
	}
	for(int i=1;i<=m;i++){
		Rd(X[i]);Rd(Y[i]);Rd(W[i]);
	}
	if(n<=1000||m<=1000)p1.solve();
	else if(p2.check())p2.solve();
	else if(p3.check())p3.solve();
	else if(p4.check())p4.solve();
	return 0;
}
