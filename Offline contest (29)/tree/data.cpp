#include<bits/stdc++.h>
using namespace std;
int A[100005];
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int n=rand()%20+2,m=rand()%20+2,i;
	printf("%d\n",n);
	for(i=1;i<=n;i++)A[i]=i;
	for(i=1;i<=n;i++)swap(A[i],A[rand()%n+1]);
	for(i=2;i<=n;i++)printf("%d %d\n",A[rand()%(i-1)+1],A[i]);
	printf("%d\n",m);
	for(i=1;i<=m;i++){
		int x,y;
		do{
			x=rand()%n+1,y=rand()%n+1;
		}while(x==y);
		printf("%d %d\n",x,y);
	}
	return 0;
}
