#include<bits/stdc++.h>
using namespace std;
int P,mxd;
bool flag;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void dfs(int lft,int a,int b){
	if(a==0&&b==0)return;
	if(a>b)swap(a,b);
	if(P%gcd(b,a)!=0||flag)return;
	if((b<<lft)<P)return;
	if(lft==0){
		flag|=(a==P||b==P);
		return;
	}
	if(a==b){
		dfs(lft-1,a,a+b);
		return;
	}
	if(a){
		dfs(lft-1,a,b-a);
		dfs(lft-1,a,a+b);
		dfs(lft-1,2*a,b);
		dfs(lft-1,2*a,a);
	}
	dfs(lft-1,b,a+b);
	dfs(lft-1,b,b-a);
	dfs(lft-1,a,2*b);
	dfs(lft-1,b,2*b);
}
int main(){
	scanf("%d",&P);
	for(mxd;mxd<P;mxd++){
		dfs(mxd,0,1);
		if(flag)break;
	}
	printf("%d\n",mxd);
	return 0;
}
