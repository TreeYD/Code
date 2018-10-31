#include<bits/stdc++.h>
using namespace std;
#define M 100005
int A[M],n;
int cnt[M];
struct P100{
	void solve(){
		int mi=A[1],mx=A[n],nxtmi=-1,nxtmx=-1;
		for(int i=1;i<=n;i++){
			cnt[A[i]]++;
			if(A[i]!=A[1]&&nxtmi==-1)nxtmi=A[i];
		}
		for(int i=n;i>=1;i--)
			if(A[i]!=A[n]&&nxtmx==-1)nxtmx=A[i];
		bool cur=0;
		while(mi!=mx&&nxtmi!=mx){
			if(cnt[mi]==1||cnt[mx]==1){
				if(cur==0)cnt[mi]--,cnt[nxtmi]++;
				else cnt[mx]--,cnt[nxtmx]++;
				cur=!cur;
			}else{
				int t=min(cnt[mx],cnt[mi])-1;
				cnt[mx]-=t;cnt[nxtmx]+=t;
				cnt[mi]-=t;cnt[nxtmi]+=t;
			}
			if(cnt[mi]==0){
				mi=nxtmi;nxtmi++;
				while(nxtmi<=M-5&&!cnt[nxtmi])nxtmi++;
			}
			if(cnt[mx]==0){
				mx=nxtmx;nxtmx--;
				while(nxtmx>=1&&!cnt[nxtmx])nxtmx--;
			}
		}
		if(cur)puts("Mirko");
		else puts("Slavko");
		printf("%d %d\n",mi,mx);
	}
}p100;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ 
//	freopen("psenica.in","r",stdin);
//	freopen("psenica.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+1+n);
	p100.solve();
	return 0;
}
