#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define LL long long
char str[M];
int k,len,sum[30][M];
LL n;
int main(){//name long long memory mod
//	freopen("secret.in","r",stdin);
//	freopen("secret.out","w",stdout);
	scanf("%lld",&n);
	scanf("%s%d",str+1,&k);
	len=strlen(str+1);
	int i,j,t;
	for(i=1;i<=len;i++){
		sum[str[i]-'A'][i]++;
		for(j=0;j<26;j++)
			sum[j][i]+=sum[j][i-1];
	}
	LL p,x,y;
	char s[2];
	while(k--){
		scanf("%lld%s",&p,s);
		t=s[0]-'A';
		LL a,b;
		if(p%2==0){
			a=p/2%len*((p-1)%len)%len;
			b=p/2%len*((p+1)%len)%len;
		}else{
			a=(p-1)/2%len*(p%len)%len;
			b=(p+1)/2%len*(p%len)%len;
		}
		if(a==0)a=len;
		if(b==0)b=len;
		LL ans=0;
		if(len-a>=p){
			ans=sum[t][b]-sum[t][a];
		}else if(p-(len-a)<=len){
			ans=sum[t][len]-sum[t][a];
			ans+=sum[t][b];
		}else{
			ans=sum[t][len]-sum[t][a]+sum[t][b];
			ans+=sum[t][len]*((p-len+a-b)/len);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
