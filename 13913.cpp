#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int subin, target;
queue<pair<int, int>> myQ;	//time, position
bool visited[MAX];
int parent[MAX];
vector<int> myV;
int answer = 0;

void BFS()
{
	myQ.push(make_pair(0, subin));
	visited[subin] = true;

	while (!myQ.empty())
	{
		int curTime = myQ.front().first;
		int curPos = myQ.front().second;
		myQ.pop();

		if (curPos == target)
		{
			answer = curTime;

			while (curPos != subin)
			{
				myV.push_back(curPos);
				curPos = parent[curPos];
			}
			myV.push_back(subin);

			return;
		}

		if (curPos * 2 < MAX && visited[curPos * 2] != true)
		{
			myQ.push(make_pair(curTime + 1, curPos * 2));
			visited[curPos * 2] = true;
			parent[curPos * 2] = curPos;	//curPos*2의 부모는 curPod 이다(특정 위치에는 한번만 들리게 된다)
		}
		if (curPos + 1 < MAX && visited[curPos + 1] != true)
		{
			myQ.push(make_pair(curTime + 1, curPos + 1));
			visited[curPos + 1] = true;
			parent[curPos + 1] = curPos;
		}
		if (curPos - 1 >= 0 && visited[curPos - 1] != true)
		{
			myQ.push(make_pair(curTime + 1, curPos - 1));
			visited[curPos - 1] = true;
			parent[curPos - 1] = curPos;
		}
	}
}

int main()
{
	cin >> subin >> target;
	BFS();
	cout << answer << "\n";
	for (int i = myV.size() - 1; i >= 0; i--)
	{
		cout << myV[i] << " ";
	}
	return 0;
}
