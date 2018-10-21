#include<bits/stdc++.h>
using namespace std;
int main(){//name memory long long * mod -
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
	freopen("data.in","w",stdout);
//	freopen(".out","w",stdout);
	srand(time(NULL));
	int n=rand()%500+1,k=rand()%min(n,10)+1;
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%20+1);
	puts("");
	return 0;
}
