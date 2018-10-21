#include<bits/stdc++.h>
using namespace std;
#define M 1505
bool mark[M],tmp[M];
int A[M],n,m,K;
struct P30{
	void solve(){
		for(int i=0;i<n;i++){
			tmp[A[i]]=mark[A[i]]=1;
		}
		for(int i=2;i<=K;i++){
			memset(tmp,0,sizeof(tmp));
			for(int j=0;j<m;j++){
				if(!mark[j])continue;
				for(int k=0;k<n;k++)
					tmp[A[k]*j%m]=1;
			}
			for(int j=0;j<m;j++)
				mark[j]=tmp[j];
		}
		for(int i=0;i<m;i++)
			if(tmp[i])printf("%d ",i);
		puts("");
	}
}p30;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï
	//printf("%.2lf",(sizeof(p))/1024.0/1024);
//	freopen("ill.in","r",stdin);
//	freopen("ill.out","w",stdout);
	scanf("%d%d%d",&K,&m,&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	p30.solve();
	return 0;
}
