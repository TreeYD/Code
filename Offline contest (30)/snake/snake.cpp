#include<bits/stdc++.h>
using namespace std;
#define M 25
#define MM 405
const int P=1e9+7;
bool mark[M][M];
int can[M][M];
bool stn[M][M];
int n,m,b,K;
int s,t,mxd;
struct Block{
	int x,y,pre,nxt;
}A[MM];
int rx[]={0,-1,0,1};
int ry[]={1,0,-1,0};
int ID(int x,int y){
	return (x-1)*m+y;
}
map<int,long long>Hs[MM][MM];
int V(){
	int num=s,cnt=0;
	long long res=0;
	while(num!=0&&cnt<K){
		res=(res*500+num)%P;
		num=A[num].nxt;
		cnt++;
	}
	return res;
}
int H(){
	return A[s].x-1+A[s].y-1;
}
bool dfs1(int x,int y){
	bool res=0;
	can[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+rx[i],ny=y+ry[i];
		if(nx<1||ny<1||nx>n||ny>m)continue;
		if(!stn[nx][ny]&&!can[nx][ny])
			dfs1(nx,ny);
	}
}
bool dfs(int step){
	if(step+H()>mxd)return 0;
	if(A[s].x==1&&A[s].y==1)return 1;
	int v=V();
	if(Hs[step][mxd][v])return 0;
	Hs[step][mxd][v]=1;
	bool ans=0;
	for(int i=0;i<4&&!ans;i++){
		int nx=A[s].x+rx[i],ny=A[s].y+ry[i];
		if(nx<1||ny<1||nx>n||ny>m||mark[nx][ny])continue;
		int t1=s,t2=t;
		s=ID(nx,ny);
		mark[nx][ny]=1;
		A[s].nxt=t1;A[t1].pre=s;
		mark[A[t].x][A[t].y]=0;
		t=A[t].pre;
		A[A[t].nxt].pre=0;
		A[t].nxt=0;
		ans|=dfs(step+1);
		mark[nx][ny]=0;
		A[t1].pre=0;
		A[t].nxt=t2;
		A[t2].pre=t;
		s=t1,t=t2;
		mark[A[t].x][A[t].y]=1;
	}
	return ans;
}
int main(){//name long long memory mod
//	freopen("snake.in","r",stdin);
//	freopen("snake.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	int x,y,i,j,lstx=1,lsty=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			int id=ID(i,j);
			A[id].x=i;
			A[id].y=j;
		}
	for(i=1;i<=K;i++){
		scanf("%d%d",&x,&y);
		A[ID(x,y)].pre=ID(lstx,lsty);
		A[ID(lstx,lsty)].nxt=ID(x,y);
		mark[x][y]=1;
		lstx=x,lsty=y;
		if(i==1)s=ID(x,y);
		if(i==K)t=ID(x,y);
	}
	scanf("%d",&b);
	for(i=1;i<=b;i++){
		scanf("%d%d",&x,&y);
		mark[x][y]=1;
		stn[x][y]=1;
	}
	dfs1(1,1);
	bool flag=0;
	if(!can[A[s].x][A[s].y]){
		puts("-1");
		return 0;
	}
	for(mxd=0;mxd<=n*m;mxd++){
		if(dfs(0)){
			flag=1;
			break;
		}
	}
	if(flag==0)puts("-1");
	else printf("%d\n",mxd);
	return 0;
}
