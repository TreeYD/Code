#include<bits/stdc++.h>
using namespace std;
#define M 10
int B[M],T[M],ID[M],n;
int main(){
//	freopen("data.in","r",stdin);
//	freopen("check.out","w",stdout);
	int Case;
	scanf("%d",&Case);
	while(Case--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&T[i],&B[i]);
			ID[i]=i;
		}
		int res=1e16;
		do{
			bool flag=0;
			int ans=0,mx=0;
			for(int i=1;i<=n&&!flag;i++){
				if(mx-ID[i]>B[ID[i]])flag=1;
				if(i>1)ans+=(T[ID[i-1]]^T[ID[i]]);//-(T[ID[i-1]]&T[ID[i]]);
				mx=max(mx,ID[i]);
			}
			if(!flag&&res>ans){
				res=ans;
				printf("ans:%d\n",ans);
				for(int i=1;i<=n;i++)
					printf("%d ",T[ID[i]]);
				puts("");
			}
		}while(next_permutation(ID+1,ID+1+n));
		printf("%d\n",res);
	}
	return 0;	
}
