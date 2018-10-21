#include<bits/stdc++.h>
using namespace std;
#define M 500005
int sum[M],n,K;
int main(){
	scanf("%d%d",&n,&K);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	for(int i=K;i<=n;i++){
		printf("----%d----\n",i);
		for(int j=1;j<=i-K;j++){
			printf("%d %.2lf\n",j,1.0*(sum[i]-sum[j])/(i-j));	
		}
	}
	
}
