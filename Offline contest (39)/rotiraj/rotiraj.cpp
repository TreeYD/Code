#include<bits/stdc++.h>
using namespace std;
#define M 100005
struct node{
	int a,x;
}op[M];
int A[M],n,K,Q;
int B[M];
struct P40{
	void move(int L,int R,int d){
		int len=R-L+1;
		d%=len;
		for(int i=L;i<=R;i++){
			int newID=i+d;
			if(newID>R)newID=newID-R-1+L;
			else if(newID<L)newID=R-(L-newID-1);
			B[newID]=A[i];
		}
		for(int i=L;i<=R;i++)A[i]=B[i];
	}
	void solve(){
		for(int i=Q;i>=1;i--){
			int a=op[i].a,x=op[i].x;
			if(a==1){
				for(int j=1;j*K<=n;j++)
					move((j-1)*K+1,j*K,-x);
			}else move(1,n,-x);
		}
		for(int i=1;i<=n;i++)printf("%d ",A[i]);
		puts("");
	}
}p40;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ 
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
//	freopen("data.in","r",stdin);
//	freopen("check.out","w",stdout);
	scanf("%d%d%d",&n,&K,&Q);
	for(int i=1;i<=Q;i++)
		scanf("%d%d",&op[i].a,&op[i].x);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	p40.solve();
	return 0;
}
