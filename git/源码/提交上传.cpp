#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	system("git add --all");
	system("git status");
	cout<<endl<<endl;
	cout<<"�ύ��Ϣ(���棺ʹ�������ַ������޷��Ϻõ���ʾ):"<<endl;
	getline(cin,str);
	str="git commit -m \""+str+'"';
	cout<<str<<endl;
	cout<<endl;
	system(str.c_str());
	system("git push -u origin master");
	system("pause");
	return 0;
}
