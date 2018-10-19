#include<bits/stdc++.h>
using namespace std;
#define M 2005
double dp[M][M],p;
int n,t;
int main(){
	scanf("%d%lf%d",&n,&p,&t);
	int i,j; 
	for(i=t;i>=1;i--)
		for(j=n;j>=1;j--)
			dp[i][j]=p*(dp[i+1][j+1]+1)+(1-p)*dp[i+1][j];
	printf("%.7lf\n",dp[1][1]);
}
