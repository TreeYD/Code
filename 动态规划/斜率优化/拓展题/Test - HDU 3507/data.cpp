#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int n=rand()%10+1,m=rand()%1000+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		int f=rand()%5;
		if(f==0)puts("0");
		else printf("%d\n",rand()%101);
	}
//	puts("");
	return 0;
}
