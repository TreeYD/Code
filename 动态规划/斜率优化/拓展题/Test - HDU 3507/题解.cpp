/* Author:kzl */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxx = 500000+500;
int n,m;
int dp[maxx],sum[maxx],q[maxx];
int aa;
 
int getup(int i,int j)
{
    return dp[i] - dp[j] + sum[i] * sum[i] - sum[j] * sum[j];
}
 
int getdown(int i,int j){
return 2*(sum[i] - sum[j]);
}
 
int getdp(int i,int j)
{
    return dp[j] + (sum[i] - sum[j])*(sum[i] - sum[j]) + m;
}
 
int main(){
    sum[0] = 0;
while(scanf("%d%d",&n,&m)!=EOF)
{
    for(int i=1;i<=n;i++){
    scanf("%d",&aa);
    sum[i] = sum[i-1] + aa;
    }
 
    dp[0] = 0;
    int head = 0;
    int tail = 0;
    q[tail++] = 0;
    for(int i=1;i<=n;i++){
        while(head+1<tail && getup(q[head+1],q[head])<sum[i]*getdown(q[head+1],q[head])){
            head++;
        }
        dp[i] = getdp(i,q[head]);
         while(head+1<tail && getup(i,q[tail-1])*getdown(q[tail-1],q[tail-2]) <= getup(q[tail-1],q[tail-2])*getdown(i,q[tail-1])){
            tail--;
         }
         q[tail++] = i;
    }
    printf("%d\n",dp[n]);
}
return 0;
}
