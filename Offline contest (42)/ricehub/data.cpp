#include<bits/stdc++.h>
using namespace std;
int A[30];
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int n=rand()%25+1,m=10000,B=rand()%100+1;
	printf("%d %d %d\n",n,m,B);
	for(int i=1;i<=n;i++)
		A[i]=rand()%m+1;
	sort(A+1,A+1+n);
	for(int i=1;i<=n;i++)
		printf("%d ",A[i]);
	puts("");
	return 0;
}
