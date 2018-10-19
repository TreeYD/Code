#include<bits/stdc++.h>
using namespace std;
int pool[1005],n;
void Solve(int *a){
	cout<<*a<<' ';
	swap(a[0],a[1]);
	swap(pool[0],pool[2]);
}
int main(){
	int *a=pool;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>pool[i];
	cout<<*a<<' ';
	cout<<*a++<<' ';
	printf("A:%d A:%d\n",*(a-1),*a);
	cout<<*pool<<' ';
	cout<<*++a<<' ';
	Solve(a);
	printf("µØÖ·:%p\n",pool);
	cout<<*++a<<'\n';
	return 0;
}
