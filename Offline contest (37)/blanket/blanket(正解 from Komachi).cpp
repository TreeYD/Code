#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define LL long long
LL Cnt[M];
int Lnt[M],n,m;
void Solve(int X0,int Y0,int X1,int Y1){
	if((X0<0)^(X1<0)){
		Solve(X0,Y0,-1,Y1);
		Solve(0,Y0,X1,Y1);
	}else if((Y0<0)^(Y1<0)){
		Solve(X0,Y0,X1,-1);
		Solve(X0,0,X1,Y1);
	}else if(X0<0){
		Solve(-X1,Y0,-X0,Y1);
	}else if(Y0<0){
		Solve(X0,-Y1,X1,-Y0);
	}else if(X1<Y1){
		Solve(Y0,X0,Y1,X1);
	}else{
		int lim=max(X0,Y0);
		if(Y1<lim){//Y1==lim?为什么不可以 
			Cnt[lim]+=Y1-Y0+1;
			Cnt[X1+1]-=Y1-Y0+1;
		}else{
			Cnt[lim]+=(lim==Y0)?lim-X0+1:lim-Y0+1;
			Lnt[lim]+=2;
			Lnt[Y1]-=2;
			Cnt[Y1+1]-=Y1-X0;
			Cnt[X1+1]-=Y1-Y0+1;
		}
	}
}
int main(){
	scanf("%d",&n);
	int xa,ya,xb,yb;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		Solve(xa,ya,xb,yb);
	}
	for(int i=1;i<=M-5;i++)
		Lnt[i]+=Lnt[i-1];
	for(int i=1;i<=M-5;i++)
		Cnt[i]+=Cnt[i-1]+Lnt[i-1];
	for(int i=1;i<=M-5;i++)
		Cnt[i]+=Cnt[i-1];
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&xa);
		printf("%lld\n",Cnt[xa]);
	}
	return 0;
}
