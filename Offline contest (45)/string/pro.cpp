#include <bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
enum {N=100100};
char A[N],B[N];
int a,b,la,lb,k;
int main () {
	scanf("%s%s%d%d%d",A+1,B+1,&a,&b,&k);
	la=strlen(A+1);
	lb=strlen(B+1);
	if (!a) {
		puts("0");
		return 0;
	}
	if (!b) {
		int res=abs(la-lb)*a;
		if (res<=k) printf("%d\n",res);
		else puts("-1");
		return 0;
	}
	int res=0;
	For(i,1,min(la,lb))
	if (A[i]!=B[i]) res+=b;
	res+=abs(la-lb)*a;
	if (res<=k) printf("%d\n",res);
	else puts("-1");
	return 0;
}
//这个代码肯定过不了。
