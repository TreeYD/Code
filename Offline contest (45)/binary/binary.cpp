#include<bits/stdc++.h>
using namespace std;
#define M 10005
#define LL long long
const LL P=1e18;
char str[M];
int n;
struct BigInt{
	LL  num[405];
	int len;
	BigInt(){len=1;num[1]=1;}
	void operator+=(const BigInt &x){
		len=max(len,x.len);
		for(int i=1;i<=len;i++){
			num[i]=num[i]+x.num[i];
			if(num[i]>=P){
				num[i+1]++;
				num[i]-=P;
			}
		}
		if(num[len+1])len++;
	}
	void operator*=(const int x){
		int m=0;
		for(int i=1;i<=len;i++){
			num[i]=num[i]*x+m;	
			m=num[i]/P;
			num[i]%=P;
		}
		if(m>0)num[++len]=m;
	}
	void Print(){
		printf("%lld",num[len]);
		for(int i=len-1;i>=1;i--)
			printf("%018lld",num[i]);
		puts("");
	}
}sum,cnt;
void solve(){
	for(int i=1;i<=n;i++){
		if(str[i]=='L')sum*=2;
		if(str[i]=='R'){
			sum*=2;
			sum+=cnt;	
		}
		if(str[i]=='*'){
			sum*=5;
			sum+=cnt;
			cnt*=3;
		}	
	}
	sum.Print();
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	solve();
	return 0;
}
