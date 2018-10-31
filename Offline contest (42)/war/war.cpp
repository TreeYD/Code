#include<bits/stdc++.h>
using namespace std;
#define M 5005
struct Edge{
	int to,cost;
};
vector<Edge>E[M];
struct Node{
	int x,y,d;
	bool operator<(const Node &x)const{
		return d>x.d;
	}
};
priority_queue<Node>Q;
struct node{
	int len,pos;
	bool operator<(const node &x)const{
		return len>x.len;
	}
};
priority_queue<node>Q1;
int dis[M][M];
bool vis[M],in[M][M];
int K[M];
int n,m,q,Kcnt;
void Dijk(int s){
	for(int i=1;i<=n;i++){
		dis[s][i]=2e9;
		vis[i]=0;
	}
	dis[s][s]=0;
	Q1.push((node){0,s});
	while(!Q1.empty()){
		int x=Q1.top().pos;
		Q1.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i].to,z=E[x][i].cost;
			if(dis[s][y]>dis[s][x]+z){
				dis[s][y]=dis[s][x]+z;
				Q1.push((node){dis[s][y],y});
			}
		}
	}
}
struct P40{
	void Init(){
		for(int i=1;i<=n;i++)Dijk(i);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(K[i]!=K[j]){
					Q.push((Node){i,j,dis[i][j]});
					in[i][j]=1;
				}
			}
	}
	void solve(){
		int x,k;
		Init();
		for(int i=1;i<=q;i++){
			scanf("%d %d",&x,&k);
			K[x]=k;
			for(int j=1;j<=n;j++)
				if(K[x]!=K[j]){
					if(!in[x][j]){
						in[x][j]=1;
						Q.push((Node){x,j,dis[x][j]});
					}
				}
			Node now;
			while(1){
				now=Q.top();Q.pop();
				in[now.x][now.y]=0;
				if(K[now.x]!=K[now.y])break;
			}
			printf("%d\n",now.d);
		}
	}
	
}p40;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ³õÖµ 
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&Kcnt,&q);
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		E[x].push_back((Edge){y,z});
		E[y].push_back((Edge){x,z});
	}
	for(int i=1;i<=Kcnt;i++)
		scanf("%d",&K[i]);
	p40.solve();
	return 0;
}
