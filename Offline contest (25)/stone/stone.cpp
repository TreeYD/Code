#include<bits/stdc++.h>
using namespace std;
#define M 50005
int D[M],len,n,m;
bool mark[M];
int L[M],R[M];
struct node{
	int a,b,l;
	bool operator<(const node &x)const{
		return l>x.l;
	}
};
priority_queue<node>Q;
int main(){
//	freopen("stone.in","r",stdin);
//	freopen("stone.out","w",stdout);
	scanf("%d%d%d",&len,&n,&m);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&D[i]);
		Q.push((node){i-1,i,D[i]-D[i-1]});
		L[i]=i-1,R[i]=i+1;
	}
	R[0]=1;L[n+1]=n;
	Q.push((node){n,n+1,len-D[n]});
	while(m){
		int x=Q.top().a,y=Q.top().b;
		Q.pop();
		if(mark[x]||mark[y])continue;
		int l=L[x],r=R[y];
		if(x!=0&&(y==n+1||D[x]-D[l]<D[r]-D[y])){
			mark[x]=1;m--;
			Q.push((node){l,y,D[y]-D[l]});
			R[l]=y;L[y]=l;
		}else if(y!=n+1){
			mark[y]=1;m--;
			Q.push((node){x,r,D[r]-D[x]});
			L[r]=x;R[x]=r;
		}
	}
	int lst=0,ans=2e9;
	for(i=1;i<=n;i++){
		if(!mark[i]){
			ans=min(ans,D[i]-lst);
			lst=D[i];
		}
	}
	ans=min(ans,len-lst);
	printf("%d\n",ans);
	return 0;
}
