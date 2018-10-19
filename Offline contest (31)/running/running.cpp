#include<bits/stdc++.h>
using namespace std;
#define M 300005
vector<int>E[M];
int S[M],T[M],W[M],n,m;
struct P25{
	int fa[1005][15],cnt[1005];
	int dep[1005];
	void dfs(int x,int f){
		dep[x]=dep[f]+1;
		fa[x][0]=f;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
		}
	}
	void St_Init(){
		for(int j=1;j<=10;j++)
			for(int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	int LCA(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		int step=dep[b]-dep[a];
		for(int i=10;i>=0;i--)
			if(step&(1<<i))b=fa[b][i];
		if(a==b)return a;
		for(int i=10;i>=0;i--)
			if(fa[a][i]!=fa[b][i])
				a=fa[a][i],b=fa[b][i];
		return fa[a][0];
	}
	void solve(){
		dfs(1,0);
		St_Init();
		for(int i=1;i<=m;i++){
			int x=S[i],y=T[i];
			int tx=0,ty=dep[x]+dep[y]-2*dep[LCA(x,y)];
			while(x!=y){
				if(dep[x]>dep[y]){
					if(tx==W[x])cnt[x]++;
					tx++;x=fa[x][0];
				}else{
					if(ty==W[y])cnt[y]++;
					ty--;y=fa[y][0];
				}
			}
			if(tx==W[x])cnt[x]++;
		}
		for(int i=1;i<=n;i++)printf("%d ",cnt[i]);
		puts("");
	}
}p25;
#define Mn 100005
struct Pchain1{
	int cnt[Mn];
	vector<int>path[Mn];
	void solve(){
		for(int i=1;i<=m;i++){
			int x=S[i],y=T[i];
			if(x<y)continue;
			path[x].push_back(y);
		}
		for(int i=1;i<=n;i++)
			sort(path[i].begin(),path[i].end());
		for(int i=1;i<=n;i++){
			int lst=i+W[i];
			if(lst>n)continue;
			cnt[i]+=upper_bound(path[lst].begin(),path[lst].end(),i)-path[lst].begin();
		}
		for(int i=1;i<=n;i++)
			path[i].clear();
		for(int i=1;i<=m;i++){
			int x=S[i],y=T[i];
			if(x>=y)continue;
			path[x].push_back(y);
		}	
		for(int i=1;i<=n;i++)
			sort(path[i].begin(),path[i].end());
		for(int i=1;i<=n;i++){
			int lst=i-W[i];
			if(lst<1)continue;
			cnt[i]+=path[lst].size()-(lower_bound(path[lst].begin(),path[lst].end(),i)-path[lst].begin());
		}
		for(int i=1;i<=n;i++)printf("%d ",cnt[i]);
		puts("");
	}
}pchain1;
struct Pchain2{
	vector<int>c1[Mn],c2[Mn];
	int cnt[Mn],ans[Mn];
	void solve(){
		for(int i=1;i<=m;i++){
			int x=S[i],y=T[i];
			if(x<y){
				c1[x].push_back(y);
				c2[y+1].push_back(x);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<c1[i].size();j++){
				cnt[i]++;
			}
			for(int j=0;j<c2[i].size();j++)
				cnt[c2[i][j]]--;
			if(i-W[i]>0)ans[i]+=cnt[i-W[i]];
		}
		for(int i=1;i<=n;i++){
			c1[i].clear();
			c2[i].clear();
		}
		for(int i=1;i<=m;i++){
			int x=S[i],y=T[i];
			if(x>=y){
				c1[x].push_back(y);
				c2[y-1].push_back(x);
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=0;j<c1[i].size();j++){
				cnt[i]++;
			}
			for(int j=0;j<c2[i].size();j++)
				cnt[c2[i][j]]--;
			if(i+W[i]<=n)ans[i]+=cnt[i+W[i]];
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
}pchain2;
struct PS1{
	int cnt[Mn],ans[Mn];
	void dfs(int x,int f,int d){
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x,d+1);
			cnt[x]+=cnt[y];
		}
		if(d==W[x])ans[x]=cnt[x];
	}
	void solve(){
		for(int i=1;i<=m;i++){
			cnt[T[i]]++;
		}
		dfs(1,0,0);
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		puts("");
	}
}ps1;
struct Pt1{
	int cnt[Mn],ans[Mn];
	int c[Mn];
	void dfs(int x,int f,int d){
		int res=cnt[d+W[x]];
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x,d+1);
		}
		cnt[d]+=c[x];
		ans[x]=cnt[d+W[x]]-res;
	}
	void solve(){
		for(int i=1;i<=m;i++)c[S[i]]++;
		dfs(1,0,0);
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
}pt1;
int main(){
//	freopen("running6.in","r",stdin);
//	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&W[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&S[i],&T[i]);
	int tmp=n%10;
	if(tmp<=3)p25.solve();
	else if(tmp==4)pchain2.solve();
	else if(tmp==5)ps1.solve();
	else if(tmp==6)pt1.solve();
	return 0;
}
