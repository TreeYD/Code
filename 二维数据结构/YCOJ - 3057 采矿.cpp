#include<bits/stdc++.h>
using namespace std;
#define M 100005
const int MaxL=100000;
vector<int>V[M];
int n,S,W;
struct Seg_Tree{
	#define Ls p<<1
	#define Rs p<<1|1
	struct node{
		int L,R;
		int mx,add;
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
		if(L>mid)Update(L,R,Rs,v);
		else if(R<=mid)Update(L,R,Ls,v);
		else {
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
int main(){
	scanf("%d%d%d",&n,&S,&W);
	tree.Build(0,MaxL,1);
	int x,y,MaxR=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		V[y].push_back(x);
		MaxR=max(MaxR,y);
	}
	int ans=0;
	for(int i=0;i<=MaxR;i++){
		for(int j=0;j<V[i].size();j++){
			int x=V[i][j];
			tree.Update(max(0,x-S),x,1,1);
		}
		if(i>W){
			for(int j=0;j<V[i-W-1].size();j++){
				int x=V[i-W-1][j];
				tree.Update(max(0,x-S),x,1,-1);
			}	
		}
		if(i>=W-1){
			ans=max(ans,tree.Query(0,MaxL-S,1));	
		}
	}
	printf("%d\n",ans);
	return 0;
}
