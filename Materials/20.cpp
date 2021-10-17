#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a[100];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int b[100];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		switch (a[i] - b[i])
		{
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "A\n";
			break;
		case -1:
			cout << "B\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case -2:
			cout << "A\n";
			break;
		}
	}

	return 0;
}
