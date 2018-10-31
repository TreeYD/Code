#include<bits/stdc++.h>
using namespace std;
#define M 100005
struct node{
	int a,x;
}op[M];
int A[M],n,K,Q;
struct P70{
	int pos[M],B[M];
	void turn(int k){
		for(int i=Q;i>=1;i--){
			int a=op[i].a,x=op[i].x;
			int &p=pos[k];
			if(a==2){
				p=(p+x)%n;
			}else{
				x%=K;
				int L=p/K*K,R=(p/K+1)*K-1;
				p+=x;
				if(p>R)p=L+p-R-1;
			}
		}
	}
	void solve(){
		for(int i=0;i<n;i++)pos[i]=i;
		for(int i=0;i<K;i++)turn(i);
		for(int i=K;i<n;i++)
			pos[i]=(pos[i-K]+K)%n;
		for(int i=0;i<n;i++)
			B[pos[i]]=A[i];
		for(int i=0;i<n;i++)
			printf("%d ",B[i]);
		puts("");
	}
}p70;
int main(){
	scanf("%d%d%d",&n,&K,&Q);
	int a,x;
	for(int i=1;i<=Q;i++){
		scanf("%d%d",&a,&x);
		x=-x;
		if(a==1){
			x=(x%K+K)%K;
		}else x=(x%n+n)%n;
		op[i].a=a,op[i].x=x;
		printf("%d %d\n",op[i].a,op[i].x);
	}
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	p70.solve();
	return 0;
}
