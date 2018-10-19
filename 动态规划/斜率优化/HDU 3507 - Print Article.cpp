#include<bits/stdc++.h>
using namespace std;
#define M 500005
#define LL long long
struct node{
	LL x,y;
}Q[M],tmp;
int L,R,n,m;
LL sum[M],dp[M];
bool checkL(int k,node &a,node &b){
	return a.y-k*a.x>b.y-k*b.x;
}
bool checkR(node a,node b,node c){
	return (c.y-b.y)*1.0/(c.x-b.x)<=(b.y-a.y)*1.0/(b.x-a.x);
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		tmp.x=tmp.y=0;L=R=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&sum[i]);
			sum[i]+=sum[i-1];
		}
		//y=dp[j] k=(2*sum[i]-sum[j]) x=sum[j]
		for(int i=1;i<=n;i++){
			while(L<=R&&checkL(2*sum[i],Q[L],tmp))L++;
			Q[++R]=tmp;
			dp[i]=Q[L].y-2*sum[i]*Q[L].x+m+sum[i]*sum[i];
			tmp.x=sum[i],tmp.y=dp[i]+sum[i]*sum[i];
			while(L<R&&checkR(Q[R-1],Q[R],tmp))R--;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
