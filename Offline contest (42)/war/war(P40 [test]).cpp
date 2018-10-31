#include<bits/stdc++.h>
using namespace std;
#define M 400005
#define N 200005
int n,m,Kcnt,Qcnt;
int K[N];
struct Node{
	int x,y,d,id;
	bool operator<(const Node &x)const{
		return d>x.d;	
	}
};
priority_queue<Node>Q;
struct edge{
	int to,cost,id;
};
vector<edge>E[N];
int main(){
	scanf("%d%d%d%d",&n,&m,&Kcnt,&Qcnt);
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		E[x].push_back((edge){y,z,i});
		E[y].push_back((edge){x,z,i});
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&K[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<E[i].size();j++){
			int y=E[i][j].to,z=E[i][j].cost;
			if(K[i]==K[y])continue;
			Q.push((Node){i,y,z});
		}
	}
	for(int i=1;i<=Qcnt;i++){
		scanf("%d%d",&x,&z);
		K[x]=z;
		for(int j=0;j<E[x].size();j++){
			if(K[x]!=K[E[x][j].to]){
				Q.push((Node){x,E[x][j].to,E[x][j].cost});
			}
		}
		Node now=Q.top();
		while(K[now.x]==K[now.y]){
			Q.pop();now=Q.top();
		}
		printf("%d\n",now.d);	
	}
	return 0;
}
