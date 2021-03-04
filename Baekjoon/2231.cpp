#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int addedNum;
	cin >> addedNum;

	int jarisu;
	int ocha = 0;
	for (int i = 1000000; i >= 0; i /= 10)	//addedNum은 몇자리 수인가?
	{
		if (addedNum / i != 0)
		{
			jarisu = i;
			for (int j = jarisu; j >= 1; j /= 10)	//originalNum <= addedNum <= originalNum + ocha
			{
				ocha += 9;
			}
			break;
		}
	}

	int sum = 0;
	for (int i = addedNum - ocha; i <= addedNum; i++)	//가능성 있는 숫자들 
	{
		int temp = i;
		sum += temp;
		for (int j = jarisu; j >= 1; j /= 10)	//하나하나 분해합 해보자
		{
			sum += temp / j;
			temp %= j;
		}
		if (sum == addedNum)
		{
			cout << i;
			return 0;
		}
		sum = 0;
	}
	cout << 0;

	return 0;
}
