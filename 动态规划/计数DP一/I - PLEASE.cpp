#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int P=1e9+7;
void exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
LL Pow(LL a,LL b){
	LL base=a,ans=1;
	while(b){
		if(b&1)ans=1LL*ans*base%P;
		base=1LL*base*base%P;
		b>>=1;
	}	
	return ans;
}
int main(){
	LL a,m,d=2;
	int k,i;
	scanf("%d",&k);
	bool eve=0;
	for(i=1;i<=k;i++){
		scanf("%lld",&a);
		if(a%2==0)eve=1;
		d=Pow(d,a);
	}
	eve=!eve;
	LL x,y;
	exgcd(2,P,x,y);
	x=(x%P+P)%P;
	d=d*x%P;m=d;
	if(!eve)m++;
	else m--;
	exgcd(3,P,x,y);
	m=m*x%P;
	printf("%lld/%lld\n",m,d);
	return 0;
}
