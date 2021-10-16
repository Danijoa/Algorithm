#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int min = 100, max = 0, age;
	for (int i = 0; i < n; i++)
	{
		cin >> age;
		if (age < min)
			min = age;
		if (age > max)
			max = age;
	}

	cout << max - min;
}
