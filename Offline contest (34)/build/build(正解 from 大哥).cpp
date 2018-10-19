#include<bits/stdc++.h>
using namespace std;
#define M 4005
#define LL long long
int LA[M][M],RA[M][M];
int LB[M][M],RB[M][M];
int A[M],B[M],n;
LL dp[M][M];
void Min(LL &x,LL y){
	if(x>y)x=y;
}
void LA(int i,int j){
	return 
}
int main(){
//	freopen("build.in","r",stdin);
	memset(dp,126,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&A[i],&B[i]);
	for(int j=2;j<=n;j++)
		for(int i=j-1;i>=1;i--){
			LA[i][j]=LA[i+1][j]+B[i]*(j-i);
			LB[i][j]=LB[i+1][j]+A[i]*(j-i);
		}
	for(int j=1;j<n;j++)		
		for(int i=j+1;i<=n;i++){
			RA[i][j]=RA[i-1][j]+B[i]*(i-j);
			RB[i][j]=RB[i-1][j]+A[i]*(i-j);
		}
	dp[1][2]=B[1]+A[2];
	for(int i=3;i<=n;i++)
		dp[1][i]=dp[1][i-1]+A[i]*(i-1);
	dp[2][1]=A[1]+B[2];
	for(int i=3;i<=n;i++)
		dp[i][1]=dp[i-1][1]+B[i]*(i-1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n;j++){
			Min(dp[i][j+1],dp[i][j]+A[j+1]*(j+1-i));
			int mid=(i+1+j)>>1;
			Min(dp[j+1][j],dp[i][j]-LA[j][i]+LA[mid][i]+RA[mid+1][j+1]);
		}
		for(int j=1;j<i;j++){
			Min(dp[i+1][j],dp[i][j]+B[i+1]*(i+1-j));
			int mid=(i+1+j)>>1;
			Min(dp[i][i+1],dp[i][j]-LB[i][j]+LB[mid][j]+RB[mid+1][i+1]);
		}
	}
	LL res=1e16;
	for(int i=1;i<n;i++){
		Min(res,dp[i][n]);
		Min(res,dp[n][i]);
	}
	printf("%lld\n",res);
	return 0;
}
