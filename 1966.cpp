#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int cycle;
	cin >> cycle;
	while (cycle != 0)
	{
		cycle--;

		int result = 0;

		int paper, pivot;
		cin >> paper >> pivot;

		int num;
		queue<pair<int, int>> jungyo;
		int most[101];
		for (int i = 0; i < paper; i++)
		{
			cin >> num;
			jungyo.push(make_pair(num, i));
			most[i] = num;
		}

		sort(most, most + paper);

		int k = paper - 1;
		while(!jungyo.empty())
		{
			int curNum = jungyo.front().first;
			int checkP = jungyo.front().second;

			int curMost = most[k];
			if (curNum == curMost)
			{
				if (checkP == pivot)
				{
					result++;
					//cout << "result: " << result << endl;
					cout << result << "\n";
					break;
				}
				else
				{
					result++;
					jungyo.pop();
					k--;
				}
			}
			else
			{
				jungyo.pop();
				jungyo.push(make_pair(curNum, checkP));
			}
		}
	}
}
