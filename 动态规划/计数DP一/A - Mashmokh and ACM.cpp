#include<bits/stdc++.h>
using namespace std;
#define M 2005
const int P=1e9+7;
int dp[M][M],n,K;
vector<int>son[M];
void Init(){
	for(int i=1;i<M;i++)
		for(int j=i;j<M;j+=i)
			son[j].push_back(i);
}
void Add(int &x,int y){
	x+=y;
	if(x>=P)x-=P;
}
int main(){
	scanf("%d%d",&n,&K);
	int i,j,k;
	Init();
	for(i=1;i<=n;i++)dp[1][i]=1;
	int ans=0;
	for(i=2;i<=K;i++){
		for(j=1;j<=n;j++){
			for(k=0;k<son[j].size();k++)
				Add(dp[i][j],dp[i-1][son[j][k]]);
		}
	}
	for(i=1;i<=n;i++)Add(ans,dp[K][i]);
	printf("%d\n",ans%P);
}
