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
//int R(int s,int e){
//	if(s>e)return 0;
//	return (cnt[e]-cnt[s-1])*(e+1)-(sum[e]-sum[s-1]);
//}
int main(){//name memory long long * mod -
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
	freopen("barn.in","r",stdin);
	freopen("barn.out","w",stdout);
//	freopen("data.in","r",stdin);
//	freopen("pro.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		sum[i]=sum[i-1]+i*A[i];
		cnt[i]=cnt[i-1]+A[i];
	}
//	printf("%d %d\n",L(2,3),R(2,3));
	memset(dp,Inf,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][i][1]=0;
//	printf("%d\n",L(2,13));
	for(int i=2;i<=n;i++)
		for(int fi=1;fi<i;fi++)
			for(int p=2;p<=K&&p<=i-fi+1;p++)
				for(int j=max(1,fi+p-2);j<i;j++){
//					int mid=i+j>>1;
//					if(fi==1&&i==14&&p==2||fi==1&&i==15&&p==14){
//						printf("%d %d %d %lld\n->",fi,j,p-1,dp[fi][j][p-1]);
//						printf("%d\n",L(j+1,i-1));
//						printf("%d %d %d %lld\n",fi,i,p,dp[fi][i][p]);
//					}
					Min(dp[fi][i][p],dp[fi][j][p-1]+L(j+1,i-1));
//					printf("%d\n",dp[1][14][2]);
//					printf("%d\n",dp[1][15][14]);
//					if(dp[1][14][2]==0){
//////						
//////printf("j:%d\n",j);
////						printf("%d %d %d %d\n",fi,i,p,dp[fi][i][p]);
//						return 0;
//					}
				}
	LL ans=1e16;
	for(int lst=1;lst<=n;lst++)
		for(int fi=1;fi<=lst;fi++){
//			int mid=((fi-1+n-lst)>>1)+lst;
			LL tmp=0;
//			if(mid<=n){
//				tmp=L(lst+1,mid);
//				tmp+=R(mid+1,n)+(cnt[n]-cnt[mid])*(fi-1)+R(1,fi-1);
//			}else{
//				mid-=n;
//				tmp=R(mid+1,fi-1);
//				tmp+=R(1,mid)+cnt[mid]*(n-lst)+L(lst+1,n);
//			}
			tmp=L(lst+1,n)+cnt[fi-1]*(n-lst)+L(1,fi-1);
			Min(ans,dp[fi][lst][K]+tmp);
//			if(dp[fi][lst][K]+tmp==10){
//				printf("pro:%d %d %d\n",fi,lst,K);
//			}
		}
////	printf("%d\n",L(7,8));
//	printf("%d\n",L(15,16));
//	printf("%d\n",dp[1][17][15]);
//	printf("%d\n",dp[1][18][16]);
	printf("%lld\n",ans);
	return 0;
}
