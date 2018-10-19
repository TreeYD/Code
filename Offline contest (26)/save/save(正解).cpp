#include<bits/stdc++.h>
using namespace std;
#define M 500005
#define LL long long
#define calc(x) (-down1[x]-len[x]+down2[x])
struct edge{
	int to,cost;
};
vector<edge>E[M];
LL down1[M],down2[M];
LL up1[M],up2[M],all[M];//1 back 2 gone 
int fi[M],se[M],sz[M];
int n,K,len[M];
void dfs(int x,int f){
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to,z=E[x][i].cost;
		if(y==f)continue;
		dfs(y,x);
		sz[x]+=sz[y];
		len[y]=z;
		if(sz[y]){
			down1[x]+=down1[y]+2*z;
			LL tmp=calc(y);
			if(fi[x]==0||tmp<calc(fi[x])){
				down2[x]=tmp;
				se[x]=fi[x];
				fi[x]=y;
			}else if(se[x]==0||tmp<calc(se[x]))se[x]=y;
		}
	}
	down2[x]+=down1[x];
}
void redfs(int x,int f){
	all[x]=min(down2[x]+up1[x],down1[x]+up2[x]);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i].to,z=E[x][i].cost;
		if(y==f)continue;
		int t=(fi[x]==y)?se[x]:fi[x];
		if(K-sz[y]){
			up1[y]=2*z+(down1[x]-(sz[y]>0)*(down1[y]+2*z))+up1[x];
			up2[y]=min(z+up2[x]+down1[x]-(sz[y]>0)*(2*z+down1[y]),z+up1[x]+down1[x]-(sz[y]>0)*(2*z+down1[y])+(sz[t]>0)*(down2[t]-len[t]-down1[t]));
		}
		redfs(y,x);
	}
}
int main(){
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
	dfs(1,0);redfs(1,0);
	for(i=1;i<=n;i++)
		printf("%lld\n",all[i]);
	return 0;
}
