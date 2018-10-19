#include<bits/stdc++.h>
using namespace std;
int cnt[3005],n,lim;
int mark[3005];
bool dp[3005];
bool flag;
void dfs(int x,bool f,int lst){
	if(flag)return;
	bool chg=0;
	while(x<lim&&!cnt[x])x++,chg=1;
	if(chg)lst=x,f=0;
//	if(lim==6){
//		printf("%d\n",lim);
//		for(int i=1;i<=lim;i++)
//			printf("%d(%d) ",cnt[i],i);
//		puts("");
//		printf("%d\n",flag);
//	}
	if(x==lim){
//	printf("%d %d %d\n",x,f,lst);
		flag=1;
		return;
	}
	if(mark[x])return;
	if(!f){
		if(cnt[x]-mark[x]>1){
//			if(lim==6)printf("mark:%d %d\n",x,mark[x]);
			for(int i=2;i<=(cnt[x]-mark[x]);i++){
				if(x*i>lim)break;
				for(int j=1;j*i<=(cnt[x]-mark[x]);j++){
					cnt[x]-=i*j;
					cnt[x*i]+=j;
					mark[x*i]+=j;
//					if(lim==6){
//						puts("Self");
//						printf("x:%d->i:%d\n",x,x*i);
//						printf("%d\n",lim);
//						for(int i=1;i<=lim;i++)
//							printf("%d(%d) ",cnt[i],i);
//						puts("");	
//					}
					dfs(x,1,lst);
					cnt[x*i]-=j;
					mark[x*i]-=j;
					cnt[x]+=i*j;
				}
			}
			dfs(x,1,lst);
			return;
		}
	}
//	if(lim==5)puts("OK");
	for(int i=max(x+1,lst+1);i<=lim-x;i++){
		for(int j=1;j<=min(cnt[x]-mark[x],cnt[i]);j++){
			cnt[x]-=j;
			cnt[i+x]+=j;
			mark[i+x]+=j;
			cnt[i]-=j;
//			if(lim==6){
//				puts("Other");
//				printf("%d->%d\n",x,i);
////				printf("%d\n",lim);
//				for(int i=1;i<=lim;i++)
//					printf("%d(%d) ",cnt[i],i);
//				puts("");
//			}
			dfs(x,1,i);
			cnt[x]+=j;
			cnt[i+x]-=j;
			mark[i+x]-=j;
			cnt[i]+=j;		
		}
	}
}
int main(){
//	freopen("data.in","r",stdin);
	int cas=0;
//	while(1){
//		system("data.exe");
	scanf("%d",&n);
	int x,i,sum=0;
	memset(cnt,0,sizeof(cnt));
	memset(mark,0,sizeof(mark));
	lim=flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x>50)continue;
		lim=max(lim,x);
		sum+=x;
		cnt[x]++;
	}
	dp[0]=1;
	for(int i=1;i<=lim;i++){
		if(cnt[i]==0)continue;
		for(int j=i;j<=sum;j++)
			dp[j]|=dp[j-i];
	}
//	printf("lim:%d sum:%d\n",lim,sum);
	for(;;lim++){
		if(sum%lim!=0||!dp[lim])continue;
//		printf("%d\n",lim);
//		if(lim==sum)break;
		dfs(1,0,0);
		if(flag)break;
	}
	printf("%d\n",lim);
////	printf("Case %d: %d\n",++cas,lim);
//	}
	return 0;
}
