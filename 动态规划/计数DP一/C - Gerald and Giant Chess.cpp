#include<bits/stdc++.h>
using namespace std;
#define M 100005
const int P=1e9+7;
int fac[M<<1],inv[M<<1];
int n,m,k;
void Init(){
	int i,w=n+m;
	fac[1]=inv[1]=1;
	for(i=2;i<=w;i++)
		fac[i]=1LL*fac[i-1]*i%P;
	for(i=2;i<=w;i++)
		inv[i]=1LL*(P-P/i)*inv[P%i]%P;
	for(i=2;i<=w;i++)
		inv[i]=1LL*inv[i-1]*inv[i]%P;
}
int C(int x,int y){
	if(y==0||x==y)return 1;
	return 1LL*fac[x]*inv[y]%P*inv[x-y]%P;
}
struct node{
	int x,y,dp;
	bool operator<(const node &A)const{
		if(x!=A.x)return x<A.x;
		return y<A.y;
	}
}T[2005];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int i,j,x,y;
	Init();
	for(i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		T[i]=(node){x,y,C(x+y-2,x-1)};
	}
	T[++k]=(node){n,m,C(n+m-2,n-1)};
	sort(T+1,T+1+k);
	for(i=1;i<=k;i++){
		for(j=i+1;j<=k;j++){
			int x=T[j].x-T[i].x,y=T[j].y-T[i].y;
			if(x>=0&&y>=0)T[j].dp=(1LL*T[j].dp-1LL*T[i].dp*C(x+y,y)%P)%P;
		}
	}
	printf("%d\n",(T[k].dp%P+P)%P);
}
