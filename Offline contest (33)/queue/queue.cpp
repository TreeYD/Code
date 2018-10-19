#include<bits/stdc++.h>
using namespace std;
#define M 1000005
const int P=(1<<15)-1;
int n;
struct P50{
	int A[5005];
	void solve(){
		for(int i=1;i<=n;i++){
			scanf("%d",&A[i]);
			int t=i-1;
			while(t>=1&&A[t]<A[i])t--;
			if(t>=1){
				t--;
				while(t>=1&&A[t]<A[i])t--;
			}
			printf("%d\n",t+1);
		}
	}
}p50;
struct P100{
	int A[M],tmp[M],ID[M];
	int cnt[(1<<15)+5];
	int L[M],R[M],Ans[M];
	void Sort(){
		for(int i=0;i<=P;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[A[ID[i]]&P]++;
		for(int i=1;i<=P;i++)cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;i--)tmp[cnt[A[ID[i]]&P]--]=ID[i];
		for(int i=0;i<=P;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[A[tmp[i]]>>15]++;
		for(int i=1;i<=P;i++)cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;i--)ID[cnt[A[tmp[i]]>>15]--]=tmp[i];
	}
	void solve(){
		for(int i=1;i<=n;i++){
			scanf("%d",&A[i]);
			L[i]=i-1;R[i]=i+1;
			ID[i]=i;
		}
		Sort();
		for(int i=1;i<=n;i++){
			int x=ID[i];
			Ans[x]=L[L[x]]+1;
			R[L[x]]=R[x];
			L[R[x]]=L[x];
		}
		for(int i=1;i<=n;i++)
			printf("%d\n",Ans[i]);
	}
}p100;
int main(){//name long long memory mod
//	freopen("queue.in","r",stdin);
//	freopen("queue.out","w",stdout);
	scanf("%d",&n);
	if(n<=5000)p50.solve();
	else p100.solve();
	return 0;
}
