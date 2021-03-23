#include <iostream>
#include <queue>
#include <stack>
#define MAX 100001
using namespace std;

int subin, target;
queue<pair<int, int>> myQ; //position, time
int visited[MAX];
int parent[MAX];
stack<int> myPath;

void BFS()
{
	myQ.push(make_pair(subin, 0));
	visited[subin] = 1;

	while (!myQ.empty())
	{
		int curPos = myQ.front().first;
		int curTime = myQ.front().second;
		myQ.pop();

		if (curPos == target)
		{
			cout << curTime << endl;

			while (curPos != subin)
			{
				myPath.push(curPos);
				curPos = parent[curPos];
			}
			myPath.push(subin);

			return;
		}

		if (curPos * 2 < MAX && visited[curPos * 2] != 1)
		{
			myQ.push(make_pair(curPos * 2, curTime + 1));
			visited[curPos * 2] = 1;
			parent[curPos * 2] = curPos;	//curPos*2의 부모는 curPod 이다(특정 위치에는 한번만 들리게 된다)
		}
		if (curPos + 1 < MAX && visited[curPos + 1] != 1)
		{
			myQ.push(make_pair(curPos + 1, curTime + 1));
			visited[curPos + 1] = 1;
			parent[curPos + 1] = curPos;
		}
		if (curPos - 1 >= 0 && visited[curPos - 1] != 1)
		{
			myQ.push(make_pair(curPos - 1, curTime + 1));
			visited[curPos - 1] = 1;
			parent[curPos - 1] = curPos;
		}
	}
}

int main()
{
	cin >> subin >> target;
	BFS();
	while (!myPath.empty())
	{
		cout << myPath.top() << " ";
		myPath.pop();
	}
	return 0;
}
