#include<bits/stdc++.h>
using namespace std;
#define M 1005
int X[M],Y[M];
int K,n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&X[i],&Y[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&K);
		int mx=0,id;
		for(int j=1;j<=n;j++)
			if(Y[j]+K*X[j]>mx)
				mx=Y[j]+K*X[j],id=j;
		printf("ans:%d %d %d\n",mx,X[id],Y[id]);
	}
	return 0;
}
