#include<bits/stdc++.h>
using namespace std;
#define M 505
#define LL long long
#define Inf 0x7f7f7f7f7f
template<class T>void Min(T &x,T y){if(x>y)x=y;}
LL dp[11][M][M];
struct node{
	LL x,y;
	void set(){x=y=0;}
}Q[M],tmp;
LL sum[M],val[M];
int A[M],n,K;
bool checkL(int k,node &a,node &b){
	return a.y-a.x*k>=b.y-b.x*k;
}
bool checkR(node &a,node &b,node &c){
	return (c.y-b.y)*(b.x-a.x)<=(b.y-a.y)*(c.x-b.x);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("pro.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		val[i]=val[i-1]+A[i]*i;
		sum[i]=sum[i-1]+A[i];
	}
	memset(dp,0x7f,sizeof(dp));
	for(int i=1;i<=n;i++)dp[1][i][i]=0;
	for(int i=1;i<=n;i++){
		for(int t=2;t<=K;t++){
			int L=1,R=0;
			Q[L].set();tmp.set();
			for(int j=1;j<=n;j++){
				int k=sum[j-1];
				while(L<R&&checkL(k,Q[L],Q[L+1]))L++;
				dp[t][i][j]=Q[L].y-k*Q[L].x+val[j-1];
				tmp.y=dp[t-1][i][j]-val[j]+j*sum[j];
				tmp.x=j;
				while(L<R&&checkR(Q[R-1],Q[R],tmp))R--;
				Q[++R]=tmp;
			}
		}
	}
	LL ans=Inf;
	for(int i=1;i<=n;i++)
		for(int j=i+K-1;j<=n;j++) {
			LL costL=(val[n]-val[j])-(sum[n]-sum[j])*j;
			LL costR=sum[i-1]*(n-j)+val[i-1];
			Min(ans,dp[K][i][j]+costL+costR);
		}
	printf("%lld\n",ans);
	return 0;
}

