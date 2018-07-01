// Name: �����Z
// Date: 20180529
// Last Update: 20180529
// Problem statement: C++ Homework "1201 - Dice"
#pragma once
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class Dice
{
public:
	// Intent: Dice �� Default Constructor
	// Pre:    NULL
	Dice();
	// Intent: Dice �� Constructor
	// Pre:    ��l������
	Dice(int numSides);
	// Intent: �ּ֪����l
	// Pre:    NULL
	// Post:   ��X���I��
	virtual int rollDice() const;
protected:
	int numSides;
};

class LoadedDice:
	public Dice
{
public:
	// Intent: LoadedDice �� Default Constructor (�~��Dice)
	// Pre:    NULL
	LoadedDice() :Dice() {}
	// Intent: LoadedDice �� Constructor (�~��Dice)
	// Pre:    ��l������
	LoadedDice(int numSides) :Dice(numSides) {}
	// Intent: �ּ֪��@�����l
	// Pre:    NULL
	// Post:   ��X���I��(��50%���v�W�ѷ|���U�A�A������X�̤j��)
	virtual int rollDice() const;
protected:

};
// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2);
