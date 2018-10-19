#include<bits/stdc++.h>
using namespace std;
#define M 100005
int to[M],in[M],n,ans;
bool vis[M];
void dfs(int x,bool flag){
	if(vis[x])return;
	vis[x]=1;ans+=flag;
	in[to[x]]--;
	if(!in[to[x]]||flag)dfs(to[x],!flag);
}
int main(){
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&to[i]);
		in[to[i]]++;
	}
	for(i=1;i<=n;i++)
		if(!in[i])dfs(i,1);
	for(i=1;i<=n;i++)dfs(i,1);
	printf("%d\n",ans);
	return 0;
}
