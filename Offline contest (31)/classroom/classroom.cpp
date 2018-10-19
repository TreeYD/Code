#include<bits/stdc++.h>
using namespace std;
#define M 2005
#define N 305
int dis[N][N];
int n,m,v,e,mp[N][N];
int c[2][M];
long double k[M],dp[M][M][2][2];//memory!!!
bool vis[M];
struct edge{
	int to,cost;
};
vector<edge>E[M];
struct node{
	int pos,len;
	bool operator<(const node &x)const{
		return len>x.len;
	}
};
priority_queue<node>Q;
void Dijk(int s){
	for(int i=1;i<=v;i++)dis[s][i]=1e9,vis[i]=0;
	dis[s][s]=0;
	Q.push((node){s,0});
	while(!Q.empty()){
		node now=Q.top();
		Q.pop();
		if(vis[now.pos])continue;
		int x=now.pos;
		vis[x]=1;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i].to,z=E[x][i].cost;
			if(dis[s][y]>dis[s][x]+z){
				dis[s][y]=dis[s][x]+z;
				Q.push((node){y,dis[s][y]});
			}
		}
	}
}
long double dfs(int x,int u,bool l,bool f){
	long double &res=dp[x][u][l][f];
	if(res!=2e9)return res;
	if(x==n+1)return res=0;
	res=2e9;
	if(f==1&&u<m){
		res=k[x]*(dis[c[l][x-1]][c[1][x]]+min(dfs(x+1,u+1,1,0),dfs(x+1,u+1,1,1)));
		res+=(1-k[x])*(dis[c[l][x-1]][c[0][x]]+min(dfs(x+1,u+1,0,0),dfs(x+1,u+1,0,1)));
	}else if(f==0){
		res=dis[c[l][x-1]][c[0][x]]+min(dfs(x+1,u,0,0),dfs(x+1,u,0,1));
	}
	return res;
}
int main(){
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&v,&e);
	int x,y,z;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[0][i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[1][i]);
	for(int i=1;i<=n;i++)
		scanf("%Lf",&k[i]);
	for(int i=1;i<=e;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(mp[x][y]==0||mp[x][y]>z)mp[x][y]=mp[y][x]=z;
	}
	for(int i=1;i<=v;i++)
		for(int j=1;j<=v;j++)
			if(mp[i][j]){
				E[i].push_back((edge){j,mp[i][j]});
				E[j].push_back((edge){i,mp[i][j]});
			}
	for(int i=1;i<=v;i++)Dijk(i);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=1;k++)
				dp[i][j][k][0]=dp[i][j][k][1]=2e9;
	printf("%.2Lf\n",min(dfs(1,0,0,1),dfs(1,0,0,0)));
	return 0;
}
