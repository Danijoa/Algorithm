#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int time[2000];
	for (int i = 0; i < num; i++)
		cin >> time[i];

	int stop;
	cin >> stop;

	int index = 0, cnt;
	for (int i = 1; i <= stop + 1; i++)
	{
		cnt = 0;
		while (true)
		{
			if (cnt == num)
				break;

			if (index == num)
				index = 0;

			if (time[index] != 0)
				break;
			else
			{
				index += 1;
				cnt++;
			}
		}

		time[index++] -= 1;
	}

	if (cnt == num)
		cout << -1;
	else
		cout << index;	

	return 0;
}
