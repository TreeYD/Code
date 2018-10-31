#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define bit(x) (1<<x)
template<class T>void Add(T &x,T y){if(x<1e9)x+=y;}
int S,sz,sum[75][(1<<17)+5];
int H[M],X[M],Y[M],Ans[M];
int base,all,n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&H[i]);
//	printf("%lld\n",S);
	while((1<<base)<=n)base++;
	all=(1<<base)-1;
	scanf("%d",&m);
	S=sqrt(n+1LL*n*n*log2(n)/m);
	sz=m/S;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&X[i],&Y[i]);
		X[i]&=base;
		Add(sum[i/S][X[i]],Y[i]);
	}
	printf("S:%d\n",S);
	for(int i=0;i<=sz;i++)
		for(int j=0;j<=16;j++)
			for(int k=all;k>=0;k--)
				if(k&bit(j))Add(sum[i][k^bit(j)],sum[i][j]);
	for(int i=1;i<=n;i++){
		int tot=0,p=0;
		for(p=0;p<=sz;p++){
			if(tot+sum[p][i]>=H[i])break;
			Add(tot,sum[p][i]);
//			if(tot>=H[i])break;
//			printf("adding:%d\n",tot);
		}
		if(p>sz)continue;
		puts("Gone");
		printf("tot:%d p:%d\n",tot,p);
		for(int j=p*S+1;j<=min(m,(p+1)*S);j++){
			if(X[j]&i==i)Add(tot,Y[j]);
			if(tot>=H[i]){
				Ans[j]++;
				printf("die at:%d\n",j);
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		Ans[i]+=Ans[i-1];
		printf("%d\n",n-Ans[i]);
	}
	return 0;
}
