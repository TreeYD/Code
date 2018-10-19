#include<bits/stdc++.h>
using namespace std;
#define M 25
#define bit(x) (1<<x)
int dp[(1<<18)+5];
double X[M],Y[M],a,b;
int n,m;
bool calc(int x,int y){
 	double xa=X[x],ya=Y[x],xb=X[y],yb=Y[y];
	a=(ya*xb-xa*yb)/(xa-xb)/(xa*xb);
	if(a>=0)return 0;
	b=(ya-yb)/(xa-xb)-a*(xa+xb);
	return 1;
}
bool check(int p){
	return Y[p]==a*X[p]*X[p]+b*X[p];
}
void Min(int &x,int y){
	if(x>y)x=y;
}
void Init(){
	memset(dp,63,sizeof(dp));
	for(int i=0;i<n;i++){
		int st=bit(i);
		dp[st]=1;
		for(int j=i+1;j<n;j++){
			if(X[i]==X[j])continue;
			st=bit(i);
			if(calc(i,j)){
				st|=bit(j);
				for(int k=j+1;k<n;k++)
					if(check(k))st|=bit(k);
				dp[st]=1;
			}
		}
	}
}
int main(){//name long long memory mod -
//	freopen("angrybirds.in","r",stdin);
//	freopen("angrybirds.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&X[i],&Y[i]);
		Init();
		int e=bit(n);
		if(dp[e-1]==1){
			puts("1");
			continue;
		}
		for(int i=1;i<e;i++)
			for(int j=i;j;j=(j-1)&i)
				Min(dp[j],dp[i]);
		for(int i=1;i<e;i++)
			for(int j=i;j&&(i^j)<j;j=(j-1)&i)
				Min(dp[i],dp[j]+dp[i^j]);
		printf("%d\n",dp[e-1]);
	}
	return 0;
}
