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
	system("git init");
	cout<<"注意：您必须将“.gitignore”文件复制到项目根目录下"<<endl; 
	cout<<endl<<"您是否在本机设置过git的ID和email？ Y(y)/N(n)"<<endl;
	cin>>str;
	if(str[0]!='Y'&&str[0]!='y')configidemail();
	cout<<"添加远程仓库:"<<endl;
	cin>>str;
	str="git remote add origin "+str;
	system(str.c_str());
	cout<<"初始化完毕......"<<endl; 
	system("pause");
	return 0;
}
