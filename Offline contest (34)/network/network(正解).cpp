#include<bits/stdc++.h>
using namespace std;
#define M 100005
set<int>s[M];
set<int>::iterator it1;
map<int,int>cnt[M],dis[M];
map<int,int>::iterator it2;
vector<int>son[M],E[M];
int A[M],num,pos,n,dep[M];
long long res,tmp1,tmp2;
void Init(){
	for(int i=2;i<=M-5;i++)
		if(son[i].size()==0){
			for(int j=i;j<=M-5;j+=i){
				son[j].push_back(i);
			}
		}
}
void dfs(int x,int r,int c){
	if(x==son[num].size()){
		int flag=(c&1)?1:-1;
		tmp1+=flag*dis[pos][r];
		tmp2+=flag*cnt[pos][r];
		return;
	}
	dfs(x+1,r*son[num][x],c+1);
	dfs(x+1,r,c);
}
void Merge(int x,int y){
	if(s[x].size()<s[y].size()){
		swap(dis[x],dis[y]);
		swap(cnt[x],cnt[y]);
		swap(s[x],s[y]);
	}
	pos=x;
	for(it1=s[y].begin();it1!=s[y].end();it1++){
		int a=*it1;
		num=A[a];
		dfs(0,1,0);
		tmp1=
		res+=tmp1+tmp2*dep[a]-tmp2*2*dep[x];
	}
	for(it1=s[y].begin();it1!=s[y].end();it1++)
		s[x].insert(*it1);
	s[y].clear();
	for(it2=dis[y].begin();it2!=dis[y].end();it2++){
		dis[x][it2->first]+=dis[y][it2->second];
	}
	dis[y].clear();
	for(it2=cnt[y].begin();it2!=cnt[y].end();it2++)
		cnt[x][it2->first]+=cnt[y][it2->second];
	cnt[y].clear();
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	for(int i=0;i<son[A[x]].size();i++){
		dis[x][son[A[x]][i]]+=dep[x];
		cnt[x][son[A[x]][i]]++;
		printf("%d %d %d\n",A[x],son[A[x]][i],cnt[x][son[A[x]][i]]);
	}
	s[x].insert(x);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==f)continue;
		dfs(y,x);
		Merge(x,y);
	}
}
int main(){
	Init();
//	printf("%.2lf\n",(sizeof(cnt)+sizeof(s)+sizeof(son))/1024.0/1024);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1,0);
	printf("%lld\n",res);
	return 0;
}
