#include <iostream>
using namespace std;

int main()
{
	int number;
	cin >> number;

	int k1 = 0, k2= 0;
	for (int i = 1; i <= number; i++)
	{
		string broad;
		cin >> broad;

		if (broad == "KBS1")
			k1 = i;
		if (broad == "KBS2")
			k2 = i;
	}

	if (k1 > k2)
		k2++;

	//KBS1 첫번째로
	int temp = 1;
	if (k1 != 1)
	{
		while (temp != k1)	//찾기
		{
			temp++;
			cout << "1";
		}
		while (k1 != 1)
		{
			k1--;
			temp--;
			cout << "4";
		}
	}

	//KBS2 두번째로
	if (k2 != 2)
	{
		while (temp != k2)	//찾기
		{
			temp++;
			cout << "1";
		}
		while (k2 != 2)
		{
			k2--;
			cout << "4";
		}
	}
}
