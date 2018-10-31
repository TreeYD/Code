#include<bits/stdc++.h>
using namespace std;
#define M 100005
int dfn[M],T,tim,n;
int fa[M][20];
bool mark[M];
struct Node{
	int x;
	bool operator<(const Node &A)const{
		return dfn[x]>dfn[A.x];
	}
};
priority_queue<Node>Q;
vector<int>E[M] ;
void dfs(int x,int f){
	sort(E[x].begin(),E[x].end());
//	dfn[x]=++T;
	fa[x][0]=f;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		dfs(y,x);
	}
	dfn[x]=++T;
	Q.push((Node){x});
}
void St_Init(){
	for(int j=1;j<=17;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}
void solve(){
	int op,x;
	for(int i=1;i<=tim;i++){
		scanf("%d%d",&op,&x);
		if(op==1){
			int now;
			for(int j=1;j<=x;j++){
				now=Q.top().x;
				Q.pop();
				mark[now]=1;
			}
			printf("%d\n",now);
		}else{
			int cnt=0;
			for(int j=17;j>=0;j--)
				if(mark[fa[x][j]]){
					x=fa[x][j];
					cnt+=(1<<j);
				}
			mark[x]=0;
			Q.push((Node){x});
			printf("%d\n",cnt);
		}
	}
}
int main(){
	scanf("%d%d",&n,&tim);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);	
	}
	dfs(1,0);
	St_Init();
	solve();
	return 0;
}
