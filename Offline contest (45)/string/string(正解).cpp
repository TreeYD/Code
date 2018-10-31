#include<bits/stdc++.h>
using namespace std;
#define M 100005
const int Inf=1e9;
template<class T>void Min(T &x,T y){if(x>y)x=y;}
template<class T>void Max(T &x,T y){if(x<y)x=y;}
char A[M],B[M];
int n,m,a,b,K;
int dp[2][M];
void solve(){
	bool cur=0;
	for(int i=0;i<=m;i++)dp[0][i]=i*a;
	for(int x=1;x<=n;x++){
		cur=!cur;
		dp[cur][0]=x*a;
		for(int y=max(1,x-K);y<=min(m,x+K);y++){
			int &t=dp[cur][y];
			if(A[x]==B[y])t=dp[!cur][y-1];
			else{
				t=min(dp[!cur][y-1]+b,dp[cur][y-1]+a);
				Min(t,dp[!cur][y]+a);
			}
		}
	}
	printf("%d\n",(dp[cur][m]>K)?-1:dp[cur][m]);	
}
int main(){
	scanf("%s%s",A+1,B+1);
	n=strlen(A+1);
	m=strlen(B+1);
	scanf("%d%d%d",&a,&b,&K);
	if(a==0)puts("0");
	else solve();
	return 0;
}
