#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
template<class T>void Max(T &x,T y){if(x<y)x=y;}
int A[M],B[M],n;
int U[M],D[M];//U[i]表示i在上行的位置 
struct BIT_f{
	int C[M];
	int GetMax(int x){
		int res=0;
		while(x){
			Max(res,C[x]);
			x&=x-1;	
		}
		return res;
	}
	void Update(int x,int v){
		while(x<=n){
			Max(C[x],v);
			x+=x&-x;	
		}
	}
}bit0;
struct BIT_b{
	int C[M];
	int GetMax(int x){
		int res=0;
		while(x<=n){
			Max(res,C[x]);
			x+=x&-x;	
		}
		return res;
	}
	void Update(int x,int v){
		while(x){
			Max(C[x],v);
			x&=x-1;	
		}
	}
}bit1;
int R[M],L[M];
int cntL[M],cntR[M];
void solve(){
	int ans=0;
	for(int i=n;i>=1;i--){
		cntR[i]=bit0.GetMax(D[A[i]])+1;
		bit0.Update(D[A[i]],cntR[i]);
	}
	for(int i=1;i<=n;i++){
		cntL[i]=bit1.GetMax(D[A[i]])+1;
		bit1.Update(D[A[i]],cntL[i]);
	}
	for(int i=1;i<=n;i++){
		int x=i,cnt=cntR[i]+cntL[i]-1;
		Max(ans,cnt);
	}
	printf("%d\n",ans);
}
int main(){//name memory long long * mod - 切分判断 极值
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		U[A[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&B[i]);
		D[B[i]]=i;	
	}
	solve();
	return 0;	
}
