#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a;
	vector<int> score;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		score.push_back(a);
	}

	sort(score.begin(), score.end());

	vector<int> order;
	order.push_back(score[score.size() - 1]);
	int pre = score[score.size() - 1];
	for (int i = score.size() - 2; i >= 0; i--)
	{
		if (pre != score[i])
		{
			order.push_back(score[i]);
			pre = score[i];
		}
	}

	cout << order[2];

	return 0;
}
