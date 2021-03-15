#include <iostream>
using namespace std;

int num;
int flavor[11][2];
int minDiff = 999999999;

//1~num개 조합
void combination(int idx, int totalShin, int totalSSeun)
{
	int tempDiff = totalShin >= totalSSeun ? (totalShin - totalSSeun) : (totalSSeun - totalShin);

	if (tempDiff < minDiff)
		minDiff = tempDiff;

	for (int nIdx = idx + 1; nIdx < num; nIdx++)
	{
		combination(nIdx, totalShin * flavor[nIdx][0], totalSSeun + flavor[nIdx][1]);
	}
}

int main()
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int s, b;
		cin >> s >> b;
		flavor[i][0] = s;
		flavor[i][1] = b;
	}

	for (int idx = 0; idx < num; idx++)
	{
		combination(idx, flavor[idx][0], flavor[idx][1]);
	}

	cout << minDiff;

	return 0;
} 
