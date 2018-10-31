#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define LL long long
template<class T>void Max(T &x,T y){if(x<y)x=y;}
template<class T>void Min(T &x,T y){if(x>y)x=y;}
LL sum[M][M];
int H[M][M];
int n,m,a,b;
struct BIT{
	int C[M];
	void Init(){
		memset(C,0,sizeof(C));
	}
	int GetMax(int x){
		int res=0;
		while(x<=m){
			Max(res,C[x]);
			x+=x&-x;
		}
		return res;
	}
	void Add(int x,int v){
		while(x){
			Max(C[x],v);
			x-=x&-x;
		}
	}
}bit;
struct P100{
	int mx[M];
	int F[2][M][M],tf,tb;
	int stkf[M],stkb[M];
	void solve(){
		LL ans=1e16;
		tf=tb=0;
		for(int i=1;i<=n;i++){
			if(i>a)tf--;
			stkb[++tb]=i;
			for(int k=1;k<=m;k++){
				F[1][tb][k]=H[i][k];
				Max(F[1][tb][k],F[1][tb-1][k]);
			}
			if(tf==0){
				while(tb){
					stkf[++tf]=stkb[tb];
					for(int j=1;j<=m;j++){
						F[0][tf][j]=H[stkf[tf]][j];
						Max(F[0][tf][j],F[0][tf-1][j]);
					}
					tb--;
				}
			}
			for(int j=1;j<=m;j++){
				mx[j]=F[0][tf][j];
				Max(mx[j],F[1][tb][j]);
			}
			if(i>=a){
				bit.Init();
				for(int j=1;j<=m;j++){
					bit.Add(j,mx[j]);
					if(j>=b){
						int tot_mx=bit.GetMax(j-b+1);
						LL tot_sum=sum[i][j]-sum[i][j-b]-sum[i-a][j]+sum[i-a][j-b];
						Min(ans,1LL*a*b*tot_mx-tot_sum);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
}p100;
struct P70{
	#define Mn 205
	int mx[Mn];
	LL sum[Mn];
	void solve(){
		LL ans=1e16;
		for(int i=1;i<=n-a+1;i++){
			for(int j=i;j<=a+i-1;j++)
				for(int k=1;k<=m;k++){
					Max(mx[k],H[j][k]);
					sum[k]+=H[j][k];
				}
			for(int j=1;j<=m-b+1;j++){
				int tot_mx=0;
				LL tot_sum=0;
				for(int k=j;k<=j+b-1;k++){
					Max(tot_mx,mx[k]);
					tot_sum+=sum[k];
				}
				Min(ans,1LL*a*b*tot_mx-tot_sum);
			}
			for(int j=1;j<=m;j++)
				mx[j]=sum[j]=0;
		}
		printf("%lld\n",ans);
	}
}p70;
int main(){
//	freopen("policy.in","r",stdin);
//	freopen("policy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&H[i][j]);
			sum[i][j]=H[i][j]+sum[i][j-1];
		}
		for(int j=1;j<=m;j++)
			sum[i][j]+=sum[i-1][j];
	}
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if(n<=100)p70.solve();
		else p100.solve();
	}
	return 0;
}
