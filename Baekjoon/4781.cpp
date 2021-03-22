#include <iostream>
#include <algorithm>	//max
#include <cstring>	//memset
using namespace std;

int numCandy;
double maxMoney;
int candyCalo;
double candyPrice;
pair<int, int> candy_CP[5001];
int storeMoney[10001]; //1원으로 살수 있는 최대 칼로리, 2원으로 살수 있는 최대 칼로리, ...10001원으로 살 수 있는 최대 칼로리 저장

int solution(int my_maxMoney)
{ 
	//중복 계산 제거
	int resultCalo = storeMoney[my_maxMoney];
	if (resultCalo != -1)
	{
		return resultCalo;
	}
	resultCalo = 0;

	for (int i = 0; i < numCandy; i++)
	{
		//돈계산
		//해당 캔디를 현재 살 수 있다면
		if (my_maxMoney - candy_CP[i].second >= 0)
		{
			//칼로리 계산
			//현재칼로리 or
			//해당 캔디칼로리 + 해당칼로리는 사고 난 후 남은 돈으로 살 수 있는 최대의 칼로리
			//(해당 캔디를 사는 선택을 했을 때 남은 돈으로 살 수 있는 최선의 선택)
			//높은 결과 선택 
			resultCalo = max(resultCalo, candy_CP[i].first + solution(my_maxMoney - candy_CP[i].second));
			storeMoney[my_maxMoney] = resultCalo;
		}
	}

	return resultCalo;
}

int main()
{
	while (true)
	{
		memset(storeMoney, -1, sizeof(storeMoney));

		cin >> numCandy >> maxMoney;
		if (numCandy == 0 && maxMoney == 0.00)
			break;

		for (int i = 0; i < numCandy; i++)
		{
			cin >> candyCalo >> candyPrice;
			candy_CP[i] = make_pair(candyCalo, (int)(candyPrice * 100 + 0.5));	//소수점을 자연수로 저장
		}

		cout << solution((int)(maxMoney * 100 + 0.5)) << endl;
	}
}
