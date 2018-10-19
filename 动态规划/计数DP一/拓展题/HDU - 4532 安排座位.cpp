#include<bits/stdc++.h>
using namespace std;
#define M 505
#define N 55
const int P=1e9+7;
int A[N],C[M][M],n;
int  fac[M],dp[M][M];
void Add(int &x,int y){
	x+=y;
	if(x>=P)x-=P;
}
void Init(){
	int i,j;
	fac[0]=1;
	C[0][0]=1;
	for(i=1;i<=M-5;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++){
			Add(C[i][j],C[i-1][j-1]);
			Add(C[i][j],C[i-1][j]);
		}
		fac[i]=1LL*fac[i-1]*i%P;
	}
}
int main(){
	int T,cas=0;
	scanf("%d",&T);
	Init();
	while(T--){
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		int i,j;
		for(i=1;i<=n;i++)
			scanf("%d",&A[i]);
		dp[1][A[1]-1]=1;//start val set
		int sum=0;
		for(int i=1;i<n;i++){
			sum+=A[i];
			for(j=0;j<=sum;j++){
				for(int b=0;b<A[i+1];b++){
					int sz=A[i+1]-b;
					for(int a=min(j,sz);a>=0;a--)
						Add(dp[i+1][j-a+b],1LL*dp[i][j]*C[A[i+1]-1][sz-1]%P*C[j][a]%P*C[sum-j+1][sz-a]%P);
				}
			}
		}
		int ans=dp[n][0];
		for(i=1;i<=n;i++)
			ans=1LL*ans*fac[A[i]]%P;
		printf("Case %d: %d\n",++cas,ans);
	}
	return 0;
}
