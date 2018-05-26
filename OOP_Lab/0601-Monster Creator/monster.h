// Name: ßı¶÷ÒZ
// Date: 2018/04/05
// Last Update: 2018/04/05
// Problem statement: C++ Homework "0601"
#include <iostream> 
#include <string>
#include <map>

using namespace std;

class Monster
{
public:
	Monster();
	Monster(string name, float hp, float damage, float defense, float speed);
	void SetName(string name);
	void SetHP(float hp);
	void SetDamage(float damage);
	void SetDefense(float defence);
	void SetSpeed(float speed);

	void PrintAllState();
	string GetName();
	float GetHP();
	float GetDamage();
	float GetDefence();
	float GetSpeed();

	~Monster();
private:
	string name;
	float hp;
	float damage;
	float defense;
	float speed;
};

