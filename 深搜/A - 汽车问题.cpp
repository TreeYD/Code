#include<bits/stdc++.h>
using namespace std;
#define M 305
int A[M],n,ans,dfn;
int fi[M],se[M],mark[M];
void dfs(int x,int sz){
	if(sz>=ans)return;
	if(x==n+1){
		ans=sz;
		return;
	}
	if(mark[x]){
		dfs(x+1,sz);
		return;
	}
	for(int i=1;i<=sz;i++){
		if(se[fi[i]])continue;
		++dfn;int tmp=dfn;
		int T=A[x]-A[fi[i]],e=A[fi[i]];
		for(int j=fi[i]+1;j<=n;j++)
			if(!mark[j]&&A[j]-e==T)e=A[j];
		if(e+T<A[n])continue;
		e=A[fi[i]];
		for(int j=fi[i]+1;j<=n;j++)
			if(!mark[j]&&A[j]-e==T){
				mark[j]=dfn;
				e=A[j];
			}
		se[fi[i]]=1;
		dfs(x+1,sz);
		se[fi[i]]=0;
		e=A[fi[i]];
		for(int j=fi[i]+1;j<=n;j++)
			if(mark[j]==tmp&&A[j]-e==T){
				mark[j]=0;
				e=A[j];
			}
	}
	fi[++sz]=x;
	mark[x]=++dfn;
	dfs(x+1,sz);
	mark[x]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	ans=min((n+1)/2,17);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
