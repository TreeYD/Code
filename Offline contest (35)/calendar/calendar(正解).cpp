#include<bits/stdc++.h>
using namespace std;
#define M 305
const int P=998244353;
template<class T>void Add(T &x,T y){
	x+=y;
	if(x>=P)x-=P;
}
int dp[M][M][M<<1];
int u,v,k,u1,v1,k1;
int n,m,q,X;
int Rand(){
	X=(1LL*100000005*X+20150823)%P;
	return X/100;
}
void Data_Make(){
	v1=Rand();
	u1=Rand();
	k1=Rand();
	v=v1%n+1;
	u=u1%m+1;
	k=k1%(n+m-v-u+1);
}
int main(){
	scanf("%d%d%d%lld",&n,&m,&q,&X);
	for(int i=1;i<=q;i++){
		Data_Make();
		dp[v][u][k]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int p=0;p+i+j<=n+m;p++){
				Add(dp[i][j][p],dp[i-1][j][p+1]);
				Add(dp[i][j][p],dp[i][j-1][p+1]);
			}
			Add(dp[i][j][0],dp[i-1][j][0]);
			Add(dp[i][j][0],dp[i][j-1][0]);
			printf("%d ",dp[i][j][0]);
		}
		puts("");
	}
	return 0;
}
