#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> coor;	
vector<coor> depth;	//<수족관 깊이, 빠져나간 물 깊이> 
vector<int> hole;	//구멍이 있는 열의 위치
int row;	//수족관 열 개수

int main()
{
	//(x, y) (몇번째 row, 몇번째 column)
	
	int edgeNum;
	cin >> edgeNum;
	
	int x, y, x2, y2;
	cin >> x >> y;	//첫(0,0)
	for (int i = 0; i < (edgeNum / 2 - 1); i++)	//수족관 밑 변이 되는 꼭지점 두개씩 묶어서
	{
		cin >> x >> y >> x2 >> y2;	//y=y2
		for (int j = x; j < x2; j++)
		{
			depth.push_back({ y,0 });
		}
	}
	cin >> x >> y;	//마지막 (a,0)
	row = x;

	int holeNum;
	cin >> holeNum;
	for (int i = 0; i < holeNum; i++)
	{
		cin >> x >> y >> x2 >> y2;
		hole.push_back(x);
	}

	for (int i = 0; i < hole.size(); i++)	//첫번째 구멍 부터 마지막 구멍까지 확인해가며
	{
		int holeX = hole[i];	//구멍이 있는 곳 위치
		int curDepth = depth[holeX].first;	//구멍이 있는 곳 깊이
		depth[holeX].second = curDepth;	//구멍이 있는 곳 물 빠져 나간 깊이 저장

		for (int j = holeX - 1; j >= 0; j--)	//구멍 왼쪽 열 확인
		{
			curDepth = min(curDepth, depth[j].first);	//나보다 더 낮은 깊이 만나면 더 낮은 깊이로 왼쪽으로 이동하면서 물 뺌(물빠지는 원리 생각해보면 됨)
			depth[j].second = max(curDepth, depth[j].second);	//가장 깊은 배수량 선택
		}

		curDepth = depth[holeX].first;	//다시 구멍위치에서 시작해서
		for (int j = holeX + 1; j < row; j++)	//구멍 오른쪽 열 확인
		{
			curDepth = min(curDepth, depth[j].first);	
			depth[j].second = max(curDepth, depth[j].second);	
		}
	}

	int answer = 0;
	for (int i = 0; i < row; i++)
	{
		answer += depth[i].first - depth[i].second;
	}
	cout << answer;

	return 0;
}
