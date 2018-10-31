#include<bits/stdc++.h>
using namespace std;
#define M 105
int cnt[M],sum[M],K;
char str[M];
int main(){
	scanf("%d",&K);
	int mi,ID=-1;
	int flag=0,ans=0;
	for(int i=1;i<=K;i++){
		scanf("%s",str+1);
		int n=strlen(str+1),s=n;
		for(int j=1;j<=n;j++){
			if(s==n&&str[j]=='o')s=j-1;
			if(str[j]=='o')cnt[i]++;
		}
		sum[i]=n-s;
		if(cnt[i]==0){
			flag++;
		}
		if(ID==-1||mi>sum[i]-cnt[i]){
			mi=sum[i]-cnt[i];
			ID=i;
		}
	}
	if(flag<=1)ans+=sum[ID]-cnt[ID];
	for(int i=1;i<=K;i++)
		ans+=sum[i];
	printf("%d\n",ans);
	return 0;
}
