#include <iostream>

using namespace std;

void recursion(int num)
{
	cout << num-- << " ";

	if (num == 0)
		return;

	recursion(num);
}

int main()
{
	int num;
	cin >> num;

	recursion(num);

	return 0;
}
