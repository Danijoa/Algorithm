#include <iostream>
#include <vector>
#include <queue>
#define INF 98764321

using namespace std;

int node, edge;
int maze[21][21] = { 0, };
int dist[21];
bool visited[21];

struct myS
{
	// 거리, 노드
	int curDist;
	int curNode;
};

struct compare
{
	// 거리 오름차순
	bool operator()(myS & a, myS &b)
	{
		if (a.curDist < b.curDist)
			return true;
		return false;
	}
};

void dijkstra(int start)
{
	priority_queue<myS, vector<myS>, compare> myQ;
	myQ.push({ 0, start });
	dist[start] = 0;

	while (!myQ.empty())
	{
		int scDist = myQ.top().curDist;
		int cNode = myQ.top().curNode;
		myQ.pop();

		for (int i = 1; i <= node; i++)
		{
			if (maze[cNode][i] == 0)
				continue;

			int cnDist = maze[cNode][i];
			int nNode = i;

			if (dist[nNode] > dist[cNode] + cnDist)
			{
				dist[nNode] = dist[cNode] + cnDist;
				myQ.push({ dist[nNode], nNode });
			}
		}
	}
}

int main() 
{
	cin >> node >> edge;

	for (int i = 0; i < edge; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		maze[s][e] = w;
	}

	/* fill_n(시작주소, 개수, 값) */
	//fill_n(dist, 21, INF);
	//fill_n(dist + 3, 5, INF);

	/* fill(시작주소, 마지막 주소 + 1, 값) */
	fill(dist, dist + 21, INF);
	//fill(dist + 3, dist + 8, INF);

	// 시작은 1
	dijkstra(1);

	cout << dist[node];

	return 0;
}
