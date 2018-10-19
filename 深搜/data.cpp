#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int n=rand()%30+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%20+1);
	puts("");
}
