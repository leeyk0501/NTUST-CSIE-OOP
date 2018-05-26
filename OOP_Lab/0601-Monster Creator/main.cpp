// Name: 李聿鎧
// Date: 2018/04/05
// Last Update: 2018/04/05
// Problem statement: C++ Homework "0601"
#include <iostream> 
#include <vector>
#include <map>
#include "monster.h"

using namespace std;

void menu();
void createMonster(map<string, Monster>&);
void checkMonsterState(map<string, Monster>&, string);
void changeMonsterState(map<string, Monster>&, string);

// main funtion
int main() {
	int features;
	//會用map的人推薦用map
	//當然用vector也是ok的
	map<string, Monster> monster;

	menu();
	while (cin >> features)
	{
		if (features == 0)
		{
			cout << "Please enter monster state" << endl;
			createMonster(monster); //製作新的怪物
		}
		else if (features == 1)
		{
			cout << "Please enter monster name : ";
			string name;
			cin >> name; //要檢查的怪物名稱
			checkMonsterState(monster, name); //檢查怪物的屬性
		}
		else if (features == 2)
		{
			cout << "Please enter monster name : ";
			string name;
			cin >> name;//要修改的怪物名稱
			changeMonsterState(monster, name); //修改現有的怪物屬性
		}

		//謝謝我吧哈哈哈 謝謝你
		cout << endl;
		menu();
	}
	return 0;
}

// Intent: 印出目錄選單
// Pre: NULL
// Post: 印出目錄選單
void menu()
{
	cout << "Create monster enter 0" << endl;
	cout << "Check state enter 1" << endl;
	cout << "Change state enter 2" << endl;
	cout << "Feature : ";
}

// Intent: 依照cin的資料，製作新的怪物和屬性
// Pre: 傳入以string為key、以Monster為value的Map，名為monster。共需輸入五筆資料
// Post: 新增怪物(name、hp、damage、defense、speed)
void createMonster(map<string, Monster> &monster)
{
	//輸入怪物屬性
	string monsterName;
	float hpValue, damageValue, defenseValue, speedValue;
	cin >> monsterName;
	cin >> hpValue;
	cin >> damageValue;
	cin >> defenseValue;
	cin >> speedValue;
	Monster monsterValue(monsterName, hpValue, damageValue, defenseValue, speedValue);
	//將怪物新增到資料庫內
	monster.insert(pair<string, Monster>(monsterName, monsterValue));
}

// Intent: 輸入要檢查怪物的name，檢查怪物的屬性
// Pre: name不得為空
// Post: 輸入要檢查怪物的name，如果找到就輸出該怪物的所有屬性，如果沒有就啥都不做
void checkMonsterState(map<string, Monster> &monster, string name)
{
	//尋找怪物
	map<string, Monster>::iterator it;
	it = monster.find(name);
	if (it != monster.end()) //找到怪物，就做好做滿，輸出該怪物的屬性
	{
		monster[name].PrintAllState();
	}
}

// Intent: 修改現有的怪物屬性
// Pre: name不得為空
// Post: 輸入要修改怪物的name，並重新輸入 5 個屬性，如果有在資料庫中找到怪物，就將它更改，如果沒有就啥都不做
void changeMonsterState(map<string, Monster> &monster, string name)
{
	cout << "Please enter new state : ";
	//尋找怪物
	map<string, Monster>::iterator it;
	it = monster.find(name);
	if (it != monster.end()) //找到怪物，就做好做滿，進行更改怪物
	{
		//將原怪物資料刪掉
		monster.erase(name);
		//重新新增一個怪物
		createMonster(monster);
	}
}
