#include<bits/stdc++.h>
using namespace std;
#define M 1005
int mp[M][M];
int R,C,H,W;
void Rd(int &res){
	char c;
	res=0;
	c=getchar();
	while(c<'0'||c>'9')c=getchar();
	do{res=(res<<3)+(res<<1)+(c^48);
	}while(c=getchar(),c>='0'&&c<='9');
}
struct P50{
	int A[10005];
	void solve(){
		int ans=R*C;
		for(int i=1;i<=R-H+1;i++)
			for(int j=1;j<=C-W+1;j++){
				int tmp=0,cnt=0;
				for(int k=i;k<=i+H-1;k++)
					for(int p=j;p<=j+W-1;p++)
						A[++cnt]=mp[k][p];
				sort(A+1,A+1+cnt);
				ans=min(ans,A[cnt/2+1]);
			}
		printf("%d\n",ans);
	}
}p50;
struct P70{
	#define Mn 305
	int ans;
	bool mark[Mn][Mn];
	struct BIT{	
		int Ci[Mn*Mn];
		int Sum(int x){
			int res=0;
			while(x){
				res+=Ci[x];
				x&=x-1;
			}
			return res;
		}
		void Add(int x,int d){
			while(x<=R*C){
				Ci[x]+=d;
				x+=x&-x;
			}
		}
		int Find(int K){
			int Lx=1,Rx=R*C,ans;
			while(Lx<=Rx){
				int mid=Lx+Rx>>1;
				if(Sum(mid)>=K){
					ans=mid;
					Rx=mid-1;
				}else Lx=mid+1;
			}
			return ans;
		}
	}T;
	void dfs(int x,int y){
		if(mark[x][y])return;
		mark[x][y]=1;
		if(ans==H*W/2+1)return;
		ans=min(ans,T.Find(H*W/2+1));
		if(ans==H*W/2+1)return;
		if(y+W<=C){
			for(int i=x;i<=x+H-1;i++){
				T.Add(mp[i][y],-1);
				T.Add(mp[i][y+W],1);
			}
			dfs(x,y+1);
			for(int i=x;i<=x+H-1;i++){
				T.Add(mp[i][y],1);
				T.Add(mp[i][y+W],-1);
			}
		}
		if(x+H<=R){
			for(int i=y;i<=y+W-1;i++){
				T.Add(mp[x][i],-1);
				T.Add(mp[x+H][i],1);
			}
			dfs(x+1,y);
			for(int i=y;i<=y+W-1;i++){
				T.Add(mp[x][i],1);
				T.Add(mp[x+H][i],-1);
			}
		}
	}
	void solve(){
		ans=2e9;
		for(int i=1;i<=H;i++)
			for(int j=1;j<=W;j++)
				T.Add(mp[i][j],1);
		dfs(1,1);
		printf("%d\n",ans);
	}
}p70;
int main(){//name memory long long * mod - ÇĞ·ÖÅĞ¶Ï ³õÖµ
//	freopen("quality.in","r",stdin);
//	freopen("quality.out","w",stdout); 
	scanf("%d%d%d%d",&R,&C,&H,&W);
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			Rd(mp[i][j]);
	if(R<=100)p50.solve();	
	else p70.solve();
	return 0;
}
