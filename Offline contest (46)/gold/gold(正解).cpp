#include<bits/stdc++.h>
using namespace std;
#define M 100005
template<class T>void Max(T &x,T y){if(x<y)x=y;}
vector<int>A[M];
int n,h,mx;
bool check(double x){
	double tot=0;
	for(int i=1;i<=n;i++){
		double tmp=-2e9,sum=0;
		for(int j=0;j<h;j++){
			sum+=A[i][j]-x;
			if(sum>tmp)tmp=sum;
		}
		tot+=tmp;
	}
	return tot>=0;
}
void Find(){
	double L=0,R=mx;
	int t=0;
	while(t<=45){
		double mid=(L+R)/2;
		if(check(mid))L=mid;
		else R=mid;
		t++;	
	}
	printf("%.4lf\n",L);
}
int main(){
	int x;
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++){
		for(int j=0;j<h;j++){
			scanf("%d",&x);
			A[i].push_back(x);
			Max(mx,x); 
		}
	}	
	Find();
	return 0;
}
