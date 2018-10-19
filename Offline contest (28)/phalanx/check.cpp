#include<bits/stdc++.h>
using namespace std;
#define M 300005
#define MM (300005*20)
#define LL long long
int Lson[MM],Rson[MM],tot;
int Sum[MM],rt[M],n,m,q;
LL val[M<<1];
vector<LL>num[M];
int query(int L,int R,int &tid,int x){
	if(tid==0){
		tid=++tot;
		Sum[tid]=R-L+1;
	}
	Sum[tid]--;
	if(L==R)return L;
	int mid=(L+R)>>1,v;
	if(!Lson[tid])v=mid-L+1;
	else v=Sum[Lson[tid]];
	if(x<=v)return query(L,mid,Lson[tid],x);
	return query(mid+1,R,Rson[tid],x-v);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("check.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int x,y,i;
	for(i=1;i<=n;i++)
		val[i]=val[i-1]+m;
	int szv=n;
	LL ans;
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(y==m){
			printf("%lld\n",val[++szv]=ans=val[query(1,n+q,rt[0],x)]);
		}else{
			int t=query(1,m+q,rt[x],y);
			if(t<m)ans=1LL*(x-1)*m+t;
			else ans=num[x][t-m];
			printf("%lld\n",ans);
			val[++szv]=ans;
			num[x].push_back(val[query(1,n+q,rt[0],x)]);
		}
	}
	return 0;
}
