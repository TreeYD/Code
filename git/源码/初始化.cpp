#include<bits/stdc++.h>
using namespace std;
string str,name,email;
void configidemail(){
	NAME:;
	cout<<"��������ID(English):"<<endl;
	cin>>name;
	cout<<name<<endl;
	cout<<"ȷ�ϣ� Y(y)/N(n)"<<endl;
	cin>>str;
	if(str[0]!='Y'&&str[0]!='y')goto NAME;
	name="git config --global user.name "+name+'"';
	system(name.c_str());
	EMAIL:;
	cout<<"��������email:"<<endl;
	cin>>email;
	cout<<email<<endl;
	cout<<"ȷ�ϣ� Y(y)/N(n)"<<endl;
	cin>>str;
	if(str[0]!='Y'&&str[0]!='y')goto EMAIL;
	email="git config --global user.email "+email+'"';
	system(email.c_str());
}
int main(){
	system("cd ..");
	system("git init");
	cout<<"ע�⣺�����뽫��.gitignore���ļ����Ƶ���Ŀ��Ŀ¼��"<<endl; 
	cout<<endl<<"���Ƿ��ڱ������ù�git��ID��email�� Y(y)/N(n)"<<endl;
	cin>>str;
	if(str[0]!='Y'&&str[0]!='y')configidemail();
	cout<<"���Զ�ֿ̲�:"<<endl;
	cin>>str;
	str="git remote add origin "+str;
	system(str.c_str());
	cout<<"��ʼ�����......"<<endl; 
	system("pause");
	return 0;
}
