#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 10001
using namespace std;

int test; //테스트케이스 개수

int nodeNum; //컴퓨터 개수
int depend; //의존성 개수
int start; //해킹당한 컴퓨터 번호

int a; //a가 b를 의존 (a<-b)
int b;
int s; //a와 b 사이 감염되는 시간

int com; //감염된 컴퓨터 수
int time; //마지막 컴퓨터가 감염되기 까지 시간

int dist[MAX]; //출발 노드에서 인덱스 노드까지 걸린 시간

struct info {
	int arrive, second;
};
info temp;
vector<info> myV[MAX]; //그래프 정보

struct compare {
	bool operator()(info& a, info& b) {
		return a.second > b.second; 
	}
}; //a시간이 b시간보다 크면 true 반환

int main()
{
	cin >> test;

	while (test != 0)
	{
		test--;

		cin >> nodeNum >> depend >> start;

		for (int i = 0; i <= nodeNum; i++) //초기화
		{
			dist[i] = INF;
			myV[i].clear();
		}

		for (int i = 0; i < depend; i++) //벡터에 그래프 정보 저장
		{
			cin >> a >> b >> s;
			temp.arrive = a;
			temp.second = s;
			myV[b].push_back(temp);
		}

		dist[start] = 0; //출발 노드 인덱스 0 으로 설정

		//우선순위 큐<데이터 타입, 컨테이너 타입, 정렬 기준>
		priority_queue<info, vector<info>, compare> myQ; //가장 시간이 짧은 것 부터
		temp.arrive = start;
		temp.second = 0;
		myQ.push(temp); //첫번째 출발 정보 큐에 저장

		while (!myQ.empty())
		{
			int curNode = myQ.top().arrive; 
			int curSec = myQ.top().second;
			myQ.pop();

			if (dist[curNode] < curSec) //전에 계산했던 거리가 더 짧으면 현재 길을 선택할 이유가 없음
			{
				continue;
			}

			for (int i = 0; i < myV[curNode].size(); i++) //현대 노드에서 갈 수 있는 다른 노드 탐색
			{
				int nextNode = myV[curNode][i].arrive;
				int nextSec = myV[curNode][i].second;

				if (dist[nextNode] > curSec + nextSec) //전에 계산했던 거리보다 짧으면 갱신
				{
					dist[nextNode] = curSec + nextSec;
					temp.arrive = nextNode;
					temp.second = curSec + nextSec;
					myQ.push(temp);
				}
			}
		}

		com = 0;
		time = -1;
		for (int i = 0; i <= nodeNum; i++)
		{
			if (dist[i] != INF)
			{
				com++;
				time = max(time, dist[i]);
			}
		}

		cout << com << " " << time << "\n";
	}
}
