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
�������麬����ͣ�
S����άǰ׺��
Sum����ĳ����Ϊ���½ǵľ�����Ȩֵ���������ܺͣ�
LU�����ε����½�ȡ��ĳ���㵽��������Ͻ�ʱ�����Ȩֵ
LD�����ε����½�ȡ��ĳ���㵽��������½�ʱ�����Ȩֵ
RU�����ε����½�ȡ��ĳ���㵽��������Ͻ�ʱ�����Ȩֵ
RD�����ε����½�ȡ��ĳ���㵽��������½�ʱ�����Ȩֵ
Row�����ε����½��ڵ�i�е���j��֮������Ȩֵ
Col�����ε����½��ڵ�i�е���j��֮������Ȩֵ
���ϳ�S�⣬�±��k��ʼ��Ч����Ϊ�������½ǵĺ������궼�϶�>=k
*/
void Init() {
    for(int i=k; i<=n; i++)for(int j=k; j<=m; j++)Sum[i][j]=S[i][j]-S[i][j-k]-S[i-k][j]+S[i-k][j-k];
    for(int i=k; i<=n; i++)for(int j=k; j<=m; j++)LU[i][j]=max(Sum[i][j],max(LU[i-1][j],LU[i][j-1]));
    for(int i=k; i<=n; i++)for(int j=m; j>=k; j--)RU[i][j]=max(Sum[i][j],max(RU[i-1][j],RU[i][j+1]));
    for(int i=n; i>=k; i--)for(int j=k; j<=m; j++)LD[i][j]=max(Sum[i][j],max(LD[i+1][j],LD[i][j-1]));
    for(int i=n; i>=k; i--)for(int j=m; j>=k; j--)RD[i][j]=max(Sum[i][j],max(RD[i+1][j],RD[i][j+1]));
//�����ö�άǰ׺�ͷ���������������
    for(int i=k; i<=n; i++) {
        int Max=0;
        for(int j=k; j<=m; j++)Max=max(Max,Sum[i][j]);//��һ�е����ֵ
        for(int j=k; j<i; j++)Row[j][i]=max(Row[j][i-1],Max);//��ǰ�����ת��
        Row[i][i]=Max;
    }
    for(int i=k; i<=m; i++) {
        int Max=0;
        for(int j=k; j<=n; j++)Max=max(Max,Sum[j][i]);
        for(int j=k; j<i; j++)Col[j][i]=max(Col[j][i-1],Max);
        Col[i][i]=Max;
    }
}
//�����ö�άתһά������������
void Solve() {
    Init();
    int ans=0;
    for(int i=k; i<=n; i++)
        for(int j=i+k; j+k<=n; j++)
            ans=max(ans,Row[k][i]+Row[i+k][j]+Row[j+k][n]);
//�����к۶�Ϊ����
    for(int i=k; i<=m; i++)
        for(int j=i+k; j+k<=m; j++)
            ans=max(ans,Col[k][i]+Col[i+k][j]+Col[j+k][m]);
//�����к۶�Ϊ����
    for(int i=k; i+k<=n; i++)
        for(int j=k; j+k<=m; j++) {
            ans=max(ans,Row[k][i]+LD[i+k][j]+RD[i+k][j+k]);
            ans=max(ans,Row[i+k][n]+LU[i][j]+RU[i][j+k]);
        }
//��һ���к�Ϊ���򣬵ڶ����к�Ϊ����
    for(int i=k; i+k<=m; i++)
        for(int j=k; j+k<=n; j++) {
            ans=max(ans,Col[k][i]+RU[j][i+k]+RD[j+k][i+k]);
            ans=max(ans,Col[i+k][m]+LU[j][i]+LD[j+k][i]);
        }
//��һ���к�Ϊ���򣬵ڶ����к�Ϊ����
    printf("%d\n",ans);
}
int main() {
	freopen("data.in","r",stdin);
	freopen("check.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            qRead(A);
            S[i][j]=A+S[i-1][j]+S[i][j-1]-S[i-1][j-1];//ǰ׺��
        }
    Solve();
    return 0;
}
