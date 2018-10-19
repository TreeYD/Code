#include<bits/stdc++.h>
using namespace std;
#define M 9000005
#define LL long long
const int P=1e9+7;
int a,b,n;
int fac[M],inv[M];
void Add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
bool check(int x){
	while(x){
		int t=x%10;
		if(t!=a&&t!=b)return 0;
		x/=10;
	}
	return 1;
}
void Init(){
	inv[0]=inv[1]=fac[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=1LL*(P-P/i)*inv[P%i]%P;
		fac[i]=1LL*fac[i-1]*i%P;
	}
	for(int i=1;i<=n;i++)
		inv[i]=1LL*inv[i]*inv[i-1]%P;
}
int main(){//name long long memory mod 负数 
//	freopen("excellent.in","r",stdin);
//	freopen("excellent.out","w",stdout);
	scanf("%d%d%d",&a,&b,&n);
	int i;//和不为0 
	LL ans=0;
	Init();
	for(i=0;i<=n;i++){
		if(check(a*(n-i)+i*b))
			Add(ans,1LL*fac[n]*inv[i]%P*inv[n-i]%P);
	}
	printf("%lld\n",ans);
	return 0;
}
