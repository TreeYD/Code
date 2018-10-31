#include<bits/stdc++.h>
using namespace std;
#define M 200005
struct Node{
	int a,b,id;
	bool operator<(const Node &x)const{
		return a<x.a;
	}
}A[M<<1];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*2+1;i++){
		scanf("%d%d",&A[i].a,&A[i].b);
		A[i].id=i;
	}
	sort(A+1,A+1+n*2+1);
	for(int i=1;i<=n;i++){
		int a=2*i-1,b=2*i;	
		if(A[a].b>A[b].b)printf("%d\n",A[a].id);
		else printf("%d\n",A[b].id);
	}
	printf("%d\n",A[n*2+1].id);
	return 0;
}
