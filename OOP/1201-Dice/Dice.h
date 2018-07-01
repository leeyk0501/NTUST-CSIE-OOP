// Name: 李聿鎧
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
	// Intent: Dice 的 Default Constructor
	// Pre:    NULL
	Dice();
	// Intent: Dice 的 Constructor
	// Pre:    骰子的面數
	Dice(int numSides);
	// Intent: 快樂的骰骰子
	// Pre:    NULL
	// Post:   骰出的點數
	virtual int rollDice() const;
protected:
	int numSides;
};

class LoadedDice:
	public Dice
{
public:
	// Intent: LoadedDice 的 Default Constructor (繼承Dice)
	// Pre:    NULL
	LoadedDice() :Dice() {}
	// Intent: LoadedDice 的 Constructor (繼承Dice)
	// Pre:    骰子的面數
	LoadedDice(int numSides) :Dice(numSides) {}
	// Intent: 快樂的作弊骰骰子
	// Pre:    NULL
	// Post:   骰出的點數(有50%機率上天會眷顧你，直接輸出最大數)
	virtual int rollDice() const;
protected:

};
// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2);
