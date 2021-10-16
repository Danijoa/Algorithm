#include <iostream>
#include <string>

using namespace std;

int cal(int n)
{
	int cnt = 0;
	
	for (int i = 1; i <= (int)sqrt(n); i++)
	{
		if (n % i == 0)
			cnt += 2;
	}
	if ((int)sqrt(n) * (int)sqrt(n) == n)
		cnt -= 1;

	return cnt;
}

int main()
{
	int n;
	cin >> n;
	
	int num[50001];
	for (int i = 1; i <= n; i++)
	{
		num[i] = cal(i);
	}

	for (int i = 1; i <= n; i++)
		cout << num[i] << " ";

	return 0;
}
