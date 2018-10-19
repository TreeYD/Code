#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	system("git add --all");
	system("git status");
	cout<<endl<<endl;
	cout<<"提交信息(警告：使用中文字符可能无法较好地显示):"<<endl;
	getline(cin,str);
	str="git commit -m \""+str+'"';
	cout<<str<<endl;
	cout<<endl;
	system(str.c_str());
	system("git push -u origin master");
	system("pause");
	return 0;
}
