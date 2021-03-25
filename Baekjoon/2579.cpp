#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//마지막 + 마지막_누적-2
	//마지막 + 마지막-1+ 마지막_누적-3

	int step;
	cin >> step;
	int stepScore[301];
	for (int i = 1; i <= step; i++)
	{
		cin >> stepScore[i];
	}

	int maxScore[301];
	maxScore[1] = stepScore[1];
	maxScore[2] = maxScore[1] + stepScore[2];
	maxScore[3] = max(stepScore[3] + maxScore[3 - 2], stepScore[3] + stepScore[3 - 1]);
	for (int i = 4; i <= step; i++)
	{
		maxScore[i] = max((stepScore[i] + maxScore[i - 2]), (stepScore[i] + stepScore[i - 1] + maxScore[i - 3]));
	}

	cout << maxScore[step];

	return 0;
}
