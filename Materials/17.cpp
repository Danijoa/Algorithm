#include <iostream>

using namespace std;

string cal(int num, int total)
{
	int sum;
	if (num % 2 == 0)
		sum = (1 + num) * (num / 2);
	else
		sum = (1 + num) * (num / 2) + (1 + num) / 2;

	if (sum == total || num == 1)
		return "YES";
	else
		return "NO";
}

int main()
{
	int n;
	cin >> n;

	int num, total;
	for (int i = 0; i < n; i++)
	{
		cin >> num >> total;
		cout << cal(num, total) << "\n";
	}
}
