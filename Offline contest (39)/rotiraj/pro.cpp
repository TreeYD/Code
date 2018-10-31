#include<bits/stdc++.h>
using namespace std;
#define M 100005
void Inc(int &x,int mod){
	x++;if(x>=mod)x=0;
}
int op[M][2],A[M];
int n,K,Q,cnt[M];
int main(){
	scanf("%d%d%d",&n,&K,&Q);
	int a,x;
	for(int i=1;i<=Q;i++){
		scanf("%d%d",&a,&x);
		x=-x;
		if(a==1)x=(x%K+K)%K;
		else x=(x%n+n)%n;
		op[i][0]=a;
		op[i][1]=x;
	}
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	int now=0,c=n/K;
	for(int i=Q;i>=1;i--){
		int step=op[i][1];
		if(step==0)continue;
		if(op[i][0]==1){
			now=((now-step)%K+K)%K;
		}else{
			int d1=step/K;//整个块移动这么多
			cnt[0]+=d1;
			int d2=step%K,len=K-d2;
			if(d2){
				int pos=(K-now)%K;//0的位置 
				cnt[(now+len)%K]++;
				if(len>=pos){
					if(now!=0)cnt[now]--;
				}else{
					cnt[0]++;
					cnt[now]--;
				}
			}
			now=((now-step)%K+K)%K;
		}
	}
	for(int i=1;i<K;i++)cnt[i]+=cnt[i-1];
	for(int i=0;i<K;i++)
		cnt[i]=(-cnt[i]%c+c)%c;
	for(int i=0;i<n;i++){
		printf("%d ",A[now+cnt[now]*K]);
		Inc(cnt[now],c);Inc(now,K);
	}
	puts("");
	return 0;
}
