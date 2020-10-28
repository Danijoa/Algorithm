#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 3000001 //거리 최대 합

int v; //정점 개수
int e; //간선 개수
int k; //시작 정점
vector<vector<pair<int, int>>> myV; //인접 리스트
int* dist; //최소 거리 저장(양수)


void dijkstra(int k)
{
	dist[k] = 0;

	priority_queue<pair<int, int>> myQ;
	myQ.push(make_pair(dist[k], k)); //거리, 인덱스, 거리순 정렬

	while(myQ.empty() != true)
	{
		int curIndex = myQ.top().second; //큐에 저장된 거리가 가장 짧은 마을 인덱스
		int curDist = -1 * myQ.top().first;

		myQ.pop();

		if (curDist > dist[curIndex])
		{
			continue;
		}

		for (int i = 0; i < myV[curIndex].size(); i++) //인접 마을 돌며 확인
		{
			int nIndex = myV[curIndex][i].first;
			int nDist = myV[curIndex][i].second;

			if (dist[curIndex] + nDist < dist[nIndex])	//비교
			{
				dist[nIndex] = dist[curIndex] + nDist;
				myQ.push(make_pair(-dist[nIndex], nIndex));
			}
		}

	}
}

int main()
{
	cin >> v >> e;
	cin >> k;

	//마을 벡터 생성
	myV.resize(v + 1);

	//거리 저장 배열 생성 및 초기화
	dist = new int[v + 1];
	for (int i = 0; i < v + 1; i++)
	{
		dist[i] = MAX;
	}

	//마을 거리 입력
	int start, end, distance;
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> distance;
		myV[start].push_back(make_pair(end, distance));
	}

	//시작 마을에서 부터 각 마을 까지의 최단 거리 찾기
	dijkstra(k);

	//출력
	for (int i = 1; i < v + 1; i++)
	{
		if (dist[i] >= MAX )
		{
			cout << "INF" << "\n";
		}
		else
			cout << dist[i]<< "\n";
	}

	return 0;
}
