#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int num, horse;
	cin >> num >> horse;

	vector<unsigned int> coor;
	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		coor.push_back(a);
	}

	sort(coor.begin(), coor.end()); 

	int min = 1, mid, max = coor[num - 1] - coor[0];	// 최소 길이, 중간, 최대 길이
	int result, cnt, piv;

	while (min <= max)
	{
		mid = (min + max) / 2;
		//cout << "mid " << mid << "\n";

		cnt = 1;
		piv = coor[0];
		for (int i = 1; i < num; i++)
		{
			if (coor[i] - piv >= mid)
			{
				//cout << coor[i] << " - " << piv << " = coor[i] - piv\n";
				cnt++;
				piv = coor[i];	// 다음 마구간으로
			}
		}
		//cout << "cnt : " << cnt << "\n\n";
		
		if (cnt >= horse)
		{
			result = mid;
			min = mid + 1;
		}
		else
			max = mid - 1;

	}

	cout << result;

	return 0;
}
