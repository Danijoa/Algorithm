#include<iostream>
#include <vector>
#include <queue>
#define MAX_CITY 1002
#define INF 987654321
using namespace std;

int cityNum;
int busNum;
int start, target;
vector<vector<pair<int, int> > > vBus;	//출발지-(도착지, 비용)
priority_queue<pair<int, int> > qCost;	//비용, 도시번호
int dist[MAX_CITY];						//출발지~도착지 최단비용

void dijkstra(int start)
{
	dist[start] = 0;

	qCost.push(make_pair(dist[start], start));

	while (!qCost.empty())
	{
		int curCost = qCost.top().first;	//start~curCity 버스 비용 중 하나
		int curCity = qCost.top().second;
		qCost.pop();
		
		//curCost > start~curCity 현재 까지의 최단비용
		if (curCost > dist[curCity])		
			continue;							//해당 비용으로 curCity를 거져서 다른 도시에 도착하는 길은 볼 필요 없음

		//curCity에서 tempCity로 가는 버스들 탐색
		for (int i = 0; i < vBus[curCity].size(); i++)
		{
			int tmepCost = vBus[curCity][i].second;	
			int tempCity = vBus[curCity][i].first;
			
			if (dist[tempCity] > curCost + tmepCost)
			{
				dist[tempCity] = curCost + tmepCost;
				qCost.push(make_pair(dist[tempCity], tempCity));
			}
		}
	}
}

int main()
{
	cin >> cityNum;
	cin >> busNum;

	//출발 도착 비용
	vBus.resize(cityNum + 1);
	int s, t, c;
	for (int i = 0; i < busNum; i++)
	{
		cin >> s >> t >> c;
		vBus[s].push_back(make_pair(t, c));
	}

	//출발점 도착점
	cin >> start >> target;

	//도시 사이 최소비용 계산
	for (int i = 0; i < MAX_CITY; i++)
		dist[i] = INF;
	dijkstra(start);

	//결과: 비용
	cout << dist[target];

	return 0;
}
