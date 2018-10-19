#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define LL long long
template<class T>void Max(T &x,T y){if(x<y)x=y;}
vector<int>E[M];
int Rt,Mx,tot[M],big[M];
bool mark[M];
int tot_sz,tot_dep;
int mo[M],cnt[M],tot_cnt;
LL dis[M],tot_dis;
void Init(){
	mo[1]=1;
	for(int i=2;i<M;i++)mo[i]=-1;
	for(int i=2;i<M;i++){
		if(!mark[i]){
			for(int j=i;j<M;j+=i){
				if((j/i)%i==0)mo[j]=0;
				else mo[j]=-mo[j];
			}
		}
		if(mo[i]){
			for(int j=i;j<M;j+=i)
				son[j].push_back(i);
		}
	}
}
void GetRt(int x){
	dfs_find(x,0);
	tot_sz=0;
	tot_dep=0;
	dfs_init(Rt,0,1);
}
void dfs_init(int x,int f,int d){
	sz[x]=1;tot_sz++;
	tot_dep+=d;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f||vis[y])continue;
		dfs_init(y,x,d+1);
		sz[x]+=sz[y];
	}
}
void dfs_find(int x,int f){
	tot[x]=1;big[x]=0;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f||vis[y])continue;
		dfs_find(y,x);
		tot[x]+=tot[y];
		Max(big[x],tot[y]);
	}
	Max(big[x],tot_sz-tot[x]);
	if(big[x]<Mx)Mx=big[x],Rt=x;
}
void dfs_add(int x,int f,int d,int dep){
	for(int i=0;i<son[x].size();i++){
		cnt[son[x][i]]+=d;
		dis[son[x][i]]+=dep*d;
	}
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f||vis[y])continue;
		dfs_add(y,x,d,dep+1);
	}
}
void dfs_calc(int x,int f,int d){
	tot_cnt+=tot_sz*d;
	tot_dis+=tot_dep*d;
	for(int i=0;i<son[x].size();i++){
		int v=son[x][i];
		tot_cnt-=cnt[v]*mo[v]*d;
		tot_dis-=dis[v]*mo[v]*d;
	}
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f||vis[y])continue;
		dfs_calc(y,x,d);
	}
}
void Divide(int x){
	vis[x]=1;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(vis[y])continue;
		dfs_calc()
	}
	
}
int main(){
	
	return 0;
}
