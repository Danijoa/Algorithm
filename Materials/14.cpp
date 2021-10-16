#include <iostream>
#include <string>

using namespace std;

int reverse(int x)
{
	int reNum = 0;

	while(x % 10 == 0)
	{
		x /= 10;
	}

	string sX = to_string(x);
	int len = sX.size();

	for (int i = 0; i < len; i++)
	{
		reNum += (sX[i] - '0') * pow(10, i);
	}

	return reNum;
}

bool isPrime(int x)
{
	if (x == 1)
		return false;

	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return false;
	}

	return true;
}

int main()
{
	int n;
	cin >> n;

	int num, reNum;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		reNum = reverse(num);
		if (isPrime(reNum))
			cout << reNum << " ";
	}
}
