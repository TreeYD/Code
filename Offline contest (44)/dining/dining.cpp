#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define calc(a,b) ((a|b)-(a&b))
const int Inf=1e9;
template<class T>void Min(T &x,T y){if(x>y)x=y;}
template<class T>void Max(T &x,T y){if(x<y)x=y;}
int B[M],T[M],n;
struct P30{//B<=1
	int dp[M][2];//dp[i][1/0]0表示第i个最后， 1表示第i-1个最后 
	void solve(){
		memset(dp,63,sizeof(dp));
		dp[0][0]=0;
		dp[1][0]=0;
		for(int i=1;i<n;i++){
			if(B[i+1]>0)Min(dp[i+2][1],min(dp[i][0]+T[i]^T[i+2],dp[i][1]+T[i-1]^T[i+2]));
			Min(dp[i+1][0],dp[i][0]+T[i]^T[i+1]);
			if(i)Min(dp[i+1][0],dp[i][1]+T[i-1]^T[i+1]);
		}
		printf("%d\n",min(dp[n][0],dp[n][1]));
	}
}p30;
struct P65{
	int dp[M][M],ID[M];
	vector<int>V;
	void Init(){
		memset(dp,63,sizeof(dp));
		int k=0;
		ID[k]=1;
		while(k<=B[1]+1){
			do{
				int mx=0,ans=0;
				bool flag=1;
				for(int j=1;j<=k;j++){
					if(mx-ID[j]>B[ID[j]]){
						flag=0;
						break;
					}
					Max(mx,ID[j]);
					if(j>1)ans+=calc(T[ID[j]],T[ID[j-1]]);
				}
				Min(dp[k][ID[k]],ans);
			}while(next_permutation(ID+1,ID+1+k));
			ID[++k]=k;
		}
	}
	void solve(){
		Init();
		for(int i=1;i<n;i++){
			int k=1;
			V.clear();
			for(int j=1;j<=i;j++)
				if(dp[i][j]<Inf)V.push_back(j);
			ID[k]=i+1;
			while(k<=B[i+1]+1){
				do{
					int mx=0,ans=0;
					bool flag=1;
					for(int j=1;j<=k;j++){
						if(mx-ID[j]>B[ID[j]]){
							flag=0;
							break;
						}
						Max(mx,ID[j]);
						if(j>1)ans+=calc(T[ID[j]],T[ID[j-1]]);
					}
					if(flag){
						for(int j=0;j<V.size();j++){//5 !!!
							int x=V[j];
							Min(dp[i+k][ID[k]],dp[i][x]+calc(T[x],T[ID[1]])+ans);
						}
					}
				}while(next_permutation(ID+1,ID+1+k));
				ID[++k]=i+k;
			}
		}
		int ans=Inf;
		for(int i=1;i<=n;i++)
			Min(ans,dp[n][i]);
		printf("%d\n",ans);
	}
}p65;
int main(){//name memory long long * mod - 切分判断 初值
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
	freopen("dining.in","r",stdin);
	freopen("dining.out","w",stdout); 
	int Cas;
	scanf("%d",&Cas);
	while(Cas--){
		scanf("%d",&n);
		bool flag=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&T[i],&B[i]);
			if(B[i]>1)flag=0;
		}
		if(flag)p30.solve();
		else p65.solve();
	}
	return 0;	
}
