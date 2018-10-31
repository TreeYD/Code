#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int n=200,m=200,K=1e9;
	printf("%d %d %d\n",n,m,K);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%c",'a'+rand()%26);
		puts("");
	}
	return 0;
}
