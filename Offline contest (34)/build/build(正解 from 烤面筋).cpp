#include<bits/stdc++.h>
using namespace std;
#define M 4005
#define Inf 0x7f7f7f7f7f
#define LL long long
LL sum[2][M],val[2][M];
LL dp[2][M],n;
void Min(LL &x,LL y){
	if(x>y)x=y;
}
LL L(int s,int e,int f){
	return (val[f][e]-val[f][s-1])-(s-1)*(sum[f][e]-sum[f][s-1]);
}
LL R(int s,int e,int f){
	return (sum[f][e]-sum[f][s-1])*(e+1)-(val[f][e]-val[f][s-1]);
}
int main(){
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++){
			scanf("%d",&x);
			sum[j][i]=sum[j][i-1]+x;
			val[j][i]=val[j][i-1]+x*i;
		}
	for(int i=1;i<n;i++)
		for(int j=0;j<=1;j++){
			dp[j][i]=R(1,i,!j);
			for(int k=1;k<i;k++){
				int mid=(k+1+i)>>1;
				Min(dp[j][i],dp[!j][k]+L(k+1,mid,!j)+R(mid+1,i,!j));
			}
		}
	for(int i=0;i<=1;i++){
		dp[i][n]=Inf;
		for(int j=1;j<n;j++)
			Min(dp[i][n],dp[!i][j]+L(j+1,n,!i));
	}
	printf("%lld\n",min(dp[0][n],dp[1][n]));
	return 0;
}
