#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	int n;
	cin >> n;
	
	int num, max = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		int k = 7;
		int total = 0;
		int temp = num;
		while (k >= 0)
		{
			int p = temp / pow(10, k);
			if (p != 0)
			{
				total += p;
				temp -= p * pow(10, k);
			}
			k--;
		}
		if (max < total)
		{
			max = total;
			ans = num;
		}
		else if (max == total)
		{
			ans = ans < num ? num : ans;
		}
	}

	cout << ans;

	return 0;
}
