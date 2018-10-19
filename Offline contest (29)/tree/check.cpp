#include<bits/stdc++.h>
#define M 100005
using namespace std;
int head[M],nxt[2*M],to[2*M],f[M],mxd[M],lg[M],cnt,n,m,tot;
void Add(int a,int b) {
    to[++cnt]=b;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
void Read(int &res) {
    char c;
    res=0;
    while(c=getchar(),!isdigit(c));
    do res=(res<<1)+(res<<3)+(c^48);
    while(c=getchar(),isdigit(c));
}
struct p100 {
    int dis[M],a[M],mx,dep[M],mark[M];
    struct ST {
        int a[18][M];
        void Init(bool cur) {
            for(int i=1; i<=tot; i++) {
                if(cur==0)a[0][i]=mxd[i]+i-1;
                else a[0][i]=mxd[i]+tot-i;
            }
            for(int i=1; i<18; i++) {
                for(int j=1; j+(1<<i)<=tot+1; j++)a[i][j]=max(a[i-1][j],a[i-1][j+(1<<(i-1))]);
            }
        }
        int query(int L,int R) {
            int t=lg[R-L+1];
            return max(a[t][L],a[t][R-(1<<t)+1]);
        }
    } st[2];
    void dfs1(int u) {
        if(dis[u]>dis[mx])mx=u;
        for(int i=head[u]; ~i; i=nxt[i]) {
            int v=to[i];
            if(f[u]==v)continue;
            f[v]=u;
            dis[v]=dis[u]+1;
            dfs1(v);
        }
    }
    void dfs2(int u,int rt) {
        mark[u]=rt;
        mxd[rt]=max(mxd[rt],dep[u]);
        for(int i=head[u]; ~i; i=nxt[i]) {
            int v=to[i];
            if(f[v]==-1||f[u]==v)continue;
            dep[v]=dep[u]+1;
            dfs2(v,rt);
        }
    }
    void solve() {
        dfs1(1);
        dis[1]=0;
        f[mx]=-1;
        dis[mx]=0;
        dfs1(mx);
        tot=0;
        int x=mx;
        while(x!=-1) {
            a[++tot]=x;
            x=f[x];
        }
        for(int i=1; i<=tot; i++) {
            f[a[i]]=-1;
            dep[a[i]]=0;
            mxd[i]=0;
        }
        for(int i=1; i<=tot; i++)dfs2(a[i],i);
        lg[0]=-1;
        for(int i=1; i<=tot; i++)lg[i]=lg[i/2]+1;
        st[0].Init(0);
        st[1].Init(1);
        while(m--) {
            int a,b;
            Read(a);
            Read(b);
            int x=mark[a],y=mark[b];
            if(x>y) {
                swap(x,y);
                swap(a,b);
            }
            int ans=max(min(dep[a]+x-1,dep[b]+y-1),min(dep[a]+tot-x,dep[b]+tot-y));
            int mid=((dep[a]+y-x+dep[b])>>1)+x-dep[a];
            if(x+1<=mid)ans=max(ans,st[0].query(x+1,mid)-(x-1)+dep[a]);
            if(y-1>=mid+1)ans=max(ans,st[1].query(mid+1,y-1)-(tot-y)+dep[b]);
            printf("%d\n",ans);
        }
    }
} p100;
int main() {
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1; i<n; i++) {
        int a,b;
        Read(a);
        Read(b);
        Add(a,b);
        Add(b,a);
    }
    scanf("%d",&m);
    p100.solve();
    return 0;
}
