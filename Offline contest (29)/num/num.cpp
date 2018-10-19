#include<bits/stdc++.h>
using namespace std;
#define M 3005
const int P=1e9+7;
int dp[M][M],sum[M][M],n;
int same[M][M];
char str[M];
void Add(int &x,int y){
	x+=y;if(x>=P)x-=P;
	if(x<0)x+=P;
}
bool check(int L1,int L2,int len){
	if(same[L1][L2]>=len)return 0;
	return str[L1+same[L1][L2]]>str[L2+same[L1][L2]];
}
void Init(){
	int i,j;
	for(i=n;i>=1;i--)
		for(j=i;j>=1;j--){
			if(str[i]==str[j]){
				same[i][j]=same[i+1][j+1]+1;
			}else same[i][j]=0;
		}
}
void solve(){
	int i,j,k;
	for(i=1;i<=n;i++){
		dp[1][i]=1;
		sum[1][i]=1;
	}
	for(i=2;i<=n;i++){
		for(j=2;j<=i;Add(sum[j][i],sum[j-1][i]+dp[j][i]),j++){
			if(str[j]=='0')continue;
			int &res=dp[j][i];
			if(2*j-i>1&&str[2*j-i-1]!='0'){ 
				if(check(j,2*j-i-1,i-j+1))
					Add(res,dp[2*j-i-1][j-1]);
			}
			Add(res,sum[j-1][j-1]);
			if(2*j-i>1)Add(res,-sum[2*j-i-1][j-1]);
		}
	}
	int ans=sum[n][n];
	printf("%d\n",(ans%P+P)%P);
}
int main(){
	scanf("%d%s",&n,str+1);
	Init();
	solve();
	return 0;
}
