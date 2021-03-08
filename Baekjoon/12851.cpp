#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int subin, target;
queue<pair<int, int>> subinData;
int visited[MAX] = { 0, };
int cntPath = 0;
int minSec = -1;

void BFS()
{
	subinData.push(make_pair(subin, 0));

	while (!subinData.empty())
	{
		int curPos = subinData.front().first;
		int curTime = subinData.front().second;
		subinData.pop();

		//pop할때 방문 확인
		//
		visited[curPos] = 1;

		//목적지 도달 && 처음
		//최소 시간 기록, 최소 시간 기록
		if (curPos == target && minSec == -1)
		{
			minSec = curTime;
			cntPath++;
		}

		//목적지 도달
		//목적지 도달 && 처음이 아님
		//경로 경우의 수 업데이트
		if (curPos == target && minSec == curTime) 
			cntPath++;

		//x+1
		//범위안에 있고 && 방문하지 않았다면
		if (curPos + 1 < MAX && visited[curPos + 1] == 0)
			subinData.push(make_pair(curPos + 1, curTime + 1));

		//x-1
		if (curPos - 1 >= 0 && visited[curPos - 1] == 0)
			subinData.push(make_pair(curPos - 1, curTime + 1));

		//x*2
		if (curPos * 2 < MAX && visited[curPos * 2] == 0)
			subinData.push(make_pair(curPos * 2, curTime + 1));
	}
}

int main()
{
	cin >> subin >> target;

	BFS();

	cout << minSec << endl;
	cout << cntPath << endl;

	return 0;
}
