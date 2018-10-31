#include<bits/stdc++.h>
using namespace std;
#define M 100005
int V[M],n,m;
struct P30{//n<=1000&&m<=1000
	void solve(){
		int x,y;
		int cnt=n;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			for(int j=0;j<n;j++){
				if((j&x)!=j)continue;
				if(V[j]>0&&V[j]-y<=0)cnt--;
				V[j]-=min(y,V[j]);
			}
			printf("%d\n",cnt);
		}	
	}
}p30;
struct P20{//H == Y == 1
	int A[M],B[M];
	void solve(){
		for(int i=0;i<n;i++)A[++A[0]]=i;
		int x,k,cnt=n;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&k);
			B[0]=0;
			for(int j=1;j<=A[0];j++){
				int y=A[j];
				if((y&x)==y){
					cnt--;
					V[y]=0;
				}
				if(V[y]>0)B[++B[0]]=y;
			}
			A[0]=0;
			for(int j=1;j<=B[0];j++)
				A[++A[0]]=B[j];
			printf("%d\n",cnt);
		}
	}
}p20;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024); 
//	freopen("monster.in","r",stdin);
//	freopen("monster.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&V[i]);
	scanf("%d",&m);
	if(n<=1000)p30.solve();
	else p20.solve();
	return 0;
}
