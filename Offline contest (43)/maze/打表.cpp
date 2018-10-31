#include<bits/stdc++.h>
using namespace std;
int fac[10005];
const int P=1e9+7;
void Make_Table(){
	int L=1,base=2e5;
	while(L<=1e9){	
		int ans=1;
		for(int i=L;i<=L+base-1;i++)
			ans=1LL*ans*i%P;
		printf("%d,",ans);
		L+=base;
	}
}
int main(){
	freopen("Table.out","w",stdout);
	Make_Table();
	return 0;
}
