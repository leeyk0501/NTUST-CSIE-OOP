#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <time.h>
using namespace std;
class Creature
{
private:
	int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf, 4 demon
	int strength; // How much damage we can inflict
	int hitpoints; // How much damage we can sustain
	string getSpecies(); // Returns type of species
public:
	Creature();
	// Initialize to human, 10 strength, 10 hit points
	Creature(int newType, int newStrength, int newHit) :type(newType), strength(newStrength), hitpoints(newHit) {}
	// Initialize creature to new type, strength, hit points
	// Also add appropriate accessor and mutator functions
	// for type, strength, and hit points
	int getDamage();
	// Returns amount of damage this creature
	// inflicts in one round of combat
	// Intent: 設定Type
	// Pre: NULL
	// Post: 設定type
	void setType(int newType);
	// Intent: 設定Strength
	// Pre: NULL
	// Post: 設定Strength
	void setStrength(int newStrength);
	// Intent: 設定Hitpoints
	// Pre: NULL
	// Post: 設定Hitpoints
	void setHitpoints(int newHit);
	// Intent: 取得Type
	// Pre: NULL
	// Post: 取得Type
	int getType();
	// Intent: 取得Strength
	// Pre: NULL
	// Post: 取得Strength
	int getStrength();
	// Intent: 取得Hitpoints
	// Pre: NULL
	// Post: 取得Hitpoints
	int getHitpoints();
};

class Human : public Creature  //繼承Creature
{
private:

public:
	// Intent: Human建構子
	// Pre: NULL
	// Post: Human建構子(strength & hitpoints 皆預設10)
	Human();
	// Intent: Human建構子
	// Pre: strength & hitpoints
	// Post: Human建構子
	Human(int strength, int hitpoints);
	// Intent: 取得傷害
	// Pre: NULL
	// Post: 取得傷害
	virtual int getDamage();
};

class Demon : public Creature //繼承Creature
{
private:

public:
	// Intent: Demon建構子
	// Pre: NULL
	// Post: Demon建構子(strength & hitpoints 皆預設10)
	Demon();
	// Intent: Demon建構子(有type)
	// Pre: type為角色種類
	// Post: Demon建構子(strength & hitpoints 皆預設10)
	Demon(int type);
	// Intent: Demon建構子(有type)
	// Pre: type為角色種類
	// Post: Demon建構子
	Demon(int type, int strength, int hitpoints);
	// Intent: 取得傷害
	// Pre: NULL
	// Post: 取得傷害
	virtual int getDamage();
};

class Cyberdemon : public Demon //繼承Demon
{
private:

public:
	// Intent: Cyberdemon建構子
	// Pre: NULL
	// Post: Cyberdemon建構子(strength & hitpoints 皆預設10)
	Cyberdemon();
	// Intent: Demon建構子
	// Pre: strength & hitpoints
	// Post: Demon建構子
	Cyberdemon(int strength, int hitpoints);
	// Intent: 取得傷害
	// Pre: NULL
	// Post: 取得傷害
	virtual int getDamage();
};

class Balrog : public Demon
{
private:

public:
	// Intent: Balrog建構子
	// Pre: NULL
	// Post: Balrog建構子(strength & hitpoints 皆預設10)
	Balrog();
	// Intent: Balrog建構子
	// Pre: strength & hitpoints
	// Post: Balrog建構子
	Balrog(int strength, int hitpoints);
	// Intent: 取得傷害
	// Pre: NULL
	// Post: 取得傷害
	virtual int getDamage();
};

class Elf : public Creature
{
private:

public:
	// Intent: Elf建構子
	// Pre: NULL
	// Post: Elf建構子(strength & hitpoints 皆預設10)
	Elf();
	// Intent: Elf建構子
	// Pre: strength & hitpoints
	// Post: Elf建構子
	Elf(int strength, int hitpoints);
	// Intent: 取得傷害
	// Pre: NULL
	// Post: 取得傷害
	virtual int getDamage();
};