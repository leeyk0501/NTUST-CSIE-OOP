#include<iostream>
using namespace std;

int main()
{
	long long int n, h, m, s;
	while (cin >> n)
	{
		h = n / 3600;
		n %= 3600;
		m = n / 60;
		n %= 60;
		s = n;
		cout << h << " hours " << m << " minutes and " << s << " seconds" << endl;
	}
	return 0;
}