#include<bits/stdc++.h>
using namespace std;
const int M=(1<<16);
int cnt0[M+5],cnt1[M+5];
int sum[25],res,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<min(n+1,M);i++){
		if(i&1){
			cnt1[i]=cnt1[i>>1]+1;
			cnt0[i]=cnt0[i>>1];
		}else{
			cnt0[i]=cnt0[i>>1]+1;
			cnt1[i]=cnt1[i>>1];
		}
		sum[cnt1[i]]++;
		if(cnt1[i]>cnt0[i])res++;
	}
	int L=n>>16;
	if(n<M){
		printf("%d %d\n",res,n-res);
		return 0;
	}
	for(int i=20;i>0;i--){
		sum[i]+=sum[i+1];
	}
	for(int i=1;i<L;i++){
		int b1=cnt1[i],b0=cnt0[i];
		int lim=(16-b1+b0)/2+1;
		res+=sum[lim];
	}
	int b1=cnt1[L],b0=cnt0[L];
	for(int i=0;i+(L<<16)<=n;i++)
		if(b1+cnt1[i]>b0+16-cnt1[i])res++;
	printf("%d %d\n",res,n-res);
	return 0;
}
