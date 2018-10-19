#include<bits/stdc++.h>
using namespace std;
#define M 100005
int mxd,ID;
int A[M],num,pos[M],dep[M];
int mx1[M][20],mx2[M][20];
int fa[M],Log[M];
int n,m,mxdep[M];
bool indx[M];
vector<int>E[M];
void St_Init(){
	for(int j=1;j<=19;j++){
		for(int i=1;i+(1<<j)<=n;i++){
			mx1[i][j]=max(mx1[i][j-1],mx1[i+(1<<j-1)][j-1]);
			mx2[i][j]=max(mx2[i][j-1],mx2[i+(1<<j-1)][j-1]);	
		}
	}
}
void Max(int &x,int y){
	if(x<y)x=y;
}
void dfs_init(int x,int f,int d){
	if(d>mxd)mxd=d,ID=x;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		fa[y]=x;
		dfs_init(y,x,d+1);
	}
}
void dfs_col(int x,int ps){
	pos[x]=ps;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(indx[y]||pos[y])continue;
		dep[y]=dep[x]+1;
		fa[y]=x;
		dfs_col(y,ps);
		Max(mxdep[x],mxdep[y]+1);
	}
}
int getL(int L,int R){
	int k=Log[R-L+1];
	return max(mx1[L][k],mx1[R-(1<<k)+1][k]);
}
int getR(int L,int R){
	int k=Log[R-L+1];
	return max(mx2[L][k],mx2[R-(1<<k)+1][k]);
}
void Init(){
	for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
	memset(mx2,-63,sizeof(mx2));
}
int main(){
	int x,y,i;
	scanf("%d",&n);
	Init();
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs_init(1,0,0);
	mxd=0;
	int e=ID;
	dfs_init(ID,0,0);
	x=ID;
	while(x!=e){
		A[++num]=x;
		indx[x]=1;
		x=fa[x];
	}
	A[++num]=x;
	indx[x]=1;
	for(i=1;i<=num;i++){
		dfs_col(A[i],i);
		mx1[i][0]=mxdep[A[i]]+pos[A[i]]-1;
		mx2[i][0]=mxdep[A[i]]+num-pos[A[i]];
	}
	St_Init();
	scanf("%d",&m);
	int a,b;
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(pos[a]>pos[b])swap(a,b);
		x=pos[a],y=pos[b];
		int ans;
		ans=max(min(x-1+dep[a],y-1+dep[b]),min(num-y+dep[b],num-x+dep[a]));
		int mid=((dep[a]+y-x+dep[b])>>1)+x-dep[a];
		if(mid<x)mid=x;
		if(mid>y)mid=y;
		if(x+1<=mid)Max(ans,getL(x+1,mid)-(x-1)+dep[a]);
		if(y-1>mid)Max(ans,getR(mid+1,y-1)-(num-y)+dep[b]);
		printf("%d\n",ans);
	}
	return 0;
}
