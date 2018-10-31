#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int K=rand()%3+1,n=(rand()%4+1)*K,Q=rand()%5+1;
	printf("%d %d %d\n",n,K,Q);
	for(int i=1;i<=Q;i++)
		printf("%d %d\n",rand()%2+1,rand()%10+1);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%20+1);
	puts("");
	
}
