#include<bits/stdc++.h>
using namespace std;
#define M 100005
vector<int>E[M];
int n,m;
struct P30{
	#define N 2005
	int get[N][N],rt;
	void dfs(int x,int f){
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			get[y][rt]=get[x][rt]+1;
			dfs(y,x);
		}
	}
	void solve(){
		for(rt=1;rt<=n;rt++)dfs(rt,0);
		int x,y,i,j;
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			int ans=0;
			for(j=1;j<=n;j++)
				ans=max(ans,min(get[j][x],get[j][y]));
			printf("%d\n",ans);
		}
	}
}p30;
struct Pchain{
	int mp[M];
	bool Init(){
		int rt,sz=0,i;
		for(i=1;i<=n;i++)
			if(E[i].size()==1){
				rt=i;
				break;
			}
		int x=rt,f=0;
		while(1){
			if(E[x].size()>2)return 0;
			mp[x]=++sz;
			if(E[x][0]==f&&E[x].size()==1)break;
			if(E[x][0]==f){
				f=x; 
				x=E[x][1];
			}else{
				f=x;
				x=E[x][0];
			}
		}
		return 1;
	}
	void solve(){
		int x,y,i;
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			x=mp[x],y=mp[y];
			if(x>y)swap(x,y);
			int mid=x+y>>1;
			printf("%d\n",max(max(x-1,n-y),min(mid-x,y-mid)));
		}
	}
}pchain;
struct P70{
	int fa[M][20],dep[M];
	int fi[M][2],se[M][2];//1 refers to node 0 refers to val
	void Up(int x,int y,int v){
		if(fi[x][0]<v+1){
			se[x][0]=fi[x][0];
			se[x][1]=fi[x][1];
			fi[x][0]=v+1;
			fi[x][1]=y;
		}else if(se[x][0]<v+1)se[x][0]=v+1,se[x][1]=y;;
	}
	void dfs(int x,int f){
		fa[x][0]=f;
		dep[x]=dep[f]+1;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x);
			Up(x,y,fi[y][0]);
		}
	}
	void Init(){
		for(int j=1;j<=19;j++)
			for(int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	void solve(){
		dfs(1,0);
		Init();
		int x,y,i,j;
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(x==1)x=y;
			y=fa[x][0];
			for(j=19;j>=0;j--)
				if(fa[y][j]!=1&&fa[y][j]!=0)
					y=fa[y][j];
			if(y!=1){
				int v1=(fi[1][1]==y)?se[1][0]:fi[1][0],v2=fi[x][0]; 
				int v3=(fi[fa[x][0]][1]==x)?se[fa[x][0]][0]:fi[fa[x][0]][0];
				int mid=(1+dep[fa[x][0]])>>1,v4;
				if((1+dep[fa[x][0]])%2==0){
					v4=mid-1;
				}else v4=mid;
				printf("%d\n",max(v4,max(v1,max(v2,v3+1))));
			}else{
				int v1=(fi[1][1]==x)?se[1][0]:fi[1][0],v2=fi[x][0];
				printf("%d\n",max(v1,v2));
			}
		}
	}
}p70;
int main(){//name long long memory mod ¸ºÊý 
	freopen("data.in","r",stdin);
	freopen("check.out","w",stdout);
	scanf("%d",&n);
	int x,y,i;
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	scanf("%d",&m);
	if(n<=2000)p30.solve();
	else if(pchain.Init())pchain.solve();
	else p70.solve();
	return 0;
}
