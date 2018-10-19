#include<bits/stdc++.h>
using namespace std;
#define M 40
#define LL long long
LL dp[M][M][M];
LL sum[M][M][M];
int n,h;
int main(){
	scanf("%d%d",&n,&h);
	if(n<h){
		puts("0");
		return 0;
	}
	int i,L,R,x;
	for(i=1;i<=n;i++){
		dp[i][i][1]=1;
		sum[i][i][1]=1;
	}
	for(i=2;i<=n;i++){
		for(L=1;L<=n;L++)
			for(R=L;R<=n;R++){
				LL &res=dp[L][R][i];
				if(R>=L+i-1){
					if(L<R){
						res+=dp[L+1][R][i-1];
						res+=dp[L][R-1][i-1];
					}
					for(x=L+1;x<R;x++){
						LL tmp=res;
						res+=sum[L][x-1][i-1]*dp[x+1][R][i-1];
						res+=sum[x+1][R][i-1]*dp[L][x-1][i-1];
						res-=dp[L][x-1][i-1]*dp[x+1][R][i-1];
					}
				}
				sum[L][R][i]=sum[L][R][i-1]+res;
			}
	}
	printf("%lld\n",sum[1][n][n]-sum[1][n][h-1]);
	return 0;
}
