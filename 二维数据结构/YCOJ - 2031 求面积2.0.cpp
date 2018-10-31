#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define N 2005
#define LL long long
struct Node{
	int x,y,a,b;
	void Rd(){
		scanf("%d%d%d%d",&x,&b,&y,&a);
	}
}A[M];
int H[N],szh,W[N],szw,n;
vector<int>S[N],E[N];
struct Seg_Tree{
	#define Ls p<<1
	#define Rs p<<1|1
	struct Node{
		int L,R;
		int cnt,sum;
	}T[N<<2];
	void Up(int p){
		if(T[p].cnt)T[p].sum=W[T[p].R+1]-W[T[p].L];
		else if(T[p].L==T[p].R)T[p].sum=0;
		else T[p].sum=T[Ls].sum+T[Rs].sum;
	}
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		if(L==R)return;
		int mid=L+R>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
	}
	void Update(int L,int R,int p,int d){
		if(T[p].L==L&&T[p].R==R){
			T[p].cnt+=d;
			Up(p);
			return;
		}
		int mid=T[Ls].R;
		if(R<=mid)Update(L,R,Ls,d);
		else if(L>mid)Update(L,R,Rs,d);
		else{
			Update(L,mid,Ls,d);
			Update(mid+1,R,Rs,d);	
		}
		Up(p);
	}
}tree;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		A[i].Rd();
		H[++szh]=A[i].a;
		H[++szh]=A[i].b;
		W[++szw]=A[i].x;
		W[++szw]=A[i].y;
	}
	sort(H+1,H+1+szh);
	szh=unique(H+1,H+1+szh)-H-1;
	sort(W+1,W+1+szw);
	szw=unique(W+1,W+1+szw)-W-1;
	tree.Build(1,szw-1,1);
	for(int i=1;i<=n;i++){
		int x=lower_bound(H+1,H+1+szh,A[i].a)-H;
		S[x].push_back(i);
		int y=lower_bound(H+1,H+1+szh,A[i].b)-H;
		E[y].push_back(i);
		A[i].x=lower_bound(W+1,W+1+szw,A[i].x)-W;
		A[i].y=lower_bound(W+1,W+1+szw,A[i].y)-W;
	}
	LL ans=0;
	for(int i=1;i<szh;i++){
		for(int j=0;j<S[i].size();j++){
			int x=A[S[i][j]].x,y=A[S[i][j]].y;
			tree.Update(x,y-1,1,1);
		}
		for(int j=0;j<E[i].size();j++){
			int x=A[E[i][j]].x,y=A[E[i][j]].y;
			tree.Update(x,y-1,1,-1);
		}
		ans+=1LL*(H[i+1]-H[i])*tree.T[1].sum;
	}
	printf("%lld\n",ans);
	return 0;
}
