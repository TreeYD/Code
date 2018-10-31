#include<bits/stdc++.h>
using namespace std;
#define M 100005
template<class T>void Max(T &x,T y){if(x<y)x=y;}
int mx[M][20],n,m;
void St_Init(){
	for(int j=1;j<=18;j++)
		for(int i=1;i+(1<<j)-1<=M-5;i++){
			Max(mx[i][j],mx[i][j-1]);
			Max(mx[i][j],mx[i+(1<<j-1)][j-1]);
		}
}
int main(){
	memset(mx,-1,sizeof(mx));
	int t,v,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&t,&v);
		Max(mx[t][0],v);
	}
	St_Init();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		int s=log2(b-a+1);
		int ans=max(mx[a][s],mx[b-(1<<s)+1][s]);
		if(ans==-1)puts("None");
		else printf("%d\n",ans);
	}
	return 0;
}
