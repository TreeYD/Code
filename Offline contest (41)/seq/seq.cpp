#include<bits/stdc++.h>
using namespace std;
#define M 1000005
const int P=(1<<16)-1;
int A[M],B[M],ID[M],n;
int cnt[P+5];
int L[M],R[M];
void Sort(){
	for(int i=1;i<=n;i++)cnt[A[ID[i]]&P]++;
	for(int i=1;i<=P;i++)cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;i--)B[cnt[A[ID[i]]&P]--]=ID[i];
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)cnt[A[B[i]]>>16]++;
	for(int i=1;i<=P;i++)cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;i--)ID[cnt[A[B[i]]>>16]--]=B[i];
}
int main(){//name memory long long * mod - «–∑÷≈–∂œ ≥ı÷µ 
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
//	freopen("seq.in","r",stdin);
//	freopen("seq.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		L[i]=i-1;
		R[i]=i+1;
		ID[i]=i;
	}
	Sort();
	long long ans=0;
	for(int i=1;i<n;i++){
		int x=ID[i],tmp;
		if(L[x]==0)tmp=A[R[x]];
		else if(R[x]==n+1)tmp=A[L[x]];
		else tmp=min(A[L[x]],A[R[x]]);
		ans+=tmp;
		R[L[x]]=R[x];
		L[R[x]]=L[x];
	}
	printf("%lld\n",ans);
	return 0;
}
