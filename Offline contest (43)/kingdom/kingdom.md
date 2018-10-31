内部边对答案的贡献已经算了出来。所以只需要算换边对答案的贡献即可。

#### 顺时针

$$
\sum_{i=1}^{x}(x-i)\times sz[i]\\
->x\times sum[x] - val[x]\\
(n- \sum_{i=1}^{x} sz[i])  \times(x-1)+\sum_{i=x+1}^{m}(m+1-i)\times sz[i]\\
->(n- sum[x])  \times(x-1)+(m+1)\times {(sum[m]-sum[x])}-(val[m]-val [x])\\
n\times x-n-sum[x]\times x+sum[x]+sum[m]+m\times sum[m] -m\times sum[x]-sum[x]-val[m]+val[x]\\
val[x]-sum[x]\times (x+m)+n\times x-n +sum[m]+m\times sum[m]-val[m]\\
两式相加可得\\
-sum[x]\times m+n\times x-n +sum[m]+m\times sum[m]-val[m]
$$



#### 逆时针

$$
A:\sum_{i=x+1}^m((i-x)\times sz[i])\\
val[m]-val[x]-x\times (sum[m]-sum[x])\\
B:val[x-1]+(m-x)\times (sum[x-1])
$$

