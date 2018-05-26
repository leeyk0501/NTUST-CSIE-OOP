// Name: �����Z
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
	//�|��map���H���˥�map
	//��M��vector�]�Ook��
	map<string, Monster> monster;

	menu();
	while (cin >> features)
	{
		if (features == 0)
		{
			cout << "Please enter monster state" << endl;
			createMonster(monster); //�s�@�s���Ǫ�
		}
		else if (features == 1)
		{
			cout << "Please enter monster name : ";
			string name;
			cin >> name; //�n�ˬd���Ǫ��W��
			checkMonsterState(monster, name); //�ˬd�Ǫ����ݩ�
		}
		else if (features == 2)
		{
			cout << "Please enter monster name : ";
			string name;
			cin >> name;//�n�ק諸�Ǫ��W��
			changeMonsterState(monster, name); //�ק�{�����Ǫ��ݩ�
		}

		//���§ڧa������ ���§A
		cout << endl;
		menu();
	}
	return 0;
}

// Intent: �L�X�ؿ����
// Pre: NULL
// Post: �L�X�ؿ����
void menu()
{
	cout << "Create monster enter 0" << endl;
	cout << "Check state enter 1" << endl;
	cout << "Change state enter 2" << endl;
	cout << "Feature : ";
}

// Intent: �̷�cin����ơA�s�@�s���Ǫ��M�ݩ�
// Pre: �ǤJ�Hstring��key�B�HMonster��value��Map�A�W��monster�C�@�ݿ�J�������
// Post: �s�W�Ǫ�(name�Bhp�Bdamage�Bdefense�Bspeed)
void createMonster(map<string, Monster> &monster)
{
	//��J�Ǫ��ݩ�
	string monsterName;
	float hpValue, damageValue, defenseValue, speedValue;
	cin >> monsterName;
	cin >> hpValue;
	cin >> damageValue;
	cin >> defenseValue;
	cin >> speedValue;
	Monster monsterValue(monsterName, hpValue, damageValue, defenseValue, speedValue);
	//�N�Ǫ��s�W���Ʈw��
	monster.insert(pair<string, Monster>(monsterName, monsterValue));
}

// Intent: ��J�n�ˬd�Ǫ���name�A�ˬd�Ǫ����ݩ�
// Pre: name���o����
// Post: ��J�n�ˬd�Ǫ���name�A�p�G���N��X�өǪ����Ҧ��ݩʡA�p�G�S���Nԣ������
void checkMonsterState(map<string, Monster> &monster, string name)
{
	//�M��Ǫ�
	map<string, Monster>::iterator it;
	it = monster.find(name);
	if (it != monster.end()) //���Ǫ��A�N���n�����A��X�өǪ����ݩ�
	{
		monster[name].PrintAllState();
	}
}

// Intent: �ק�{�����Ǫ��ݩ�
// Pre: name���o����
// Post: ��J�n�ק�Ǫ���name�A�í��s��J 5 ���ݩʡA�p�G���b��Ʈw�����Ǫ��A�N�N�����A�p�G�S���Nԣ������
void changeMonsterState(map<string, Monster> &monster, string name)
{
	cout << "Please enter new state : ";
	//�M��Ǫ�
	map<string, Monster>::iterator it;
	it = monster.find(name);
	if (it != monster.end()) //���Ǫ��A�N���n�����A�i����Ǫ�
	{
		//�N��Ǫ���ƧR��
		monster.erase(name);
		//���s�s�W�@�өǪ�
		createMonster(monster);
	}
}
