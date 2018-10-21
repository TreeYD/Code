#include<bits/stdc++.h>
using namespace std;
#define M 305
int A[6][M],n;
struct P20{
	bool dfs(int x,int s){
		if(x==6){
			return (s==0);
		}
		for(int i=1;i<=n;i++){
			if(dfs(x+1,s+A[x][i]))return 1;
		}
		return 0;
	}
	void solve(){
		if(dfs(1,0))puts("YES");
		else puts("NO");
	}
}p20;
struct P100{
	int sum[M*M*M];
	void solve(){
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					sum[++cnt]=A[3][k]+A[4][i]+A[5][j];
		sort(sum+1,sum+1+cnt);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				int s=A[1][i]+A[2][j];
				int x=lower_bound(sum+1,sum+1+cnt,-s)-sum;
				if(sum[x]==-s){
					puts("YES");
					return;
				}
			}
		puts("NO");
	}
}p100;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ 
//  printf("%.2lf\n",(sizeof(p100)+sizeof(A))/1024.0/1024);
//	freopen("zero.in","r",stdin);
//	freopen("zero.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=5;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&A[i][j]);
		p100.solve();
	}
	return 0;
}
