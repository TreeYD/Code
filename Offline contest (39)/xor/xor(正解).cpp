#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define uint unsigned int
#define bit(x) (1LL<<x)
const int N=(M<<6)+5;
int fa[N],ID[M];
int n,e,tot,dis[N];
bool vis[N],col[N];
int code(int x,int v){
	return (x-1)*32+v;
}
int getfa(int v){
	if(fa[v]!=v){
		int t=fa[v];
		fa[v]=getfa(t);
		dis[v]^=dis[t];
	}
	return fa[v];
}
int newID(){
	++tot;
	for(int i=0;i<32;i++){
		int c=code(tot,i);
		fa[c]=c;dis[c]=0;
	}
	return tot;
}
//给每一位都编码
int main(){
	scanf("%d%d",&n,&e);
	for(int i=1;i<=n;i++){
		newID();
		ID[i]=i;
	}
	int op,x,y;
	uint z;
	for(int i=1;i<=e;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==2){
			x=ID[x],y=ID[y];
			scanf("%u",&z);
			int cx=code(x,0),cy=code(y,0);
			for(int j=0;j<32;j++){
				int fx=getfa(cx),fy=getfa(cy);
				if(fx!=fy){
					if(z&bit(j)){
						fa[fy]=fx;
						dis[fy]=((1-dis[cy]-dis[cx])%2+2)%2;
					}else{
						fa[fy]=fx;
						dis[fy]=((-dis[cy]-dis[cx])%2+2)%2;
					}
				}else{
					if((dis[cx]+dis[cy])%2!=((z&bit(j))>0)){
						puts("-1");
						return 0;
					}
				}
				cx++,cy++;
			}
		}else{
			int m=y,t=ID[x];
			y=newID();
			ID[x]=y;x=t;
			for(int j=0;j<32;j++){
				int cx=code(x,j),cy=code(y,(j+32-m)%32);
				int fx=getfa(cx);
				fa[cy]=fx;
				dis[cy]=((-dis[cx])%2+2)%2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		long long ans=0;
		for(int j=31;j>=0;j--){
			int x=code(i,j);
			int fx=getfa(x);
			if(vis[fx]){
				ans|=bit(j)*(col[fx]^dis[x]);
			}else{
				fa[x]=x;
				fa[fx]=x;
				dis[fx]=dis[x];
				dis[x]=0;
				vis[x]=1;
			}
		}
		printf("%lld",ans);
		if(i!=n)printf(" ");
	}
	puts("");
	return 0;
}
