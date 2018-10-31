#include<bits/stdc++.h>
using namespace std;
#define LL long long
template<class T>void Max(T &x,T y){if(x<y)x=y;}
int n,h;
struct P1{
	#define M 100005
	LL dp[2][M];
	int tot;
	void solve(){
		bool cur=0;
		for(int i=1;i<=n;i++){
			LL s=0;
			int x;
			cur=!cur;
			for(int j=1;j<=h;j++){
				scanf("%d",&x);
				s+=x;tot++;
				for(int k=tot;k-j>=i-1;k--){
					if(j==1)dp[cur][k]=dp[!cur][k-j]+s;
					else Max(dp[cur][k],dp[!cur][k-j]+s);
				}
			}
		}
		double ans=0;
		for(int i=n;i<=tot;i++)
			Max(ans,1.0*dp[cur][i]/i);
		printf("%.4lf\n",ans);
	}
}p1;
struct P2{
	void solve(){
		LL s=0,sum=0,cnt=0;
		int x;
		for(int i=1;i<=h;i++){
			scanf("%d",&x);
			s+=x;
			if(cnt==0||s*cnt>sum*i)
				sum=s,cnt=i;	
		}
		printf("%.4lf\n",1.0*sum/cnt);	
	}
}p2;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	scanf("%d%d",&n,&h);
	if(n==1)p2.solve();
	else p1.solve();
	return 0;	
}
