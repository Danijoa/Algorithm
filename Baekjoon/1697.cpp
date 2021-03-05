#include <iostream>
#define MAX 100001
#include <queue>
using namespace std;

int subin, target;
queue<pair<int, int>> myQ;	//위치, 시간
bool visited[MAX];

void BFS()
{
	visited[subin] = true;
	myQ.push(make_pair(subin, 0));

	while(!myQ.empty())
	{
		int curPos = myQ.front().first;
		int curTime = myQ.front().second;
		myQ.pop();

		//목표지점에 도착
		if (curPos == target)
		{
			cout << curTime;
			break;
		}

		//앞으로
		if (curPos + 1 <= MAX && !visited[curPos + 1])
		{
			visited[curPos + 1] = true;
			myQ.push(make_pair(curPos + 1, curTime + 1));
		}

		//뒤로
		if (curPos - 1 >= 0 && !visited[curPos - 1])
		{
			visited[curPos  - 1] = true;
			myQ.push(make_pair(curPos - 1, curTime + 1));
		}

		//텔포
		if (curPos * 2 <= MAX && !visited[curPos * 2])
		{
			visited[curPos * 2] = true;
			myQ.push(make_pair(curPos * 2, curTime + 1));
		}

	}
}

int main()
{
	cin >> subin >> target;

	BFS();

	return 0;
}
