#include <iostream>
using namespace std;

void solution(long long int start, long long int end)
{
	long long int number[10];
	for (int i = 0; i < 10; i++)
	{
		number[i] = 0;
	}
 
	long long int point = 1;
	while (start <= end)
	{
		//큰 수 끝자리 9
		while (end % 10 != 9 && start <= end)
		{
			long long int temp = end;
			while (temp > 0)
			{
				number[temp % 10] += point;
				temp /= 10;
			}
			end--;
		}

		if (end < start)
			break;

		//작은 수 끝자리 0
		while (start % 10 != 0 && start <= end)
		{
			long long int temp = start;
			while (temp > 0)
			{
				number[temp % 10] += point;
				temp /= 10;
			}
			start++;
		}

		start /= 10;
		end /= 10;

		//point 자리 확인
		for (int i = 0; i < 10; i++)
		{
			number[i] += (end - start + 1) * point;
		}

		point *= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << number[i] << " ";
	}
} 

int main()
{
	long long int page;
	cin >> page;

	solution(1, page);
}
