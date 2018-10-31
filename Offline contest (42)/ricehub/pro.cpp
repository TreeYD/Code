#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define LL long long
template<class T>void Max(T &x,T y){if(x<y)x=y;}
template<class T>void Min(T &x,T y){if(x>y)x=y;}
int A[M],n,Len;
LL B,sumL[M],sumR[M];
LL calc(int L,int R){
	if(L==R)return 0;
	LL res=0;
	int x=(L+R>>1)+1;
	int cnt0=x-L,cnt1=R-x+1;
	res+=sumR[L]-sumR[x]-1LL*cnt0*(A[n]-A[x-1]);
	res+=sumL[R]-sumL[x-1]-1LL*cnt1*(A[x]-A[1]);
	res+=1LL*min(cnt0,cnt1)*(A[x]-A[x-1]);
	return res;
}
void solve(){
	int ans=0;
	for(int L=1,R=1;L<=n;L++){
		while(R<=n&&calc(L,R)<=B)R++;
		ans=max(ans,R-L);
	}
	printf("%d\n",ans);
}
int main(){;
	scanf("%d%d%lld",&n,&Len,&B);
	for(int i=1;i<=n;i++){ 
		scanf("%d",&A[i]);
		sumL[i]=sumL[i-1]+A[i]-A[1];
	}
	for(int i=n-1;i>=1;i--)
		sumR[i]=sumR[i+1]+A[n]-A[i];
	solve();
	return 0;
}
