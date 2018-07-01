// Name: 李聿鎧
// Date: 20180612
// Last Update: 20180612
// Problem statement: C++ Homework "1401 - ATM"
#include<iostream>
using namespace std;
// Intent: 不足的資金(例外處理)
class InsufficientFunds
{
public:
	// Intent: InsufficientFunds 建構子
	InsufficientFunds() {}
private:

};
// Intent: 存款為負的(例外處理)
class NegativeDeposit
{
public:
	// Intent: NegativeDeposit 建構子
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
			throw NegativeDeposit(); //存款為負的 丟出錯誤
		return balance;
	}
	// Intent: return new balance or -1 if invalid amount
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0))
			throw InsufficientFunds(); //不足資金 丟出錯誤
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
// class NegativeDeposit {…};
// class InsufficientFunds {…};