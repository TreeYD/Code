#include<bits/stdc++.h>
using namespace std;
#define M 205
#define LL long long
struct Node{
	int x,y,a,b;	
	bool operator<(const Node &B)const{
		return x<B.x;
	}	
}A[M];
int H[M<<1],n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&A[i].x,&A[i].a,&A[i].y,&A[i].b);	
		H[++cnt]=A[i].a,H[++cnt]=A[i].b;
	}
	sort(H+1,H+1+cnt);
	sort(A+1,A+1+n);
	cnt=unique(H+1,H+1+cnt)-H;
	LL ans=0;
	for(int i=1;i<cnt;i++){
		int h=H[i];
		int len=0,lst=0;
		for(int j=1;j<=n;j++){
			if(A[j].a>h||A[j].b<=h)continue;
			if(A[j].x>lst){
				len+=A[j].y-A[j].x;
				lst=A[j].y;
			}else{
				if(A[j].y>lst){
					len+=A[j].y-lst;
					lst=A[j].y;
				}	
			}
		}
		ans+=1LL*len*(H[i+1]-H[i]);
	}
	printf("%lld\n",ans);
	return 0;
}	
