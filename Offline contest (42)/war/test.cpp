#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define M 200005
#define oo 1061109567

template <class T>void Rd(T &x){
    x=0;
    char c;
    while(c=getchar(),!isdigit(c));
    do{
        x=(x<<3)+(x<<1)+(c^'0');
    }while(c=getchar(),isdigit(c));
}

struct list{
    int to,nx,v;
}lis[M<<1];
int tot,head[M];
void Add(int x,int y,int v){
    lis[++tot]=(list){y,head[x],v};
    head[x]=tot;    
}

struct edge{
    int a,b,v;
    bool operator <(const edge &t)const{
        return v<t.v;
    }
}eg[M<<1];

int Fa[M];
int Find(int x){
    if(Fa[x]==x)return x;
    return Fa[x]=Find(Fa[x]);
}

int n,m,k,q;

multiset<int>ans,st[M<<2];
int cc;
int C[M],la[M];
int ls[M*30],rs[M*30],num[M*30],sz;
int Rt[M];
int id[M*30];

void Up(int p){
    num[p]=min(num[ls[p]],num[rs[p]]);
}

void Update(int &p,int L,int R,int x,int v,bool f){
    if(p==0)p=++sz,num[p]=oo;
//  cout<<L<<" "<<R<<endl;
    if(L==R){
        if(id[p]==0)id[p]=++cc;
        int nc=id[p];
        if(f==true)st[nc].insert(v);
        else st[nc].erase(st[nc].find(v));
        if(st[nc].size())num[p]=*(st[nc].begin());
        else num[p]=oo;
        return;
    }
    int mid=L+R>>1;
    if(mid>=x)Update(ls[p],L,mid,x,v,f);
    else Update(rs[p],mid+1,R,x,v,f);
    Up(p);
}

int Query(int p,int L,int R,int l,int r){
    if(p==0||l>r)return oo;
    if(l==L&&r==R)return num[p];
    int mid=L+R>>1;
    if(mid>=r)return Query(ls[p],L,mid,l,r);
    else if(mid<l)return Query(rs[p],mid+1,R,l,r);
    else return min(Query(ls[p],L,mid,l,mid),Query(rs[p],mid+1,R,mid+1,r));
}

int tf[M],tv[M];

void DFS(int x,int p){
    tf[x]=p;
    for(int i=head[x];i;i=lis[i].nx){
        int to=lis[i].to;
        if(to==p)continue;
        DFS(to,x);
        tv[to]=lis[i].v;
        Update(Rt[x],1,k,C[to],lis[i].v,1);
    }
    if(Rt[x]){
        la[x]=min(Query(Rt[x],1,k,1,C[x]-1),Query(Rt[x],1,k,C[x]+1,k));
//      cout<<"!"<<x<<" "<<la[x]<<endl;
        ans.insert(la[x]);
    }
}

void Pt(){
    for(int i=1;i<=n;i++)
        printf("%d ",la[i]);
    puts("");
}

int main(){
//  freopen("grass.in","r",stdin);
//  freopen("grass.out","w",stdout);
    Rd(n),Rd(m),Rd(k),Rd(q);
    for(int i=1;i<=m;i++)Rd(eg[i].a),Rd(eg[i].b),Rd(eg[i].v);
    for(int i=1;i<=n;i++)Rd(C[i]),Fa[i]=i;
    sort(eg+1,eg+m+1);
    for(int i=1;i<=m;i++){
        int fu=Find(eg[i].a),fv=Find(eg[i].b);
        if(fu!=fv){
            Add(eg[i].a,eg[i].b,eg[i].v);
            Add(eg[i].b,eg[i].a,eg[i].v);
            Fa[fu]=fv;
        }
    }
    num[0]=oo;
    DFS(1,0);
    for(int qq=1,x,c;qq<=q;qq++){
        Rd(x),Rd(c);
        if(C[x]!=c){
            if(Rt[x]){
                ans.erase(ans.find(la[x]));
                la[x]=min(Query(Rt[x],1,k,1,c-1),Query(Rt[x],1,k,c+1,k));
                ans.insert(la[x]);
            }if(x!=1){
                int p=tf[x];
                ans.erase(ans.find(la[p]));
                Update(Rt[p],1,k,C[x],tv[x],0);
                Update(Rt[p],1,k,c,tv[x],1);
                la[p]=min(Query(Rt[p],1,k,1,C[p]-1),Query(Rt[p],1,k,C[p]+1,k));
                ans.insert(la[p]);
            }
            C[x]=c;
        }
        printf("ans:%d\n",*(ans.begin()));
    }
    return 0;
}
