#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	freopen("data.in","w",stdout);
	int n=7,m=7,K=2;
	printf("%d %d %d\n",n,m,K);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ",rand()%5);
		puts("");
	}
} 
