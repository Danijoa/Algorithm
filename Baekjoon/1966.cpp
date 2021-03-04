#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int loop;
	cin >> loop;

	for (int i = 0; i < loop; i++)
	{
        queue<pair<int, int>> myQ;	//(중요도, 처음 저장되어 있었던 인덱스)
        
		int num, searchIndex;
		cin >> num >> searchIndex;

		int findMax[101];		
		for (int j = 0; j < num; j++)	//큐에 넣기
		{
			int importance;
			cin >> importance;
			myQ.push(make_pair(importance, j));
			findMax[j] = importance;
		}
		sort(findMax, findMax + num);	//현재 큐에 있는 수 오름차순 정렬

		int cnt = 0;
		int k = num - 1;
		while (!myQ.empty())
		{
			int curMax = findMax[k];

			int curImportance = myQ.front().first;
			int curIndex = myQ.front().second;

			if (curMax == curImportance)
			{
				myQ.pop();
				cnt++;
				if (curIndex == searchIndex)
				{
					cout << cnt << endl;
					break;
				}
				k--;
			}
			else
			{
				myQ.pop();
				myQ.push(make_pair(curImportance, curIndex));
			}
		}
	}
	return 0;
}
