#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct P50{
	#define Mn 50005
	#define LL long long
	long long mp[505][Mn],lst[Mn];
	int qx[Mn],qy[Mn],h[Mn],A[Mn];
	void solve(){
		int x,y,i,j,t=0;
		for(i=1;i<=q;i++){
			scanf("%d%d",&qx[i],&qy[i]);
			h[++t]=qx[i];
		}
		sort(h+1,h+1+q);
		t=unique(h+1,h+1+q)-h-1;
		for(i=1;i<=q;i++){
			qx[i]=lower_bound(h+1,h+1+t,qx[i])-h;
			if(!mp[qx[i]][1])
				for(j=1;j<m;j++)
					mp[qx[i]][j]=j+1LL*(h[qx[i]]-1)*m;
		}
		for(i=1;i<=n;i++)lst[i]=lst[i-1]+m;
		for(i=1;i<=q;i++){
			x=qx[i],y=qy[i];
			long long ans;
			if(y!=m)printf("%lld\n",ans=mp[x][y]);
			else printf("%lld\n",ans=lst[h[x]]);
			if(y!=m){
				for(j=y;j<m-1;j++)mp[x][j]=mp[x][j+1];
				mp[x][m-1]=lst[h[x]];
			}
			for(j=h[x];j<n;j++)lst[j]=lst[j+1];
			lst[n]=ans;
		}
	}
}p50;
struct P_x_1{
	#define M 1000005
	#define Ls p<<1
	#define Rs p<<1|1
	#define LL long long
	struct node{
		int L,R;
		int sz;
		LL num;
	}T[M<<2];
	void Build(int L,int R,int p){
		T[p].L=L,T[p].R=R;
		if(L==R){
			if(L<=n+m-1){
				T[p].sz=1;
				if(L>m){
					T[p].num=m+1LL*(L-m)*m;
				}else T[p].num=L;
			}
			return;
		}
		int mid=(L+R)>>1;
		Build(L,mid,Ls);
		Build(mid+1,R,Rs);
		T[p].sz=T[Ls].sz+T[Rs].sz;
	}
	LL Query(int x,int p){
		if(T[p].L==T[p].R){
			LL t=T[p].num;
			T[p].sz=0;T[p].num=0;
			return t;
		}
		int mid=T[Ls].R;
		LL ans;
		if(T[Ls].sz>=x)ans=Query(x,Ls);
		else ans=Query(x-T[Ls].sz,Rs);
		T[p].sz=T[Ls].sz+T[Rs].sz;
		return ans;
	}
	void Update(int x,int p,LL v){
		if(T[p].L==T[p].R){
			T[p].sz=1;
			T[p].num=v;
			return;
		}
		int mid=T[Ls].R;
		if(x<=mid)Update(x,Ls,v);
		else Update(x,Rs,v);
		T[p].sz=T[Ls].sz+T[Rs].sz;
	}
	void solve(){
		int x,y,i,cnt=n+m-1;
		Build(1,n+m+q,1);
		for(i=1;i<=q;i++){
			scanf("%d%d",&x,&y);
			++cnt;
			LL ans=Query(y,1);
			printf("%lld\n",ans);
			Update(cnt,1,ans);
		}
	}
}px1;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	if(q<=500)p50.solve();
	else px1.solve();
	return 0;
}
