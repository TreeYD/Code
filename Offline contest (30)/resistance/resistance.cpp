#include<bits/stdc++.h>
using namespace std;
#define M 50005
int R[M],n,len;
long double val[15];
char str[M];
int stk[M],top;
string tmp1,tmp2;
long double dfs(int x){
	long double res=0;
	bool op=0;//op 0-> -  1-> |
	for(int i=x+1;i<R[x];i++){
		if(str[i]<='9'&&str[i]>='0'){
			if(!op)res+=val[str[i]-'0'];
			else res=res*val[str[i]-'0']/(res+val[str[i]-'0']);
		}else if(str[i]=='('){
			long double tmp=dfs(i);
			if(!op)res+=tmp;
			else res=res*tmp/(res+tmp);
			i=R[i];
		}else op=(str[i]=='|');
	}
	return res;
}
int main(){//name long long memory mod
//	freopen("resistance.in","r",stdin);
//	freopen("resistance.out","w",stdout);
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%Lf",&val[i]);
	while(~scanf("%s",str))tmp1+=str;
	int tmp=tmp1.size();
	int a=0,b=0;
	str[0]='(';
	while(b<tmp){
		if(tmp1[b]=='R'){
			b++;
			continue;
		}
		str[++a]=tmp1[b++];
		if(str[a]=='('){
			stk[++top]=a;
		}else if(str[a]==')')
			R[stk[top--]]=a;
	}
	len=a;
	str[++len]=')';
	R[0]=len;
	printf("%.5Lf\n",dfs(0));
	return 0;
}
