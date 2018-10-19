#include<bits/stdc++.h>
using namespace std;
const int M=1505;
void qRead(int &r) {
    r=0;
    char c;
    for(c=0; c<'0'||c>'9'; c=getchar());
    for(; c>='0'&&c<='9'; c=getchar())r=(r<<1)+(r<<3)+(c^48);
}
int n,m,k,A,S[M][M],Sum[M][M],LU[M][M],LD[M][M],RU[M][M],RD[M][M],Row[M][M],Col[M][M];
/*
部分数组含义解释：
S：二维前缀和
Sum：以某个点为右下角的矩形总权值（即油量总和）
LU：矩形的右下角取在某个点到大矩形左上角时的最大权值
LD：矩形的右下角取在某个点到大矩形左下角时的最大权值
RU：矩形的右下角取在某个点到大矩形右上角时的最大权值
RD：矩形的右下角取在某个点到大矩形右下角时的最大权值
Row：矩形的右下角在第i行到第j行之间的最大权值
Col：矩形的右下角在第i列到第j列之间的最大权值
以上除S外，下标从k开始有效，因为矩形右下角的横纵坐标都肯定>=k
*/
void Init() {
    for(int i=k; i<=n; i++)for(int j=k; j<=m; j++)Sum[i][j]=S[i][j]-S[i][j-k]-S[i-k][j]+S[i-k][j-k];
    for(int i=k; i<=n; i++)for(int j=k; j<=m; j++)LU[i][j]=max(Sum[i][j],max(LU[i-1][j],LU[i][j-1]));
    for(int i=k; i<=n; i++)for(int j=m; j>=k; j--)RU[i][j]=max(Sum[i][j],max(RU[i-1][j],RU[i][j+1]));
    for(int i=n; i>=k; i--)for(int j=k; j<=m; j++)LD[i][j]=max(Sum[i][j],max(LD[i+1][j],LD[i][j-1]));
    for(int i=n; i>=k; i--)for(int j=m; j>=k; j--)RD[i][j]=max(Sum[i][j],max(RD[i+1][j],RD[i][j+1]));
//以上用二维前缀和方法递推所需数组
    for(int i=k; i<=n; i++) {
        int Max=0;
        for(int j=k; j<=m; j++)Max=max(Max,Sum[i][j]);//这一行的最大值
        for(int j=k; j<i; j++)Row[j][i]=max(Row[j][i-1],Max);//从前面的行转移
        Row[i][i]=Max;
    }
    for(int i=k; i<=m; i++) {
        int Max=0;
        for(int j=k; j<=n; j++)Max=max(Max,Sum[j][i]);
        for(int j=k; j<i; j++)Col[j][i]=max(Col[j][i-1],Max);
        Col[i][i]=Max;
    }
}
//以上用二维转一维递推所需数组
void Solve() {
    Init();
    int ans=0;
    for(int i=k; i<=n; i++)
        for(int j=i+k; j+k<=n; j++)
            ans=max(ans,Row[k][i]+Row[i+k][j]+Row[j+k][n]);
//两条切痕都为横向
    for(int i=k; i<=m; i++)
        for(int j=i+k; j+k<=m; j++)
            ans=max(ans,Col[k][i]+Col[i+k][j]+Col[j+k][m]);
//两条切痕都为纵向
    for(int i=k; i+k<=n; i++)
        for(int j=k; j+k<=m; j++) {
            ans=max(ans,Row[k][i]+LD[i+k][j]+RD[i+k][j+k]);
            ans=max(ans,Row[i+k][n]+LU[i][j]+RU[i][j+k]);
        }
//第一条切痕为横向，第二条切痕为纵向
    for(int i=k; i+k<=m; i++)
        for(int j=k; j+k<=n; j++) {
            ans=max(ans,Col[k][i]+RU[j][i+k]+RD[j+k][i+k]);
            ans=max(ans,Col[i+k][m]+LU[j][i]+LD[j+k][i]);
        }
//第一条切痕为纵向，第二条切痕为横向
    printf("%d\n",ans);
}
int main() {
	freopen("data.in","r",stdin);
	freopen("check.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            qRead(A);
            S[i][j]=A+S[i-1][j]+S[i][j-1]-S[i-1][j-1];//前缀和
        }
    Solve();
    return 0;
}
