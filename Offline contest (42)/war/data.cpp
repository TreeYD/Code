#include<bits/stdc++.h>
using namespace std;
#define M 1005
int A[M];
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int n=rand()%5+5,m=n*2,K=rand()%5+2,q=rand()%5+1;
	for(int i=1;i<=n;i++)A[i]=i;
	random_shuffle(A+1,A+1+n);
	printf("%d %d %d %d\n",n,m,K,q);
	for(int i=2;i<=n;i++)
		printf("%d %d %d\n",A[rand()%(i-1)+1],A[i],rand()%10+1);
	for(int i=n;i<=m;i++)
		printf("%d %d %d\n",A[rand()%n+1],A[rand()%n+1],rand()%10+1);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%K+1);
	puts("");
	for(int i=1;i<=q;i++){
		printf("%d %d\n",rand()%n+1,rand()%K+1);	
	}
	return 0;	
}
