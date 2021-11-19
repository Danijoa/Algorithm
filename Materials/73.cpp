#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> myQ;

	int input;
	while (true)
	{
		cin >> input;

		if (input == -1)
			break;
		else if (input == 0)
		{
			if (myQ.empty())
				cout << -1 << "\n";
			else
			{
				cout << myQ.top();
				myQ.pop();
			}
		}
		else
			myQ.push(input);
	}
	return 0;
}
