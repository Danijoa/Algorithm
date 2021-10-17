#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int day, sequence;
	cin >> day >> sequence;

	int temper[100001];
	int hap = 0;
	for (int i = 0; i < day; i++)
	{
		cin >> temper[i];
		if(i < sequence)
			hap += temper[i];
	}

	// (1 2 3 4) 5 6 7 -> 1+2+3+4=10
	// 1 (2 3 4 5) 6 7 -> 2+3+4+5=10-1+5=14
	int temp = hap;
	int ans = temp;
	for (int i = sequence; i < day; i++)
	{
		temp = temp - temper[i - sequence] + temper[i];
		ans = max(ans, temp);
	}

	cout << ans;

	return 0;
}
