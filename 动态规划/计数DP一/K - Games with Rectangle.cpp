#include<bits/stdc++.h>
using namespace std;
#define M 1005
const int P=1e9+7;
int C[M][M],n,m,K;
int main(){
	int i,j;
	scanf("%d%d%d",&n,&m,&K);
	if(2*K>n-1||2*K>m-1){
		puts("0");
		return 0;
	}
	int w=max(n,m);
	for(i=1;i<=w;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
		}
	}
	printf("%d\n",1LL*C[n-1][2*K]*C[m-1][2*K]%P);
	return 0;
}
