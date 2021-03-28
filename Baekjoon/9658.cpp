#include <iostream>
using namespace std;

int main()
{
	int dol;
	cin >> dol;

	int DP[1001];

	DP[1] = 0;	//1개 남으면 상근이 짐
	DP[2] = 1;	//2개 이김
	DP[3] = 0;	//3개 짐
	DP[4] = 1;	//4개 이김
	
	for (int i = 5; i <= dol; i++)
	{
		if (DP[i - 1] == 0 || DP[i - 3] == 0 || DP[i - 4] == 0)
			DP[i] = 1;
		else
			DP[i] = 0;
	}

	cout << ((DP[dol] == 0) ? "CY" : "SK");

	return 0;
}
