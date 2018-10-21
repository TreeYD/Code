#include<bits/stdc++.h>
using namespace std;
int rx[]={0,1,0,-1,1,1,-1,-1};
int ry[]={-1,0,1,0,-1,1,1,-1};
map<string,int>cnt;
map<string,int>::iterator it;
int n,m,K;
char mp[205][205];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
struct P40{
	void dfs(int x,int y,int c,int f,string s){
		if(c==K){
			cnt[s]++;
			cout<<s<<endl;
			return;
		}
		int nx=x+rx[f],ny=y+ry[f];
		if(nx>n)nx=1;
		if(nx<1)nx=n;
		if(ny>m)ny=1;
		if(ny<1)ny=m;
		dfs(nx,ny,c+1,f,s+mp[nx][ny]);
	}
	void solve(){
		string s="";
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				for(int k=0;k<8;k++){
					dfs(i,j,1,k,s+mp[i][j]);
				}	
			}
		int ans=0,minu=0;
		for(it=cnt.begin();it!=cnt.end();it++){
			string s=it->first;
			int c=it->second;
			ans+=c*c;
			minu+=c;
		}
		minu=minu*minu;
		int d=gcd(ans,minu);
		printf("%d/%d\n",ans/d,minu/d);
	}
}p40;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ¼«Öµ 
//  printf("%.2lf\n",(sizeof(p))/1024.0/1024);
//	freopen("genius.in","r",stdin);
//	freopen("genius.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	if(K<=10000)p40.solve();
	return 0;
}
