#include<bits/stdc++.h>
using namespace std;
string str,name,email;
void configidemail(){
	NAME:;
	cout<<"输入您的ID(English):"<<endl;
	cin>>name;
	cout<<name<<endl;
	cout<<"确认？ Y(y)/N(n)"<<endl;
	cin>>str;
	if(str[0]!='Y'&&str[0]!='y')goto NAME;
	name="git config --global user.name "+name+'"';
	system(name.c_str());
	EMAIL:;
	cout<<"输入您的email:"<<endl;
	cin>>email;
	cout<<email<<endl;
	cout<<"确认？ Y(y)/N(n)"<<endl;
	cin>>str;
	if(str[0]!='Y'&&str[0]!='y')goto EMAIL;
	email="git config --global user.email "+email+'"';
	system(email.c_str());
}
int main(){
	system("cd ..");
	configidemail();
	cout<<"初始化完毕......"<<endl; 
	system("pause");
	return 0;
}
