#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define bit(x) (1<<x)
const int M=(1<<18)+5;
LL dp[M][105],n;
int num[M],sz[M];
int cnt[10],len,m,e;
LL per[20];
vector<int>bin[20];
void Init(){
	LL t=n;
	int i;
	while(t){
		num[len++]=t%10;
		cnt[t%10]++;
		t/=10;
	}
	if(!len)len++;
	e=1<<len;per[1]=1;
	for(i=2;i<=len;i++)per[i]=per[i-1]*i;
	for(i=1;i<e;i++){
		sz[i]=sz[i&i-1]+1;
		bin[sz[i]].push_back(i);
	}
}
int main(){
	scanf("%lld%d",&n,&m);
	Init();
	int i,j,k,r;
	for(i=0;i<len;i++)
		if(num[i])dp[bit(i)][num[i]%m]=1;
	for(i=2;i<=len;i++)
		for(j=0;j<bin[i].size();j++){
			int t=bin[i][j];
			for(k=0;k<len;k++)
				if(t&bit(k)){
					int p=t^bit(k);
					for(r=0;r<m;r++)
						dp[t][(r*10+num[k])%m]+=dp[p][r];
				}
		}
	LL ans=dp[e-1][0];
	for(i=0;i<=9;i++)
		if(cnt[i]>1)ans/=per[cnt[i]];
	printf("%lld\n",ans);
}
