// Name: �����Z
// Date: 2018/04/02
// Last Update: 2018/04/04
// Problem statement: C++ Homework "0501"
#include "Header.h"

//�]�wtotal���
int HotDogStand::totalSold = 0;

// Intent: �^���`�P��ƶq
// Pre: NULL
// Post: �^���`�P��ƶq�A���O��int
int HotDogStand::allStandsoldAmount()
{
	return totalSold;
}
// Intent: ���u�P��ƶq+1
// Pre: NULL
// Post: ���u�P��ƶq+1�A�B�`�P��q�]+1
void HotDogStand::justSold()
{
	sold++;
	totalSold++;
}
// Intent: print�X���u�P��ƶq
// Pre: NULL
// Post: print�X���u�P��ƶq
void HotDogStand::print()
{
	cout << name << " " << thisStandSoldAmount() << endl;
}
// Intent: �^�Ǹ��u�P��ƶq
// Pre: NULL
// Post: �^�ǥX���u�P��ƶq�A���A��int
int HotDogStand::thisStandSoldAmount()
{
	return sold;
}