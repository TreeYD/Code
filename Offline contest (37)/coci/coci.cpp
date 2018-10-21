#include<bits/stdc++.h>
using namespace std;
#define M 500005
#define N 655
int big[M],small[M],n;
struct P30{
	int big[M],eql[M];
	int fi[M],se[M];
	void solve(){
		for(int i=1;i<=n;i++)
			scanf("%d%d",&fi[i],&se[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(fi[i]>fi[j]&&se[i]>se[j])continue;
				if(fi[i]<fi[j]&&se[i]<se[j])big[i]++;
				else if(fi[i]+se[i]+650<fi[i]+se[i])big[i]++;
				else if(fi[i]+se[i]<fi[j]+se[j]+650)eql[i]++;
			}
		for(int i=1;i<=n;i++)
			printf("%d %d\n",big[i]+1,big[i]+eql[i]+1);
	}
}p30;
struct node{
	int x,y,id;
	bool operator<(const node &X)const{
		if(x!=X.x)return x<X.x;
		return y<X.y;
	}
}A[M],B[M];
int nxt[N],X[N],Y[N],pre[N][N];
void CDQ(int L,int R){
	if(L>=R)return;
	int mid=L+R>>1;
	CDQ(L,mid);CDQ(mid+1,R);
	int i=L,j=mid+1,k=0,len=R-L+1;
	for(int i=mid+1;i<=R;i++)nxt[A[i].x]++;
	while(i<=mid&&j<=R){
		if(A[i].y<A[j].y){
			B[++k]=A[i];
			big[A[i].id]+=R-j+1-nxt[A[i].x];
			X[A[i].x]++,Y[A[i].y]++;
			pre[A[i].x][A[i].y]++;
			i++;
		}else{
			B[++k]=A[j];
			int cnt=i-L-X[A[j].x]-Y[A[j].y]+pre[A[j].x][A[j].y];
			small[A[j].id]+=cnt;
			nxt[A[j].x]--;
			j++;
		}
	}
	while(i<=mid){
		B[++k]=A[i];
		X[A[i].x]++;Y[A[i].y]++;
		pre[A[i].x][A[i].y]++;
		i++;
	}
	while(j<=R){
		B[++k]=A[j];
		int cnt=mid-L+1-X[A[j].x]-Y[A[j].y]+pre[A[j].x][A[j].y];
		small[A[j].id]+=cnt;
		nxt[A[j].x]--;
		j++;
	}
	for(int p=L;p<=mid;p++){
		X[A[p].x]--,Y[A[p].y]--;
		pre[A[p].x][A[p].y]--;
	}
	k=0;
	for(int p=L;p<=R;p++)	
		A[p]=B[++k];
}
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï 
//	freopen("coci.in","r",stdin);
//	freopen("coci.out","w",stdout);
	scanf("%d",&n);
	if(n<=5000)p30.solve();
	else{
		for(int i=1;i<=n;i++){
			scanf("%d%d",&A[i].x,&A[i].y);
			A[i].id=i;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(A[i].x==0&&A[i].y==0)cnt++;
		for(int i=1;i<=n;i++)
			if(A[i].x==650&&A[i].y==0||A[i].x==0&&A[i].y==650)
				small[A[i].id]+=cnt;
		sort(A+1,A+1+n);
		CDQ(1,n);
		for(int i=1;i<=n;i++)
			printf("%d %d\n",big[i]+1,n-small[i]);
	}
	return 0;
}
