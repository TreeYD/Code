#include<bits/stdc++.h>
using namespace std;
#define M 8000005
int n,m,q,u,v,t;
struct que{
	int num[M],L,R;
	que(){memset(num,-125,sizeof(num));L=R=0;}
	int front(){return num[L];}
	void pop(){L++;}
	void push(int a){num[R++]=a;}
	bool operator>(const que &x)const{
		return num[L]>x.num[x.L];
	}
}Q[3];
bool cmp(int a,int b){
	return a>b;
}
int Getmx(){
	int res=0;
	if(Q[1]>Q[0])res=1;
	if(Q[2]>Q[res])res=2;
	return res;
}
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		Q[0].push(x);
	}
	sort(Q[0].num,Q[0].num+n,cmp);
	int tot=0;
	for(int i=1;i<=m;i++){
		int ID=Getmx();
		int p=Q[ID].front();Q[ID].pop();
		int p1=1LL*(p+tot)*u/v-tot,p2=p-p1-tot;
		bool flag=0;
		Q[1].push(p1-q),Q[2].push(p2-q);
		if(i%t==0)printf("%d ",p+tot);
		tot+=q;
	}
	puts("");
	int cnt=0;
	for(int i=n+m;i>=1;i--){
		cnt++;
		int ID=Getmx();
		if(cnt%t==0)
			printf("%d ",Q[ID].front()+tot);
		Q[ID].pop();
	}
	puts("");
}
