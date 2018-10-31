#include<bits/stdc++.h>
using namespace std;
#define M 500005
#define LL long long
const LL Inf=1e16;
template<class T>void Max(T &x,T y){
	if(x<y)x=y;
}
int n,U,D,S,MaxS;
struct Node{
	int t,l,m;
	void read(){
		scanf("%d%d%d",&t,&l,&m);
		Max(MaxS,l);
	}
}A[M];
bool cmp(Node a,Node b){
	if(a.t!=b.t)return a.t<b.t;
	return a.l<b.l;
}
struct Tree{
	#define Ls p<<1
	#define Rs p<<1|1
	struct node{
		int L,R;
		LL mxD,mxU;
	}T[M<<2];
	void Up(int p){
		T[p].mxU=max(T[Ls].mxU,T[Rs].mxU);
		T[p].mxD=max(T[Ls].mxD,T[Rs].mxD);
	}
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		if(L==R){
			if(L==S){
				T[p].mxD=D*S;
				T[p].mxU=-U*S;
			}else T[p].mxD=T[p].mxU=-Inf;
			return;
		}
		int mid=L+R>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
		Up(p);
	}
	LL QueryD(int L,int R,int p){
		if(T[p].L==L&&T[p].R==R){
			return T[p].mxD;
		}
		int mid=T[Ls].R;
		if(R<=mid)return QueryD(L,R,Ls);
		if(L>mid)return QueryD(L,R,Rs);
		return max(QueryD(L,mid,Ls),QueryD(mid+1,R,Rs));
	}
	LL QueryU(int L,int R,int p){
		if(T[p].L==L&&T[p].R==R){
			return T[p].mxU;
		}
		int mid=T[Ls].R;
		if(R<=mid)return QueryU(L,R,Ls);
		if(L>mid)return QueryU(L,R,Rs);
		return max(QueryU(L,mid,Ls),QueryU(mid+1,R,Rs));
	}
	void Update(int x,int p,LL vu,LL vd){
		if(T[p].L==T[p].R){
			Max(T[p].mxU,vu);
			Max(T[p].mxD,vd);
			return;
		}
		int mid=T[Ls].R;
		if(x<=mid)Update(x,Ls,vu,vd);
		else Update(x,Rs,vu,vd);
		Up(p);
	}
}tree;
LL solve(){
	tree.Build(0,MaxS,1);
	LL ans;
	for(int i=1;i<=n+1;i++){
		ans=-Inf;
		Max(ans,A[i].m-D*A[i].l+tree.QueryD(1,A[i].l,1));
		Max(ans,A[i].m+U*A[i].l+tree.QueryU(A[i].l,MaxS,1));
		tree.Update(A[i].l,1,ans-U*A[i].l,ans+A[i].l*D);
	}
	return ans;
}
int main(){
//	freopen("salesman2.in","r",stdin);
	scanf("%d%d%d%d",&n,&U,&D,&S);
	MaxS=S;
	LL ans=0;
	for(int i=1;i<=n;i++)
		A[i].read();
	A[n+1].l=A[0].l=S;
	sort(A+1,A+1+n,cmp);
	ans=solve();
	printf("%lld\n",ans);
	return 0;
}
