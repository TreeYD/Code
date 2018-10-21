#include<bits/stdc++.h>
using namespace std;
int n,m;
struct P20{
	#define Maxn 2005
	#define Mx 200001
	#define My 2001
	int sum[Mx+5],ans[100005];
	vector<int>S[My+5],E[My+5];
	void solve(){
		int xa,ya,xb,yb;
		int addy=1001,addx=100001;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
			xa+=addx,ya+=addy;xb+=addx,yb+=addy;
			//xa,yb×óÉÏ½Ç
			for(int j=ya;j<=yb;j++)
				S[j].push_back(xa),E[j].push_back(xb+1);
		}
		for(int i=1;i<=My;i++){
			for(int j=0;j<S[i].size();j++)
				sum[S[i][j]]++,sum[E[i][j]]--;
			for(int j=1;j<=Mx;j++){
				sum[j]+=sum[j-1];
				sum[j-1]=0;
				int dx=abs(addx-j),dy=abs(addy-i);
				ans[max(dx,dy)]+=sum[j];
			}
			sum[Mx]=0;
		}
		for(int i=1;i<=100000;i++)
			ans[i]+=ans[i-1];
		scanf("%d",&m);
		int len;
		for(int i=1;i<=m;i++){
			scanf("%d",&len);
			printf("%d\n",ans[i]);
		}
	}
}p20;
struct P50{
	#define Maxn 2005
	#define Mx 2001
	#define My 2001
	int sum[Maxn][Maxn];
	void solve(){
		int xa,ya,xb,yb;
		int add=1001;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
			xa+=add,ya+=add;xb+=add,yb+=add;
			//xa,yb×óÉÏ½Ç
			for(int j=ya;j<=yb;j++)
				sum[j][xa]++,sum[j][xb+1]--;
		}
		for(int i=1;i<=My;i++){
			for(int j=1;j<=Mx;j++)
				sum[i][j]+=sum[i][j-1];
			for(int j=1;j<=Mx;j++)
				sum[i][j]+=sum[i][j-1];
			for(int j=1;j<=Mx;j++){
				sum[i][j]+=sum[i-1][j];
			}
		}
		scanf("%d",&m);
		int len;
		for(int i=1;i<=m;i++){
			scanf("%d",&len);
			printf("%d\n",sum[add+len][add+len]+sum[add-len-1][add-len-1]-sum[add+len][add-len-1]-sum[add-len-1][add+len]);
		}
	}
}p50;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï 
//	freopen("blanket.in","r",stdin);
//	freopen("blanket.out","w",stdout);
	scanf("%d",&n);
	if(n<=1000)p50.solve();
	else p20.solve();
	return 0;
}
