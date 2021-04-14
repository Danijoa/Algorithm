#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> coor;
vector<coor> eDepth;			// <수족관 깊이(y), 빠져나간 물 깊이>
vector<int> xHole;			// 구멍 열(x)위치
int row;				// 열 개수

int main()
{
	//꼭짓점
	int edge;
	cin >> edge;

	int x1, y1, x2, y2;
	cin >> x1 >> y1;				//첫(0,0)
	for (int i = 0; i < (edge / 2 - 1); i++)	//수족관 밑 변이 되는 꼭기점 두개씩 묶어서 저장 할 것이기에 for문도 반토막
	{
		cin >> x1 >> y1 >> x2 >> y2;		//y1=y2
		for (int j = x1; j < x2; j++)
		{
			eDepth.push_back({ y1, 0 });
		}
	}
	cin >> x2 >> y2;				//마지막(x2,0)
	row = x2;

	//구멍
	int hole;
	cin >> hole;

	for (int i = 0; i < hole; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		xHole.push_back(x1);
	}

	//각 열마다 빠져나갈 깊이 계산
	for (int i = 0; i < xHole.size(); i++)		//첫번째 구멍 부터 마지막 구멍까지 확인해가며
	{
		int curHole = xHole[i];			//현재 구멍 x열 위치
		int curDepth = eDepth[curHole].first;	//현재 구멍 y 깊이
		eDepth[curHole].second = curDepth;	//현재 구멍이 있는 열에서 물이 빠진 깊이 저장(다 빠져 나감)

		for (int j = curHole - 1; j >= 0; j--)				//현재 구멍있는 열 기준 왼쪽으로 하나씩 이동하면서 확인
		{
			curDepth = min(curDepth, eDepth[j].first);		//현재 구멍 깊이 보다 더 얕은 깊이를 만나면 그 깊이로 왼쪽으로 이동하면서 물을 뺌(물 빠지는 원리 생각해보면 됨)
			eDepth[j].second = max(curDepth, eDepth[j].second);	//현재 깊이랑 이미 줄어든 깊이 비교하여 더 깊은것 선택
		}

		curDepth = eDepth[curHole].first;	//다시 현재 깊이로 돌아와서
		for (int j = curHole + 1; j < row; j++)	//오른똑 열 확인하기
		{
			curDepth = min(curDepth, eDepth[j].first);
			eDepth[j].second = max(curDepth, eDepth[j].second);
		}
	}

	//수족관에 남아있는 양 계산
	int answer = 0;
	for (int i = 0; i < row; i++)
	{
		answer += (eDepth[i].first - eDepth[i].second);
	}
	cout << answer;

	return 0;
}
