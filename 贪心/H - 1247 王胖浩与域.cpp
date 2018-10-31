#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define LL long long
#define calc(x) (n-sz[x])*sz[x]
template<class T>void Min(T &x,T y){if(x>y)x=y;}
int fi[M],se[M],n;
LL sz[M],up[M],all[M];
LL down[M],ans[M];
vector<int>E[M];
void dfs(int x,int f){
	sz[x]=1;
	LL tmp=0;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		dfs(y,x);
		down[x]+=down[y];
		down[x]+=calc(y);
		if(sz[y]>sz[fi[x]]){
			se[x]=fi[x];	
			fi[x]=y;
		}else if(sz[y]>sz[se[x]])se[x]=y;
		sz[x]+=sz[y];
	}
	all[x]=down[x];
	down[x]-=calc(fi[x]);
}
void redfs(int x,int f){
	ans[x]=down[x]+up[x]+calc(x);
	Min(ans[x],all[x]+up[x]);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		int choose=(y==fi[x])?se[x]:fi[x];
		if(n-sz[x]>sz[choose]){
			up[y]=up[x];
			up[y]+=all[x]-calc(y)-down[y];
		}else{
			up[y]=up[x]+calc(x);
			up[y]+=all[x]-calc(y)-down[y]-calc(choose);
		}
		redfs(y,x);		
	}
}
int main(){
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1,0);
	redfs(1,0);
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	return 0;	
}
