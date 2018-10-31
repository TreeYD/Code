#include<bits/stdc++.h>
using namespace std;
const int M=805,MM=M*M;
int rx[]={0,1,0,-1};
int ry[]={1,0,-1,0};
int to[M][M],n,S;
char mp[M][M];
bool check(int x,int y){
	if(x<1||y<1||x>n||y>n)return 0;
	if(mp[x][y]=='T'||mp[x][y]=='H'||mp[x][y]=='D')return 0;
	return 1;
}
int Qx[MM],Qy[MM];	
void Init(){
	int L=1,R=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='H'){
				Qx[++R]=i;
				Qy[R]=j;
				to[i][j]=0;
			}else to[i][j]=-1;
		}
	while(L<=R){
		int x=Qx[L],y=Qy[L++];
		for(int i=0;i<4;i++){
			int nx=x+rx[i],ny=y+ry[i];
			if(check(nx,ny)&&to[nx][ny]==-1){
				to[nx][ny]=to[x][y]+1;
				Qx[++R]=nx,Qy[R]=ny;
			}
		}
	}
}
struct Node{
	int x,y,t,r;
}Q[MM];
bool vis[M][M];
bool Check(int tim){
	int L=1,R=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='M'){
				Q[++R]=(Node){i,j,tim,S};
				vis[i][j]=1;
			}else vis[i][j]=0;
		}
	while(L<=R){
		int x=Q[L].x,y=Q[L].y;
		if(mp[x][y]=='D')return 1;
		if(to[x][y]<=Q[L].t){
			L++;continue;
		}
		int nt=Q[L].t,nr=Q[L].r;
		if(nr==1)nt++,nr=S;
		else nr--;
		for(int i=0;i<4;i++){
			int nx=x+rx[i],ny=y+ry[i];
			if((check(nx,ny)&&!vis[nx][ny])||mp[nx][ny]=='D'){
				vis[nx][ny]=1;
				Q[++R]=(Node){nx,ny,nt,nr};
			}
		}
		L++;
	}
	return 0;
}
void Find(){
	int L=0,R=n*n,ans=-1;
	while(L<=R){
		int mid=L+R>>1;
		if(Check(mid)){
			ans=mid;
			L=mid+1;
		}else R=mid-1;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&S);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	Init();
	Find();
	return 0;
}
