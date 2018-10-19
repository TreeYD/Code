#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define LL long long
int A[M],n;
int pcnt[M];
LL psum[M];
bool mark[M];
int mo[M],dep[M];
int L[M],R[M],tot_sz;
int Line[M],T;
LL sum,cnt,tot_dis,ans;
vector<int>son[M],E[M];
int sz[M],big[M];
void Init(){
	for(int i=1;i<M;i++)mo[i]=-1;
	mo[1]=1;
	for(int i=2;i<M;i++){
		if(!mark[i]){
			for(int j=i;j<M;j+=i){
				mark[j]=1;
				if((j/i)%i==0)mo[j]=0;
				else mo[j]*=-1;
			}
		}
		if(mo[i]){
			for(int j=i;j<M;j+=i)
				son[j].push_back(i);
		}
	}
}
void dfs(int x,int f){
	sz[x]=1;big[x]=0;
	L[x]=++T;
	Line[T]=x;
	dep[x]=dep[f]+1;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		dfs(y,x);
		if(sz[y]>sz[big[x]])big[x]=y;
	}
	R[x]=T;
}
void Add_point(int x,int d){
	LL res1=tot_sz;
	LL res2=tot_dis;
	for(int i=0;i<son[A[x]].size();i++){
		int v=son[A[x]][i];
		res1-=mo[v]*pcnt[v];
		res2-=mo[v]*psum[v];
		pcnt[v]+=d;
		psum[v]+=d*dep[x];
	}
	cnt+=res1*d;
	sum+=(res2+res1*dep[x])*d;
	tot_sz+=d;
	tot_dis+=d*dep[x];
}
void Add_tree(int x,int d){
	for(int i=L[x];i<=R[x];i++)Add_point(Line[i],d);
}
void DSU(int x,int f){
	LL more1=0,more2=0;
	cnt=sum=0;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f||y==big[x])continue;
		DSU(y,x);
		more1+=cnt;more2+=sum;
		Add_tree(y,-1);
	}
	if(big[x])DSU(big[x],x);
	more1+=cnt;more2+=sum;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f||y==big[x])continue;
		Add_tree(y,1);
	}
	Add_point(x,1);
	ans+=sum-2*(cnt-more1)*dep[x]-more2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	Init();
	dfs(1,0);
	DSU(1,0);
	printf("%lld\n",ans);
	return 0;
}
