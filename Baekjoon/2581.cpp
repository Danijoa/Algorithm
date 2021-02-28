#include <iostream>
#include <math.h>
#define MAX  10001
using namespace std;

//n = a*b 일때, a >= √n 이면, a*b = n = √n*√n 이므로, b <= √n 된다.

int main()
{
	int result = 0;

	int minNum, maxNum;
	cin >> minNum >> maxNum;

	int firstSosu;
	int sosu[MAX] = { 0 };
	for (int i = minNum ; i <= maxNum; i++)
	{
		bool check = true;
		if (sosu[i] != 1)	//소수일 가능성 있는 숫자
		{
			for (int j = 2; j <= sqrt(i); j++)	//2~√i로 
			{
				if (i % j == 0)	//나누어 지면 소수 아님
				{
					check = false;

					int k = 1;
					while(true)	//소수가 아니면 그 배수도 소수가 아님
					{
						sosu[i * k] = 1;
						k++;
						if (i * k > maxNum)	
							break;
					}

					break;
				}
			}
			if (check == true && i != 1)	//소수임 (1은 아님)
			{
				if (result == 0)
					firstSosu = i;
				result += i;
			}
		}
	}

	if (result == 0)	//소수 없음
		cout << -1;
	else
	{
		cout << result << "\n" << firstSosu;
	}

	return 0;
}
