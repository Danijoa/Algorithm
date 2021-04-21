#include <iostream>
using namespace std;

int coin;
int money;
int store[11];
int result = 0;

int main()
{
	cin >> coin;
	cin >> money;
	for (int i = 0; i < coin; i++)
	{
		cin >> store[i];
	}

	for (int i = coin - 1; i >= 0; i--)
	{
		int temp = money / store[i];
		if (temp == 0)
			continue;
		else
		{
			result += temp;
			money -= store[i] * temp;
		}
	}

	cout << result;
}
