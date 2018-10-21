#include<bits/stdc++.h>
using namespace std;
#define M 1505
bool tmp[M];
int n,m;
struct DSU{
	bool mark[M];
	void Read(){
		int x;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			mark[x]=1;
		}
	}
	void operator*=(const DSU &x){
		for(int i=0;i<m;i++)tmp[i]=0;
		for(int i=0;i<m;i++){
			if(mark[i]){
				for(int j=0;j<m;j++)
					if(x.mark[j])tmp[i*j%m]=1;					
			}
		}
		for(int i=0;i<m;i++)
			mark[i]=tmp[i];
	}
	void Print(){
		for(int i=0;i<m;i++)
			if(mark[i])printf("%d ",i);
		puts("");
	}
}Ans,Base;
long long K;
int main(){
	scanf("%lld%d%d",&K,&m,&n);
	Base.Read();
	Ans.mark[1]=1;
	while(K){
		if(K&1)Ans*=Base;
		Base*=Base;
		K>>=1;
	}
	Ans.Print();
	return 0;
}
