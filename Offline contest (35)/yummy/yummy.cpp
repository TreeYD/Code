#include<bits/stdc++.h>
using namespace std;
#define M 20005
#define N 4005
const int maxn=4000;
struct node{
	int a,b,id;
	bool operator<(const node &x)const{
		return a<x.a;
	}
}Q[M];
int n,p,q,Ans[M];
int C[N],H[N],T[N];
void Max(int &x,int y){
	if(x<y)x=y;
}
struct P30{//n<=50 || p==1
	int dp[4005];
	vector<int>U[30005];
	void solve(){
		for(int i=1;i<=n;i++)
			for(int j=T[i];j<=T[i]+p-1;j++)
				U[j].push_back(i);
		for(int i=1;i<=q;i++){
			int a=Q[i].a,b=Q[i].b;
			if(a==Q[i-1].a){
				Ans[Q[i].id]=dp[b];
				continue;
			}
			memset(dp,0,sizeof(dp));
			for(int t=0;t<U[a].size();t++){
				int j=U[a][t];
				if(T[j]<=a&&T[j]+p-1>=a)
					for(int k=maxn;k>=C[j];k--)
						Max(dp[k],dp[k-C[j]]+H[j]);
			}
			Ans[Q[i].id]=dp[b];
		}
	}
}p30;
struct P40{//n=1
	void solve(){
		for(int i=1;i<=q;i++){
			int a=Q[i].a,b=Q[i].b;
			if(T[1]<=a&&T[1]+p-1>=a&&b>=C[1])
				Ans[Q[i].id]=H[1];
		}
	}
}p40;
struct P50{//p>max(ai,ti)
	int dp[maxn+5];
	vector<int>S[20005];
	void solve(){
		int mp=0;
		for(int i=1;i<=n;i++)
			S[T[i]].push_back(i);
		for(int i=1;i<=q;i++){
			int a=Q[i].a,b=Q[i].b;
			while(mp<a){
				mp++;
				for(int j=0;j<S[mp].size();j++){
					int x=S[mp][j];
					for(int k=maxn;k>=C[x];k--)
						Max(dp[k],dp[k-C[x]]+H[x]);
				}
			}
			Ans[Q[i].id]=dp[Q[i].b];
		}
	}
}p50;
int main(){//name memory long long * mod -
//	freopen("yummy.in","r",stdin);
//	freopen("yummy.out","w",stdout);
	scanf("%d%d",&n,&p);
	int mx_time=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&C[i],&H[i],&T[i]);
		Max(mx_time,T[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&Q[i].a,&Q[i].b);
		Q[i].id=i;
		Max(mx_time,Q[i].a);
	}
	sort(Q+1,Q+1+q);
	if(n==1)p40.solve();
	else if(n<=50||p==1)p30.solve();
	else if(p>=mx_time)p50.solve();
	for(int i=1;i<=q;i++)
		printf("%d\n",Ans[i]);
	return 0;
}
