#include<bits/stdc++.h>
using namespace std;
const int N=100010,K=17;
struct edge{
    int nxt,t;
}e[N<<1];
int head[N],edge_cnt;
void add_edge(int x,int y){
    e[edge_cnt]=(edge){head[x],y};
    head[x]=edge_cnt++;
}
int fa[N][K],B[N],tot,Ord[N],h,ID[N];
void dfs_pre(int x,int f){
    int i;
    fa[x][0]=f;
    for (i=1;i<K;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    int lb=tot+1;
    for (i=head[x];~i;i=e[i].nxt){
        int to=e[i].t;
        if (to==f){
            continue;
        }
        B[++tot]=to;
    }
    int rb=tot;
    sort(B+lb,B+rb+1);
    for (i=lb;i<=rb;i++){
        dfs_pre(B[i],x);
    }
    Ord[++h]=x;
    ID[x]=h;
}
struct Segment_Tree{
    #define Lc (p<<1)
    #define Rc (p<<1|1)
    int sum[N<<2],sum1[N<<2];
    bool upd[N<<2];
    void Down(int p){
        if (upd[p]){
            upd[Lc]=1;
            upd[Rc]=1;
            upd[p]=0;
            sum1[Lc]=sum[Lc];
            sum1[Rc]=sum[Rc];
        }
    }
    void Up(int p){
        sum1[p]=sum1[Lc]+sum1[Rc];
    }
    void build(int l,int r,int p){
        sum[p]=r-l+1;
        if (l==r){
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,Lc);
        build(mid+1,r,Rc);
    }
    int Find(int l,int r,int p,int x){
        if (l==r){
            return l;
        }
        int mid=(l+r)>>1;
        Down(p);
        int t=sum[Lc]-sum1[Lc];
        if (x<=t){
            return Find(l,mid,Lc,x);
        }else{
            return Find(mid+1,r,Rc,x-t);
        }
    }
    void Fill(int l,int r,int p,int pl,int pr){
        if (l==pl && r==pr){
            upd[p]=1;
            sum1[p]=sum[p];
            return;
        }
        int mid=(l+r)>>1;
        Down(p);
        if (pr<=mid){
            Fill(l,mid,Lc,pl,pr);
        }else if (pl>mid){
            Fill(mid+1,r,Rc,pl,pr);
        }else{
            Fill(l,mid,Lc,pl,mid),Fill(mid+1,r,Rc,mid+1,pr);
        }
        Up(p);
    }
    bool Query(int l,int r,int p,int x){
        if (sum[p]==sum1[p]){
            return 1;
        }
        if (l==r){
            return sum1[p];
        }
        int mid=(l+r)>>1;
        Down(p);
        if (x<=mid){
            return Query(l,mid,Lc,x);
        }else{
            return Query(mid+1,r,Rc,x);
        }
    }
    void Update(int l,int r,int p,int x){
        if (l==r){
            sum1[p]=0;
            return;
        }
        int mid=(l+r)>>1;
        Down(p);
        if (x<=mid){
            Update(l,mid,Lc,x);
        }else{
            Update(mid+1,r,Rc,x);
        }
        Up(p);
    }
    #undef Lc
    #undef Rc
}T;
int main(){
  freopen("queue2.in","r",stdin);
  freopen("queue2.ans","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    memset(head+1,-1,sizeof(int)*1*n);
    for (i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs_pre(1,0);
    T.build(1,n,1);
    for (i=1;i<=m;i++){
        int op,x;
        scanf("%d%d",&op,&x);
        if (op==1){
            int pos=T.Find(1,n,1,x);
            T.Fill(1,n,1,1,pos);
            printf("%d\n",Ord[pos]);
        }else{
            int y=x,res=0;
            for (j=K-1;j>=0;j--){
                if (fa[y][j]==0){
                    continue;
                }
                if (T.Query(1,n,1,ID[fa[y][j]])){
                    res|=(1<<j);
                    y=fa[y][j];
                }
            }
            T.Update(1,n,1,ID[y]);
            printf("%d\n",res);
        }
    }
    return 0;
}
