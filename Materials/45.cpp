#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int num, start;
	cin >> num >> start;

	queue<int> myQ;
	for (int i = 1; i <= num; i++)
		myQ.push(i);

	while (myQ.size() != 1)
	{
		for (int i = 1; i < start; i++)
		{
			int a = myQ.front();
			myQ.pop();
			myQ.push(a);
		}

		myQ.pop();
	}

	cout << myQ.front();

	return 0;
}
