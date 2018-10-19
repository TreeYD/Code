#include<bits/stdc++.h>
using namespace std;
#define M 25 
int Vi[M],Si[M];
int N,m,ans=2e9;
void dfs(int x,int LR,int LH,int S,int V){
	if(V+Vi[x]>N)return;
	if(S+Si[x]>=ans)return;
	if(x==m+1){
		if(V==N)ans=S;
		return;
	}
	if(V+(m-x+1)*LH*LR*LR<=N)return;
	for(int i=LR-1;i>=m-x+1;i--){
		for(int j=LH-1;j>=m-x+1;j--)
			dfs(x+1,i,j,S+(2*i*j),V+i*i*j);
	}
}
void Init(){
	for(int i=m;i>=1;i--){
		int R=m-i+1;
		Si[i]=Si[i+1]+2*R*R;
		Vi[i]=Vi[i+1]+R*R*R;
	}
}
int main(){
	scanf("%d%d",&N,&m);
	Init();
	for(int i=N;i>=m;i--)
		for(int j=N/i;j>=m;j--)
			dfs(2,i,j,i*i+2*i*j,i*i*j);
	printf("%d\n",ans);
	return 0;
}
