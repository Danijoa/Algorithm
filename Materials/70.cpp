#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertex, edge;
vector<int> myV[21];
bool visited[21] = { false, };
vector<int> myAns[21];

void BFS(int start)
{
	queue<pair<int, int>> myQ;
	myQ.push(make_pair(start, 0));
	visited[start] = true;

	while (!myQ.empty())
	{
		int curNode = myQ.front().first;
		int curCnt = myQ.front().second;
		myQ.pop();
		myAns[curNode].push_back(curCnt);

		for (int i = 0; i < myV[curNode].size(); i++)
		{
			int nextNode = myV[curNode][i];
			if (visited[nextNode] == false)
			{
				visited[nextNode] = true;
				myQ.push(make_pair(nextNode, curCnt + 1));
			}
		}
	}
}

int main() 
{
	cin >> vertex >> edge;

	for (int i = 0; i < edge; i++)
	{
		int s, e;
		cin >> s >> e;
		myV[s].push_back(e);
	}

	BFS(1);

	for (int i = 2; i <= vertex; i++)
		cout << i << " : " << myAns[i][0] << "\n";

	return 0;
}
