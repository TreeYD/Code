把每一个点的取反，那么y+kx=y-kx，所以每一点对答案的贡献为直线经过该点与y轴的交点，那么把点排序，去掉凸包。再把直线按K排序，斜率优化。
$$
对于a,b,c三点\\ 
x_a<x_b<x_c\\
Kab>0　and　Kbc<0\\
则y_a<y_b　and　y_b>y_c\\ 
如果b对答案的贡献最大，则存在\\
y_b-kx_b>y_a-kx_a\\
y_b-kx_b>y_c-kx_c\\
k*(x_a-x_b)>y_a-y_b\\
k*(x_c-x_b)>y_c-y_b\\
\frac{y_a-y_b}{x_a-x_b}>k\\
\frac{y_c-y_b}{x_c-x_b}<k\\
也就是说Kab>k,Kbc<k\\
反过来推，Kab=\frac{(y_a-y_b)}{(x_a-x_b)}>0\\
→y_a-y_b<0\\
Kbc=\frac{}{}
$$
