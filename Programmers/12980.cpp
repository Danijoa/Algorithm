#include <iostream>
using namespace std;

int pow(int a, int b) {
	if (b == 0) {
		return 1;
	}

	int n = pow(a, b / 2);
	int temp = n * n;

	if (b % 2 == 0) {
		return temp;
	}
	else {
		return a * temp;
	}
}

int solution(int num)
{
	int ans = 1;

	int temp;
	int i = 0;
	while (true)
	{
		temp = pow(2, i);
		if (num == temp)
		{
			return ans;
		}
		else if (temp > num)
		{
			temp = temp / 2;
			num = num - temp;
			ans++;
			i = -1;
		}
		i++;
	}
}
