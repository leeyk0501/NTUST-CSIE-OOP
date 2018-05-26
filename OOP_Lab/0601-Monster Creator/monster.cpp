// Name: 李聿鎧
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

// Intent: 製作怪物
// Pre: name、hp、damage、defense、speed不得為空
// Post: 新增怪物(name、hp、damage、defense、speed)
Monster::Monster(string name, float hp, float damage, float defense, float speed)
{
	SetName(name);
	SetHP(hp);
	SetDamage(damage);
	SetDefense(defense);
	SetSpeed(speed);
}

// Intent: 設定name
// Pre: name不得為空
// Post: 將名稱加入monster的name裡面
void Monster::SetName(string name)
{
	this->name = name;
}

// Intent: 設定hp
// Pre: hp不得為空
// Post: 將名稱加入monster的hp裡面
void Monster::SetHP(float hp)
{
	this->hp = hp;
}

// Intent: 設定damage
// Pre: damage不得為空
// Post: 將名稱加入monster的damage裡面
void Monster::SetDamage(float damage)
{
	this->damage = damage;
}

// Intent: 設定damage
// Pre: damage不得為空
// Post: 將名稱加入monster的damage裡面
void Monster::SetDefense(float defence)
{
	this->defense = defence;
}

// Intent: 設定speed
// Pre: speed不得為空
// Post: 將名稱加入monster的speed裡面
void Monster::SetSpeed(float speed)
{
	this->speed = speed;
}

// Intent: 印出怪物的屬性
// Pre: NULL
// Post: 印出怪物的name、hp、damage、defense、speed
void Monster::PrintAllState()
{
	cout << "Name : " << this->name << endl;
	cout << "Hp : " << this->GetHP() << endl;
	cout << "Damage : " << this->GetDamage() << endl;
	cout << "Defence : " << this->GetDefence() << endl;
	cout << "Speed : " << this->GetSpeed() << endl;
}

// Intent: 取得怪物的name
// Pre: NULL
// Post: 回傳怪物的name
string Monster::GetName()
{
	return name;
}

// Intent: 取得怪物的hp
// Pre: NULL
// Post: 回傳怪物的hp
float Monster::GetHP()
{
	return hp;
}

// Intent: 取得怪物的damage
// Pre: NULL
// Post: 回傳怪物的damage
float Monster::GetDamage()
{
	return damage;
}

// Intent: 取得怪物的defense
// Pre: NULL
// Post: 回傳怪物的defense
float Monster::GetDefence()
{
	return defense;
}

// Intent: 取得怪物的speed
// Pre: NULL
// Post: 回傳怪物的speed
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
