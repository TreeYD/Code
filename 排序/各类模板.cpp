#include<bits/stdc++.h>
using namespace std;
#define M 10000005
#define N ((1<<16)-1)
int A[M],B[M],n;
int cnt[M];
/*-----------O(n^2)------------- 
void Sort(int *A,int sz){//Ã°ÅÝÅÅÐò 
	for(int i=1;i<=sz;i++){
		bool flag=true;
		for(int j=sz;j>i;j--)
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				flag=false;
			}
		if(flag)return;
	}
}
void Sort(int *A,int sz){//²åÈëÅÅÐò 
	for(int i=2;i<=sz;i++){
		int tmp=A[i],x=i;
		while(x>1&&tmp<A[x-1]){
			A[x]=A[x-1];
			x--;
		}
		A[x]=tmp;
	}
}
void Sort(int *A,int sz){//Ñ¡ÔñÅÅÐò 
	for(int i=1;i<sz;i++){
		int x=i;
		for(int j=i+1;j<=sz;j++)
			if(A[j]<A[x])x=j;
		if(x!=i)swap(A[x],A[i]);
	}
}*/
/*-----------O(nlogn)-------------
void Sort(int L,int R){//¿ìËÙÅÅÐò 
	int x=rand()%(R-L+1)+L;
	swap(A[x],A[L]);
	int key=A[L];
	int i=L,j=R;
	while(i<j){
		while(A[j]>=key&&i<j)j--;
		if(i<j)A[i]=A[j];
		while(A[i]<=key&&i<j)i++;
		if(i<j)A[j]=A[i];
	}
	A[i]=key;
	if(i-1>L)Sort(L,i-1);
	if(i+1<R)Sort(i+1,R);
}
void Sort(int L,int R){//¹é²¢ÅÅÐò 
	if(L==R)return;
	int mid=L+R>>1;
	Sort(L,mid);Sort(mid+1,R);
	int i=L,j=mid+1,k=0;
	while(i<=mid&&j<=R){
		if(A[i]<A[j])B[++k]=A[i++];
		else B[++k]=A[j++];
	}
	while(i<=mid)B[++k]=A[i++];
	while(j<=R)B[++k]=A[j++];
	k=0;
	for(int i=L;i<=R;i++)A[i]=B[++k];
}
void Up(int p){//¶ÑÅÅÐò 
	int tmp=A[p];
	while(p>>1){
		int fa=p>>1;
		if(A[fa]>tmp)A[p]=A[fa],p=fa;
		else break;
	}
	A[p]=tmp;
}
void Down(int p){
	int tmp=A[p];
	while((p<<1)<=n){
		int son=p<<1;
		if(son+1<=n&&A[son+1]<A[son])son++;
		if(A[son]<tmp)A[p]=A[son],p=son;
		else break;
	}
	A[p]=tmp;
}
void Sort(){
	for(int i=1;i<=n;i++)Up(i);
	int sz=n;
	for(int i=1;i<=sz;i++){
		printf("%d ",A[1]);
		A[1]=A[n];n--;
		Down(1);
	}
	puts("");
}*/				 
/*-----------O(n¡Ìn)-------------
void Sort(){//Ï£¶ûÅÅÐò 
	int step=n>>1;
	while(step>=1){
		for(int i=step+1;i<=n;i++){
			int x=i,tmp=A[x];
			while(x>step&&tmp<A[x-step]){
				A[x]=A[x-step];
				x-=step;
			}
			A[x]=tmp;
		}
		step>>=1;
	}
}*/
/*-----------O(n+M)-------------
void Sort(){//¼ÆÊýÅÅÐò 
	for(int i=1;i<=n;i++)
		cnt[A[i]]++;
	for(int i=1;i<=N;i++)
		cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;i--)
		B[cnt[A[i]]--]=A[i];
	for(int i=1;i<=n;i++)
		A[i]=B[i];
}
void Sort(){//»ùÊýÅÅÐò 
	for(int i=1;i<=n;i++)
		cnt[A[i]&N]++;	
	for(int i=1;i<=N;i++)
		cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;i--)
		B[cnt[A[i]&N]--]=A[i];
	for(int i=0;i<=N;i++)
		cnt[i]=0;
	for(int i=1;i<=n;i++)
		cnt[B[i]>>16]++;
	for(int i=1;i<=N;i++)
		cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;i--)
		A[cnt[B[i]>>16]--]=B[i];
} */
int main(){
	srand(time(NULL));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
//	Sort();
	for(int i=1;i<=n;i++)
		printf("%d ",A[i]);
	puts("");
	return 0;
}
