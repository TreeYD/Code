#include<bits/stdc++.h>
using namespace std;
#define M 100005
struct edge{
	int to;
	unsigned int cost;
};
vector<edge>E[M];
int n,e; 
struct P30{
	unsigned int dis[M];
	int Q[M<<1];
	bool vis[M];
	void BFS(){
		int L=1,R=0;
		for(int i=1;i<=n;i++)dis[i]=-1;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				dis[i]=0;
				Q[++R]=i;
				vis[i]=1;
			}
			while(L<=R){
				int x=Q[L++];
				for(int i=0;i<E[x].size();i++){
					int y=E[x][i].to,z=E[x][i].cost;
					unsigned int v=z^dis[x];
					if(dis[y]!=-1&&v!=dis[y]){
						puts("-1");return;
					}
					dis[y]=v;
					if(!vis[y]){
						Q[++R]=y;
						vis[y]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			printf("%u ",dis[i]);
		return;
	}
	void solve(){
		BFS();
	}
}p30;
int main(){//name memory long long * mod - ÇĞ·ÖÅĞ¶Ï ¼«Öµ 
//	printf("%.2lf\n",(sizeof(p30))/1024.0/1024);
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&e);
	int op,x,y;
	unsigned int z;
	bool flag=1;
	for(int i=1;i<=e;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==2){
			scanf("%u",&z);
			E[x].push_back((edge){y,z});
			E[y].push_back((edge){x,z});
		}else flag=0;
	}
	if(flag)p30.solve();
	else puts("-1");
	return 0;
}
