#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define bit(x) (1<<x)
struct Node{
	int H,id,L,R,mid,ans;	
	bool operator<(const Node &x)const{
		return mid<x.mid;
	}	
}A[M];
int X[M],Y[M],base;
int Ans[M],n,m;
int cnt[M<<1],all;
int query(int x){
	int S=all^x,ans=cnt[x];
	for(int j=S;j;j=(j-1)&S)
		if(ans<1e9)ans+=cnt[j|x];
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i].H);
		A[i].id=i;
	}
	while(bit(base)<n)base++;
	all=bit(base)-1;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&X[i],&Y[i]);
		X[i]&=all; 
	}
	for(int i=0;i<n;i++){
		A[i].L=0;A[i].R=m-1;
		A[i].mid=m-1>>1;
		A[i].ans=-1;	
	}
	int t=0;
	while(t<18){
		sort(A,A+n);
		memset(cnt,0,sizeof(cnt));
		for(int i=0,j=0;i<n;i++){
			while(j<m&&j<=A[i].mid){
				if(cnt[X[j]]<1e9)
					cnt[X[j]]+=Y[j];
				j++;			
			}
			if(A[i].H<=query(A[i].id)){
				A[i].ans=A[i].mid;
				A[i].R=A[i].mid-1;
			}else A[i].L=A[i].mid+1;
		}
		t++;
		for(int i=0;i<n;i++)
			A[i].mid=A[i].L+A[i].R>>1;
	}
	for(int i=0;i<n;i++)
		if(~A[i].ans)Ans[A[i].ans]++;
	for(int i=0;i<m;i++){
		if(i)Ans[i]+=Ans[i-1];
		printf("%d\n",n-Ans[i]);
	}
	return 0;	
}
