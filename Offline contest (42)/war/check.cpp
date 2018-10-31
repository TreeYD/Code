#include<bits/stdc++.h>
using namespace std;
#define M 400005
#define N 200005
#define Inf 1061109567 //63
int n,m,Kcnt,Qcnt;
int K[N];
bool in[M];
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
//	freopen("data.in","r",stdin);
//	freopen("check.out","w",stdout);
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
			if(in[E[i][j].id]||K[i]==K[y])continue;
			in[E[i][j].id]=1;
			Q.push((Node){i,y,z,E[i][j].id});
		}
	}
	for(int i=1;i<=Qcnt;i++){
		scanf("%d%d",&x,&z);
		K[x]=z;
		for(int j=0;j<E[x].size();j++){
			if(!in[E[x][j].id]&&K[x]!=K[E[x][j].to]){
				in[E[x][j].id]=1;
				Q.push((Node){x,E[x][j].to,E[x][j].cost,E[x][j].id});
			}
		}
		Node now=Q.top();
		while(K[now.x]==K[now.y]){
			in[now.id]=0;
			Q.pop();now=Q.top();
		}
		printf("ans:%d\n",now.d);	
	}
	return 0;
}
