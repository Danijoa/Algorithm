#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> myV[8];

void BFS(int node)
{
	queue<int> myQ;
	myQ.push(node);

	while (!myQ.empty())
	{
		int curNode = myQ.front();
		myQ.pop();
		cout << curNode << " ";

		for (int i = 0; i < myV[curNode].size(); i++)
		{
			int nextNode = myV[curNode][i];
			myQ.push(nextNode);
		}
	}
}

int main() 
{
	for (int i = 0; i < 6; i++)
	{
		int p, c;
		cin >> p >> c;
		myV[p].push_back(c);
	}

	BFS(1);

	return 0;
}
