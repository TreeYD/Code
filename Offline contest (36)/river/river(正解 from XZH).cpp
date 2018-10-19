#include<bits/stdc++.h>
using namespace std;
#define M 305
#define Set(a,b) memset(a,b,sizeof(a)) 
#define Inf 0x7f7f7f
template<class T>void Min(T &x,T y){if(x>y)x=y;}
int dp[2][M],tmp[M];
int len,A[105];
int S,T,n;
bool check(int l){
	if(l<0)return 0;
	int t=l/S,lim=t*T;
	return l<=lim;
}
int main(){
	scanf("%d",&len);
	scanf("%d%d%d",&S,&T,&n);
	Set(dp,Inf);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+1+n);
	bool cur=1;
	for(int i=0;i<n;i++){
		Set(tmp,Inf);Set(dp[cur],Inf);
		for(int j=0;j<=T;j++)
			if(A[i+1]-A[i]+j<=T)
				Min(dp[cur][A[i+1]-A[i]+j],dp[!cur][j]);
		for(int j=0;j<=T;j++)
			for(int k=max(j,S);k<=T;k++)
				Min(tmp[k-j],dp[!cur][j]);
		tmp[0]=dp[!cur][0];
		for(int j=0;j<=T;j++){
			for(int k=0;k<=T;k++)
				if(check(A[i+1]-k-A[i]-j))
					Min(dp[cur][k],tmp[j]+(k==0));
		}
		cur=!cur;
	}
	int ans=Inf;
	cur=!cur;
	for(int i=0;i<T;i++)
		Min(ans,dp[cur][i]);
	printf("%d\n",ans);
	return 0;
}	
