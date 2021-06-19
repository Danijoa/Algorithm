#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 10000001
using namespace std;

int c;	//약수 개수 구할 숫자 개수 1<=c<=10
int l;	//작은 숫 (두 수 차이는 1000이하)
int u;	//큰 수 1<=u<=10000000 
int cnt;
int result;

void solution(int l, int u)	//l~u 사이 수 중 가장 약수의 개수가 큰 수의 약수 개수를 구하시오
{
	result = 0;
	for (int n = l; n <= u; n++)
	{
		cnt = 0;
		for (int i = 1; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				if (i == sqrt(n))
				{
					cnt += 1;
				}
				else
				{
					cnt += 2;
				}
			}
		}
		result = max(result, cnt);
	}
	cout << result << "\n";
}

int main()
{
	cin >> c;
	while (c != 0)
	{
		c--;
		cin >> l >> u;
		solution(l, u);
	}
}
