$dp[i]=min(dp[j]+sum[j]*sum[j]-2*sum[j]*sum[i])\\+sum[i]*sum[i]+M\\$

$设 y=dp[j]+sum[j]*sum[j],k=2*sum[i],x=sum[j]\\P=sum[i]*sum[i]+M 则 dp[i]=min(y-kx)+P$

$那么 对于j∈ [1,i-1]来说，k是相同的。过任意一个点作一条直线，\\再过其他点做一条平行的直线，与y轴的交点即为它们对答案的贡献。\\随着k的增大，原先对答案没有贡献的点最优性也在增大。$



