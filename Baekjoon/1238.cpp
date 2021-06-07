#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 3000001
#define INF 987654321
using namespace std;

int student, road, party;
vector<vector<pair<int, int> > > goV;
vector<vector<pair<int, int> > > backV;
int time[MAX];
int sumTime[MAX];

void dijkstra(int start, vector<vector<pair<int, int> > >& graphV)	// & *
{
	// (시작마을 ~ 각 마을까지) 거리 저장 배열 생성 및 초기화
	fill(&time[0], &time[MAX - 1], INF);
	time[start] = 0;

	priority_queue<pair<int, int>> myQ;
	myQ.push(make_pair(-1 * time[start], start)); 

	while (!myQ.empty())
	{
		int curIndex = myQ.top().second; 
		int curTime = -1 * myQ.top().first;
		myQ.pop();

		for (int i = 0; i < graphV[curIndex].size(); i++)
		{
			int nextIndex = graphV[curIndex][i].first;
			int nextTime = graphV[curIndex][i].second;

			if (time[nextIndex] > nextTime + time[curIndex])	
			{
				time[nextIndex] = nextTime + time[curIndex];
				myQ.push(make_pair(-1 * time[nextIndex], nextIndex));
			}
		}
	}

	for (int i = 1; i <= student; i++)
	{
		sumTime[i] += time[i];
	}
}

int main()
{
	cin >> student >> road >> party;

	// 마을 벡터 생성 및 거리 입력
	backV.resize(student + 1);
	goV.resize(student + 1);
	int s, e, t;
	for (int i = 0; i < road; i++)
	{
		cin >> s >> e >> t;
		backV[s].push_back(make_pair(e, t));
		goV[e].push_back(make_pair(s, t));
	}

	// goTime 이랑 backTime 합 저장 할 곳
	fill(&sumTime[0], &sumTime[MAX - 1], 0);

	// 시작마을 ~ 각 마을까지의 최단거리 찾기
	dijkstra(party, goV);
	dijkstra(party, backV);

	// 출력
    int max = 0;
	for (int i = 1; i <= student; i++)
	{
        if(max < sumTime[i])
            max = sumTime[i];
	}
    cout << max;

	return 0;
}
