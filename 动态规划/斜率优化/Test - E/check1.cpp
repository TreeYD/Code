#include<bits/stdc++.h>
using namespace std;
#define M 505
#define LL long long
#define Inf 0x7f7f7f
template<class T>void Min(T &x,T y){if(x>y)x=y;}
LL dp[M][M][11];
LL sum[M],cnt[M];
int A[M],n,K;
LL L(int s,int e){
	if(s>e)return 0;
	return (sum[e]-sum[s-1])-(s-1)*(cnt[e]-cnt[s-1]);
}
int main(){//name memory long long * mod -
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
//	freopen("barn.in","r",stdin);
//	freopen("barn.out","w",stdout);
	freopen("data.in","r",stdin);
	freopen("check.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		sum[i]=sum[i-1]+i*A[i];
		cnt[i]=cnt[i-1]+A[i];
	}
	memset(dp,Inf,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][i][1]=0;
	for(int i=2;i<=n;i++)
		for(int fi=1;fi<i;fi++)
			for(int p=2;p<=K&&p<=i-fi+1;p++){
				for(int j=max(1,fi+p-2);j<i;j++){
					Min(dp[fi][i][p],dp[fi][j][p-1]+L(j+1,i-1));
				}
			}
//	for(int p=1;p<=K;p++)%d %lld\n",p,i,j,dp[i][j][p]);
	LL ans=1e16;
	for(int lst=1;lst<=n;lst++)
		for(int fi=1;fi<=lst;fi++){
			LL tmp=0;
			tmp=L(lst+1,n)+cnt[fi-1]*(n-lst)+L(1,fi-1);
			Min(ans,dp[fi][lst][K]+tmp);
		}
	printf("%lld\n",ans);
	return 0;
}
