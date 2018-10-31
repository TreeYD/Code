#include<bits/stdc++.h>
using namespace std;
#define M 100005
int fa[M],n,T;
vector<int>Tmp[M];
set<int>E[M];
void dfs(int x,int f){
	fa[x]=f;
	for(int i=0;i<Tmp[x].size();i++){
		int y=Tmp[x][i];
		if(y==f)continue;
		E[x].insert(y);
		dfs(y,x);
	}
}
struct P1{//n<=2000&&t<=2000 || 树是随机造的 
	bool mark[M];
	void solve(){
		dfs(1,0);
		int op,x;
		for(int i=1;i<=T;i++){
			scanf("%d%d",&op,&x);
			if(op==1){
				int now;
				for(int j=1;j<=x;j++){
					now=1;
					while(E[now].size())
						now=*E[now].begin();
					mark[now]=1;
					int f=fa[now];
					E[f].erase(now);
				}
				printf("%d\n",now);
			}else{
				int cnt=0;
				while(mark[fa[x]]){
					x=fa[x];
					cnt++;
				}
				E[fa[x]].insert(x);
				mark[x]=0;
				printf("%d\n",cnt);
			}
		}
	}
}p1;
int main(){//name memory long long * mod - 切分判断 极值
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
//	freopen("queue2.in","r",stdin);
//	freopen("queue.out","w",stdout);
	scanf("%d%d",&n,&T);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		Tmp[x].push_back(y);
		Tmp[y].push_back(x);	
	}
	p1.solve();
	return 0;	
}
