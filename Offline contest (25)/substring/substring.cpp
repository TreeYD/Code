#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int dp[1005][105][105];
char A[1005],B[205];
int n,m,k;
void dfs(int x,int y,int z){//A[x,n] B[y,m] 要选取z个 
	if(~dp[x][y][z])return;
	int &res=dp[x][y][z];
	res=0;
	if(z==0){
		if(y>m)res=1;
		else res=0;
		return;
	}
	int i,j;
	for(i=y;i<=m-z+1;i++){//B[y,i] 
		for(j=x;j<=n-z+1;j++){//A[j,n]
			if(n-j>=i-y&&A[j]==B[y]){
				int t1=j,t2=y;
				while(t2<=i&&A[t1]==B[t2])t1++,t2++;
				if(t2==i+1){
					dfs(t1,t2,z-1);
					res+=dp[t1][t2][z-1];
					if(res>=P)res-=P;
				}
			}
		}
	}	
}
int main(){
//	freopen("substring.in","r",stdin);
//	freopen("substring.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",A+1,B+1);
	memset(dp,-1,sizeof(dp));
	dfs(1,1,k);
	printf("%d\n",dp[1][1][k]);
	return 0;
}
