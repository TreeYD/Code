#include<bits/stdc++.h>
using namespace std;
#define M 1505
//#define Inf 0x7f7f7f
//#define clr(a) memset(a,-123,sizeof(a))
int LH[M][M],RH[M][M],LD[M][M],RD[M][M];
int val[M][M],sum[M][M];
int Line[M][M],List[M][M];
int n,m,K,res;
void Max(int &x,int y){
	if(x<y)x=y;
}
void Init(){
//	clr(Line);clr(List);
//	clr(LH);clr(RH);clr(LD);clr(RD);
//	printf("%d\n",Line[1][1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)sum[i][j]+=sum[i][j-1];
		for(int j=1;j<=m;j++)sum[i][j]+=sum[i-1][j];
	}
	for(int i=1;i<=n-K+1;i++)
		for(int j=1;j<=m-K+1;j++){
			val[i][j]=sum[i+K-1][j+K-1]+sum[i-1][j-1]-sum[i+K-1][j-1]-sum[i-1][j+K-1];
//			printf("%d %d %d\n",i,j,val[i][j]);
		}
//	puts("-----------LH------------");
	for(int i=K;i<=n;i++)
		for(int j=K;j<=m;j++){
			LH[i][j]=max(max(LH[i-1][j],LH[i][j-1]),val[i-K+1][j-K+1]);
		}
	for(int i=K;i<=n;i++)
		for(int j=m-K+1;j>=1;j--){
			RH[i][j]=max(max(RH[i-1][j],RH[i][j+1]),val[i-K+1][j]);
		}
	for(int i=n-K+1;i>=1;i--)
		for(int j=m-K+1;j>=1;j--){
			RD[i][j]=max(max(RD[i+1][j],RD[i][j+1]),val[i][j]);
		}
	for(int i=n-K+1;i>=1;i--)
		for(int j=K;j<=m;j++){
			LD[i][j]=max(max(LD[i+1][j],LD[i][j-1]),val[i][j-K+1]);
//			printf("%d %d %d\n",i,j,LD[i][j]);
		}
	for(int i=K;i<=n;i++)
		for(int j=1;j<=m-K+1;j++){
			Line[i-K+1][i]=max(Line[i][i+K-1],val[i-K+1][j]);
		}
//	puts("----------Line----------");
	for(int i=n-K+1;i>=1;i--)
		for(int j=i+K;j<=n;j++){
			Line[i][j]=max(Line[i][j-1],Line[i+1][j]);
//			printf("%d %d %d\n",i,j,Line[i][j]);
		}
	for(int i=K;i<=m;i++)
		for(int j=1;j<=n-K+1;j++)
			List[i-K+1][i]=max(List[i-K+1][i],val[j][i-K+1]);
	for(int i=m-K+1;i>=1;i--)	
		for(int j=i+K;j<=m;j++)
			List[i][j]=max(List[i][j-1],List[i+1][j]);
}		
void Solve(){
//	puts("-------");
	for(int i=K+1;i<=n;i++)
		for(int j=i+K-1;j<=n-K;j++){
			Max(res,Line[i][j]+Line[1][i-1]+Line[j+1][n]);
//			printf("%d %d %d\n",Line[i][j],Line[1][i-1],Line[j+1][n]);
		}
	for(int i=K+1;i<=m;i++)
		for(int j=i+K-1;j<=m-K;j++){
			Max(res,List[i][j]+List[1][i-1]+List[j+1][m]);
//			printf("%d %d %d\n",List[i][j],List[1][i-1],List[j+1][m]);
//			printf("%d\n",res);
		}
//	printf("ans:%lld\n",res);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
//			if(i>=K&&j>=K&&i<=n-K&&j<=m-K)
			Max(res,LH[i][j]+RH[i][j+1]+Line[i+1][n]);//,puts("1");
//			if(i<=n-K+1&&j<=m-K+1&&j-1>=K&&n-i>=K)
			Max(res,RH[i][j]+RD[i+1][j]+List[1][j-1]);//,puts("2");
//			if(n-i+1>=K&&m-j+1>=K&&i-1>=K&&j-1>=K)
			Max(res,RD[i][j]+LD[i][j-1]+Line[1][i-1]);//,puts("3");
//			if(n-i+1>=K&&j>=K&&i-1>=K&&m-j>=K)
			Max(res,LD[i][j]+LH[i-1][j]+List[j+1][m]);//,puts("4");
//			printf("%d %d %d\n",i,j,res);
		}
	printf("%d\n",res);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("pro.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&sum[i][j]);
	Init();
	Solve();
	return 0;
}
