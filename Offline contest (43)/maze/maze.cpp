#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
struct P80{
	#define Maxn 10000005
	int fac[Maxn];
	void Init(){
		fac[0]=1;
		for(int i=1;i<=Maxn-5;i++)
			fac[i]=1LL*fac[i-1]*i%P;
	}
	void solve(int k){
		printf("%d\n",fac[k]);	
	}
}p80;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024); 
//	freopen("maze.in","r",stdin);
//	freopen("maze.out","w",stdout);
	int T,x;
	p80.Init();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		p80.solve(x);
	}
	return 0;
}
