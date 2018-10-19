#include<bits/stdc++.h>
using namespace std;
int A[105],cnt;
int len,res,n,t;
void Add(){
	A[1]++;
	if(A[1]==2)cnt--;
	else cnt++;
	int i;
	for(i=1;;i++){
		if(A[i]>=2){
			A[i]=0;
			if(A[i+1]&1)cnt--;
			else cnt++;
			A[i+1]++;
		}else break;
	}
	len=max(len,i);
	res+=(cnt>len-cnt);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)Add();
	printf("%d %d\n",res,n-res);
	return 0;
}

