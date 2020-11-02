#include <iostream>
#include <algorithm>	//max
#include <cstring>	//memset
using namespace std;

int stairNumber;	//계단 수
int stairScore[333];	//각 계단 점수 저장
int storeScore[333];	//인덱스 값에 위치 하기 까지 최대값 저장

int solution(int stairNumber)
{
	//처음 시작 3칸만 미리 결정 해 줌
	storeScore[1] = stairScore[1];
	storeScore[2] = stairScore[2] + stairScore[1];
	storeScore[3] = max(stairScore[3] + stairScore[2], stairScore[3] + storeScore[1]);

	//이후는 계산식으로 해결
	for (int i=4; i<= stairNumber; i++)
	{
		//현재 계단[i]로 올 수 있는 경우
		//[i-1]를 밟고 올라오는 경우(연속 3칸 불가) 
		//or [i-1]를 밟지 않고 올라오는 경우
		storeScore[i] = max(stairScore[i] + stairScore[i - 1] + storeScore[i - 3], stairScore[i] + storeScore[i - 2]);
	}

	return storeScore[stairNumber];
}

int main()
{
	cin >> stairNumber;

	for (int i = 1; i <= stairNumber; i++)
	{
		cin >> stairScore[i];
	}

	memset(storeScore, 0, sizeof(storeScore));

	cout << solution(stairNumber);
}
