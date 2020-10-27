#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int start, target;
int dis[3] = {-1, +1, 2};

void bfs()
{
	bool visited[MAX] = {false};
	visited[start] = true;

	int count = 0;
	queue<pair<int, int>> myQ;
	myQ.push(make_pair(start, count));

	while (!myQ.empty())
	{
		int cur = myQ.front().first;
		count = myQ.front().second;
		if (cur==target)
		{
			cout << count;
			break;
		}
		myQ.pop();

		if (cur + 1 < MAX && !visited[cur + 1])
		{
			visited[cur + 1] = true;
			myQ.push(make_pair(cur + 1, count + 1));
		}

		if (cur * 2< MAX && !visited[cur * 2])
		{
			visited[cur * 2] = true;
			myQ.push(make_pair(cur * 2, count + 1));
		}

		if (cur - 1 >= 0 && !visited[cur - 1])
		{
			visited[cur - 1] = true;
			myQ.push(make_pair(cur - 1, count + 1));
		}
	}
}

int main()
{
	cin >> start >> target;
	bfs();
}
