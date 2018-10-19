#include<bits/stdc++.h>
using namespace std;
#define M 2005 
const int P=1e9+7;
int A[M],n,h;
int Solve(){
	n++;
	long long res=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int t=A[i]-A[i-1];
		if(t>1||t<-1)return 0;
		if(t==0)res=res*(cnt+1)%P;
		else if(t==1)cnt++;
		else if(t==-1){
			res=res*cnt%P;
			cnt--;
		}
	}
	return res;
}
int main(){
	int i;
	scanf("%d%d",&n,&h);
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
		A[i]=h-A[i];
	}
	printf("%d\n",Solve());	
	return 0;
}
