#include <iostream>
#include <math.h>
#include <queue>

#define MAX 100001

using namespace std;

int a, b, n, m;	//2~30 0~100000
int visited[MAX] = {0};

int bfs(int n)
{
	queue<pair<int, int>> myQ;
	myQ.push(make_pair(n, 0));

	while (myQ.empty() != true)
	{
		int current = myQ.front().first;
		int count = myQ.front().second;

		if(current == m)
		{
			return count; 
		}

		myQ.pop();

		if ((current * a < MAX) && (visited[current * a] != 1))
		{
			visited[current * a] = 1;
			myQ.push(make_pair(current * a, count + 1));
		}
		if ((current * b < MAX) && (visited[current * b] != 1))
		{
			visited[current * b] = 1;
			myQ.push(make_pair(current * b, count + 1));
		}
		if ((current + a < MAX) && (visited[current + a] != 1))
		{
			visited[current + a] = 1;
			myQ.push(make_pair(current + a, count + 1));
		}
		if ((current + b < MAX) && (visited[current + b] != 1))
		{
			visited[current + b] = 1;
			myQ.push(make_pair(current + b, count + 1));
		}
		if ((current - a >= 0) && (visited[current - a] != 1))
		{
			visited[current - a] = 1;
			myQ.push(make_pair(current - a, count + 1));
		}
		if ((current - b >= 0) && (visited[current - b] != 1))
		{
			visited[current - b] = 1;
			myQ.push(make_pair(current - b, count + 1));
		}
		if ((current + 1 < MAX) && (visited[current + 1] != 1))
		{
			visited[current + 1] = 1;
			myQ.push(make_pair(current + 1, count + 1));
		}
		if ((current - 1 >= 0) && (visited[current - 1] != 1))
		{
			visited[current - 1] = 1;
			myQ.push(make_pair(current - 1, count + 1));
		} 
	}
	return -1;
}

int main()
{
	cin >> a >> b >> n >> m;

	cout << bfs(n);
}
