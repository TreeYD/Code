#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#define lowbit(x) (x&-x)
#define ll unsigned long long
#define P 1000000007
#define M 100005
using namespace std;
int n,m,K;
char s[205][205];
int dx[]= {0,0,1,1,1,-1,-1,-1},dy[]= {1,-1,0,1,-1,0,1,-1};
ll gcd(ll a,ll b) {
    if(!b) return a;
    else return gcd(b,a%b);
}
int P1=1000000009,P2=1000000009;
int base1=1000007,base2=1000009;
int bin[1<<16];
struct Pxx {
    struct node{
        int a1,a2;
        bool operator <(const node x) const{
            if(x.a1!=a1) return a1<x.a1;
            else return a2<x.a2;
        }
    }ST[205][205][8][16];;
    map<node,int> cnt;
    map<node,int>::iterator it;
    ll b1[40005],b2[40005];
    void init() {
        for(int i=0;i<16;i++) bin[1<<i]=i;
        b1[0]=b2[0]=1;
        for(int i=1; i<=40000; i++) b1[i]=b1[i-1]*base1%P1,b2[i]=b2[i-1]*base2%P2;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                for(int d=0; d<8; d++) 
                    ST[i][j][d][0].a1=ST[i][j][d][0].a2=s[i][j]-'a';
        for(int t=1; t<16; t++)
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    for(int d=0; d<8; d++) {
                        int ni=((i+(1<<t-1)*dx[d])%n+n)%n,nj=((j+(1<<t-1)*dy[d])%m+m)%m;
                        ST[i][j][d][t].a1=(ST[i][j][d][t-1].a1*b1[1<<(t-1)]%P1+ST[ni][nj][d][t-1].a1)%P1;
                         
                        ST[i][j][d][t].a2=(ST[i][j][d][t-1].a2*b2[1<<(t-1)]%P2+ST[ni][nj][d][t-1].a2)%P2;
                    }
    }
    void solve() {
        init();
        ll base=1ll*n*m*n*m*64;
        K=min(K,n*m);
        if(m==n) K=min(K,n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                for(int d=0; d<8; d++) {
                    int px=i,py=j,tmp=K;
                    node h=(node){0,0};
                    while(tmp){
                        int t=bin[lowbit(tmp)];
                        tmp-=lowbit(tmp);
                        h.a1=(h.a1*b1[1<<t]%P1+ST[px][py][d][t].a1)%P1;
                        h.a2=(h.a2*b2[1<<t]%P1+ST[px][py][d][t].a2)%P2;
                        px=((px+(1<<t)*dx[d])%n+n)%n,py=((py+(1<<t)*dy[d])%m+m)%m;
                    }   
                    cnt[h]++;
                }
            }
        }
        ll ans=0;
        for(it=cnt.begin();it!=cnt.end();it++)
            ans+=(it->second)*(it->second);
        ll d=gcd(ans,base);
        printf("%lld/%lld\n",ans/d,base/d);
    }
} D;
int main() {
//  freopen("genius.in","r",stdin);
//  freopen("genius.out","w",stdout);
	freopen("data.in","r",stdin);
    scanf("%d%d%d",&n,&m,&K);
     
    for(int i=0; i<n; i++) scanf("%s",s[i]);
//  if(K<=50) C.solve();
    D.solve();
    return 0;
}
