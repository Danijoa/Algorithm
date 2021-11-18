#include <iostream>
#include <queue>

using namespace std;

int main() 
{
	queue<int> myQ;
	int num, jump;
	cin >> num >> jump;
	for (int i = 1; i <= num; i++)
		myQ.push(i);
	
	while (myQ.size() > 1)
	{
		for (int i = 1; i< jump; i++)
		{
			int temp = myQ.front();
			myQ.pop();
			myQ.push(temp);
		}
		myQ.pop();
	}

	cout << myQ.front();

	return 0;
}
