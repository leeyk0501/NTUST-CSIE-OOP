#include "Creatures.h"

void Creature::setType(int newType)
{
	this->type = newType;
}

void Creature::setStrength(int newStrength)
{
	this->strength = newStrength;
}

void Creature::setHitpoints(int newHit)
{
	this->hitpoints = newHit;
}

int Creature::getType()
{
	return this->type;
}

int Creature::getStrength()
{
	return this->strength;
}

int Creature::getHitpoints()
{
	return this->hitpoints;
}

string Creature::getSpecies()
{
	switch (type)
	{
		case 0: return "Human";
		case 1: return "Cyberdemon";
		case 2: return "Balrog";
		case 3: return "Elf";
		case 4: return "Demon";
	}
	return "Unknown";
}

int Creature::getDamage()
{
	// All creatures inflict damage which is a random number up to their strength
	int damage;
	damage = (rand() % strength) + 1;
	cout << getSpecies() << " attacks for " << damage << " points!" << endl;
	return damage;
}

Creature::Creature()
{
}

Human::Human() : Creature(0, 10, 10) 
{

}

Human::Human(int strength, int hitpoints) : Creature(0, strength, hitpoints) 
{
}

int Human::getDamage()
{
	return Creature::getDamage();
}

Demon::Demon() : Creature(4, 10, 10)
{

}

Demon::Demon(int type) : Creature(type, 10, 10)
{

}

Demon::Demon(int type, int strength, int hitpoints) : Creature(type, strength, hitpoints)
{

}

int Demon::getDamage()
{
	int damage = Creature::getDamage();
	if ((rand() % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 " << " additional damage points!" << endl;
	}
	return damage;
}

Cyberdemon::Cyberdemon() :Demon(1, 10, 10) 
{

}

Cyberdemon::Cyberdemon(int strength, int hitpoints) : Demon(1, strength, hitpoints) 
{
}

int Cyberdemon::getDamage()
{
	return Demon::getDamage();
}

Balrog::Balrog() : Demon(2, 10, 10)
{

}

Balrog::Balrog(int strength, int hitpoints) : Demon(2, strength, hitpoints)
{

}

int Balrog::getDamage()
{
	int damage = Demon::getDamage();
	int damage2 = (rand() % getStrength()) + 1;
	cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
	damage = damage + damage2;
	return damage;
}

Elf::Elf() :Creature(3, 10, 10)
{

}

Elf::Elf(int strength, int hitpoints) :Creature(3, strength, hitpoints)
{

}

int Elf::getDamage()
{
	// Elves inflict double magical damage with a 10% chance
	int damage = Creature::getDamage();
	if ((rand() % 10) == 0)
	{
		cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
		damage = damage * 2;
	}
	return damage;
}