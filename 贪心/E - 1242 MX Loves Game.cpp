#include<bits/stdc++.h>
using namespace std;
#define M 305
#define Inf 0x7f7f7f
int A[M][M];
int B[M][M];
int C[M][M];
int n,mp[M],pos[M];
bool Check(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(C[i][1]!=B[j][1])continue;
			for(int k=1;k<=n;k++)
				if(C[i][k]!=B[j][k])return 0;
		}
	}
	return 1;
}
int Solve(int k){
	int ans=0;
	memcpy(C,A,sizeof(A));
	for(int i=1;i<=n;i++){
		mp[B[k][i]]=i;
		pos[A[k][i]]=i;
	}
	for(int i=1;i<=n;i++){
		int a=mp[A[k][i]];
		if(C[k][a]==A[k][i])continue;
		ans++;
//		printf("%d %d swap:%d %d\n",C[k][a],A[k][i],a,i);
		pos[C[k][a]]=pos[A[k][i]];
		for(int j=1;j<=n;j++){
			C[j][pos[A[k][i]]]=C[j][a];
			C[j][a]=A[j][i];
		}
		pos[A[k][i]]=a;
	}
//	printf("%d %d\n",k,ans);
	if(!Check())return Inf;
	for(int i=1;i<=n;i++){
		mp[B[i][1]]=i;
		pos[C[i][1]]=i;
	}
	for(int i=1;i<=n;i++){
		int s=pos[i],e=mp[i];
		if(s==e)continue;
		ans++;
		int tmp=C[s][1];
		C[s][1]=C[e][1];
		pos[C[e][1]]=s;
		C[e][1]=tmp;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&A[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&B[i][j]);
	int ans=Inf;
	for(int i=1;i<=n;i++)
		ans=min(ans,Solve(i));
	printf("%d\n",ans==Inf?-1:ans);
	return 0;	
}
