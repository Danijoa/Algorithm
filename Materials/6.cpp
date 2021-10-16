#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int num = 0;
	int p = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			num += (s[i] - '0') * pow(10, p);
			p++;
		}
	}
	cout << num << "\n";

	int cnt = 0;
	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			cnt += 2;
	}
	if ((int)sqrt(num) * (int)sqrt(num) == num)
		cnt -= 1;

	cout << cnt;
}
