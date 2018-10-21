#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define N 200005
vector<int>T[N];
int Q[N],far[N],dp[N];
int cnt[N],hav[N];
int lst[N],n,m;
int A[M],B[M];
struct P30{
	int cnt[25],sum[25],ans;
	void dfs(int x){
		if(x==n+1){
			for(int i=1;i<=n;i++)
				sum[i]=sum[i-1]+cnt[i];
			for(int i=1;i<=m;i++){
				if(sum[B[i]]-sum[A[i]-1]!=1)return;
			}
			ans=max(ans,sum[n]);
			return;
		}
		cnt[x]=1;
		dfs(x+1);
		cnt[x]=0;
		dfs(x+1);
	}
	void solve(){
		ans=-1;
		dfs(1);
		if(ans==0)ans=-1;
		printf("%d\n",ans);
	}	
}p30;
struct Tree{
	#define Ls p<<1
	#define Rs p<<1|1
	struct node{
		int L,R;
		int mx;
	}T[N<<2];
	void Up(int p){
		T[p].mx=max(T[Ls].mx,T[Rs].mx);
	}
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		if(L==R){
			if(L==1)T[p].mx=1;
			else if(L==0)T[p].mx=0;
			else T[p].mx=-1e9;
			return;
		}
		int mid=(L+R)>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
		Up(p);
	}
	void Update(int x,int v,int p){
		if(T[p].L==T[p].R){
			T[p].mx=v;
			return;
		}
		int mid=T[Ls].R;
		if(x<=mid)Update(x,v,Ls);
		else Update(x,v,Rs);
		Up(p);
	}
	int Query(int L,int R,int p){
		if(T[p].L==L&&T[p].R==R){
			return T[p].mx;
		}
		int mid=T[Ls].R;
		if(R<=mid)return Query(L,R,Ls);
		if(L>mid)return Query(L,R,Rs);
		return max(Query(L,mid,Ls),Query(mid+1,R,Rs));
	}
}tree;
struct P100{
	void solve(){
		int mx=0,L=0,R=0;
		for(int i=1;i<=m;i++){
			T[B[i]].push_back(A[i]);
			hav[A[i]]++;
		}
		memset(dp,-63,sizeof(dp));
		dp[0]=0;
		tree.Build(0,n,1);
		for(int i=1;i<=n+1;i++){
			while(L<=R&&!cnt[Q[L]])L++;
			if(hav[i])cnt[i]=hav[i];
			Q[++R]=i;
			lst[i]=Q[L];
			far[i]=mx;
			for(int j=0;j<T[i].size();j++){
				cnt[T[i][j]]--;
				mx=max(mx,T[i][j]);
			}
		}
		lst[n+1]=n+1;
		for(int i=2;i<=n+1;i++){
			if(far[i]<lst[i])
				dp[i]=tree.Query(far[i],lst[i]-1,1)+1;
			tree.Update(i,dp[i],1);
		}
		int ans=dp[n+1]-1;
		if(ans<=0)puts("-1");
		else printf("%d\n",ans);
	}
}p100;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ 
//	freopen("photo.in","r",stdin);
//	freopen("photo.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&A[i],&B[i]);
	if(n<=20)p30.solve();
	else p100.solve();
	return 0;
}
