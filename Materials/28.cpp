#include <iostream>

using namespace std;

int main()
{
	// 입력
	int num;
	cin >> num;

	// 사용된 소수(index)의 개수 저장
	int sosuCnt[1001] = { 0, };

	// 2부터 num까지 <소인수 분해>
	int curNum, div;
	for (int i = 2; i <= num; i++)
	{
		curNum = i;
		div = 2;

		while (curNum > 1)
		{
			if (curNum % div == 0)
			{
				curNum /= div;
				sosuCnt[div] += 1;
			}
			else
				div++;
		}
	}

	// 출력
	cout << num << "! = ";
	for (int i = 2; i <= num; i++)
	{
		if (sosuCnt[i] != 0)
			cout << sosuCnt[i] << " ";
	}

	return 0;
}
