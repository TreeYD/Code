#include<bits/stdc++.h>
using namespace std;
#define M 305
int A[5][M],n;
int S1[M*M],S2[M*M];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int j=0;j<5;j++)
			for(int i=1;i<=n;i++)
				scanf("%d",&A[j][i]);
		int tot=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				S1[++tot]=A[0][i]+A[1][j];
		tot=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				S2[++tot]=A[2][i]+A[3][j];
		sort(S1+1,S1+1+tot);
		sort(S2+1,S2+1+tot);
		bool flag=0;
		for(int i=1;i<=n&&!flag;i++){
			int L=1,R=tot;
			int lim=-A[4][i];
			for(int L=1,R=tot;L<=tot;L++){
				while(R>=1&&S1[L]+S2[R]>lim)R--;
				if(S1[L]+S2[R]==lim){
					flag=1;break;
				}
			}
		}
		if(!flag)puts("NO");
		else puts("YES");
	}
	return 0;
}
