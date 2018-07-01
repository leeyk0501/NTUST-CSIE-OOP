// Name: 李聿鎧
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1002- WordGame"
#include<iostream>
#include<fstream>
#include<string>
#define SIZE 4
#define FILENAME "words.txt"
using namespace std;
// 8個方向
const int add[8][8] = { { 1,0 },{ 1,1 },{ 0,1 },{ -1,1 },{ -1,0 },{ -1,-1 },{ 0,-1 },{ 1,-1 } };
// SIZE*SIZE 文字方陣
char wordBoard[SIZE + 1][SIZE + 1];
// SIZE*SIZE 方陣，紀錄走訪狀態
int board[SIZE][SIZE] = { 0 };

// Intent: 設定Board為預設狀態
// Pre: NULL
// Post: Board重新設定為0
void resetBoard()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = 0;
		}
	}
}
// Intent: 遞迴走訪文字方陣有無符合的字串
// Pre: findWord為尋找的文字
// Post: 若有符合的字串，會回傳true，反之為false
bool recursiveWordSearch(int x, int y, string word, string findWord)
{
	if (board[x][y] == 1 || x == SIZE || x < 0 || y == SIZE || y < 0) 
	{
		//若以走訪過，或超出邊界，則回傳false
		return false;
	}
	else
	{
		//紀錄走訪
		board[x][y] = 1;
		
		word.push_back(wordBoard[x][y]);
		
		if (word == findWord)
		{
			//若組合出相同單字，回傳true
			return true;
		}
		else if (findWord[word.size() - 1] != wordBoard[x][y]) 
		{
			//若目前單字已經錯誤，倒退走訪一步，並回傳false
			board[x][y] = 0;
			return false;
		}
		else
		{
			for (int i = 0; i < 8; i++) // 8個方向
			{
				if (recursiveWordSearch(x + add[i][0], y + add[i][1], word, findWord))
				{
					return true;
				}
			}
		}
	}
	//倒退走訪一步，並回傳false
	board[x][y] = 0;
	return false;
}
// Intent: 從不同的位置開始遞迴尋找符合的文字
// Pre: findWord為尋找的文字
// Post: 從不同的位置開始遞迴尋找符合的文字，找到就回傳true，反之為false
bool wordSearch(string findWord)
{
	for (int startX = 0; startX < SIZE; startX++)
	{
		for (int startY = 0; startY < SIZE; startY++)
		{
			resetBoard();
			if (recursiveWordSearch(startX, startY, "", findWord))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	while (cin >> wordBoard[0])
	{
		for (int i = 1; i < SIZE; i++) 
		{
			cin >> wordBoard[i];
		}

		string inputStr;
		fstream fs;
		fs.open(FILENAME);
		while (getline(fs, inputStr))
		{
			if (wordSearch(inputStr)) 
			{
				//若能在wordBoard中找到符合單字，就輸出單字。
				cout << inputStr << endl;
			}
		}
		fs.close();
	}
	
	return 0;
}