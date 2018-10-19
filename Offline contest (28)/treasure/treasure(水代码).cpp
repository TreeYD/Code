#include<bits/stdc++.h>
using namespace std;
#define M 15
#define bit(x) (1<<x)
#define Inf 0x7f7f7f7f7f7f
long long dp[(1<<12)+5];
int mp[M][M],dis[M],n,m;
void dfs(int x){
	for(int i=0;i<n;i++)
		if(x&bit(i)){
			for(int j=0;j<n;j++){
				if(mp[i][j]&&!(x&bit(j))){
					int t=x|bit(j);
					if(dp[t]>dp[x]+(dis[i]+1)*mp[i][j]){
						dp[t]=dp[x]+(dis[i]+1)*mp[i][j];
						int tmp=dis[j];
						dis[j]=dis[i]+1;
						dfs(x|bit(j));
						dis[j]=tmp;
					}
				}
			}
		}
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y,z,i;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		x--,y--;
		if(!mp[x][y]||mp[x][y]>z)
			mp[x][y]=mp[y][x]=z;
	}
	long long ans=9e18;
	for(i=0;i<n;i++){
		memset(dp,Inf,sizeof(dp));
		dp[bit(i)]=0;
		dfs(bit(i));
		ans=min(ans,dp[(1<<n)-1]);
	}
	printf("%lld\n",ans);
}
