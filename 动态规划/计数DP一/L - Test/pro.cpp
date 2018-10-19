#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define bit(x) (1LL<<(x-1))
LL C[105][105],m;
LL dp[105][105];
int k;
LL calc(LL n){
	LL res=0;
//	puts("------------");
//	printf("calc:%lld\n",n);
	int i,j,cnt=0;
//	for(i=1;i<=64;i++){
////		printf(" %lld\n",bit(i));
//		if(n&bit(i)){
//			cnt++;
//			printf("1");
//		}else printf("0");
//	}
//	puts("");
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=1;i<=64;i++){
		dp[i][0]=1;
		for(j=1;j<=min(i,k);j++){
//			dp[i][j]+=dp[i-1][j];
			if(n&bit(i)){
				dp[i][j]+=dp[i-1][j-1];
				if(i-1>=j)dp[i][j]+=C[i-1][j];
			}else dp[i][j]+=dp[i-1][j];
		}
	}
//	if(cnt==k)res++;
//	printf("%d\n",dp[64][k]);
//	printf("%lld %lld\n",n,dp[64][k]);
	return dp[64][k];
}
void Find(){
	LL L=0,R=1e18,ans=-1;
	while(L<=R){
		LL mid=L+R>>1;
		if(calc(2*mid)-calc(mid)>=m){
			ans=mid;
			R=mid-1;
		}else L=mid+1;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("L.in","r",stdin);
	freopen("L.out","w",stdout);
	scanf("%lld%d",&m,&k);
	int i,j;
	for(i=0;i<=100;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	Find();
//	printf("%lld\n",calc(5009));
//	printf("%lld\n",calc(10018));
	return 0;
}
