#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int money = 1000;
	int change[6] = { 500,100,50,10,5,1 };
	
	int pay;
	cin >> pay;
	money -= pay;

	int cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		if (money / change[i] > 0)
		{
			cnt += money / change[i];
			money = money % change[i];
		}

		if (money == 0)
		{
			break;
		}
	}

	cout << cnt;
}
