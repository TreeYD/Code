#include<bits/stdc++.h>
using namespace std;
int main(){//name memory long long * mod - «–∑÷≈–∂œ 
	//printf("%.2lf",(sizeof(p))/1024.0/1024);
	//freopen(".in","r",stdin);
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int n=rand()%10+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		int f=rand()%10;
		if(f==1){
			int a=rand()%2,b=rand()%2;
			printf("%d %d\n",a==0?650:0,b==0?650:0);
		}else printf("%d %d\n",rand()%651,rand()%651);
	}
	return 0;
}
