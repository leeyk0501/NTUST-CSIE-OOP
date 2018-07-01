#include "Dice.h"

Dice::Dice()
{
	this->numSides = 6;
	srand(time(NULL)); // Seeds random number generator
}
Dice::Dice(int numSides)
{
	this->numSides = numSides;
	srand(time(NULL)); // Seeds random number generator
}
int Dice::rollDice() const
{
	//�^�ǻ�l���I��
	return (rand() % numSides) + 1;
}
int LoadedDice::rollDice() const
{
	//Override the rollDice function so that with a 50 % chance the
	//function returns the largest number possible(i.e.numSides) and with
	//a 50 % chance return what Dice��s rollDice function returns.
	int number = rand() % numSides + 1;
	int chance = rand() % 100 + 1;
	if (chance > 50)
	{
		//��50%���v�W�ѷ|���U�A�A������X�̤j��
		return this->numSides;
	}
	else
	{
		//�t�~50%���v�W�Ѥ��|���U�A�A������
		return number;
	}
}
int rollTwoDice(const Dice& die1, const Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}