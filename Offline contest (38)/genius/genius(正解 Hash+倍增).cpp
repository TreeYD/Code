#include<bits/stdc++.h>
using namespace std;
#define M 205
#define LL long long
#define bit(x) (1<<i)
int rx[]={0,1,0,-1,1,1,-1,-1};
int ry[]={-1,0,1,0,-1,1,1,-1};
const int BASE1=131,MOD1=205033;//注意修改模数 
const int BASE2=133,MOD2=205031;
struct Edge{
	int nxt,to,cnt;
}E[M*M*8];
int head[MOD1+5],e_tot;
struct Node{
	int x,y;
	int v1,v2;
}T[M][M][31];
int Base1[35],Base2[35];
char mp[M][M];
int n,m,K;
LL son,mo;
template<class T>void Add(T &x,LL y,int MOD){
	x+=y;if(x>=MOD)x-=MOD;
}
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
void Init(){//倍增为开区间,不包含第一个点!!! 
	Base1[0]=BASE1;
	Base2[0]=BASE2;
	for(int i=1;i<=30;i++){//!!! 15->30
		Base1[i]=1LL*Base1[i-1]*Base1[i-1]%MOD1;
		Base2[i]=1LL*Base2[i-1]*Base2[i-1]%MOD2;
	} 
}
void Find(int x,int y){
	for(int i=head[x];i;i=E[i].nxt){
		int t=E[i].to;
		if(t==y){
			E[i].cnt++;
			return;
		}
	}
	E[++e_tot].nxt=head[x];
	E[e_tot].to=y;
	E[e_tot].cnt=1;
	head[x]=e_tot;
}
void Up(int x,int y,int d,int t){
	int r1=mp[x][y],r2=mp[x][y];
	for(int i=0;i<=30;i++){
		if(t&bit(i)){
			Node &tmp=T[x][y][i];
			r1=(1LL*r1*Base1[i]+tmp.v1)%MOD1;
			r2=(1LL*r2*Base2[i]+tmp.v2)%MOD2;
			x=tmp.x,y=tmp.y;
		}
	}
	Find(r1,r2);
}
void Solve(){
	for(int d=0;d<8;d++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				int nx=i+rx[d],ny=j+ry[d];
				if(nx<1)nx=n;
				if(nx>n)nx=1;
				if(ny<1)ny=m;
				if(ny>m)ny=1;
				T[i][j][0]=(Node){nx,ny,mp[nx][ny],mp[nx][ny]};
			}
		for(int t=1;t<=30;t++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					Node &a=T[i][j][t-1];
					Node &b=T[a.x][a.y][t-1];
					Node &c=T[i][j][t];
					c=b;
					Add(c.v1,1LL*a.v1*Base1[t-1]%MOD1,MOD1);
					Add(c.v2,1LL*a.v2*Base2[t-1]%MOD2,MOD2);
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				Up(i,j,d,K-1);
	}
	for(int i=0;i<MOD1;i++)
		for(int j=head[i];j;j=E[j].nxt)
			son+=E[j].cnt*E[j].cnt;
	mo=n*m*8;
	mo*=mo;
	LL d=gcd(son,mo);
	son/=d,mo/=d;
	printf("%lld/%lld\n",son,mo);
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	Init();
	Solve();
	return 0;
}
