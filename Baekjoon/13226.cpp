#include <iostream>
#include "math.h"
using namespace std;

int cnt;
int result;

void DiviserCount(int l, int u) //l ~ u 사이 수 중 가장 약수의 개수가 큰 수의 약수 개수를 구하시오
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
					cnt += 1;
				else
					cnt += 2;
			}
		}
		result = max(result, cnt);
	}
	cout << result << "\n";
}

int main()
{
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int l, u;
        cin >> l >> u;
        DiviserCount(l, u);
    }
}
