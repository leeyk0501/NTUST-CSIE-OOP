#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct player
{
	string name;
	int money;
	bool beBanker = false;
};
void print(vector<player> game)
{
	for (int i = 0;i < game.size();i++)
	{
		cout << game[i].name << " " << game[i].money << endl;
	}
}
int find(vector<player> game, string name) 
{
	for (int i = 0;i < game.size();i++)
	{
		if (game[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
bool allBeBanker(vector<player> game)
{
	for (int i = 0;i < game.size();i++)
	{
		if (!game[i].beBanker)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		string temp;
		vector<player> game;
		for (int i = 0;i < n;i++)
		{
			player p;
			cin >> p.name;
			p.money = 1000;
			game.push_back(p);
		}
		//---------------------------
		string banker, winer;
		int bankID, winMoney, winPeople, winID;
		while (cin >> banker)
		{
			bankID = find(game, banker);
			cin >> winMoney >> winPeople;
			game[bankID].beBanker = true;
			if (winPeople > 0)
			{
				game[bankID].money -= winMoney;
				game[bankID].money += winMoney % winPeople;
			}
			for (int i = 0;i < winPeople;i++)
			{
				cin >> winer;
				winID = find(game, winer);
				game[winID].money += (winMoney / winPeople);
			}

			if (allBeBanker(game))
			{
				print(game);
				break;
			}
		}
	}
	
	return 0;
}