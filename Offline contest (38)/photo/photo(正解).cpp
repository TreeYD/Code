#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define N 200005
template<class T>void Min(T &x,T y){if(x>y)x=y;}
template<class T>void Max(T &x,T y){if(x<y)x=y;}
int A[M],B[M],n,m;
int L[N],R[N];
int main(){
	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n+1;i++)R[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d",&A[M],&B[M]);
		Max(L[B[i]+1],A[i]);
		Min(R[B[i]],A[i]-1);
	}
	for(int i=1;i<=n;i++)
		Max(L[i],L[i-1]);
	for(int i=1;i<=n;i++)
		Min(R[i],R[i-1]);
	return 0;
}
