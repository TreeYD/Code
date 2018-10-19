#include<bits/stdc++.h>
using namespace std;
#define M 2005
int C[M][M],n,m,K;
int cnt[M][M];
void Add(int &x,int y){
	x+=y;
	if(x>=K)x-=K;
}
int main(){//name long long memory mod -
//	freopen("problem.in","r",stdin);
//	freopen("problem.out","w",stdout);
	int T;
	scanf("%d%d",&T,&K);
	for(int i=1;i<=M-5;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			Add(C[i][j],C[i-1][j]);
			Add(C[i][j],C[i-1][j-1]);
		}
	}
	for(int i=1;i<=M-5;i++){
		for(int j=1;j<=i;j++){
			if(C[i][j]==0)cnt[i][j]++;
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	for(int i=1;i<=M-5;i++)
		for(int j=0;j<=i;j++)
			cnt[i][j]+=cnt[i-1][min(i-1,j)];
	while(T--){
		scanf("%d%d",&n,&m);
		printf("%d\n",cnt[n][min(n,m)]);
	}
	return 0;
}
