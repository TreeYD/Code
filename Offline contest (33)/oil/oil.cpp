#include<bits/stdc++.h>
using namespace std;
#define M 1505
int mp[M][M],sum[M][M];
struct node{
	int x,y,v;
	bool operator<(const node &x)const{
		return v>x.v;
	}
}A[M*M];
int n,m,K;
bool check(int a,int b){
	int xa=A[a].x,ya=A[a].y,xb=A[b].x,yb=A[b].y;
	if(xa+K-1>=xb&&xa<=xb){
		if(ya<=yb&&ya+K-1>=yb||ya>=yb&&ya<=yb+K-1)return 1;
	}
	if(xa<=xb+K-1&&xa>=xb){
		if(ya<=yb&&ya+K-1>=yb||ya>=yb&&yb+K-1>=ya)return 1;
	}
	return 0;
}
int main(){//name long long memory mod
	freopen("oil2.in","r",stdin);
//	freopen("oil.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			sum[i][j]+=sum[i][j-1]+mp[i][j];
		}
		for(int j=1;j<=m;j++)
			sum[i][j]+=sum[i-1][j];
	}
	int cnt=0;
	for(int i=1;i<=n-K+1;i++)
		for(int j=1;j<=m-K+1;j++)
			A[++cnt]=(node){i,j,sum[i+K-1][j+K-1]+sum[i-1][j-1]-sum[i+K-1][j-1]-sum[i-1][j+K-1]};
	sort(A+1,A+1+cnt);
	int ans=0;
	for(int i=1;i<cnt-1;i++){
		if(A[i].v+A[i+1].v+A[i+2].v<=ans)break;
		for(int j=i+1;j<cnt;j++){
			if(A[i].v+A[j].v+A[j+1].v<=ans)break;
			if(check(i,j))continue;
			for(int k=j+1;k<=cnt;k++){
				if(A[i].v+A[j].v+A[k].v<=ans)break;
				if(check(i,k)||check(j,k))continue;
				ans=A[i].v+A[j].v+A[k].v;
//				printf("%d %d %d %d\n",i,j,k,ans);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
