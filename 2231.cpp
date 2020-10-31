#include <iostream>
using namespace std;

int added;
int original;

int main()
{
	cin >> added;

	int most;
	int ocha = 0;
	for (int i = 1000000; i >= 0; i = i / 10)
	{
		if (added / i != 0)
		{
			most = i;
			for (int j = most; j >= 1; j = j / 10)
			{
				ocha += 9;
			}
			break;
		}
	}

	bool check = false;
	int sum = 0;
	for (int i = added - ocha; i <= added; i++)
	{
		int temp = i;
		sum += i;
		for (int j = most; j >= 1; j = j / 10)
		{
			sum += temp / j;
			temp %= j;
		}
		
		if (sum == added)
		{
			check = true;
			cout << i;
			break;
		}
		sum = 0;
	}
	if (!check)
		cout << "0\n";
}
