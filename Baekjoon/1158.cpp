#include <iostream>
#include <queue>

using namespace std;

/*
int sol(int n, int k)
{
	if (n == 1)
		return 1;

	return ((sol(n - 1, k) + k - 1) % n + 1);
}
*/

int main()
{
	int num, jump;
	cin >> num >> jump;

	queue<int> myQ;
	for (int i = 1; i <= num; i++)
		myQ.push(i);

	cout << "<";
	while (!myQ.empty())
	{
		if (myQ.size() == 1)
		{
			cout << myQ.front() << "> ";
			myQ.pop();
			break;
		}

		for (int i = 1; i <= jump - 1; i++)
		{
			myQ.push(myQ.front());
			myQ.pop();
		}
		cout << myQ.front() << ", ";
		myQ.pop();
	}

	/*
	int idx = jump;
	int visited[5001] = { false, };
	visited[idx] = true;
	cout << "<" << idx << ", ";
	for (int i = 0; i < num - 1; i++)
	{
		int cnt = 0;
		while (cnt < jump)
		{
			idx += 1;
			if (idx > num)
				idx -= num;

			if (visited[idx] == false)
				cnt++;
		}

		visited[idx] = true;
		if(i == num - 2)
			cout << idx << ">";
		else
			cout << idx << ", ";
	}
	*/
	
	return 0;
}
