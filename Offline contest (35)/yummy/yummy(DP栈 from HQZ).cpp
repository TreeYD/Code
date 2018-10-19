#include<bits/stdc++.h>
using namespace std;
#define N 4005
#define M 10005
const int Maxv=4000;
template<class T>void Max(T &x,T y){if(x<y)x=y;}
struct Node{
	int c,h,t;
	bool operator<(const Node &x)const{
		return t<x.t;
	}
}S[N];
struct Query{
	int a,b,id;
	bool operator<(const Query &x)const{
		return a<x.a;
	}
}Q[M<<1];
int n,p,q,Tmax,tf,tb;
int front[N],back[N];
int dp[2][N][N],Ans[M<<1];
int main(){
	scanf("%d%d",&n,&p);
	int x,y,z;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		S[i]=(Node){x,y,z};
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		Q[i]=((Query){x,y,i});
		Max(Tmax,x);
	}
	int id=1,qid=1;
	sort(S+1,S+1+n);
	sort(Q+1,Q+1+q);
	for(int i=1;i<=Tmax;i++){
		while(tf&&S[front[tf]].t+p-1<i)tf--;
		while(S[id].t==i){
			back[++tb]=id;
			for(int j=0;j<=Maxv;j++)dp[1][tb][j]=dp[1][tb-1][j];
			for(int j=Maxv;j>=S[id].c;j--)
				Max(dp[1][tb][j],dp[1][tb-1][j-S[id].c]+S[id].h);
			id++;
		}
		if(!tf){
			while(tb){
				front[++tf]=back[tb--];
				int id=front[tf];
				for(int j=0;j<=Maxv;j++)dp[0][tf][j]=dp[0][tf-1][j];
				for(int j=Maxv;j>=S[id].c;j--)
					Max(dp[0][tf][j],dp[0][tf-1][j-S[id].c]+S[id].h);
			}
		}
		while(Q[qid].a==i){
			int v=Q[qid].b,id=Q[qid].id;
			for(int k=0;k<=v;k++)
				Max(Ans[id],dp[0][tf][k]+dp[1][tb][v-k]);
			qid++;
		}
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",Ans[i]);
	return 0;
}
