#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 10001
using namespace std;

//n = a*b 일때, a >= √n 이면, a*b = n = √n*√n 이므로, b <= √n 된다.

int main()
{
	int m, n;	//m이상 n이하 자연수(10000이하) 중 소수인것 찾기
	int hap = 0;	//합
	int minNum = MAX;	//최소값

	cin >> m;
	cin >> n;

	bool check;
	for (int i = m; i <= n; i++)	//i는
	{
		check = true;
		for (int j = 2; j <= sqrt(i); j++)	//소수인가? i는 4 이상 부터
		{
			if (i % j == 0)
			{
				check = false;	//소수 아님
				break;
			}
		}

		if (check == true && i != 1)	//소수 맞음 (1은 소수 아님)
		{
			hap += i;
			minNum = min(minNum, i);
		}
	}

	if (hap != 0)
	{
		cout << hap << "\n";
		cout << minNum;
	}
	else
	{
		cout << -1;//소수 없음
	}
}
