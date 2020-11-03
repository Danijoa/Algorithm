#include <iostream>
using namespace std;

int main()
{
	int num, maxNum;
	cin >> num >> maxNum;

	int *card = new int[num];
	for (int i = 0; i < num; i++)
		cin >> card[i]; 

	int maxHap = 0;
	for (int first = 0; first < num - 2; first++)
	{
		for (int second = first + 1; second < num - 1; second++)
		{
			for (int third = second + 1; third < num; third++)
			{
				int tempHap = card[first] + card[second] + card[third];
				if ((tempHap <= maxNum) && (tempHap > maxHap))
				{
					maxHap = tempHap;
				}
			}
		}
	}

	cout << maxHap;
}
