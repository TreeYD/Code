#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define bit(x) (1<<x)
#define Inf 0x7f7f7f7f
LL dp[15][15][(1<<12)+5],res;
int mp[15][15],cnt[(1<<12)+5],n,m;
int nxt[(1<<12)+5];
void Min(LL &x,LL y){
	if(x>y)x=y;
}
void Solve(){
	int i,j,k,t,p,a;
	int e=(1<<n);
	memset(dp,Inf,sizeof(dp));
	res=Inf;
	for(i=0;i<n;i++){
		dp[i][n-1][0]=0;
		nxt[bit(i)]=i;
	}
	for(i=1;i<e;i++){
		cnt[i]=cnt[i&i-1]+1;
		nxt[i]=nxt[i&-i];
	}
	for(j=n-2;j>=0;j--){
		for(i=0;i<n;i++){//×¢Òâ±ß½ç 
			dp[i][j][0]=0;
			for(k=1;k<e;k++){//p¡Ê k	
				dp[i][j][k]=Inf;
				if(k&bit(i)||n-cnt[k]<j+1)continue;
				for(t=k;t;t=(t-1)&k){ 
					p=k^t;
					int tmp=t;
					for(a=nxt[tmp];tmp;a=nxt[(tmp^=bit(a))]){
						if(mp[i][a]&&(t&bit(a))&&dp[a][j+1][t^bit(a)]!=Inf&&dp[i][j][p]!=Inf){
							Min(dp[i][j][k],dp[a][j+1][t^bit(a)]+(j+1)*mp[i][a]+dp[i][j][p]);
						}
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		Min(res,dp[i][0][(e-1)^bit(i)]);
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
	Solve();
	printf("%lld\n",res);
	return 0;
}
