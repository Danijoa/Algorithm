#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	/*
	 num = a + (a - 1) = 2a - 1 
	 (num + 1) % 2 == 0

	 num = a + (a - 1) + (a - 2) = 3a - (1 + 2) = 3a - 3
	 (num + 3) % 3 == 0

	 num = a + (a - 1) + (a - 2) + (a - 3) = 4a - (1 + 2 + 3) = 4a - 6
	 (num + 6) % 4 == 0

	 ... 해가 있는 것만 출력
	*/

	int count = 2, hap, result = 0;
	while (true)
	{
		hap = 0;
		for (int i = 1; i < count; i++)
			hap += i;

		if ((num + hap) % count == 0)
		{
			int a = (num + hap) / count;

			if (a - (count - 1) < 1)
				break;

			for (int i = count - 1; i >= 0; i--)
			{
				if(i == 0)
					cout << a - i << " = " << num;
				else
					cout << a - i << " + ";
			}
			cout << "\n";
			result++;
		}

		count++;
	}
	cout << result;

	return 0;
}
