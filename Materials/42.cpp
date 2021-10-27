#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;

	int a;
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		temp.push_back(a);
	}

	sort(temp.begin(), temp.end());

	int mid, start = 0, end = n - 1;
	while (start <= end) // 출력이 없는 경우 대비
	{
		mid = (start + end) / 2;

		if (temp[mid] == p)
		{
			cout << mid + 1;
			break;
		}
		else if (temp[mid] < p)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return 0;
}
