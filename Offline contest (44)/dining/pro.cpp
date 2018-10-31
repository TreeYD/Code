#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define bit(x) (1<<x)
//#define num(x,lst) )
//#define calc(a,b) (x==0?0:((T[a]|T[b])-(T[a]&T[b])))
template<class T>void Min(T &x,T y){if(x>y)x=y;}
const int Inf=1e9;
int dp[M][20][(1<<7)+5];//x lst -> 最后一点 x+1+lst-10
int B[M],T[M],n;
int calc(int a,int b){
	if(a==0)return 0;
	return (T[a]^T[b]);
}
int dfs(int x,int lst,int st){
//	printf("%d %d %d\n",x,x+1+lst-10,st);
	if(st>>B[x])return Inf;
	if(x>n)return 0;
	int &res=dp[x][lst][st];
	if(~res)return res;
	res=Inf;
	int mi=Inf,num=x+lst-9;
	for(int i=0;i<B[x];i++){
		int y=x+i+1;
		if(bit(i)&st){
			if(y>mi)return res=Inf;
		}else {
			Min(mi,y+B[y]);
			Min(res,dfs(x,i+10,st|bit(i))+calc(num,y));
		}
//		if(B[x+lst-9]<i-lst+10)continue;
	}
	for(int i=0;i<=B[x];i++){
		if(bit(i)&st)continue;
//		if(B[x+lst-9]<9-lst)return res=Inf;
		Min(res,dfs(x+i+1,-i+8,st>>i+1)+calc(num,x));
		break;
	}
//	if(st>(1<<7))
	return res;
}
int main(){
	freopen("dining.in","r",stdin);
	int Cas;
	scanf("%d",&Cas);
	while(Cas--){
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&T[i],&B[i]);
		B[0]=B[1]+1;
		printf("%d\n",dfs(1,8,0));
		int ans=Inf;
	}
	return 0;
}
