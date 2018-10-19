#include<bits/stdc++.h>
using namespace std;
#define M 2605
#define LL long long
const int P=1e9+7;
LL C[M][M],inv[M];
char str[105];
int sum,n;
void Add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
LL Pow(LL a,LL b){
	LL base=a,ans=1;
//	if(a==0)return 1;
	while(b){
		if(b&1)ans=ans*base%P;
		base=base*base%P;
		b>>=1;
	}
	return ans;
}
void Init(){
	inv[0]=inv[1]=1;
	for(int i=1;i<M;i++){
		C[i][0]=C[i][i]=1;
		if(i>1)inv[i]=(P-P/i)*inv[P%i]%P;
		for(int j=1;j<i;j++){
			Add(C[i][j],C[i-1][j-1]);
			Add(C[i][j],C[i-1][j]);
		}
	}
	for(int i=1;i<M;i++)
		inv[i]=inv[i-1]*inv[i]%P;
}
int main(){
	int T;
	scanf("%d",&T);
	Init();
	while(T--){
		scanf("%s",str+1);
		int mo=-1,i,j;
		n=strlen(str+1);sum=0;
		for(i=1;i<=n;i++)
			sum+=str[i]-'a'+1;
		LL ans=0;
		printf("sum:%d\n",sum);
		ans=C[sum-1][n-1];
		for(i=1;i<=n;i++){
			LL tmp=0;
			for(j=i*26+1;j<=sum+i-n;j++){
				LL t=j-i*26;
				Add(tmp,Pow(i,t)*inv[t]%P*C[sum-j-1][n-i-1]%P);
			}
			Add(ans,mo*tmp*C[n][i]%P);
			printf("choose %d get:%lld %lld\n",i,ans,tmp);
			mo=-mo;
		}
		printf("%lld\n",((ans-1)%P+P)%P);
	}
	return 0;
}
