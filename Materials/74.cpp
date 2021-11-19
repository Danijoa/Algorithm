#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(int &a, int &b)
	{
		if (a > b)
			return true;	// a가 b보다 크면 swap : b가 더 앞쪽에 위치 -> 오름차순
		return false;
	}
};

int main()
{
	// greater<int>
	priority_queue<int, vector<int>, cmp> myQ;

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
