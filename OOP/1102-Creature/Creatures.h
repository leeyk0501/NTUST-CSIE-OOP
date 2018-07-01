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
	// Intent: �]�wType
	// Pre: NULL
	// Post: �]�wtype
	void setType(int newType);
	// Intent: �]�wStrength
	// Pre: NULL
	// Post: �]�wStrength
	void setStrength(int newStrength);
	// Intent: �]�wHitpoints
	// Pre: NULL
	// Post: �]�wHitpoints
	void setHitpoints(int newHit);
	// Intent: ���oType
	// Pre: NULL
	// Post: ���oType
	int getType();
	// Intent: ���oStrength
	// Pre: NULL
	// Post: ���oStrength
	int getStrength();
	// Intent: ���oHitpoints
	// Pre: NULL
	// Post: ���oHitpoints
	int getHitpoints();
};

class Human : public Creature  //�~��Creature
{
private:

public:
	// Intent: Human�غc�l
	// Pre: NULL
	// Post: Human�غc�l(strength & hitpoints �ҹw�]10)
	Human();
	// Intent: Human�غc�l
	// Pre: strength & hitpoints
	// Post: Human�غc�l
	Human(int strength, int hitpoints);
	// Intent: ���o�ˮ`
	// Pre: NULL
	// Post: ���o�ˮ`
	virtual int getDamage();
};

class Demon : public Creature //�~��Creature
{
private:

public:
	// Intent: Demon�غc�l
	// Pre: NULL
	// Post: Demon�غc�l(strength & hitpoints �ҹw�]10)
	Demon();
	// Intent: Demon�غc�l(��type)
	// Pre: type���������
	// Post: Demon�غc�l(strength & hitpoints �ҹw�]10)
	Demon(int type);
	// Intent: Demon�غc�l(��type)
	// Pre: type���������
	// Post: Demon�غc�l
	Demon(int type, int strength, int hitpoints);
	// Intent: ���o�ˮ`
	// Pre: NULL
	// Post: ���o�ˮ`
	virtual int getDamage();
};

class Cyberdemon : public Demon //�~��Demon
{
private:

public:
	// Intent: Cyberdemon�غc�l
	// Pre: NULL
	// Post: Cyberdemon�غc�l(strength & hitpoints �ҹw�]10)
	Cyberdemon();
	// Intent: Demon�غc�l
	// Pre: strength & hitpoints
	// Post: Demon�غc�l
	Cyberdemon(int strength, int hitpoints);
	// Intent: ���o�ˮ`
	// Pre: NULL
	// Post: ���o�ˮ`
	virtual int getDamage();
};

class Balrog : public Demon
{
private:

public:
	// Intent: Balrog�غc�l
	// Pre: NULL
	// Post: Balrog�غc�l(strength & hitpoints �ҹw�]10)
	Balrog();
	// Intent: Balrog�غc�l
	// Pre: strength & hitpoints
	// Post: Balrog�غc�l
	Balrog(int strength, int hitpoints);
	// Intent: ���o�ˮ`
	// Pre: NULL
	// Post: ���o�ˮ`
	virtual int getDamage();
};

class Elf : public Creature
{
private:

public:
	// Intent: Elf�غc�l
	// Pre: NULL
	// Post: Elf�غc�l(strength & hitpoints �ҹw�]10)
	Elf();
	// Intent: Elf�غc�l
	// Pre: strength & hitpoints
	// Post: Elf�غc�l
	Elf(int strength, int hitpoints);
	// Intent: ���o�ˮ`
	// Pre: NULL
	// Post: ���o�ˮ`
	virtual int getDamage();
};