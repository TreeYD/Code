#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define MM 1000005
template<class T>void Min(T &x,T y){if(x>y)x=y;}
template<class T>void Max(T &x,T y){if(x<y)x=y;}
template<class T>inline void Rd(T &res){
	res=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	do{
		res=(res<<3)+(res<<1)+(c^48);
		c=getchar();
	}while(c>='0'&&c<='9');
}

int pos[MM];
int num[MM];
int A[M][M];
int B[M][M];
bool have[M];//记录第i行是否有0
int dp[M];//lis处理数组 
int lis[M];//记录每行的lis 
int fa[M],sz[M];
bool ok[M];
int n,m,ans;
//-------------head-------------//
int getfa(int v){return fa[v]==v?v:fa[v]=getfa(fa[v]);}

void Solve(){
	for(int i=1;i<=n;i++){
		int len=0,cnt=0;
		bool flag=1;
		for(int j=1;j<=m;j++){
			if(A[i][j]){
				if(pos[A[i][j]]==i){
					cnt++;
					int x=num[A[i][j]];
					int y=lower_bound(dp+1,dp+1+len,x)-dp;
					dp[y]=x;
					Max(len,y);
				}else{
					int x=i,y=pos[A[i][j]];
					int fx=getfa(x),fy=getfa(y);
					if(fx!=fy){
						fa[fy]=fx;
						sz[fx]+=sz[fy];
						have[fx]|=have[fy];
					}
					sz[fx]++;
				}
			}	
		}
		ans+=cnt-len;
		ok[i]=(cnt==len);
	}
	for(int i=1;i<=n;i++){
		if(fa[i]==i){
			if(sz[i])ans+=!have[i];
			else ans+=!have[i]&&!ok[i];
			ans+=sz[i];
		}
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d%d",&n,&m);
	bool zero=0,same=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&A[i][j]);
			have[i]|=(A[i][j]==0);
		}
		zero|=have[i];
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&B[i][j]);
			pos[B[i][j]]=i;
			num[B[i][j]]=num[B[i][j-1]]+1;
			same&=(A[i][j]==B[i][j]);
		}
	if(same)puts("0");
	else{
		if(!zero)puts("-1");
		else Solve();
	}
	return 0;
}
