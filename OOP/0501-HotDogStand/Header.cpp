// Name: 李聿鎧
// Date: 2018/04/02
// Last Update: 2018/04/04
// Problem statement: C++ Homework "0501"
#include "Header.h"

//設定total初值
int HotDogStand::totalSold = 0;

// Intent: 回傳總銷售數量
// Pre: NULL
// Post: 回傳總銷售數量，型別為int
int HotDogStand::allStandsoldAmount()
{
	return totalSold;
}
// Intent: 該攤銷售數量+1
// Pre: NULL
// Post: 該攤銷售數量+1，且總銷售量也+1
void HotDogStand::justSold()
{
	sold++;
	totalSold++;
}
// Intent: print出該攤銷售數量
// Pre: NULL
// Post: print出該攤銷售數量
void HotDogStand::print()
{
	cout << name << " " << thisStandSoldAmount() << endl;
}
// Intent: 回傳該攤銷售數量
// Pre: NULL
// Post: 回傳出該攤銷售數量，型態為int
int HotDogStand::thisStandSoldAmount()
{
	return sold;
}