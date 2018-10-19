#include<bits/stdc++.h>
using namespace std;
#define M 100005
int n,m,K,P;
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),c>'9'||c<'0');
	do{
		res=(res<<3)+(res<<1)+(c^48);
	}while(c=getchar(),c>='0'&&c<='9');
}
struct edge{
	int to,cost;
};
vector<edge>E[M];
void Add(int &x,int y){
	x+=y;
	if(x>=P)x-=P;
}
int cnt[M][51],dis[M][51];
int tmp1[51],tmp2[51];
int Q[M];
bool vis[M];
void SPFA(){
	int L=0,R=0;
	memset(dis,63,sizeof(dis));
	dis[1][1]=vis[1]=0;
	cnt[1][1]=1;
	Q[R++]=1;
	while(L!=R){
		int x=Q[L];
		L++;if(L>=100000)L=0;
		vis[x]=0;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i].to,z=E[x][i].cost;
			int k1=1,k2=1,k3=0,flag=0,j;
			for(j=0;j<=K;j++)tmp1[j]=tmp2[j]=0;
			while(k3<K&&cnt[x][k1]!=0&&cnt[y][k2]!=0){
				int a=dis[x][k1]+z,b=dis[y][k2];
				if(a<b){
					if(tmp1[k3]!=a){
						tmp1[++k3]=a;
						flag=1;
						tmp2[k3]=cnt[x][k1];
					}else Add(tmp2[k3],cnt[x][k1]);
					k1++;
				}else{
					if(tmp1[k3]!=b){
						tmp1[++k3]=b;
						tmp2[k3]=cnt[y][k2];
					}else Add(tmp2[k3],cnt[y][k2]);
					k2++;
				}
			}
			while(cnt[x][k1]!=0){
				int a=dis[x][k1]+z;
				if(tmp1[k3]!=a){
					tmp1[++k3]=a;
					flag=1;
					tmp2[k3]=cnt[x][k1];
				}else Add(tmp2[k3],cnt[x][k1]);
				k1++;
				if(k3>=K)break;
			}
			while(cnt[y][k2]!=0){
				int b=dis[y][k2];
				if(tmp1[k3]!=b){
			  		tmp1[++k3]=b;
					tmp2[k3]=cnt[y][k2];
				}else Add(tmp2[k3],cnt[y][k2]);
				k2++;
				if(k3>=K)break;
			}
//			printf("%d->%d\n",x,y);
			for(j=1;j<=min(k3,K);j++){
				dis[y][j]=tmp1[j];
				cnt[y][j]=tmp2[j];
//				printf("dis:%d cnt:%d\n",dis[y][j],cnt[y][j]);
			}
			if(flag){
				if(!vis[y]){
					Q[R]=y;
					vis[y]=1;
					R++;
					if(R==100000)R=0;
				}
			}
		}
		if(x!=n){
			for(int i=1;i<=K;i++)cnt[x][i]=0,dis[x][i]=1e9;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&K,&P);
		int x,y,z,i;
		for(i=1;i<=m;i++){
			Rd(x);Rd(y);Rd(z);
			E[x].push_back((edge){y,z});
		}
		SPFA();
		int ans=0;
		bool flag=1;
		for(i=1;i<=K;i++){
			if(dis[n][i]<=dis[n][1]+K){
				Add(ans,cnt[n][i]);
				if(dis[n][i]!=0)flag=0;
			}else break;
		}
		if(flag)ans=-1;
		printf("%d\n",ans);
		for(i=1;i<=n;i++)E[i].clear();
	}
}
