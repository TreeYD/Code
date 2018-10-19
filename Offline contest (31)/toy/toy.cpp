#include<bits/stdc++.h>
using namespace std;
#define M 100005
char Name[M][15];
bool dir[M];
int n,m;
int main(){//name long long memory mod -
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d%s",&dir[i],Name[i]);
	int pos=0,len;
	bool rev;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&rev,&len);
		rev^=dir[pos];
		pos+=(rev==0)?-len:len;
		pos=((pos%n)+n)%n;
	}
	printf("%s\n",Name[pos]);
	return 0;
}
