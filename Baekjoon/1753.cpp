include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 3000001
#define INF 987654321
using namespace std;

int vertex, edge;
int start;
vector<vector<pair<int, int> > > myGraph;
int dist[MAX];

void dijkstra(int start)
{
	dist[start] = 0;

	priority_queue<pair<int, int>> myQ;
	myQ.push(make_pair(-1 * dist[start], start)); // 거리, 인덱스 -> 거리순 오름차순 정렬

	while (!myQ.empty())
	{
		int curIndex = myQ.top().second; //큐에 저장된 거리가 가장 짧은 마을 인덱스
		int curDist = -1 * myQ.top().first;
		myQ.pop();

		//if(curDist > dist[curIndex])
			//continue;

		for (int i = 0; i < myGraph[curIndex].size(); i++) // 인접 마을 돌며 확인
		{
			int nextIndex = myGraph[curIndex][i].first;
			int nextDist = myGraph[curIndex][i].second;

			if (dist[nextIndex] > nextDist + dist[curIndex])	// 비교
			{
				dist[nextIndex] = nextDist + dist[curIndex];
				myQ.push(make_pair(-1 * dist[nextIndex], nextIndex));
			}
		}

	}
}

int main()
{
	cin >> vertex >> edge;
	cin >> start;

	// 마을 벡터 생성 및 거리 입력
	int u, v, w;
	myGraph.resize(vertex + 1);
	for (int i = 0; i < edge; i++)
	{
		cin >> u >> v >> w;
		myGraph[u].push_back(make_pair(v, w));
	}

	// (시작마을 ~ 각 마을까지) 거리 저장 배열 생성 및 초기화
	fill(&dist[0], &dist[MAX - 1], INF);

	// 시작마을 ~ 각 마을까지의 최단거리 찾기
	dijkstra(start);

	// 출력
	for (int i = 1; i <= vertex; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}
