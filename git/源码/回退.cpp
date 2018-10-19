#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	cout<<"输入要回退到的版本号"<<endl;
	cin>>str;
	str="git reset --hard "+str;
	system(str.c_str());
	system("pause");
	return 0;
}
