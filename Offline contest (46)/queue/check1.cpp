#include<bits/stdc++.h>
#define M 100005
using namespace std;
int n,T,dfn;
int Dfn[M],Fa[M][17],Dep[M];
vector<int>E[M];
void Add_edge(int u,int v){
    E[u].push_back(v);
}
struct P50{
    void Dfs(int x,int f){
        Fa[x][0]=f,Dep[x]=Dep[f]+1;
        for(int i=0;i<E[x].size();i++){
            int y=E[x][i];
            if(y==f)continue;
            Dfs(y,x);   
        }
        Dfn[x]=++dfn;
    }   
    struct Node{
        int x;
        bool operator<(const Node&_)const{
            return Dfn[x]>Dfn[_.x];
        }
    };
    priority_queue<Node>Q;
    bool Mark[M];
    void Solve(){
        for(int i=1;i<=n;i++)sort(E[i].begin(),E[i].end());
        Dfs(1,0);
        for(int i=1;i<17;i++)
            for(int j=1;j<=n;j++)
                Fa[j][i]=Fa[Fa[j][i-1]][i-1];
        while(!Q.empty())Q.pop();
        memset(Mark,0,sizeof(Mark));
        for(int i=1;i<=n;i++)Q.push((Node){i});
        while(T--){
            int op,x;
            scanf("%d%d",&op,&x);
            if(op==1){
                for(int i=1;i<x;i++){
                    int t=Q.top().x;
                    Q.pop();
                    Mark[t]=1;  
                }
                int t=Q.top().x;
                Q.pop();
                Mark[t]=1;
                printf("%d\n",t);
            }else{
                int tx=x;
                for(int i=16;i>=0;i--)
                    if(Mark[Fa[x][i]])x=Fa[x][i];
                Mark[x]=0;Q.push((Node){x});
                printf("%d\n",Dep[tx]-Dep[x]);                          
            }
        }
    }
}p50;
int main(){
//  freopen("queue.in","r",stdin);
  freopen("queue2.in","r",stdin);
  freopen("queue.out","w",stdout);    
    scanf("%d%d",&n,&T);
    for(int i=1,a,b;i<n;i++){
        scanf("%d%d",&a,&b);
        Add_edge(a,b);
        Add_edge(b,a);  
    }
    p50.Solve();
    return 0;
}
