#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define LL long long
struct node{
	int x,y;
	bool operator<(const node &a)const{
		return x<a.x;
	}
}A[M];
int Q[M];
struct line{
	int k,id;
	bool operator<(const line &x)const{
		return k>x.k;
	}
}Line[M];
bool check(int a,int b,int c){
	return 1LL*(A[c].y-A[b].y)*(A[b].x-A[a].x)>=1LL*(A[b].y-A[a].y)*(A[c].x-A[b].x);
}
int n,m;
LL Ans[M];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&A[i].x,&A[i].y);
		A[i].x=-A[i].x;
	}
	sort(A+1,A+1+n);
	int L=1,R=0;
	for(int i=1;i<=n;i++){
		while(L<R&&check(Q[R-1],Q[R],i))R--;
		Q[++R]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&Line[i].k);
		Line[i].id=i;
	}
	sort(Line+1,Line+1+m);
	for(int i=1;i<=m;i++){
		int k=Line[i].k;
		while(L<R&&(A[Q[L]].y-A[Q[L+1]].y)<=1LL*k*(A[Q[L]].x-A[Q[L+1]].x))L++;
		Ans[Line[i].id]=A[Q[L]].y-1LL*k*A[Q[L]].x;
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",Ans[i]);
	return 0;
}
