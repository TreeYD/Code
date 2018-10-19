#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define bit(x) (1LL<<(x-1))
LL C[65][65],m;
int k;
LL calc(LL n){
	LL res=0;
	int cnt=0,ID=0,i;
	for(i=1;i<=64;i++)
		if(n&bit(i))cnt++;
	for(i=64;i>=1;i--)
		if(n&bit(i)){
			++ID;
			if(ID+k-cnt<0)continue;
			res+=C[i-1][k-cnt+ID];
		}
	return res;
}
void Find(){
	LL L=1,R=1e18,ans=-1;
	while(L<=R){
		LL mid=L+R>>1;
		if(calc(2*mid)-calc(mid)>=m){
			ans=mid;
			R=mid-1;
		}else L=mid+1;
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%lld%d",&m,&k);
	int i,j;
	for(i=0;i<=64;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	Find();
	return 0;
}
