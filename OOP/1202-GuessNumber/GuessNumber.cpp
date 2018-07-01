// Name: 李聿鎧
// Date: 20180530
// Last Update: 20180530
// Problem statement: C++ Homework "1202 - GuessNumber"
#include<iostream>
#include<time.h>
using namespace std;
int top, bottom, answer;
class Player
{
public:
	// Intent: Player的預設建構子
	// Pre:    NULL
	Player();
	// Intent: 
	// Pre:    
	// Post:   
	virtual int getGuess();
private:

};
class HumanPlayer : public Player
{
public:
	// Intent: HumanPlayer的預設建構子(繼承Player)
	// Pre:    NULL
	HumanPlayer();
	// Intent: 使用者透過輸入猜數字
	// Pre:    cin >> 數字
	// Post:   回傳使用者輸入的數字
	virtual int getGuess();
private:

};
class ComputerPlayer : public Player
{
public:
	// Intent: ComputerPlayer的預設建構子(繼承Player)
	// Pre:    NULL
	ComputerPlayer();
	// Intent: 電腦自動猜數字
	// Pre:    NULL
	// Post:   電腦會在目前的區間內猜一個數字回傳
	virtual int getGuess();
private:

};
Player::Player()
{

}
HumanPlayer::HumanPlayer()
{

}
ComputerPlayer::ComputerPlayer()
{

}
int Player::getGuess()
{
	return 0;
}
int HumanPlayer::getGuess()
{
	int guess;
	cin >> guess;
	return guess;
}
int ComputerPlayer::getGuess()
{
	int guess;
	guess = (rand() % (top - bottom + 1)) + bottom; //bottom ~ top 的亂數
	cout << "computer guess " << guess << endl;
	return guess;
}
// you can modify the following codes to let your “guess” more smarter
bool checkForWin(int guess, int answer)
{
	
	if (answer == guess)
	{
		//猜中了
		cout << "You're right! You win!" << endl;
		return true;
	}
	else
	{
		if (guess > answer && guess < top)
		{
			top = guess;
		}
		else if (guess < answer && guess > bottom)
		{
			bottom = guess;
		}
		if (answer < guess)
			cout << "Your guess is too high." << endl << bottom << "~" << top << endl;
		else
			cout << "Your guess is too low." << endl << bottom << "~" << top << endl;
		return false;
	}
	
}
void play(Player &player1, Player &player2)
{
	top = 100;
	bottom = 0;
	srand(time(NULL));
	answer = rand() % top + bottom;
	int guess = 0;
	bool win = false;
	while (!win)
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win) return;
		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}
// Main
int main()
{
	HumanPlayer playerH1, playerH2;
	ComputerPlayer playerC1, playerC2;
	play(playerH1, playerH2); //人類VS人類
	play(playerH1, playerC1); //人類VS電腦
	play(playerC1, playerC2); //電腦VS電腦
	system("pause");
	return 0;
}