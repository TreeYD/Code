#include<bits/stdc++.h>
using namespace std;
#define M 100005
int F[M],L[M],R[M],m;
int A[M],n,q;
bool B[M];
struct Tree{
	#define Ls p<<1
	#define Rs p<<1|1
	struct Node{
		int L,R,len;
		int c0,c1;
		int op;//-1 no | 0 -> 0 | 1 -> 1
		void Add(int t){
			if(t==0)c0=len,c1=0;
			else c1=len,c0=0;
			op=t;
		}
	}T[M<<2];
	void Up(int p){
		T[p].c0=T[Ls].c0+T[Rs].c0;
		T[p].c1=T[Ls].c1+T[Rs].c1;
	}
	void Down(int p){
		int &t=T[p].op;
		if(t==-1)return;
		T[Ls].Add(t);
		T[Rs].Add(t);
		t=-1;
	}
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		T[p].op=-1;
		T[p].len=R-L+1;
		if(L==R){
			T[p].c0=(B[L]==0);
			T[p].c1=(B[L]==1);
			return;
		}
		int mid=L+R>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
		Up(p);
	}
	void Update(int L,int R,int p,int v){
		if(L>R)return;
		if(T[p].L==L&&T[p].R==R){
			T[p].Add(v);
			return;
		}
		Down(p);
		int mid=T[Ls].R;
		if(R<=mid)Update(L,R,Ls,v);
		else if(L>mid)Update(L,R,Rs,v);
		else {
			Update(L,mid,Ls,v);
			Update(mid+1,R,Rs,v);
		}
		Up(p);
	}
	int Query(int L,int R,int p){
		if(T[p].L==L&&T[p].R==R){
			return T[p].c0;
		}
		Down(p);
		int mid=T[Ls].R;
		if(R<=mid)return Query(L,R,Ls);
		if(L>mid)return Query(L,R,Rs);
		return Query(L,mid,Ls)+Query(mid+1,R,Rs);
	}
}tree;
bool Check(int x){
	for(int i=1;i<=n;i++)
		B[i]=(A[i]>=x);
	tree.Build(1,n,1);
	for(int i=1;i<=m;i++){
		if(F[i]){
			int c0=tree.Query(L[i],R[i],1);
			int c1=R[i]-L[i]+1-c0;
			tree.Update(L[i],L[i]+c1-1,1,1);
			tree.Update(L[i]+c1,R[i],1,0);
		}else{
			int c0=tree.Query(L[i],R[i],1);
			tree.Update(L[i],L[i]+c0-1,1,0);
			tree.Update(L[i]+c0,R[i],1,1);
		}
	}
	return tree.Query(q,q,1)==0;
}
void Find(){
	int L=1,R=n,ans;
	while(L<=R){
		int mid=L+R>>1;
		if(Check(mid)){
			ans=mid;
			L=mid+1;
		}else R=mid-1;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&F[i],&L[i],&R[i]);
	scanf("%d",&q);
	Find();
	return 0;
}
