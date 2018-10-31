#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define LL long long
const int P=1e9+7;
int two[M],A[M],n,ans;
template<class T>void Add(T &x,LL y){
	x+=y;
	if(x>=P)x-=P;
	if(x<0)x+=P;
}
int main(){
	scanf("%d",&n);
	two[0]=1;
	for(int i=1;i<=n;i++){
		two[i]=two[i-1]%P;	
		scanf("%d",&A[i]);
	}
	sort(A+1,A+1+n);
	int have=0,lst;
	for(int i=1;i<=n;i++){
		if(A[i]!=A[i-1])lst=i;
		int tmp=have;
		Add(have,two[lst-1]);
		Add(ans,1LL*two[i-1]*A[i]%P-1LL*have%P);
		Add(have,tmp);
	}
	printf("%d",ans);
	return 0;
}
