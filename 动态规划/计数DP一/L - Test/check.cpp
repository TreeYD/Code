#include<bits/stdc++.h>
using namespace std;
int m,k,cnt[20005];
void Init(){
	for(int i=1;i<=20000;i++)
		cnt[i]=cnt[i&i-1]+1;
}
int main(){
	freopen("L.in","r",stdin);
	freopen("check.out","w",stdout);
	Init();
	scanf("%d%d",&m,&k);
	int i,j;
//	for(i=1;i<=10;i++){
//		printf("%d:\n",i); 
//		for(j=1;j<=1000;j++){
//			if(cnt[j]==i)printf("%d ",j);
//		}
//		puts("");
//	}
	for(i=0;i<=10000;i++){
		int c=0;
		for(j=i+1;j<=2*i;j++)
			if(cnt[j]==k)c++;
		if(c==m){
			printf("%d\n",i);
			return 0;
		}	
	}
	return 0;
}
