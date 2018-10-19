#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define M 205
const int P=1e9+7;
int dp[2][M][M][2],n,m,K;
char A[N],B[M];
void Add(int &x,int y){
	x+=y;if(x>=P)x-=P;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s%s",A+1,B+1);
	dp[0][0][0][0]=1;
	int i,j,k; 
	bool cur=0;
	for(i=1;i<=n;i++){
		cur=!cur;
		for(j=0;j<=m;j++)
			for(k=(j==0?0:1);k<=min(K,j);k++){
				dp[cur][j][k][0]=dp[cur][j][k][1]=0;
				Add(dp[cur][j][k][0],dp[!cur][j][k][1]);
				Add(dp[cur][j][k][0],dp[!cur][j][k][0]);
				if(A[i]==B[j]){
					Add(dp[cur][j][k][1],dp[!cur][j-1][k-1][0]);
					Add(dp[cur][j][k][1],dp[!cur][j-1][k-1][1]);
					if(A[i-1]==B[j-1])Add(dp[cur][j][k][1],dp[!cur][j-1][k][1]);
				}
			}
	}
	printf("%d\n",(dp[cur][m][K][1]+dp[cur][m][K][0])%P);
	return 0;
}
