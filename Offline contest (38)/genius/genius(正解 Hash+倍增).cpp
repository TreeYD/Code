#include<bits/stdc++.h>
using namespace std;
#define M 205
#define LL long long
#define bit(x) (1<<i)
int rx[]={0,1,0,-1,1,1,-1,-1};
int ry[]={-1,0,1,0,-1,1,1,-1};
const int BASE=1e9+7,MOD=1e9+9;//注意修改模数 
struct Node{
	int x,y;
	LL val;
};
map<int,Node>T[M][M][8];
map<LL,int>cnt;
LL Base[35];
char mp[M][M];
int n,m,K;
LL son,mon;
template<class T>void Add(T &x,T y){
	x+=y;if(x>=MOD)x-=MOD;
}
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
void Init(){//倍增为开区间,不包含第一个点!!! 
	Base[0]=BASE;
	for(int i=1;i<=30;i++){
		Base[i]=Base[i-1]*Base[i-1]%MOD;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			for(int k=0;k<8;k++){
				int nx=i+rx[k],ny=j+ry[k];
				if(nx<1)nx=n;
				if(nx>n)nx=1;
				if(ny<1)ny=m;
				if(ny>m)ny=1;
				T[i][j][k][0]=(Node){nx,ny,mp[nx][ny]};
//				printf("%d\n",mp[nx][ny]-'a');
			}
		}
	for(int t=1;t<=30;t++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				for(int d=0;d<8;d++){
					Node a=T[i][j][d][t-1];
					Node b=T[a.x][a.y][d][t-1];
					Node c=b;
					Add(c.val,a.val*Base[t-1]%MOD);
					T[i][j][d][t]=c;
//					printf("%lld\n",c.val);
				}
			}
}
LL Up(int x,int y,int d,int t){
	LL res=mp[x][y];
	for(int i=0;i<=30;i++){
		if(t&bit(i)){
			Node tmp=T[x][y][d][i];
			res=res*Base[i]+tmp.val;
			x=tmp.x,y=tmp.y;
		}
	}
	return res;
}
void Solve(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
//			printf("%d %d\n",i,j);
			for(int d=0;d<8;d++){
				LL NewV=Up(i,j,d,K-1);
				LL c=cnt[NewV];
				mon++;
				son+=1+2*c;
				cnt[NewV]++;
				printf("%lld\n",NewV);
			}
		}
//	printf("son:%lld\n",son);
	mon=mon*mon;
	LL d=gcd(son,mon);
	son/=d,mon/=d;
	printf("%lld/%lld\n",son,mon);
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	Init();
	Solve();
	return 0;
}
