#include<bits/stdc++.h>
using namespace std;
int L,com;
int sn[1005],szn;
char sc[1005],szc;
bool mp[30];
void Rd_com(){
	char c;
	bool flag=0;
	c=getchar();
	while(c>'9'||c<'0'){
		if(c=='n')flag=1;
		c=getchar();
	}
	do{
		com=(com<<3)+(com<<1)+(c^48);
	}while(c=getchar(),c>='0'&&c<='9');
	if(!flag)com=0;
}
void Init(){
	szn=szc=com=0;
	memset(sn,0,sizeof(sn));
	memset(mp,0,sizeof(mp));
}
int main(){
	freopen("complexity.in","r",stdin);
	freopen("complexity.out","w",stdout);
	int T;
	char op[15],c[10],x[10],y[10];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&L);
		Init();
		Rd_com();
		bool flag=0,agn=0;
		int ans=0,i;
		for(i=1;i<=L;i++){
			scanf("%s",op);
			if(op[0]=='F'){
				scanf("%s%s%s",c,x,y);
				if(mp[c[0]-'a']==1)flag=1;
				mp[c[0]-'a']=1;
				int a=(x[0]=='n'),b=(y[0]=='n');
				int t=b-a;
				if(t<0)t=-1000;
				if(b==0&&a==0){
					int t1=0,t2=0,k1=0,k2=0,n1=strlen(y),n2=strlen(x);
					while(t1<n1)k1=k1*10+y[t1]-'0',t1++;
					while(t2<n2)k2=k2*10+x[t2]-'0',t2++;
					if(k1<k2)t=-1000;
				}
				sn[szn+1]=t+sn[szn];szn++;
				sc[++szc]=c[0];
			}else if(op[0]=='E'){
				if(szc){
					mp[sc[szc]-'a']=0;
					szc--;
					ans=max(ans,sn[szn]);
					szn--;
				}else flag=1;
			}
		}
		if(flag||szn)puts("ERR");
		else{
			if(ans!=com)puts("No");
			else puts("Yes");
		}
	}	
	return 0;
}
