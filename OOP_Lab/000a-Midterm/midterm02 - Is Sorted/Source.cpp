#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int d, num;
		int status = 0; //1:Ascending order, 2:Descending order, 3:All same, 4:No
		bool up = true;
		bool flag = true;
		vector<int> number;
		int upZero = 0, downZero = 0, Zero = 0;
		
		for (int i = 0;i < n;i++)
		{
			cin >> d;
			number.push_back(d);
			if (i == 0)
			{
				
			}
			else if (i == 1 || flag)
			{

				if (number[i] - number[i - 1] > 0) 
				{
					up = true;
					upZero++;
				}
				else if (number[i] - number[i - 1] < 0) 
				{
					up = false;
					downZero++;
				}
				else
				{
					Zero++;
				}
			}
			else
			{
				if (number[i] - number[i - 1] > 0)upZero++;
				else if (number[i] - number[i - 1] < 0)downZero++;
				else Zero++;
				
			}
		}
		if (Zero != 0 && downZero == 0 && upZero == 0) 
		{
			status = 3;
		}
		else if (downZero == 0 && upZero != 0)
		{
			status = 1;
		}
		else if (downZero != 0 && upZero == 0)
		{
			status = 2;
		}
		else
		{
			status = 4;
		}
		if (status == 1)cout << "Yes" << endl << "Ascending order" << endl;
		else if (status == 2)cout << "Yes" << endl << "Descending order" << endl;
		else if (status == 3)cout << "Yes" << endl << "All same" << endl;
		else if (status == 4)cout << "No" << endl;
	}

	return 0;
}