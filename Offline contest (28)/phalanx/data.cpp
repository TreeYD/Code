#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int n=rand()%10+1,m=rand()%10+1,q=rand()%10+1;
	printf("%d %d %d\n",n,m,q);
	for(int i=1;i<=q;i++)
		printf("%d %d\n",rand()%n+1,rand()%m+1);
	return 0;
} 
