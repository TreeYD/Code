#include<bits/stdc++.h>
using namespace std;
#define M 500005
int H[M],S[M],n,m;
int ans[M];
struct P60{
	void solve(){
		int s;
		for(int i=1;i<=m;i++){
			scanf("%d",&s);
			bool have=0;
			int cnt=0;
			for(int j=1;j<=n+1;j++){
				if(H[j]>s)have=1;
				else{
					cnt+=have;
					have=0;
				}
			}
			printf("%d\n",cnt);	
		}
	}
}p60;
struct P100{
	void solve(){
		for(int i=1;i<=m;i++)
			scanf("%d",&S[i]);
		int L=1;
		for(int i=1;i<=n;i++){
			if(H[i]!=H[i+1]){
				int x=lower_bound(S+1,S+1+m,H[i])-S;
				if(H[L-1]<H[i]&&H[i+1]<H[i])ans[x]--;
				if(H[i]<H[L-1]&&H[i]<H[i+1])ans[x]++;
				L=i+1;	
			}
		}
		ans[0]=1;
		for(int i=1;i<=m;i++){
			ans[i]+=ans[i-1];
			printf("%d\n",ans[i]);
		}
	}
}p100;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ³õÖµ
//	printf("%.2lf\n",(sizeof(p))/1024.0/1024);
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&H[i]);
	p100.solve();
	return 0;	
}
