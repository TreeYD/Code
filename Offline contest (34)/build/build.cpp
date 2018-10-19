#include<bits/stdc++.h>
using namespace std;
#define M 4005
int A[M],B[M],n;
void Min(int &x,int y){
	if(x>y)x=y;
}
struct P30{
	int ans1[M],ans2[M],ans;
	bool mark[M];
	void dfs(int x){
		if(x==n+1){
			int res=0;
			for(int i=1;i<=n;i++)
				ans1[i]=ans2[i]=n+1;
			int ka=-n-1,kb=-n-1;
			for(int i=1;i<=n;i++){
				if(mark[i])ka=i;
				else kb=i;
				ans1[i]=min(ans1[i],(i-ka));
				ans2[i]=min(ans2[i],(i-kb));
			}
			ka=2*n+1,kb=2*n+1;
			for(int i=n;i>=1;i--){
				if(mark[i])ka=i;
				else kb=i;
				ans1[i]=min(ans1[i],ka-i);
				ans2[i]=min(ans2[i],kb-i);
				res+=ans1[i]*A[i]+ans2[i]*B[i];
			}
			ans=min(ans,res);
			return;
		}
		mark[x]=1;
		dfs(x+1);
		mark[x]=0;
		dfs(x+1);
	}
	void solve(){
		ans=1e9;
		memset(mark,0,sizeof(mark));
		dfs(1);
		printf("%d\n",ans);
	}
}p30;
int main(){//name long long memory mod - 
//	freopen("build.in","r",stdin);
//	freopen("build.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&A[i],&B[i]);
	p30.solve();
	return 0;
}
