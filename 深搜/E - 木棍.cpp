#include<bits/stdc++.h>
using namespace std;
int A[105],n,odd;
int tot,len,sum;
int nxt[105],cnt[105];
bool cmp(int a,int b){
    return a>b;
}
bool dfs(int x,int p,int r){
//  printf("%d %d %d\n",x,p,r);
    if(x==tot+1){
        return 1;
    }
    if(r==0){
	    if(len%2==1){
	        if(tot-x>odd||(odd-tot+x)%2==1)return 0;
	    }else if(odd%2==1)return 0;
		return dfs(x+1,1,len);
	}
    while(p<=n&&!cnt[A[p]])p++;
    if(r<A[n]||r>nxt[p])return 0;
    for(int i=p;i<=n;i++){
        for(int j=1;j<=cnt[A[i]]&&j*A[i]<=r;j++){
            cnt[A[i]]-=j;
            odd-=A[i]%2*j;
            if(dfs(x,i+1,r-A[i]*j))return 1; 
            cnt[A[i]]+=j;
            odd+=A[i]%2*j;
            if(r-A[i]*j==0)return 0; 
        }
    }
    return 0;
}
int main(){
    while(scanf("%d",&n)&&n){
        memset(A,0,sizeof(A));
        memset(nxt,0,sizeof(nxt));
        memset(cnt,0,sizeof(cnt));
        sum=len=odd=0;
        int x,i,sz=0;
//      scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            if(x>50)continue;
            A[++sz]=x;
            if(x%2)odd++; 
            cnt[x]++;
            sum+=x;
            len=max(len,x); 
        }
        n=sz;
        sort(A+1,A+1+n,cmp);
        n=unique(A+1,A+1+n)-A-1;    
        for(i=n;i>=1;i--){
            nxt[i]=nxt[i+1]+A[i]*cnt[A[i]];
        }
        for(;;len++){
            if(sum%len!=0)continue;
            tot=sum/len;
            if(len%2==1){
                if(odd<tot||odd-tot%2==1)continue;
            }else if(odd%2==1)continue;
        //      printf("len:%d tot:%d\n",len,tot);
    		if(len==sum)break;
            if(dfs(1,1,len))break;
        }
        printf("%d\n",len);
    }
    return 0;
}
