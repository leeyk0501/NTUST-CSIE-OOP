#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double n, r, guess;
	while (cin >> n)
	{
		guess = n / 2;
		while (1)
		{
			r = n / guess;
			if ((guess - ((guess + r) / 2))<0.01)
			{
				guess = (guess + r) / 2;
				break;
			}
			guess = (guess + r) / 2;
		}
		cout << fixed << setprecision(2) << guess << endl;
	}
	return 0;
}