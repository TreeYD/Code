#include<bits/stdc++.h>
using namespace std;
#define M 500005
int ID,n,K;
int sum[M];
int main(){
	scanf("%d%d",&n,&K);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	double ans=0;
	for(int i=K;i<=n;i++){
		if(1LL*(sum[i]-sum[i-K])*(i-ID)>1LL*(sum[i]-sum[ID])*K)ID=i-K;
		ans=max(ans,1.0*(sum[i]-sum[ID])/(i-ID));
	}
	printf("%.2lf\n",ans);
	return 0;
}
