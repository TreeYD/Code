#include<bits/stdc++.h>
using namespace std;
#define M 50005
int D[M],Len,n,m;
bool check(int x){
	int k=0,lst=0;
	for(int i=1;i<=n;i++){
		if(D[i]-lst>=x)lst=D[i];
		else k++;
	}
	return k<=m;
}
void Find(){
	int L=0,R=Len,ans;
	while(L<=R){
		int mid=L+R>>1;
		if(check(mid)){
			ans=mid;
			L=mid+1;
		}else R=mid-1;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d%d",&Len,&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&D[i]);
	D[++n]=Len;
	Find();
	return 0;
}
