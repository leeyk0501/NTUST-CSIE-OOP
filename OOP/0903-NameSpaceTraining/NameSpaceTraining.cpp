// Name: ßı¶÷ÒZ
// Date: 20180509
// Last Update: 20180509
// Problem statement: C++ Homework "0903 - namespace"
#include<iostream>
#include<string>
using namespace std;
namespace Authenticate
{
	void inputUserName();
	void inputPassword();
	string getUserName();
	string getPassword();
}
using namespace Authenticate;
int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() << " and your password is: "<< getPassword() << endl;
	system("pause");
	return 0;
}