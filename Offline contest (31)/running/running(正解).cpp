#include<bits/stdc++.h>
using namespace std;
#define M 300005
vector<int>E[M];
struct path{
    int fr,to,lca;
};
int up[M],down[M<<1];
int ans[M];
int n,m,W[M],fa[M],top[M];
int sz[M],son[M],cnt[M],dep[M];
vector<path>c1[M],c2[M],c3[M];
void dfs_top(int x,int tp){
    top[x]=tp;
    if(son[x])dfs_top(son[x],tp);
    for(int i=0;i<E[x].size();i++){
        int y=E[x][i];
        if(y==fa[x]||y==son[x])continue;
        dfs_top(y,y);
    }
}
void dfs(int x,int f){//for lca
    sz[x]=1;
    fa[x]=f;
    dep[x]=dep[f]+1;
    for(int i=0;i<E[x].size();i++){
        int y=E[x][i];
        if(y==f)continue;
        dfs(y,x);
        if(sz[y]>sz[son[x]])son[x]=y;
        sz[x]+=sz[y];
    }
}
int LCA(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]>dep[top[b]]){
            a=fa[top[a]];
        }else b=fa[top[b]];
    }
    return dep[a]<dep[b]?a:b;
}
void redfs(int x){//for ans
    int ans=up[dep[x]+W[x]]+down[W[x]-dep[x]+n];
    for(int i=0;i<c1[x].size();i++){
        int a=c1[x][i].fr,b=c1[x][i].to,lca=c1[x][i].lca;
        up[dep[a]]++;if(dep[a]-dep[lca]==W[lca])cnt[lca]--;
    }
    for(int i=0;i<c2[x].size();i++){
        int a=c2[x][i].fr,b=c2[x][i].to;
        int dist=dep[a]+dep[b]-2*dep[c2[x][i].lca];
        down[n+dist-dep[b]]++;
    }
    for(int i=0;i<E[x].size();i++){
        int y=E[x][i];
        if(y==fa[x])continue;
        redfs(y);
    }
    cnt[x]+=(up[dep[x]+W[x]]+down[W[x]-dep[x]+n])-ans;
    //del path
    for(int i=0;i<c3[x].size();i++){
        int a=c3[x][i].fr,b=c3[x][i].to;
        int dist=dep[a]+dep[b]-2*dep[c3[x][i].lca];
        up[dep[a]]--;down[dist-dep[b]+n]--;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&W[i]);
    dfs(1,0);
    dfs_top(1,1);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        int lca=LCA(x,y);
        c1[x].push_back((path){x,y,lca});
        c2[y].push_back((path){x,y,lca});
        c3[lca].push_back((path){x,y,lca});
    }
    redfs(1);
    for(int i=1;i<=n;i++)printf("%d ",cnt[i]);
    puts("");
    return 0;
}
