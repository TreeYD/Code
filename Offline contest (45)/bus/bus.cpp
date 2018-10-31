#include<bits/stdc++.h>
using namespace std;
#define M 100005
int dep[M],mx[M][20];
struct Node{
	int x,d;
	bool operator<(const Node &A)const{
		return d<A.d;	
	}
};
multiset<Node>S[M];
multiset<Node>::iterator it;
bool mark[M];
struct path{
	int s,t,lca,id;	
}R[M];
vector<path>V[M],D[M];//V for Add D for Del
vector<int>E[M];
map<int,bool>lk[M];
int fa[M][20];
int n,T,m;
void St_Init(){
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}
void Up(int &x,int step){
	for(int i=0;i<=18;i++)
		if(step&(1<<i))x=fa[x][i];	
}
int LCA(int a,int b){
//	puts("------");
//	printf("%d %d\n",a,b);
	if(dep[a]>dep[b])swap(a,b);
	Up(b,dep[b]-dep[a]);
	if(a==b)return a;
//	puts("!");
	for(int i=18;i>=0;i--)
		if(fa[a][i]!=fa[b][i])
			a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		dfs(y,x);
	}
}
void Merge(int x,int y){
	if(S[y].size()>S[x].size())swap(S[x],S[y]);
	for(it=S[y].begin();it!=S[y].end();it++){
		int x=it->x;
		S[x].insert((Node){x,dep[x]});
	}
	S[y].clear();	
}
void redfs(int x,int f){
//	printf("%d %d\n",x,f);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		redfs(y,x);
//		printf("%d->%d\n",y,x);
		Merge(x,y);
	}
	for(int i=0;i<V[x].size();i++){
		int id=V[x][i].id,lca=V[x][i].lca;
//		if(mark[id])continue;
//		mark[id]=1;
		S[x].insert((Node){lca,dep[lca]});	
//		printf("Insert:%d %d\n",lca,dep[lca]);
	}
	if(S[x].size()!=0){
		it=S[x].begin();
		mx[x][0]=it->x;
//		if((it->x)==x)mx[x][0]=-1;
	}else mx[x][0]=-1;
//	puts("erase");
	for(int i=0;i<D[x].size();i++){
		int id=D[x][i].id,lca=D[x][i].lca;
		S[x].erase(S[x].find((Node){lca,dep[lca]}));
		S[x].erase(S[x].find((Node){lca,dep[lca]}));
	}
//	puts("------");
}
void solve(){
	dfs(1,0);
	St_Init();
//	printf("LCA:%d\n",LCA(4,5));
	for(int i=1;i<=T;i++){
		int x=R[i].s,y=R[i].t;
		int lca=LCA(x,y);
//		printf("Add:%d %d %d\n",x,y,lca);
		R[i].lca=lca;
		V[x].push_back((path){x,y,lca,i});
		V[y].push_back((path){x,y,lca,i});
		D[lca].push_back((path){x,y,lca,i});
		if(lca!=x&&lca!=y){
			Up(x,dep[x]-dep[lca]-1);
			Up(y,dep[y]-dep[lca]-1);
			lk[x][y]=lk[y][x]=1;
		}
	}
	redfs(1,0);
}
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ³õÖµ
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024); 
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&T,&m);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i=1;i<=T;i++){
		scanf("%d%d",&x,&y);
		R[i].s=x;R[i].t=y;
	}
	solve();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		int lca=LCA(x,y);
		int ans=0;
		while(x!=lca&&mx[x][0]!=-1&&mx[x][0]!=x&&dep[mx[x][0]]>dep[lca])x=mx[x][0],ans++;
		while(y!=lca&&mx[y][0]!=-1&&mx[y][0]!=y&&dep[mx[y][0]]>dep[lca])y=mx[y][0],ans++;
		if(lca==y&&mx[x][0]!=-1||lca==x&&mx[y][0]!=-1){
			printf("%d\n",ans-1);
			continue;	
		}
		if(mx[x][0]==-1&&mx[x][0]!=lca||mx[y][0]==-1&&mx[y][0]!=lca){
			puts("-1");
			continue;	
		}
		if(mx[x][0]==x&&x!=lca||mx[y][0]==y&&y!=lca){
			puts("-1");
			continue;	
		}
		Up(x,dep[lca]-dep[x]-1);
		Up(y,dep[lca]-dep[y]-1);
		if(lk[x][y])ans++;
		else ans+=2;
		printf("%d\n",ans-1);	
	}
	return 0;
}
