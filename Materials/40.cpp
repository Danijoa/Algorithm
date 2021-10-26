#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 첫번째 집합 정렬
	int n1;
	cin >> n1;

	int a1;
	vector<int> v1;
	for (int i = 0; i < n1; i++)
	{
		cin >> a1;
		v1.push_back(a1);
	}

	sort(v1.begin(), v1.end());

	// 두번째 집합 정렬
	int n2;
	cin >> n2;

	int a2;
	vector<int> v2;
	for (int i = 0; i < n2; i++)
	{
		cin >> a2;
		v2.push_back(a2);
	}

	sort(v2.begin(), v2.end());

/*
 2 3 5 7 10
 3 5 10 12 17
*/

	vector<int> temp;
	int i = 0, j = 0, k;
	while (true)
	{
		if (i == n1 || j == n2)
			break;

		if (v1[i] == v2[j])
		{
			i++;
			temp.push_back(v2[j++]);
		}
		else if (v1[i] < v2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
		cout << temp[i] << " ";

	return 0;
}
