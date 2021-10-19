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

	// 뒤에서 부터 0 개수 = 2 * 5 개수
	int ans = sosuCnt[2] <= sosuCnt[5] ? sosuCnt[2] : sosuCnt[5];
	cout << ans;

	return 0;
}
