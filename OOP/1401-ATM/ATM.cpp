// Name: �����Z
// Date: 20180612
// Last Update: 20180612
// Problem statement: C++ Homework "1401 - ATM"
#include<iostream>
using namespace std;
// Intent: ���������(�ҥ~�B�z)
class InsufficientFunds
{
public:
	// Intent: InsufficientFunds �غc�l
	InsufficientFunds() {}
private:

};
// Intent: �s�ڬ��t��(�ҥ~�B�z)
class NegativeDeposit
{
public:
	// Intent: NegativeDeposit �غc�l
	NegativeDeposit() {}
private:
};
class Account
{
private:
	double balance;
public:
	Account()
	{
		balance = 0;
	}
	Account(double initialDeposit)
	{
		balance = initialDeposit;
	}
	double getBalance()
	{
		return balance;
	}
	// Intent: returns new balance or -1 if error
	double deposit(double amount)
	{
		if (amount > 0)
			balance += amount;
		else
			throw NegativeDeposit(); //�s�ڬ��t�� ��X���~
		return balance;
	}
	// Intent: return new balance or -1 if invalid amount
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0))
			throw InsufficientFunds(); //������� ��X���~
		else
			balance -= amount;
		return balance;
	}
};

int main()
{
	Account a(100);
	try
	{
		cout << "Depositing 50" << endl;
		cout << "New balance: " << a.deposit(50) << endl;
		cout << "Depositing -25" << endl;
		cout << "New balance: " << a.deposit(-25) << endl;
		cout << "Withdraw 25" << endl;
		cout << "New balance: " << a.withdraw(25) << endl;
		cout << "Withdraw 250" << endl;
		cout << "New balance: " << a.withdraw(250) << endl;
	}
	catch (InsufficientFunds) // InsufficientFunds: a class name
	{
		cout << "Not enough money to withdraw that amount." << endl;
	}
	catch (NegativeDeposit) // NegativeDeposit: a class name
	{
		cout << "You may only deposit a positive amount." << endl;
	}
	cout << "Enter a character to exit" << endl;
	char wait;
	cin >> wait;
	system("pause");
	return 0;
}
// note that
// class NegativeDeposit {�K};
// class InsufficientFunds {�K};