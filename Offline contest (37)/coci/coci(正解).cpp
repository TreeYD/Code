#include<bits/stdc++.h>
using namespace std;
#define N 655
#define M 500005
void Max(int &x,int y){
	if(x<y)x=y;
}
int sum[N][N],cnt[2][N];
int fi[M],se[M];
int n,Mx,My;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&fi[i],&se[i]);
		sum[fi[i]][se[i]]++;
		if(fi[i]==0)cnt[0][se[i]]++;
		if(se[i]==0)cnt[1][fi[i]]++;
		Max(Mx,fi[i]);
		Max(My,se[i]);
	}
	for(int i=Mx;i>=0;i--){
		for(int j=My;j>=0;j--)
			sum[i][j]+=sum[i][j+1];
		for(int j=My;j>=0;j--)
			sum[i][j]+=sum[i+1][j];
	}
	for(int i=1;i<=n;i++){
		int big=sum[fi[i]+1][se[i]+1];
		int tmp=n-sum[0][se[i]]-sum[fi[i]][0]+sum[fi[i]][se[i]];
		if(fi[i]==650)tmp+=cnt[0][se[i]];
		if(se[i]==650)tmp+=cnt[1][fi[i]];
		printf("%d %d\n",big+1,n-tmp);
	}
	return 0;
}
