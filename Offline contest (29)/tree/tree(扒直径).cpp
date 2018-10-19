#include<bits/stdc++.h>
using namespace std;
#define M 100005
int mxd,ID,dis1[M],dis2[M];
int A[M],num,pos[M],dep[M];
int mx1[M][20],mx2[M][20];
int fa[M],Log[M];
int n,m,mxdep[M];
bool indx[M];
vector<int>E[M];
void St_Init(){
	for(int j=1;j<=19;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
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
//	printf("to:%d\n",x);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		fa[y]=x;
		dfs_init(y,x,d+1);
	}
}
void dfs_col(int x,int ps){
	pos[x]=ps;
//	printf("%d->%d\n",x,ps);
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
	if(L>R)return L-1;
//	if(L==R)return L-1;
	int k=Log[R-L+1];
	return max(mx1[L][k],mx1[R-(1<<k)+1][k]);
}
int getR(int L,int R){
	if(L>R)return -R-1;
//	if(L==R)return -R+1;
	int k=Log[R-L+1];
	return max(mx2[L][k],mx2[R-(1<<k)+1][k]);
}
void Init(){
	for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
	memset(mx2,-63,sizeof(mx2));
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("pro.out","w",stdout);
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
//		printf("Dx:%d\n",x);
		dis1[x]=num-1;
		x=fa[x];
	}
	A[++num]=x;
	indx[x]=1;
//	printf("%d\n",mx2[1][0]);
	for(i=1;i<=num;i++){
		dfs_col(A[i],i);
		dis2[A[i]]=num-i;
		mx1[i][0]=mxdep[A[i]]+pos[A[i]];
		mx2[i][0]=mxdep[A[i]]-pos[A[i]];
//		printf("%d\n",A[i]);
	}
	St_Init();
	scanf("%d",&m);
	int a,b;
//	printf("getL(1,2):%d\n",getL(1,2));
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(pos[a]>pos[b])swap(a,b);
		x=A[pos[a]],y=A[pos[b]];
		int ans;
//		printf("%d %d\n",a,b);
//		printf("%d %d\n",pos[x],pos[y]);
		if(x!=y){
			ans=max(dis1[x]+dep[a],dis2[y]+dep[b]);
			int mid=pos[a]+pos[b]>>1;
//			printf("val1:%d\n",ans);
//printf("A");
			if((pos[a]+pos[b])%2!=0)
				Max(ans,max(getL(pos[a]+1,mid)-pos[a]+dep[a],getR(mid+1,pos[b]-1)+pos[b]+dep[b]));
			else Max(ans,max(max(getL(pos[a]+1,mid-1)-pos[a]+dep[a],getR(mid+1,pos[b]-1)+pos[b]+dep[b]),mxdep[A[mid]]+mid-pos[a]+min(dep[a],dep[b])));
//			printf("L:%d\n",getL(pos[a]+1,mid));
//			printf("R:%d\n",getR(mid+1,pos[b]-1));
		}else{
			ans=max(dis1[x],dis2[x])+min(dep[a],dep[b]);
//			printf("B");
		}
		printf("%d\n",ans);
	}
	return 0;
}
