#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define MM 100005
int mp[M][M],R,C;
int H,W,tot,sum[M][M];
void Rd(int &res){
	res=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9')c=getchar();
	do{
		res=(res<<3)+(res<<1)+(c^48);
	}while(c=getchar(),c>='0'&&c<='9');
}
bool check(int v){
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++)
			sum[i][j]=(mp[i][j]>v)+sum[i][j-1];
		for(int j=1;j<=C;j++)
			sum[i][j]+=sum[i-1][j];
	}
	for(int i=1;i<=R-H+1;i++)
		for(int j=1;j<=C-W+1;j++){
			if(sum[i+H-1][j+W-1]+sum[i-1][j-1]-sum[i+H-1][j-1]-sum[i-1][j+W-1]<=tot/2){
				return 1;
			}
		}
	return 0;
}
void Find(){
	int Lx=1,Rx=R*C,ans=-1;
	while(Lx<=Rx){
		int mid=Lx+Rx>>1;
		if(check(mid)){
			Rx=mid-1;
			ans=mid;
		}else Lx=mid+1;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d%d%d",&R,&C,&H,&W);
	tot=H*W;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			Rd(mp[i][j]);
	Find();
	return 0;
}
