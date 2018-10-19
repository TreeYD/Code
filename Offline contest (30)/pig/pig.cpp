#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define M 1005
#define inf 0x7f7f7f7f7f
int cnt[M],n,m,T;
LL dis[M];
int Q[M];
bool vis[M];
struct edge{int to,cost;};
vector<edge>E[M];
bool Spfa(int s,int t){
	int L=0,R=0,i;
	for(i=1;i<=n;i++)dis[i]=inf,cnt[i]=0;
	dis[s]=0;vis[s]=1;
	Q[R++]=s;
	while(L!=R){
		int x=Q[L++];
		if(L>=1000)L=0;
		vis[x]=0;cnt[x]++;
		if(cnt[x]==n)dis[x]=-inf;
		if(cnt[x]>n)continue;
		for(i=0;i<E[x].size();i++){
			int y=E[x][i].to,z=E[x][i].cost;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				if(!vis[y]){
					Q[R++]=y;
					if(R>=1000)R=0;
					vis[y]=1;
				}
			}
		}
	}
	return T+dis[t]<=0;
}
int main(){//name long long memory mod
//	freopen("pig.in","r",stdin);
//	freopen("pig.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d%d",&n,&m,&T);
		int x,y,z,i;
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			E[x].push_back((edge){y,z});
		}
		int a,b;
		scanf("%d%d",&a,&b);
		if(Spfa(a,b))puts("yes");
		else if(Spfa(b,a))puts("yes");
		else puts("no");
		for(i=1;i<=n;i++)E[i].clear();
	}
	return 0;
}
