// Name: �����Z
// Date: 20180522
// Last Update: 20180522
// Problem statement: C++ Homework "1002- WordGame"
#include<iostream>
#include<fstream>
#include<string>
#define SIZE 4
#define FILENAME "words.txt"
using namespace std;
// 8�Ӥ�V
const int add[8][8] = { { 1,0 },{ 1,1 },{ 0,1 },{ -1,1 },{ -1,0 },{ -1,-1 },{ 0,-1 },{ 1,-1 } };
// SIZE*SIZE ��r��}
char wordBoard[SIZE + 1][SIZE + 1];
// SIZE*SIZE ��}�A�������X���A
int board[SIZE][SIZE] = { 0 };

// Intent: �]�wBoard���w�]���A
// Pre: NULL
// Post: Board���s�]�w��0
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
// Intent: ���j���X��r��}���L�ŦX���r��
// Pre: findWord���M�䪺��r
// Post: �Y���ŦX���r��A�|�^��true�A�Ϥ���false
bool recursiveWordSearch(int x, int y, string word, string findWord)
{
	if (board[x][y] == 1 || x == SIZE || x < 0 || y == SIZE || y < 0) 
	{
		//�Y�H���X�L�A�ζW�X��ɡA�h�^��false
		return false;
	}
	else
	{
		//�������X
		board[x][y] = 1;
		
		word.push_back(wordBoard[x][y]);
		
		if (word == findWord)
		{
			//�Y�զX�X�ۦP��r�A�^��true
			return true;
		}
		else if (findWord[word.size() - 1] != wordBoard[x][y]) 
		{
			//�Y�ثe��r�w�g���~�A�˰h���X�@�B�A�æ^��false
			board[x][y] = 0;
			return false;
		}
		else
		{
			for (int i = 0; i < 8; i++) // 8�Ӥ�V
			{
				if (recursiveWordSearch(x + add[i][0], y + add[i][1], word, findWord))
				{
					return true;
				}
			}
		}
	}
	//�˰h���X�@�B�A�æ^��false
	board[x][y] = 0;
	return false;
}
// Intent: �q���P����m�}�l���j�M��ŦX����r
// Pre: findWord���M�䪺��r
// Post: �q���P����m�}�l���j�M��ŦX����r�A���N�^��true�A�Ϥ���false
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
				//�Y��bwordBoard�����ŦX��r�A�N��X��r�C
				cout << inputStr << endl;
			}
		}
		fs.close();
	}
	
	return 0;
}