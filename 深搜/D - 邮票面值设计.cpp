#include<bits/stdc++.h>
using namespace std;
bool mk[20][2005];
int ans,tmp[15],num[15];
int n,m;
bool Isbetter(){
	for(int i=m;i>=1;i--){
		if(num[i]<tmp[i])return 1;
		if(num[i]>tmp[i])return 0;
	}
}
void dfs(int x,int lst,int mx){
	if(lst>mx)return;
	if(x==m+1){
		if(ans<mx){
			ans=mx;
			for(int i=1;i<=m;i++)
				num[i]=tmp[i];
		}else if(ans==mx&&Isbetter()){
			for(int i=1;i<=m;i++)
				num[i]=tmp[i];
		}
		return;
	}
	bool mk1[20][2005];
	memcpy(mk1,mk,sizeof(mk));
	for(int i=lst+1;i<=mx+1;i++){
		tmp[x]=i;
		int t=mx;
		for(int j=1;j<=n;j++)
			for(int k=0;k<=i*n;k++){
				if(k>=i)mk[j][k]|=mk[j-1][k-i];
				mk[j][k]|=mk[j-1][k];
			}
		while(mk[n][t+1])t++;
		dfs(x+1,i,t);
		memcpy(mk,mk1,sizeof(mk));
	}
}
int main(){
	scanf("%d%d",&n,&m);
	mk[0][0]=1;
	dfs(1,0,0);
	for(int i=1;i<=m;i++)
		printf("%d ",num[i]);
	puts("");
	printf("MAX=%d\n",ans);
	return 0;
}
