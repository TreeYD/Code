#include<bits/stdc++.h>
#define unable AC
#define KLL dying
#define rep(q,a,b) for(int q(a),q##_end_(b);q<=q##_end_;++q)
#define dep(q,a,b) for(int q(a),q##_end_(b);q>=q##_end_;--q)
using namespace std;
void in(int &r) {
    static char c;
    while(c=getchar(),c<48);
    do r=(r<<1)+(r<<3)+(c^48);
    while(c=getchar(),c>=48);
}
const int mn=500005;
int n,l[mn],r[mn],cnt[655][655];
int main() {
	freopen("data.in","r",stdin);
	freopen("check.out","w",stdout);
    in(n);
    rep(q,1,n)in(l[q]),in(r[q]),++cnt[l[q]+1][r[q]+1];
    rep(q,1,651)rep(w,1,651)cnt[q][w]+=cnt[q-1][w]+cnt[q][w-1]-cnt[q-1][w-1];
    rep(q,1,n) {
        int a=cnt[651][651]-cnt[651][r[q]+1]-cnt[l[q]+1][651]+cnt[l[q]+1][r[q]+1];
        printf("%d %d\n",a+1,n-cnt[l[q]][r[q]]-(l[q]==650?cnt[1][r[q]+1]-cnt[1][r[q]]:0)-(r[q]==650?cnt[l[q]+1][1]-cnt[l[q]][1]:0));
    }
    return 0;
}
