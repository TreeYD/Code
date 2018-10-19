#include<bits/stdc++.h>
using namespace std;
#define M 20
#define bit(x) (1<<x)
template<class T>void Min(T &x,T y){
	if(x>y)x=y;
}
double X[M],Y[M],a,b;
vector<int>S[M];
int n,m,e,lst[(1<<18)+5];
int dp[(1<<18)+5];
bool calc(int x,int y){
	double xa=X[x],ya=Y[x],xb=X[y],yb=Y[y];
	a=(ya*xb-xa*yb)/(xa-xb)/(xa*xb);
	if(a>=0)return 0;
	b=(ya-yb)/(xa-xb)-a*(xa+xb);
	return 1;
}
bool check(int p){
	return abs(Y[p]-(a*X[p]*X[p]+b*X[p]))<=1e-8;
}
void Init(){
	e=bit(n);
	for(int i=0;i<n;i++)
		S[i].clear();
	for(int i=1;i<e;i++){
		dp[i]=dp[i&i-1]+1;
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(X[i]==X[j])continue;
			int st=bit(i);
			if(calc(i,j)){
				st|=bit(j);
				for(int k=j+1;k<n;k++)
					if(check(k))st|=bit(k);
			}
			S[i].push_back(st);
		}
}
int main(){
	int T;
	for(int i=0;i<18;i++){
		int back=bit(18)-bit(i+1);
		lst[bit(i)-1]=i;
		for(int j=back;j;j=(j-1)&back)
			lst[j|(bit(i)-1)]=i;
 	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&X[i],&Y[i]);
		Init();
		for(int i=0;i<e-1;i++){
			int x=lst[i];
			for(int j=0;j<S[x].size();j++)
				Min(dp[i|S[x][j]],dp[i]+1);
		}
		printf("%d\n",dp[e-1]);
	}
	return 0;
}
