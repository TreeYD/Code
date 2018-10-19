#include<bits/stdc++.h>
using namespace std;
#define M 100005
int A[M<<2],n,m;
int q,u,v,t;
struct P35{
	void solve(){
		for(int i=1;i<=m;i++){
			int mx=0,mxid=0;
			for(int j=1;j<=n+i-1;j++)
				if(A[j]>mx){
					mx=A[j];
					mxid=j;
				}
			A[mxid]=1LL*mx*u/v;
			A[n+i]=mx-A[mxid];
			for(int j=1;j<=n+i-1;j++)
				if(j!=mxid)A[j]+=q;
			if(i%t==0)printf("%d ",mx);
		}
		puts("");
		sort(A+1,A+1+n+m);
		int cnt=0;
		for(int i=n+m;i>=1;i--){
			cnt++;
			if(cnt%t==0)printf("%d ",A[i]);
		}
		puts("");
	}
}p35;
struct P30{
	#define Mn 400005
	#define Ls p<<1
	#define Rs p<<1|1
	struct node{
		int L,R;
		int mx;
	}T[Mn<<2];
	int tot;
	void Up(int p){
		T[p].mx=T[Ls].mx;
		if(A[T[p].mx]<A[T[Rs].mx])T[p].mx=T[Rs].mx;
	}
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		if(L==R){
			T[p].mx=L;
			return;
		}
		int mid=(L+R)>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
		Up(p);
	}
	void Update(int p,int x,int v){
		if(T[p].L==T[p].R){
			A[x]=v;
			return;
		}
		int mid=T[Ls].R;
		if(x<=mid)Update(Ls,x,v);
		else Update(Rs,x,v);
		Up(p);
	}
	int Query(int L,int R,int p){
		if(T[p].L==L&&T[p].R==R){
			return T[p].mx;
		}
		int mid=T[Ls].R;
		int ans;
		if(R<=mid)ans=Query(L,R,Ls);
		else if(L>mid)ans=Query(L,R,Rs);
		else {
			ans=Query(L,mid,Ls);
			int tmp=Query(mid+1,R,Rs);
			if(A[ans]<A[tmp])ans=tmp;
		}
		return ans;
	}
	void solve(){
		int nm=n+m;
		Build(1,nm,1);
		for(int i=1;i<=m;i++){
			int mx=Query(1,n+i-1,1),ans=A[mx]+tot;
			Update(1,mx,1LL*ans*u/v-tot-q);
			Update(1,n+i,ans-1LL*ans*u/v-tot-q);
			if(i%t==0)printf("%d ",ans);
			tot+=q;
		}
		puts("");
		sort(A+1,A+1+n+m);
		int cnt=0;
		for(int i=n+m;i>=1;i--){
			cnt++;
			if(cnt%t==0)printf("%d ",A[i]+tot);
		}
		puts("");
	}
}p30;
int main(){//name long long memory mod -
//	freopen("earthworm.in","r",stdin);
//	freopen("earthworm.out","w",stdout);
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	if(n<=1000&&m<=1000)p35.solve();
	else if(m<=300005)p30.solve();
	return 0;
}
