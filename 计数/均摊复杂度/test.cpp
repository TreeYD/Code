#include <bits/stdc++.h>
#define clr(x,y) memset(x,y,sizeof(x))
#define pf printf
#define sf scanf
#define FOR(x,y,z) for(int x=y,x_=z;x<=x_;x++)
#define DOR(x,y,z) for(int x=y,x_=z;x>=x_;x--)
#define FOR_edge(x,y,v) for(int x=head[y],v=edge[x].e;~x;x=edge[x].to,v=edge[x].e)
#define FOR__edge(x,y,v,w) for(int x=head[y],v=edge[x].e,w=edge[x].c;~x;x=edge[x].to,v=edge[x].e,w=edge[x].c)
#define read2(x,y) read(x),read(y)
#define read3(x,y,z) read(x),read(y),read(z)
#define db double
#define ll long long
using namespace std;
void read(int &x){
    sf("%d",&x);
}
bool a[35],res;
void Add(){
    int x=0;
    while(a[x])a[x++]=0,res^=1;
    a[x]=1,res^=1;
}
int main(){
    int n,ans=0;
    read(n);
    FOR(i,1,n){
        Add();
        ans+=res;
    }
    pf("%d %d",ans,n-ans);
}
