#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int T=rand()%5+1;
	printf("%d\n",T);
	while(T--){
		int n=rand()%5+5;
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
			printf("%d %d\n",rand()%10+1,rand()%5+1);
		puts("");
	}
	return 0;	
}
