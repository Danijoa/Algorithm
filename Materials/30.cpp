#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;
	
	// 3보다 작으면 leftnum*자리수
	// 3과 같으면 leftnum*자리수 + rightNum + 1
	// 3보다 크면 (leftnum+1)*자리수

	int p = 0;
	int sum = 0;
	while (true)
	{
		if (num / pow(10, p) == 0)
			break;

		int left = num / (int)pow(10, p + 1);
		int right = num % (int)pow(10, p + 1);
		int cur = (num - left * (int)pow(10, p + 1)) / (int)pow(10, p);

		if (cur < 3)
			sum += left * (int)pow(10, p);
		else if (cur == 3)
			sum += (left * (int)pow(10, p) + right + 1);
		else
			sum += (left + 1) * (int)pow(10, p);

		p++;
	}

	cout << sum;
	
	return 0;
}
