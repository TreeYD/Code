#include<bits/stdc++.h>
using namespace std;
#define M 100005
const int Inf=1e9;
template<class T>void Min(T &x,T y){if(x==-1||x>y)x=y;}
char A[M],B[M];
int n,m,a,b,K;
map<int,int>dp[M];
struct PDFS{
	int ans;
	void dfs(int x,int y,int v){
		if(v>K||ans!=-1&&v+abs(y-x)*a>=ans)return;
		if(x==0){
			Min(ans,a*y+v);
			return;
		}
		if(y==0){
			Min(ans,a*x+v);
			return;
		}
		if(dp[x].count(y)&&dp[x][y]<=v)return;
		dp[x][y]=v;
		if(A[x]==B[y])dfs(x-1,y-1,v);
		else{
			dfs(x-1,y-1,v+b);
			dfs(x,y-1,v+a);
			dfs(x-1,y,v+a);
		}
	}
	void solve(){
		ans=-1;
		dfs(n,m,0);
		printf("%d\n",ans);
	}
}pdfs;
int main(){
//	freopen("string.in","r",stdin);
	scanf("%s%s",A+1,B+1);
	scanf("%d%d%d",&a,&b,&K);
	n=strlen(A+1);
	m=strlen(B+1);
	pdfs.solve();
	return 0;
}
