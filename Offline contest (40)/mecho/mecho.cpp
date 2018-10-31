#include<bits/stdc++.h>
using namespace std;
#define M 805
const int MM=M*M;
int rx[]={0,-1,0,1};
int ry[]={1,0,-1,0};
char mp[M][M];
int mark[M][M];
struct node{
	int x,y,res,tim;
}Q[MM];
bool vis[M][M];
int Qx[MM],Qy[MM];
int n,S,dfn,Lx,Rx;
int L,R;
bool check(int x,int y){
	if(x<1||y<1||x>n||y>n)return 0;
	if(mark[x][y]!=-1||mp[x][y]=='H'||mp[x][y]=='D'||mp[x][y]=='T')return 0;
	return 1;
}
void get(){
	dfn++;
	while(Lx<=Rx){
		int x=Qx[Lx],y=Qy[Lx];
		if(mark[x][y]==dfn)break;
		for(int i=0;i<4;i++){
			int nx=x+rx[i];
			int ny=y+ry[i];
			if(check(nx,ny)){
				mark[nx][ny]=dfn;
				Qx[++Rx]=nx;
				Qy[Rx]=ny;
			}
		}
		Lx++;
	}
}
bool solve(int x){
	Lx=1,Rx=0;dfn=0;
	L=1,R=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='H'){
				vis[i][j]=0;
				Qx[++Rx]=i;
				Qy[Rx]=j;
				mark[i][j]=dfn;
			}else {
				mark[i][j]=-1;vis[i][j]=0;
				if(mp[i][j]=='M'){
					vis[i][j]=1;
					Q[++R]=(node){i,j,S,x};
				}
			}
		}
	for(int i=1;i<=x;i++)get();
	while(L<=R){
		int x=Q[L].x,y=Q[L].y;
		if(mp[x][y]=='D')return 1;
		if(Q[L].tim>dfn)get();
		if(mark[x][y]!=-1){
			L++;continue;
		}
		for(int i=0;i<4;i++){
			int nx=x+rx[i],ny=y+ry[i];
			if(mp[nx][ny]=='D'||check(nx,ny)){
				if(vis[nx][ny])continue;
				int nt=Q[L].tim,nr=Q[L].res;
				if(mp[nx][ny]=='D')return 1;
				if(nr==1){
					nr=S;nt++;
				}else nr--;
				vis[nx][ny]=1;
				Q[++R]=(node){nx,ny,nr,nt};
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
		if(solve(mid)){
			L=mid+1;
			ans=mid;
		}else R=mid-1;
	}
	printf("%d\n",ans);
}
int main(){//name memory long long * mod - «–∑÷≈–∂œ ≥ı÷µ
//	freopen("mecho.in","r",stdin);
//	freopen("mecho.out","w",stdout); 
	scanf("%d%d",&n,&S);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	Find();
	return 0;
}
