#include<bits/stdc++.h>
using namespace std;
#define M 1005
int A[M][M],B[M][M];
int pos[M*M],dp[M];
int n,m; 
bool have[M];
struct P30{
	void solve(){
		int ans=0;
		for(int i=1;i<=n;i++){
			int len=0,num=0;
			for(int j=1;j<=m;j++){
				if(B[i][j])
					pos[B[i][j]]=++num;
				dp[j]=0;
			}
			dp[1]=m+1;
			int tmp=0;
			for(int j=1;j<=m;j++){
				if(A[i][j]){
					A[i][j]=pos[A[i][j]];
					int x=A[i][j];
					int y=lower_bound(dp+1,dp+1+len,x)-dp;
					dp[y]=A[i][j];
					if(y>len)len=y;
				}
			}
			ans+=num-len;
			if(!have[i])ans++;
		}
		printf("%d\n",ans);
	}
}p30;
int main(){
	scanf("%d%d",&n,&m);
	int flag=0,same=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&A[i][j]);
			have[i]|=(A[i][j]==0);
		}
		flag|=have[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&B[i][j]);
			same&=(B[i][j]==A[i][j]);
		}
	if(same)puts("0");
	else if(!flag&&!same)puts("-1");
	else p30.solve();	
	return 0;
}
