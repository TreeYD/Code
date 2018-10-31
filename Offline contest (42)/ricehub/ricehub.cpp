#include<bits/stdc++.h>
using namespace std;
#define M 100005
template<class T>void Max(T &x,T y){if(x<y)x=y;}
int A[M],Len;
int n;
long long B;
struct P40{
	void solve(){
		int mx=0;
		for(int i=1;i<=Len;i++){
			int R=lower_bound(A+1,A+1+n,i)-A;
			int L=R-1,tmp=0;
			long long res=B;
			while(L>=1&&R<=n&&res>0){
				if(A[R]-i<i-A[L]){
					if(res<A[R]-i)break;
					res-=A[R]-i;
					tmp++;R++;
				}else{
					if(res<i-A[L])break;
					res-=i-A[L];
					tmp++;L--;
				}
			}
			while(L>=1&&i-A[L]<=res){
				res-=i-A[L];
				tmp++;L--;
			}
			while(R<=n&&A[R]-i<=res){
				res-=A[R]-i;
				tmp++;R++;
			}
			if(mx<tmp)mx=tmp;
		}
		printf("%d\n",mx);
	}
}p40;
struct P70{
	void solve(){
		int ans=1;
		for(int i=1;i<n;i++){
			if(B<A[i+1]-A[i])continue;
			long long res=B;
			int L=i,R=i+1;
			while(res-(A[i]-A[L])>=0&&L>=1){
				res-=A[i]-A[L];
				L--;
			}
			if(res>=0)Max(ans,i-L);
			L++;
			for(;L<=i;L++){
				while(R<=n&&R-i<=i-L+1&&res-(A[R]-A[i])>=0){
					res-=A[R]-A[i];
					R++;
				}
				Max(ans,R-L);
			}
			res=B;
			R=i+1;L=i;
			while(res-(A[R]-A[i+1])>=0&&R<=n){
				res-=A[R]-A[i+1];
				R++;
			}
			if(res>=0)Max(ans,R-i-1);
			R--;
			for(;R>=i+1;R--){
				while(L>=1&&R-i>=i-L+1&&res-(A[i+1]-A[L])>=0){
					res-=A[i+1]-A[L];
					L--;
				}
				Max(ans,R-L);
			}
		}
		printf("%d\n",ans);
	}
}p70;
int main(){//name memory long long * mod - «–∑÷≈–∂œ ≥ı÷µ 
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
//	freopen("ricehub.in","r",stdin);
//	freopen("ricehub.out","w",stdout);
	scanf("%d%d%lld",&n,&Len,&B);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	if(n<=500)p40.solve();
	else p70.solve();
	return 0;
}
