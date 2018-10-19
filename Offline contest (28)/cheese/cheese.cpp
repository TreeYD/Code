#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define LL long long
int Q[M],n,h,r;
bool vis[M];
vector<int>E[M];
struct node{
	int x,y,z;
}A[M];
bool check(int x,int y){
    LL dis=1LL*(A[x].x-A[y].x)*(A[x].x-A[y].x)+1LL*(A[x].y-A[y].y)*(A[x].y-A[y].y)+1LL*(A[x].z-A[y].z)*(A[x].z-A[y].z);
	if(dis<=1LL*(2*r)*(2*r))return 1;
	return 0;
}
bool BFS(){
	int L=1,R=0,i;
	for(i=1;i<=n;i++){
		if(A[i].z-r<=0){
			vis[i]=1;	
			Q[++R]=i;
		}
	}
	while(L<=R){
		int x=Q[L++];
		if(A[x].z+r>=h)return 1;
		for(i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(vis[y])continue;
			vis[y]=1;Q[++R]=y;
		}
	}
	return 0;
}
int main(){//name long long memory mod
	int T;
	scanf("%d",&T);
	printf("%d\n",T);
	while(T--){
//		cnt++;
//		if(cnt==8)printf("n:%d\n",n);
		scanf("%d%d%d",&n,&h,&r);
		int x,y,z,i,j;
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			A[i]=(node){x,y,z};
		}
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++){
				if(check(i,j)){
					E[i].push_back(j);
					E[j].push_back(i);
				}
			}
		bool ans=BFS();
//		printf("Case:%d\n",20-T);
		if(ans)puts("Yes");
		else puts("No");
		for(i=1;i<=n;i++){
			E[i].clear();
			vis[i]=0;
		}
	}
	return 0;
}
