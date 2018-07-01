// Name: �����Z
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
	// Intent: Player���w�]�غc�l
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
	// Intent: HumanPlayer���w�]�غc�l(�~��Player)
	// Pre:    NULL
	HumanPlayer();
	// Intent: �ϥΪ̳z�L��J�q�Ʀr
	// Pre:    cin >> �Ʀr
	// Post:   �^�ǨϥΪ̿�J���Ʀr
	virtual int getGuess();
private:

};
class ComputerPlayer : public Player
{
public:
	// Intent: ComputerPlayer���w�]�غc�l(�~��Player)
	// Pre:    NULL
	ComputerPlayer();
	// Intent: �q���۰ʲq�Ʀr
	// Pre:    NULL
	// Post:   �q���|�b�ثe���϶����q�@�ӼƦr�^��
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
	guess = (rand() % (top - bottom + 1)) + bottom; //bottom ~ top ���ü�
	cout << "computer guess " << guess << endl;
	return guess;
}
// you can modify the following codes to let your ��guess�� more smarter
bool checkForWin(int guess, int answer)
{
	
	if (answer == guess)
	{
		//�q���F
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
	play(playerH1, playerH2); //�H��VS�H��
	play(playerH1, playerC1); //�H��VS�q��
	play(playerC1, playerC2); //�q��VS�q��
	system("pause");
	return 0;
}