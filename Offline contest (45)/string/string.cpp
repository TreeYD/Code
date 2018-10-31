#include<bits/stdc++.h>
using namespace std;
#define M 100005
const int Inf=1e9;
template<class T>void Min(T &x,T y){if(x>y)x=y;}
template<class T>void Max(T &x,T y){if(x<y)x=y;}
char A[M],B[M];
int n,m,a,b,K;
struct P60{
	#define Mn 4005
	int dp[Mn][Mn];
	int dfs(int x,int y){
		if(~dp[x][y])return dp[x][y];
		if(x==0)return dp[x][y]=a*y;
		if(y==0)return dp[x][y]=a*x;
		int &res=dp[x][y];
		if(A[x]==B[y])return res=dfs(x-1,y-1);
		res=min(dfs(x-1,y-1)+b,dfs(x,y-1)+a);
		Min(res,dfs(x-1,y)+a);
		return res;
	}
//	void solve(){
//		memset(dp,-1,sizeof(dp));
//		int ans=dfs(n,m);
//		printf("%d\n",(ans>K)?-1:ans);
//	}
//}p60;
struct P_60{
	#define M 100005
	int dp[2][M];
	void solve(){
		bool cur=0;
		for(int i=0;i<=m;i++)
			dp[0][i]=i*a;
		for(int x=1;x<=n;x++){
			cur=!cur;
			dp[cur][0]=x*a;
			for(int y=1;y<=m;y++){
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
}p_60;
int main(){//name memory long long * mod - «–∑÷≈–∂œ ≥ı÷µ
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024); 
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	scanf("%s%s",A+1,B+1);
	n=strlen(A+1);
	m=strlen(B+1);
	scanf("%d%d%d",&a,&b,&K);
	p_60.solve();
	return 0;
}
