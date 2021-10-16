#include <iostream>
#include <math.h>

using namespace std;

int visited[200001] = { false, };

int main()
{
	int n;
	cin >> n;
  int cnt = 0;

  // 에라토스테네스의 체 : 소수 구하기
	// a = b * c 일 때, b 또는 c 중 하나는 반드시 sqrt(a) 이상이다
	// 따라서 sqrt(a) 이후에 나오는 소수가 아닌 숫자들은 
	// 2 ~ sqrt(a)을 확인하면서 걸러진다
	for (int i = 2; i <= (int)sqrt(n); i++)
	{
		if (visited[i] == false)
		{
			for (int j = i + i; j <= n; j += i)
			{
				visited[j] = true;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (visited[i] == false)
			cnt++;
	}

	cout << cnt;
}
