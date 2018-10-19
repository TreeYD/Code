#include<bits/stdc++.h>
using namespace std;
#define M 305
int sum[M][M],mp[M][M];
int n,m;
struct P100{
	#define calc(i,j,x) sum[j-1][x]-sum[j-1][x-1]-sum[i][x]+sum[i][x-1]
	long long cnt[3*M*M];
	int stk[M],top,val[M];
	void solve(){
		long long ans=0;
		int add=n*m;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int h=j-i-1,tmp=ans;
				for(int k=1;k<=m;k++){
					if(!mp[i][k]||!mp[j][k])
						while(top)cnt[stk[top]+add]--,top--;
					val[k]=val[k-1]+calc(i,j,k);
					if(mp[i][k]&&mp[j][k]&&calc(i,j,k)==j-i-1){
						ans+=cnt[2*val[k-1]-(k-1)*h-1+add];
						ans+=cnt[2*val[k-1]-(k-1)*h+1+add];
						ans+=cnt[2*val[k-1]-(k-1)*h+add];
						cnt[2*val[k]-h*k+add]++;
						stk[++top]=2*val[k]-h*k;
					}
				}
				while(top)cnt[stk[top]+add]--,top--;
			}
		printf("%lld\n",ans);
	}
}p100;
int main(){//name long long memory mod -
//	freopen("matrix.in","r",stdin);
//	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			sum[i][j]=sum[i][j-1]+mp[i][j];
		}
		for(int j=1;j<=m;j++)
			sum[i][j]+=sum[i-1][j];
	}
	p100.solve();
	return 0;
}
