#include <iostream>
#include <string>

using namespace std;

int main()
{
	string nS;
	cin >> nS;

	int store[10] = { 0, };
	for (int i = 0; i < nS.size(); i++)
	{
		int temp = nS[i] - '0';
		store[temp]++;
	}

	int max = 0, ans = -1;
	for (int i = 0; i <= 9; i++)
	{
		if (max <= store[i])
		{
			max = store[i];
			ans = i;
		}
	}

	cout << ans;
}
