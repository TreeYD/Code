#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int dp[105][2505];
char str[105];
int n,sum;
void Add(int &x,int y){
	x+=y;if(x>=P)x-=P;
}
void Init(){
	int tmp=0,i,j,k;
	dp[0][0]=1;
	for(i=1;i<=100;i++){
		tmp+=25;
		for(j=0;j<=25;j++)
			for(k=tmp;k>=j;k--)
				Add(dp[i][k],dp[i-1][k-j]);
	}
}
int main(){
	int T;
	Init();
	scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);
		n=strlen(str+1);sum=0;
		for(int i=1;i<=n;i++)sum+=str[i]-'a';
		printf("%d\n",dp[n][sum]-1);
	}
	return 0;
}
