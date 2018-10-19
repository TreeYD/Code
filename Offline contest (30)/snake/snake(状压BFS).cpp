#include<bits/stdc++.h>
using namespace std;
#define M 25
#define MM 405
int rx[]={0,1,0,-1};
int ry[]={1,0,-1,0};
int Astar[M][M],Hx,Hy,n,m,K,e;
bool vis[M][M],mark[M][M][(1<<14)+5];
bool stone[M][M];
struct node{char x,y;};
struct Node{
	char Hx,Hy,step;
	short body,h;
	bool operator<(const Node &x)const{
		return step+h>x.step+x.h;
	}
};
priority_queue<Node>Q;
bool check(int x,int y){
	return x<1||y<1||x>n||y>m||stone[x][y];
}
bool Getnxt(Node &s,int d){
	int nx=s.Hx+rx[d],ny=s.Hy+ry[d];
	if(check(nx,ny))return 0;
	int x=s.Hx,y=s.Hy,st=s.body;
	for(int i=0;i<K-1;i++){
		int t=st&3;
		x-=rx[t],y-=ry[t];
		if(nx==x&&ny==y)return 0;
		st>>=2;
	}
	st=s.body;
	st=(((st<<2))|d)&e;
	s.Hx=nx,s.Hy=ny;
	if(mark[nx][ny][st])return 0;
	mark[nx][ny][st]=1;
	s.step++;
	s.body=st;
	s.h=Astar[nx][ny];
	return 1;
}
int BFS(Node begin){
	Q.push(begin);
	while(!Q.empty()){
		Node now=Q.top(),nxt;Q.pop();
		if(now.Hx==1&&now.Hy==1)return now.step;
		for(int i=0;i<4;i++){
			nxt=now;
			if(Getnxt(nxt,i))
				Q.push(nxt);
		}
	}
	return -1;
}
void InitAstar(){
	int q[MM][2];
	int L=0,R=0;
	q[L][0]=1;
	q[L++][1]=1;
	Astar[1][1]=0;
	while(L<=R){
		int x=q[L][0],y=q[L++][1];
		for(int i=0;i<4;i++){
			int nx=x+rx[i],ny=y+ry[i];
			if(!check(nx,ny)&&!vis[nx][ny]){
				Astar[nx][ny]=Astar[x][y]+1;
				q[++R][0]=nx;q[R][1]=ny;
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	scanf("%d%d",&Hx,&Hy);
	int st=0,x,y,lx=Hx,ly=Hy;
	e=(1<<(2*(K-1)))-1;
	for(int i=0;i<K-1;i++){
		scanf("%d%d",&x,&y);
		for(int j=0;j<4;j++){
			if(lx-rx[j]==x&&ly-ry[j]==y){
				st|=(j<<(i*2));
				break;
			}
		}
		lx=x,ly=y;
	}
	int Sz;
	scanf("%d",&Sz);
	for(int i=1;i<=Sz;i++){
		scanf("%d%d",&x,&y);
		stone[x][y]=1;
	}
	InitAstar();
	printf("%d\n",BFS((Node){Hx,Hy,0,st}));
	return 0;
}
