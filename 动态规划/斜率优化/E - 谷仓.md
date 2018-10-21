$dp[i][j]表示第一个开放谷仓在i，开放第j个谷仓的最小代价。$

$f[j]=f[k]+Cost(k+1,j-1)$

$而 Cost(i,j)=(Val(j)-Val(i-1))-(Sum(j)-Sum(i-1))*(i-1)$

$Val(j)表示∑A[i]*i(1<=i<=j),Sum(j)表示∑A[i](1<=i<=j)$

$所以f[j]=f[k]+(Val(j-1)-Val(k))-(Sum(j-1)-Sum(k))*k\\即f[j]=f[k]-Val(k)+k*Sum(k)-k*Sum(j-1)+[Val(j-1)]$

$设y=f[k]-Val[k]+k*Sum(k),K=Sum(j-1),x=k,P=Val(j-1)​$

$那么 f[j]=y-K*x+P,可得出斜率优化Dp$



