#include<bits/stdc++.h>
using namespace std;
#define M 100005
int A[M],n;
vector<int>E[M];
struct P50{
	long long ans;
	int rt;
	int gcd(int a,int b){
		return b==0?a:gcd(b,a%b);
	}
	void dfs(int x,int f,int d){
		if(x!=rt&&gcd(A[x],A[rt])==1)ans+=d;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y==f)continue;
			dfs(y,x,d+1);
		}
	}
	void solve(){
		ans=0;
		for(int i=1;i<=n;i++){
			rt=i;
			dfs(i,0,0);
		}
		printf("%lld\n",ans/2);
	}
}p50;
struct Pchain{
	long long cnt[M],dis[M];
	long long ans1,ans2;
	vector<int>son[M];
	int num;
	void Init(){
		for(int i=2;i<=M-5;i++){
			if(son[i].size()==0){
				for(int j=i;j<=M-5;j+=i)
					son[j].push_back(i);
			}
		}
	}
	void dfs(int x,int r,int c){
		if(x==son[num].size()){
			int flag=(c&1)?1:-1;
			ans1+=flag*cnt[r];
			ans2+=flag*dis[r];
			return;
		}
		dfs(x+1,r*son[num][x],c+1);
		dfs(x+1,r,c);
	}
	bool judge(){
		for(int i=1;i<=n;i++)
			if(E[i].size()>2)return 0;
		return 1;
	}
	void solve(){
		Init();
		long long res=0;
		for(int i=n;i>=1;i--){
			ans1=ans2=0;
			num=A[i];
			dfs(0,1,0);
			ans1=n-i-ans1;
			ans2=1LL*(n+i-1)*(n-i)/2-ans2;
			res+=(ans2-1LL*ans1*(i-1));
			for(int j=0;j<son[i].size();j++){
				cnt[son[i][j]]++;
				dis[son[i][j]]+=i-1;
			}
		}
		printf("%lld\n",res);
	}
}pchain;
int main(){//name long long memory mod - 
//	freopen("network.in","r",stdin);
//	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	if(pchain.judge())pchain.solve();
	else p50.solve();
	return 0;
}
