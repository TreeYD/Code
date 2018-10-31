#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define LL long long
template<class T>
void Min(T &x,T y){
	if(x>y)x=y;	
}
int stk[M],top;
bool in[M],flag;
int sz[M],n;
LL val[M];
int sum[M];// val[i]->¡Æi*sz[i] sum->¡Æsz[i]
LL res;
LL L[M],R[M];
vector<int>E[M];
void dfs_init(int x,int f){
	sz[x]=1;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f||in[y])continue;
		dfs_init(y,x);
		res+=1LL*sz[y]*(n-sz[y]);
		sz[x]+=sz[y];
	}
}
void dfs_find(int x,int f){
	stk[++top]=x;
	in[x]=1;
	for(int i=0;i<E[x].size()&&!flag;i++){
		int y=E[x][i];
		if(y==f)continue;
		if(in[y]){
			flag=1;
			for(int j=1;j<=top;j++)
				dfs_init(stk[j],0);
			return;
		}
		dfs_find(y,x);
	}
	if(flag)return;
	top--;
	in[x]=0;
}
int main(){
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs_find(1,0);
	int m=top;
	LL base=0;
	for(int i=1;i<=m;i++){
		val[i]=val[i-1]+1LL*sz[stk[i]]*i;
		sum[i]=sum[i-1]+sz[stk[i]];
		base+=1LL*sum[i]*(n-sum[i]);
	}
	LL ans=base+res;
	for(int i=1;i<=m;i++)
		L[i]=1LL*i*sum[i]-val[i]+1LL*(n-sum[i])*(i-1)+1LL*(m+1)*(sum[m]-sum[i])-val[m]+val[i];
	for(int i=1;i<=m;i++)
		R[i]=val[m]-val[i]-1LL*i*(sum[m]-sum[i])+val[i-1]+1LL*(m-i)*sum[i-1];
	for(int i=1;i<=m;i++){
		base-=1LL*sz[stk[i]]*(R[i]-L[i]);
		Min(ans,res+base);
	}
	printf("%lld\n",ans);
	return 0;	
}
