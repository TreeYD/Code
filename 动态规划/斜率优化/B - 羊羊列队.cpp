#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define M 1005
#define LL long long
#define Inf 0x7f7f7f7f
LL A[N];
LL dp[M][N];
int n,m;
struct node{
	LL x,y;
}Q[N],tmp;
bool checkL(LL k,node &a,node &b){
	return a.y-k*a.x>=b.y-k*b.x;
}
bool checkR(node &a,node &b,node &c){
	return (c.y-b.y)*(b.x-a.x)<=(b.y-a.y)*(c.x-b.x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+1+n);
	memset(dp,Inf,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[1][i]=(A[i]-A[1])*(A[i]-A[1]);
	for(int i=2;i<=m;i++){
		int L=1,R=0;
		tmp.y=dp[i-1][i-1]+A[i]*A[i];
		tmp.x=A[i];Q[++R]=tmp;
		for(int j=i;j<=n;j++){
			int K=2*A[j];
			while(L<R&&checkL(K,Q[L],Q[L+1]))L++;
			dp[i][j]=Q[L].y-K*Q[L].x+A[j]*A[j];
			tmp.y=dp[i-1][j]+A[j+1]*A[j+1];
			tmp.x=A[j+1];
			while(L<R&&checkR(Q[R-1],Q[R],tmp))R--;
			Q[++R]=tmp;
		}
	}
	printf("%lld\n",dp[m][n]);
	return 0;
}
