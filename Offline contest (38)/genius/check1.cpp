#include<bits/stdc++.h>
using namespace std;
const int dx[]= {-1,-1,-1, 0,0, 1,1,1};
const int dy[]= {-1, 0, 1,-1,1,-1,0,1};
 
const long long Base_a=199931,Base_b=199933;
const long long Mod_a=699791,Mod_b=699793;
 
int n,m,k;
char atlas[205][205];
long long gcd(long long a,long long b) {
    long long t;
    while(b!=0)t=a,a=b,b=t%b;
    return a;
}
inline int Get_mod(int a,int md) {
    if(a>md)return a-md;
    if(a<=0)return a+md;
    return a;
}
 
long long p,q;
struct Listnode {
    int val,cnt,to;
} E[320005];
int Head[Mod_a+5],e_tot;
void Link(int u,int v) {
    E[++e_tot]=(Listnode) {
        v,1,Head[u]
    };
    Head[u]=e_tot;
}
void Insert(int x,int y) {
    for(int i=Head[x]; i!=0; i=E[i].to) {
        int val=E[i].val;
        if(val == y) {
            p+=E[i].cnt;
            E[i].cnt++;
            return;
        }
    }
    Link(x,y);
}
 
long long Pow_a[40005],Pow_b[40005];
void Init_Pow() {
    Pow_a[0]=Pow_b[0]=1;
    for(int i=1; i<=40000; i++) {
        Pow_a[i]=Pow_a[i-1]*Base_a%Mod_a;
        Pow_b[i]=Pow_b[i-1]*Base_b%Mod_b;
    }
}
 
char g_strs[40005];
bool mark[8][205][205];
void Get_strs(int x,int y,int dire,int stp) {
    memset(g_strs,0,sizeof g_strs);
    int rnd=0,i=1;
    while(rnd == 0) {
        g_strs[i]=atlas[x][y];
        x=Get_mod(x+dx[dire],n);
        y=Get_mod(y+dy[dire],m);
        if(rnd == 0 && mark[dire][x][y])rnd=i-1;
        mark[dire][x][y]=true;
        i++;
    }
    long long Hval_a=0,Hval_b=0;
    int tmp=stp;
    if(tmp >= rnd) {
        for(int i=1; i<=rnd; i++) {
            char g_th=g_strs[i];
            Hval_a = (Hval_a*Base_a+g_th)%Mod_a;
            Hval_b = (Hval_b*Base_b+g_th)%Mod_b;
        }
        long long Hase_a=Hval_a,Hase_b=Hval_b;
        tmp -= rnd;
        while(tmp >= rnd) {
            Hval_a = (Hval_a*Pow_a[rnd] + Hase_a)%Mod_a;
            Hval_b = (Hval_b*Pow_b[rnd] + Hase_b)%Mod_b;
            tmp -= rnd;
        }
    }
    for(int i=1; i<=tmp; i++) {
        char g_th=g_strs[(i-1)%rnd+1];
        Hval_a = (Hval_a*Base_a+g_th)%Mod_a;
        Hval_b = (Hval_b*Base_b+g_th)%Mod_b;
    }
    for(int i=1; i<=rnd; i++) {
        Insert(Hval_a,Hval_b);
        char g_th=g_strs[i],g_tl=g_strs[(i+stp-1)%rnd+1];
        Hval_a = ( ((Hval_a - g_th*Pow_a[stp-1])%Mod_a+Mod_a)*Base_a + g_tl )%Mod_a;
        Hval_b = ( ((Hval_b - g_th*Pow_b[stp-1])%Mod_b+Mod_b)*Base_b + g_tl )%Mod_b;
    }
}
 
void Solve() {
    Init_Pow();
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            for(int d=0; d<8; d++)
                if(!mark[d][i][j])
                    Get_strs(i,j,d,k);
    q=(1ll*n*m*n*m)<<6;
    p=p*2+n*m*8;
    long long g=gcd(p,q);
    p/=g,q/=g;
    printf("%lld/%lld\n",p,q);
}
 
int main() {
	freopen("data.in","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    k=min(k,n*m);
    for(int i=1; i<=n; i++)scanf("%s",atlas[i]+1);
    Solve();
    return 0;
}
