#include<bits/stdc++.h>
using namespace std;
#define M 1005
int have[M],pos[M*M];
int mp[M][M],n,m;
int emp[M][M];
struct P30{
	void solve(){
		int ans=0;
		for(int i=1;i<=n;i++){
			int tot=0,mi=-1;
//			printf("%d\n",have[i]);
			puts("----------");
			for(int j=1;j<=m;j++){
				if(emp[i][j]){
					pos[emp[i][j]]=++tot;
					emp[i][j]=tot;
				}
			}
			for(int j=m;j>=1;j--){
				if(mp[i][j]!=0){
					mp[i][j]=pos[mp[i][j]];
					if(mi!=-1&&mp[i][j]>mi){
						ans++;
						printf("at:%d\n",mp[i][j]);
						if(!have[i]){
							ans++;
							have[i]=1;
						}
					}
					if(mi==-1||mp[i][j]<mi)mi=mp[i][j];
				}
				printf("%d\n",mp[i][j]);
			}
			printf("%d\n",ans);
		}
		printf("%d\n",ans);
	}
}p30;
int main(){//name memory long long * mod - ÇÐ·ÖÅÐ¶Ï ³õÖµ 
//	printf("%.2lf\n",(sizeof(mp)+sizeof(emp))/1024.0/1024);
//	freopen("book.in","r",stdin);
//	freopen("book.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool hav=0,sme=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			have[i]|=(mp[i][j]==0);
			hav|=(mp[i][j]==0);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&emp[i][j]);
			if(emp[i][j]!=mp[i][j])sme=0;
		}
	if(sme)puts("0");
	else if(!sme&&hav==0)puts("-1");
	else p30.solve();
	return 0;
}
