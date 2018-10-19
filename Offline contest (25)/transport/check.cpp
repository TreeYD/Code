#include<bits/stdc++.h>
#define M 300005
using namespace std;
int n,m,id;
int fa[M],dis[M],dep[M],tos[M],sz[M];
int son[M],top[M],val[M],di[M],pos[M],pre[M],beh[M];
bool mark[M];
struct edge {
    int to,val;
};
struct node {
    int u,v,lca,dis;
} Q[M];
vector<edge>E[M];
void dfs(int x,int f) {
    dep[x]=dep[f]+1,sz[x]=1,son[x]=0;
    for(int i=0; i<E[x].size(); i++) {
        int y=E[x][i].to,z=E[x][i].val;
        if(y==f)continue;
        tos[y]=tos[x]+z,fa[y]=x;
        dfs(y,x);
        sz[x]+=sz[y];
        if(sz[son[x]]<sz[y])son[x]=y;
    }
}
void dfs_top(int x,int tp) {
    top[x]=tp;
    if(son[x])dfs_top(son[x],tp);
    for(int i=0; i<E[x].size(); i++) {
        int y=E[x][i].to;
        if(y==fa[x]||y==son[x])continue;
        dfs_top(y,y);
    }
}
int lca(int x,int y) {
    while(top[x]!=top[y]) {
        if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
        else y=fa[top[y]];
    }
    if(dep[x]<dep[y])return x;
    return y;
}
void redfs(int x,int f) {
    fa[x]=f;
    for(int i=0; i<E[x].size(); i++) {
        int y=E[x][i].to;
        if(y==f)continue;
        dis[y]=E[x][i].val;
        redfs(y,x);
    }
}
void divdfs(int x,int Id) {
    pos[x]=Id;
    for(int i=0; i<E[x].size(); i++) {
        int y=E[x][i].to;
        if(y==fa[x]||mark[y])continue;
        divdfs(y,Id);
    }
}
int main() {
	freopen("transport2.in","r",stdin);
	freopen("check.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<n; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        E[a].push_back((edge) {
            b,c
        });
        E[b].push_back((edge) {
            a,c
        });
    }
    dfs(1,0);
    dfs_top(1,1);
    int mxid,mx=0;
    for(int i=1; i<=m; i++) {
        scanf("%d%d",&Q[i].u,&Q[i].v);
        Q[i].lca=lca(Q[i].u,Q[i].v);
        Q[i].dis=tos[Q[i].u]+tos[Q[i].v]-2*tos[Q[i].lca];
        if(Q[i].dis>mx) {
            mx=Q[i].dis;
            mxid=i;
        }
    }
    redfs(Q[mxid].u,-1);
    for(int i=Q[mxid].v; ~i; i=fa[i])mark[i]=1;
    for(int i=Q[mxid].v; ~i; i=fa[i]) {
        divdfs(i,++id);
        printf("%d\n",i);
        if(fa[i]!=-1)val[id]=dis[i];
    }
    for(int i=1; i<=m; i++) {
        if(i==mxid)continue;
        int x=pos[Q[i].u],y=pos[Q[i].v];
        if(x>y)swap(x,y);
        beh[x]=max(beh[x],Q[i].dis);
        pre[y]=max(pre[y],Q[i].dis);
    }
    for(int i=id-1; i>=1; i--)beh[i]=max(beh[i],beh[i+1]);
    for(int i=2; i<=id; i++)pre[i]=max(pre[i],pre[i-1]);
    int ans=1e9;
    for(int i=1; i<id; i++)
        ans=min(ans,max(mx-val[i],max(pre[i],beh[i+1])));
    if(ans==1e9)printf("0\n");
    else printf("%d\n",ans);
    return 0;
}
