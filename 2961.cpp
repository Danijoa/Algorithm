#include <iostream>
using namespace std;

int number;
int flavor[2][10];
int minDiff = 999999999;

int cal(int shinTotal, int sseunTotal)
{
	if (shinTotal >= sseunTotal)
	{
		return (shinTotal - sseunTotal);
	}
	else
		return (sseunTotal - shinTotal);
}

//총 4개 라면
//1 -> 1,2 -> 1,2,3 -> 1,2,3,4 [num==0]
//2 -> 2,3 -> 2,3,4 [num==1]
//3 -> 3,4 [num==2]
//4 [num==4]
void solution(int point, int num, int shinTotal, int sseunTotal)
{
		int tempDiff = cal(shinTotal, sseunTotal);

		if (tempDiff < minDiff)
			minDiff = tempDiff;

	for (int y = point + 1; y < number; y++)
	{
		solution(y, num, shinTotal * flavor[0][y], sseunTotal + flavor[1][y]);
	}

	return;
}

int main()
{
	//재료 개수
	cin >> number;

	//신만 쓴맛 입력
	for (int y = 0; y < number; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			scanf("%d", &flavor[x][y]);
		}
	}
	
	//조합 확인
	for (int num = 0; num < number; num++)
	{
		for (int y = 0; y < number; y++)
		{
			solution(y, num, flavor[0][y], flavor[1][y]);
		}
	}

	//최소 차이
	cout << minDiff;

}
