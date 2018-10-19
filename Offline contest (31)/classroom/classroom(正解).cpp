#include<bits/stdc++.h>
using namespace std;
#define N 305
#define M 2005
int dis[N][N];
int C[M],D[M];
int n,m,v,e;
double dp[M][M][2],K[M];
template<class T>void Min(T &x,T y){
    if(x>y)x=y;
};
void Init(){
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=v;i++){
		dis[0][i]=0;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=1;k++)
				dp[i][j][k]=2e9;
}
void Floyd(){
	for(int k=1;k<=v;k++)
		for(int i=1;i<=v;i++)
			for(int j=1;j<=v;j++)
				Min(dis[i][j],dis[i][k]+dis[k][j]);
}
void Solve(){
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0][0]=dp[i-1][0][0]+dis[C[i-1]][C[i]];
		for(int j=1;j<=min(i,m);j++){
			dp[i][j][0]=min(dp[i-1][j][1]+
				(1-K[i-1])*dis[C[i-1]][C[i]]+
				K[i-1]*dis[D[i-1]][C[i]],
				dp[i-1][j][0]+
				dis[C[i-1]][C[i]]
			);	
			dp[i][j][1]=min(
				dp[i-1][j-1][1]+
				K[i]*(1-K[i-1])*dis[C[i-1]][D[i]]+
				K[i]*(K[i-1])*dis[D[i-1]][D[i]]+
				(1-K[i])*K[i-1]*dis[D[i-1]][C[i]]+
				(1-K[i])*(1-K[i-1])*dis[C[i-1]][C[i]],
				dp[i-1][j-1][0]+K[i]*dis[C[i-1]][D[i]]+
				(1-K[i])*dis[C[i-1]][C[i]]
			);
		}
	}
	double ans=2e9;
	for(int i=min(n,m);i>=0;i--)
		Min(ans,min(dp[n][i][0],dp[n][i][1]));
	printf("%.2lf\n",ans);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i=1;i<=n;i++)
		scanf("%d",&C[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&D[i]);
	for(int i=1;i<=n;i++)
		scanf("%lf",&K[i]);
	int x,y,z;
	Init();
	for(int i=1;i<=e;i++){
		scanf("%d%d%d",&x,&y,&z);
		Min(dis[x][y],z);
		Min(dis[y][x],z);
	}
	Floyd();
	Solve();
	return 0;
}
