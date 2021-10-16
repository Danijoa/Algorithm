#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int jari = 8;
	while (jari >= 0)
	{
		if (n / (int)pow(10, jari) != 0)
			break;
		jari--;
	}
	jari++;

	int hap = 0;
	int t = 0;
	for (int i = 1; i <= jari - 1; i++)
	{
		t += 9 * pow(10, i - 1);
		hap += (t - pow(10, (i - 1)) + 1)* i;
	}
	hap += (n - pow(10, (jari - 1)) + 1) * jari;

	cout << hap;
}

/*
	int n;
	cin >> n;

	int hap = 0, cnt = 1, digit = 9, result = 0;
	while (hap + digit < n)
	{
		// 9 + 90 + ...
		hap += digit;
		// 9*1 + 90*2 + ...
		result += digit * cnt;
		cnt++;
		digit *= 90;
	}
	result += (n - hap) * cnt;

	cout << result;
*/
