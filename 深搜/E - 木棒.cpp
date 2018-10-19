#include<bits/stdc++.h>
using namespace std;
int A[105],n,odd;
int tot,len,sum;
int nxt[105],to[105];
bool mark[105]; 
bool cmp(int a,int b){
    return a>b;
}
bool dfs(int x,int p,int r){
//  printf("%d %d %d\n",x,p,r);
    if(x==tot+1)return 1;
    if(r==0)return dfs(x+1,1,len); 
    if((len&1)&&odd<tot-x)return 0;
    if(r<A[n]||r>nxt[p])return 0;
    for(int i=p;i<=n;i++){
    	if(mark[i]||A[i]>r)continue;
    	mark[i]=1;
        odd-=A[i]%2;
        if(dfs(x,i+1,r-A[i]))return 1;
        odd+=A[i]%2;
        mark[i]=0;
        if(r==len)return 0;
        if(r-A[i]==0)return 0; 
        i=to[i];
    }
    return 0;
}
int main(){
    while(scanf("%d",&n)&&n){
        memset(A,0,sizeof(A));
        memset(nxt,0,sizeof(nxt));
        memset(mark,0,sizeof(mark));
        sum=len=odd=0;
//      scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&A[i]);
            odd+=A[i]&2; 
            sum+=A[i];
            len=max(len,A[i]); 
    	}
        sort(A+1,A+1+n,cmp);
        int t=n+1;A[n+1]=A[n+1];
        for(int i=n;i>=1;i--){
        	if(A[i]!=A[t])t=i;
        	to[i]=t;
            nxt[i]=nxt[i+1]+A[i];
        }
        for(;;len++){
            if(sum%len!=0)continue;
            tot=sum/len;
            if(len%2==1){
                if(odd<tot||odd-tot%2==1)continue;
            }else if(odd%2==1)continue;
    		if(len==sum)break;
            if(dfs(1,1,len))break;
        }
        printf("%d\n",len);
	}
    return 0;
}
