#include<bits/stdc++.h>
using namespace std;
#define M 3005
char mp[M][M];
int n,m,sum[M][M];
struct P60{
	void solve(){
		int ans=0;
		for(int L=1;L<=m;L++)
			for(int R=L;R<=m;R++){
				int cnt=0;
				for(int i=1;i<=n;i++){
					if(sum[i][R]-sum[i][L-1]==R-L+1)
						cnt++;
				}
				ans=max(ans,cnt*(R-L+1));
			}
		printf("%d\n",ans);
	}
}p60;
struct P100{
	int mxdis[M][M],cnt[M];
	void solve(){
		for(int i=1;i<=n;i++){
			int lst=-1;
			for(int j=m;j>=1;j--){
				if(mp[i][j]=='0')lst=-1;
				else if(lst==-1)lst=j;
				if(~lst)mxdis[i][j]=lst-j+1;
			}
		}
		int ans=0;
		for(int L=1;L<=m;L++){
			for(int i=1;i<=m;i++)cnt[i]=0;
			for(int i=1;i<=n;i++)
				cnt[mxdis[i][L]]++;
			for(int i=m;i>=1;i--){
				cnt[i]+=cnt[i+1];
				ans=max(ans,i*cnt[i]);
			}
		}
		printf("%d\n",ans);
	}
}p100;
int main(){//name memory long long * mod -
//	printf("%.2lf\n",(sizeof(p100)+sizeof(p60)+sizeof(sum))/1024.0/1024);
//	freopen("one.in","r",stdin);
//	freopen("one.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++)
			sum[i][j]=sum[i][j-1]+mp[i][j]-'0';
	}
	if(n<=200)p60.solve();
	else p100.solve();
	return 0;
}
