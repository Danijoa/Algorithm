#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct myData
{
	int _dist;
	int _node;
};
struct cmp
{
	bool operator()(myData& a, myData& b)
	{
		if (a._dist < b._dist)
			return true;
		return false;
	}
};
int vertex, edge;
vector<pair<int, int>> graph[21];
int dist[21];
priority_queue<myData, vector<myData>, cmp> myQ;

void dijkstra(int start)
{
	dist[start] = 0;
	myQ.push({0, start});

	while (!myQ.empty())
	{
		int curNode = myQ.top()._node;
		myQ.pop();  // priority_queue로 pop한 dist는 이미 최소 경로로 갱신되어 있음

		for (int i = 0; i < graph[curNode].size(); i++)
		{
			int cnDist = graph[curNode][i].second;
			int nextNode = graph[curNode][i].first;

			if (dist[nextNode] > cnDist + dist[curNode])
			{
				dist[nextNode] = cnDist + dist[curNode];
				myQ.push({ dist[nextNode], nextNode });
			}
		}
	}

}

int main() 
{
	cin >> vertex >> edge;
	int s, e, w;
	for (int i = 0; i < edge; i++)
	{
		cin >> s >> e >> w;
		graph[s].push_back(make_pair(e, w));
	}

	fill(dist, dist + 21, INF);
	dijkstra(1);

	cout << dist[vertex];

	return 0;
}
