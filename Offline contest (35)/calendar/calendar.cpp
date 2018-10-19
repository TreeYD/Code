#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
#define M 305
int n,m,q,C[M][M];
long long X;
int u,v,k,u1,v1,k1;
bool check(int x,int y){
	return v+x<=n&&u-x+y<=m;
}
void Add(int &x,int y){
	x+=y;
	if(x>=P)x-=P;
	if(x<0)x+=P;
}
void Init(){
	C[0][0]=1;
	for(int i=1;i<M;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			Add(C[i][j],C[i-1][j]);
			Add(C[i][j],C[i-1][j-1]);
		}
	}
}
int Rand(){
	X=(X*100000005+20150823)%P;
	return X/100;
}
int Data(){
	v1=Rand();
	u1=Rand();
	k1=Rand();
	v=v1%n+1;
	u=u1%m+1;
	k=k1%(n+m-v-u+1);
}
struct P50{
	int dp[M][M];
	void solve(){
		for(int t=1;t<=q;t++){
			Data();
			if(k>0){
				for(int i=max(0,u+k-m);i<=k&&v+i<=n;i++)
					if(check(i,k))
						Add(dp[v+i][u-i+k],C[k][i]);
			}else Add(dp[v][u],1);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				Add(dp[i][j],dp[i-1][j]);
				Add(dp[i][j],dp[i][j-1]);
				printf("%d ",(dp[i][j]%P+P)%P);
			}
			puts("");
		}
	}
}p50;
int main(){//name memory long long * mod -
	//printf("%.2lf\n",sizeof(p));
//	freopen("calendar.in","r",stdin);
//	freopen("calendar.out","w",stdout);
	Init();
	scanf("%d%d%d%lld",&n,&m,&q,&X);
	p50.solve();
	return 0;
}
