// Name: �����Z
// Date: 2018/04/05
// Last Update: 2018/04/05
// Problem statement: C++ Homework "0601"
#include "monster.h"

// Intent: NULL
// Pre: NULL
// Post: NULL
Monster::Monster()
{
}

// Intent: �s�@�Ǫ�
// Pre: name�Bhp�Bdamage�Bdefense�Bspeed���o����
// Post: �s�W�Ǫ�(name�Bhp�Bdamage�Bdefense�Bspeed)
Monster::Monster(string name, float hp, float damage, float defense, float speed)
{
	SetName(name);
	SetHP(hp);
	SetDamage(damage);
	SetDefense(defense);
	SetSpeed(speed);
}

// Intent: �]�wname
// Pre: name���o����
// Post: �N�W�٥[�Jmonster��name�̭�
void Monster::SetName(string name)
{
	this->name = name;
}

// Intent: �]�whp
// Pre: hp���o����
// Post: �N�W�٥[�Jmonster��hp�̭�
void Monster::SetHP(float hp)
{
	this->hp = hp;
}

// Intent: �]�wdamage
// Pre: damage���o����
// Post: �N�W�٥[�Jmonster��damage�̭�
void Monster::SetDamage(float damage)
{
	this->damage = damage;
}

// Intent: �]�wdamage
// Pre: damage���o����
// Post: �N�W�٥[�Jmonster��damage�̭�
void Monster::SetDefense(float defence)
{
	this->defense = defence;
}

// Intent: �]�wspeed
// Pre: speed���o����
// Post: �N�W�٥[�Jmonster��speed�̭�
void Monster::SetSpeed(float speed)
{
	this->speed = speed;
}

// Intent: �L�X�Ǫ����ݩ�
// Pre: NULL
// Post: �L�X�Ǫ���name�Bhp�Bdamage�Bdefense�Bspeed
void Monster::PrintAllState()
{
	cout << "Name : " << this->name << endl;
	cout << "Hp : " << this->GetHP() << endl;
	cout << "Damage : " << this->GetDamage() << endl;
	cout << "Defence : " << this->GetDefence() << endl;
	cout << "Speed : " << this->GetSpeed() << endl;
}

// Intent: ���o�Ǫ���name
// Pre: NULL
// Post: �^�ǩǪ���name
string Monster::GetName()
{
	return name;
}

// Intent: ���o�Ǫ���hp
// Pre: NULL
// Post: �^�ǩǪ���hp
float Monster::GetHP()
{
	return hp;
}

// Intent: ���o�Ǫ���damage
// Pre: NULL
// Post: �^�ǩǪ���damage
float Monster::GetDamage()
{
	return damage;
}

// Intent: ���o�Ǫ���defense
// Pre: NULL
// Post: �^�ǩǪ���defense
float Monster::GetDefence()
{
	return defense;
}

// Intent: ���o�Ǫ���speed
// Pre: NULL
// Post: �^�ǩǪ���speed
float Monster::GetSpeed()
{
	return speed;
}

// Intent: NULL
// Pre: NULL
// Post: NULL
Monster::~Monster()
{
}
