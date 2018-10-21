#include<bits/stdc++.h>
using namespace std;
#define M 500005
#define LL long long
struct node{
	LL x,y;
}Q[M],tmp;
int L,R,n,m;
LL sum[M],dp[M];
bool checkL(LL k,node &a,node &b){
	return a.y-k*a.x>b.y-k*b.x;
}
bool checkR(node a,node b,node c){
	return (c.y-b.y)*(b.x-a.x)<=(b.y-a.y)*(c.x-b.x);
}
int main(){
	freopen("A.in","r",stdin);
	while(~scanf("%d%d",&n,&m)){
		tmp.x=tmp.y=0;L=R=0;
		int sz=1;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			scanf("%d",&sum[sz]);
//			if(sum[sz]==0)continue;
			sum[sz]+=sum[sz-1];sz++;
		}
		n=sz-1;
		//y=dp[j] k=(2*sum[i]-sum[j]) x=sum[j]
		for(int i=1;i<=n;i++){
			while(L<R&&checkL(2*sum[i],Q[L],Q[L+1]))L++;
			dp[i]=Q[L].y-2*sum[i]*Q[L].x+m+sum[i]*sum[i];
			tmp.x=sum[i],tmp.y=dp[i]+sum[i]*sum[i];
			while(L<R&&checkR(Q[R-1],Q[R],tmp))R--;
			Q[++R]=tmp;
		}
		printf("%lld\n",n==0?m:dp[n]);
	}
	return 0;
}
