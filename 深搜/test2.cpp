#include<bits/stdc++.h>
using namespace std;
#define Cpy(a,b) memcpy(a,b,sizeof(b))
bool mk[15][2005];
int ans,tmp[15],num[15];
int n,m;
void dfs(int x,int lst,int mx){
	if(x!=1&&tmp[1]*n<=ans)return;
	if(x==m+1){
		if(ans<mx){
			ans=mx;
			for(int i=1;i<=m;i++)
				num[i]=tmp[i];
		}
		return;
	}
	bool mk1[15][2005];
	memset(mk1,0,sizeof(mk1));
	for(int i=1;i<=n;i++)
		for(int j=0;j<=tmp[1]*n;j++)
			mk1[i][j]=mk[i][j];
	for(int i=mx;i<lst;i++){
		tmp[x]=i;
		int t=mx;
		for(int j=1;j<=n;j++)
			for(int k=0;k<=tmp[1]*n;k++){
				if(k>=i)mk[j][k]|=mk[j-1][k-i];
				mk[j][k]|=mk[j-1][k];
			}
		while(mk[n][t+1])t++;
		dfs(x+1,i,t);
		for(int j=1;j<=n;j++)
			for(int k=0;k<=tmp[1]*n;k++)
				mk[j][k]=mk1[j][k];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	mk[0][0]=1;
	dfs(1,50,0);
	for(int i=1;i<=m;i++)
		printf("%d ",num[i]);
	puts("");
	printf("MAX=%d\n",ans);
	return 0;
}
