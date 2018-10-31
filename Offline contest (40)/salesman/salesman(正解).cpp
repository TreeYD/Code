#include<bits/stdc++.h>
using namespace std;
#define M 500005
#define LL long long
#define Inf 0x7f7f7f7f5f
#define Set(a) memset(a,-123,sizeof(a))
template<class T>void Max(T &x,T y){
	if(x<y)x=y;
}
LL Dpf[M],Dpb[M];
int n,U,D,S,MaxL;
struct Node{
	int t,m,l;
	bool operator<(const Node &x)const{
		if(t!=x.t)return t<x.t;
		return l<x.l;
	}
}A[M];
struct BIT_f{
	LL C[M];
	void Init(){
		Set(C);
	}
	void Update(int x,LL v){
		while(x<=MaxL){
			Max(C[x],v);
			x+=x&-x;
		}
	}
	LL GetMax(int x){
		LL res=-Inf;
		while(x){
			Max(res,C[x]);
			x&=x-1;
		}
		return res;
	}
}Tf;
struct BIT_b{
	LL C[M];
	void Init(){
		Set(C);
	}
	void Update(int x,LL v){
		while(x){
			Max(C[x],v);
			x&=x-1;
		}
	}
	LL GetMax(int x){
		LL res=-Inf;
		while(x<=MaxL){
			Max(res,C[x]);
			x+=x&-x;
		}
		return res;
	}
}Tb;
int main(){
	scanf("%d%d%d%d",&n,&U,&D,&S);
	MaxL=S;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&A[i].t,&A[i].l,&A[i].m);
		Max(MaxL,A[i].l);
	}
	A[0].l=A[n+1].l=S;
	sort(A+1,A+1+n);
	Tf.Init();
	Tb.Init();
	Tf.Update(S,D*S);
	Tb.Update(S,-U*S);
	Set(Dpf);
	Set(Dpb);
	int L=1;
	LL Mxf=-Inf,Mxb=-Inf;
	for(int i=1;i<=n+1;i++){
		Max(Dpf[i],A[i].m+Tf.GetMax(A[i].l)-D*A[i].l);
		Max(Dpf[i],A[i].m+Tb.GetMax(A[i].l)+U*A[i].l);
		Max(Dpf[i],A[i].m+Mxf-D*A[i].l);
		Max(Mxf,Dpf[i]+D*A[i].l);
		if(A[i].t!=A[i+1].t){
			Mxb=Mxf=-Inf;
			if(i>L){
				for(int j=i;j>=L;j--){
					Max(Dpb[j],A[j].m+Tf.GetMax(A[j].l)-D*A[j].l);
					Max(Dpb[j],A[j].m+Tb.GetMax(A[j].l)+U*A[j].l);
					Max(Dpb[j],A[j].m+Mxb+U*A[j].l);
					Max(Mxb,Dpb[j]-U*A[j].l);
				}
			}
			for(int j=i;j>=L;j--){
				Tf.Update(A[j].l,max(Dpf[j],Dpb[j])+D*A[j].l);
				Tb.Update(A[j].l,max(Dpf[j],Dpb[j])-U*A[j].l);
			}
			L=i+1;
		}
	}
	printf("%lld\n",max(Dpf[n+1],Dpb[n+1]));
	return 0;
}
