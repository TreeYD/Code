#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n;
int calc(int x){
	int L=2,R=1e9,ans=1;
	while(L<=R){
		int mid=L+R>>1;
		if(pow(mid,x)<=n){
			ans=mid;
			L=mid+1;
		}else R=mid-1;
	}
	return ans;
}
void solve(){
	int i,j,e=log2(n);
	LL ans=0;
	for(i=2;i<=e;i++){
		int t=i,cnt=0,flag=0;
		for(j=2;j*j<=t&&!flag;j++){
			if(t%j==0){
				cnt++;
				while(t%j==0){
					t/=j;
					flag|=(t%j==0);
				}
			}
		}
		if(flag)continue;
		if(t>1)cnt++;
		int mo=-1;
		if(cnt&1)mo=1;
		ans+=mo*(calc(i)-1);
	}
	printf("%lld\n",ans+1);
}
int main(){
	while(~scanf("%lld",&n)){
		solve();
	}
	return 0;
}
