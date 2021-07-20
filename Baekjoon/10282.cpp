#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 10001
#define INF 987654321
using namespace std;

int testCase;
int computerNum, linkNum, startNum;

struct info
{
	int arrive, second;
};
vector<info> myV[MAX];

// 다익스트라 : 감염 시작 컴퓨터에서 감염할 수 있는 모든 컴퓨터 까지의 시간 저장
int sec[MAX];

// 시간이 가장 짧은 것 부터 실행 : a시간이 b시간보다 크면 true 반환
struct compare 
{
	bool operator()(info& a, info& b) 
	{
		return a.second > b.second;
	}
};

int totalCom, totalTime;

void Dijkstra()
{
	// 우선순위 큐 : <데이터 타입, 컨테이너 타입, 정렬 기준>
	priority_queue<info, vector<info>, compare> myQ;

	// 출발 노드
	info temp;
	temp.arrive = startNum;
	temp.second = 0;
	myQ.push(temp);
	sec[startNum] = 0;

	while (!myQ.empty())
	{
		int curNum = myQ.top().arrive;
		int curSec = myQ.top().second;
		myQ.pop();

		// 전에 계산했던 거리가 더 짧으면 현재 길을 선택할 이유가 없음
		if (sec[curNum] < curSec)
			continue;

		//현대 컴퓨터에서 갈 수 있는 다른 컴퓨터 탐색
		for (int i = 0; i < myV[curNum].size(); i++)
		{
			int nextNum = myV[curNum][i].arrive;
			int nextSec = myV[curNum][i].second;	

			if (sec[nextNum] > curSec + nextSec)	// 시작~next > 시작~cur + cur~next
			{
				sec[nextNum] = curSec + nextSec;
				temp.arrive = nextNum;
				temp.second = sec[nextNum];
				myQ.push(temp);
			}
		}
	}
}

int main()
{
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		// 입력
		cin >> computerNum >> linkNum >> startNum;
		
		// 초기화
		for (int j = 1; j <= computerNum; j++)
		{
			sec[j] = INF;
			myV[j].clear();
		}

		// 저장
		for (int j = 0; j < linkNum; j++)
		{
			int a, d, s;
			cin >> a >> d >> s;

			info temp;
			temp.arrive = a;
			temp.second = s;
			myV[d].push_back(temp);
		}

		// 계산
		Dijkstra();

		// 출력
		totalCom = 0, totalTime = -1;
		for (int i = 1; i <= computerNum; i++)
		{
			if (sec[i] != INF)
			{
				totalCom++;
				totalTime = max(totalTime, sec[i]);
			}
		}
		cout << totalCom << " " << totalTime << endl;
	}
}
 
