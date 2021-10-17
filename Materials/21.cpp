#include <iostream>

using namespace std;

int main()
{
	// 이기면 3 비기면 1 
	// 동점이면 마직막 위너 
	// 모든 라운드 동일하면 비김

	int a[10];
	for (int i = 0; i <= 9; i++)
		cin >> a[i];

	int b[10];
	for (int i = 0; i <= 9; i++)
		cin >> b[i];

	char s[10];
	int aS = 0, bS = 0;
	for (int i = 0; i <= 9; i++)
	{
		if (a[i] == b[i])
		{
			aS += 1;
			bS += 1;
			s[i] = 'D';
		}
		else if (a[i] > b[i])
		{
			aS += 3;
			s[i] = 'A';
		}
		else
		{
			bS += 3;
			s[i] = 'B';
		}
	}

	if (aS == bS)
	{
		if(aS == 10)
			cout << aS << " " << bS << "\n" << "D";
		else
		{
			for (int i = 9; i >= 0; i--)
			{
				if (s[i] != 'D')
				{
					cout << aS << " " << bS << "\n" << s[i];
					break;
				}
			}
		}
	}
	else
	{
		char w = aS > bS ? 'A' : 'B';
		cout << aS << " " << bS << "\n" << w;
	}

	return 0;
}
