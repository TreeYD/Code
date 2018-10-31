#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define N 200005
#define Inf 0x7f7f7f7f
const int Mod=200000;
int A[M],B[M];
int n,m;
struct edge{
	int to,nxt,cost;
}E[N+M<<1];
int head[N],e_tot;
void Add(int u,int v,int w){
	E[++e_tot].to=v;
	E[e_tot].nxt=head[u];
	E[e_tot].cost=w;
	head[u]=e_tot;
}
int dis[N],cnt[N];
int Q[N];
bool inq[N];
void Spfa(){
	int L=0,R=0;
	for(int i=1;i<=n;i++)
		dis[i]=Inf;
	dis[0]=0;
	Q[R++]=0;
	inq[0]=1;
	while(L!=R){
		int x=Q[L++];
		if(L==Mod)L=0;
		cnt[x]++;
		inq[x]=0;
		if(cnt[x]==n+1){
			puts("-1");
			return;
		}
		for(int i=head[x];i;i=E[i].nxt){
			int y=E[i].to,z=E[i].cost;
			if(dis[x]+z<dis[y]){
				dis[y]=dis[x]+z;
				if(!inq[y]){
					inq[y]=1;
					Q[R++]=y;
					if(R==Mod)R=0;
				}
			}
		}
	}
	printf("%d\n",dis[n]);//±íÊ¾sum[n]-sum[0]<=dis[n] 
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&A[i],&B[i]);
		Add(A[i]-1,B[i],1);
		Add(B[i],A[i]-1,-1);
	}
	for(int i=0;i<n;i++){
		Add(i+1,i,0);
		Add(i,i+1,1);
	}
	Spfa();
	return 0;
}
