#include<bits/stdc++.h>
using namespace std;
int dp[5005],n,m;
int sum[5005];
int main(){
	scanf("%d%d",&n,&m);
	dp[0]=0; 
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		sum[i]=sum[i-1]+x;
		dp[i]=0x7f7f7f7f;
		for(int j=0;j<i;j++)	
			dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m);
		printf("%d %d\n",i,dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}
