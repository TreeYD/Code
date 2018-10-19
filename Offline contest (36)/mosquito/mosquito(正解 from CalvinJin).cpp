#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define LL long long
const int P=1e9+7;
template<class T>void Add(T &x,T y){
	x+=y;
	if(x>=P)x-=P;
	if(x<0)x+=P;
}
int dp[M],Q,D,n;
int d,p,q,sz[M];
LL Res;
int Pow[M<<1],InvP[M<<1];
struct edge{
	int to,nxt;
}E[M<<1];
int head[M],tot_e;
void Add_edge(int u,int v){
	E[++tot_e].nxt=head[u];
	E[tot_e].to=v;
	head[u]=tot_e;
}
LL Fast(LL a,LL b){
	LL base=a,ans=1;
	while(b){
		if(b&1)ans=ans*base%P;
		base=base*base%P;
		b>>=1;
	}
	return ans;
}
void Init(){
	Pow[0]=InvP[0]=1;
	Q=1LL*(q-p)*Fast(q,P-2)%P;
	int inv=Fast(Q,P-2);
	for(int i=1;i<2*n;i++){
		Pow[i]=1LL*Pow[i-1]*Q%P;
		InvP[i]=1LL*InvP[i-1]*inv%P;
	}
}
void dfs(int x,int f,int d){
	int son=0;
	for(int i=head[x];i;i=E[i].nxt){
		int y=E[i].to;
		if(y==f)continue;
		dfs(y,x,d+1);
		son++;
		if(d<=D)Add(Res,(1LL*sz[y]*sz[x]%P-1LL*Q*dp[x]%P*dp[y]%P*InvP[d*2]%P)%P);
		Add(dp[x],dp[y]);
		sz[x]+=sz[y];
	}
	if(!son){
		sz[x]=1;
		dp[x]=Pow[min(d,D)];
	}
}
int main(){
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		Add_edge(x,y);
		Add_edge(y,x);
	}
	scanf("%d%d%d",&D,&p,&q);
	Init();
	dfs(1,0,0);
	printf("%lld\n",2*Res%P);
	return 0;
}
