#include<bits/stdc++.h>
using namespace std;
#define M 2005
#define LL long long
struct edge{
	int to,cost;
};
vector<edge>E[M];
LL dp1[M],dp2[M];//1 回来 |2 不回来 
int n,K,sz[M],tsz[M],root;
void Min(LL &x,LL y){
	if(x>y)x=y;
}
void dfs(int x,int f){
	dp2[x]=1e16;
	dp1[x]=0;
	if(x!=root&&E[x].size()==1){
		if(tsz[x])dp2[x]=0;
		return;
	}
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to,z=E[x][i].cost;
		if(y==f)continue;
		dfs(y,x);
		tsz[x]+=tsz[y];
		if(tsz[y])dp1[x]+=dp1[y]+2*z;
	}
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to,z=E[x][i].cost;
		if(y==f)continue;
		if(tsz[y])Min(dp2[x],dp1[x]-dp1[y]-2*z+dp2[y]+z);
	}
}
int main(){
//	freopen("save.in","r",stdin);
//	freopen("save.out","w",stdout);
	scanf("%d%d",&n,&K);
	int x,y,z,i,j;
	for(i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		E[x].push_back((edge){y,z});
		E[y].push_back((edge){x,z});
	}
	for(i=1;i<=K;i++){
		scanf("%d",&x);
		sz[x]++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)tsz[j]=sz[j];
		root=i;dfs(i,0);
		printf("%lld\n",dp2[i]);
	}
	return 0;
}
