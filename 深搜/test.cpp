#include<bits/stdc++.h>
using namespace std;
int goal,mxd;
int s1[25],s2[25],sz;
bool flag;
int H(int lft,int p){
	return p*pow(2,lft);
}
void dfs(int lft,int a,int b){
	if(flag)return;
	if(H(lft,b)<goal)return;
	s1[++sz]=a;s2[sz]=b;
	if(lft==0){
		flag|=(a==goal||b==goal);
		if(a==goal||b==goal)
			for(int i=1;i<=sz;i++)
				printf("%d %d\n",s1[i],s2[i]);
		sz--;
		return;
	}
	dfs(lft-1,b,a+b);
	dfs(lft-1,a,a+b);
	if(b-a>=a){
		dfs(lft-1,a,b-a);
		dfs(lft-1,2*a,b);
	}else{
		dfs(lft-1,b-a,a);
		dfs(lft-1,b,2*a);
	}
	dfs(lft-1,b-a,b);
	dfs(lft-1,a,2*b);
	dfs(lft-1,b,2*b);
	dfs(lft-1,a,2*a);
	sz--;
}
int main(){
	scanf("%d",&goal);
	for(mxd;;mxd++){
		dfs(mxd,0,1);
		if(flag)break;
	}
	printf("%d\n",mxd);
	return 0;
}
