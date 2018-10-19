#include<bits/stdc++.h>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))
int A[105],n,lim;
bool mark[105],flag;
bool dp[3005];
void dfs(int x,int lst,int sum){
	if(flag)return;
	while(sum==lim&&mark[x])x++;
	if(x==n+1){
		flag=1;
		return;
	}
	if(!mark[x]){
		mark[x]=1;
		dfs(x,x,A[x]);
		mark[x]=0;
		return;
	}
	if(lim-sum<A[x])return;
	int nxt=max(x+1,lst+1);
	while(nxt<=n&&mark[nxt])nxt++;
	if(sum+A[nxt]>lim)return;
//	bool flag=(sum%2==1&&lim%2==0);
//	for(int i=nxt;i<=n&&flag;i++)
//		if(!mark[i])flag&=(A[i]%2==0);
	if(flag)return;
//	if(lim==6){
//		printf("OK:%d %d %d\n",x,lst,sum);
//	}
	int choose=0;
	for(int i=nxt;i<=n;i++){
		if(mark[i]||A[i]==choose)continue;
		if(sum+A[i]<=lim){
			mark[i]=1;
			dfs(x,i,sum+A[i]);
			mark[i]=0;
			choose=A[i];
		}
	}
}
int main(){
//	freopen("data.in","r",stdin);
//	int cas=0;
//	while(1){
//		system ("data.exe");
	scanf("%d",&n);
		clr(dp);clr(mark);clr(A);
		flag=0;
		int sum=0,cnt=0,x;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x>50)continue;
			A[++cnt]=x;
			sum+=x;
		}
		n=cnt;
//puts("-----------");
//		sort(A+1,A+1+n);
//		for(int i=1;i<=n;i++)
//			printf("%d ",A[i]);
//		puts("");
		dp[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=A[i];j<=sum;j++)
				dp[j]|=dp[j-A[i]];
		lim=A[n];
//		printf("sum:%d lim:%d\n",sum,lim);
		for(;;lim++){
			if(sum%lim!=0||!dp[lim])continue;
			dfs(1,1,0);
	//		printf("%d\n",lim);
			if(flag)break;
		}
		printf("%d\n",lim);
//	}
//	}
	return 0;
}
