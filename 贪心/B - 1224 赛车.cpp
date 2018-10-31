#include<bits/stdc++.h>
using namespace std;
#define M 100005
vector<int>E[M];
int n,dep[M],ans;
void dfs(int x,int d){
	int fi=0,se=0;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		dfs(y,d+1);
		int t=dep[y]+1;
		dep[x]=max(dep[x],t);
		if(t>fi){
			se=fi;
			fi=t;
		}else if(t>se)se=t;
	}
	ans=max(ans,fi+se+d);
}
int main(){
	scanf("%d",&n);
	int a,b;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		E[a].push_back(b);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
