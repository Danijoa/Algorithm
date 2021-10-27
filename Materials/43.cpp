#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num, div;
	cin >> num >> div;

	int a, hap = 0;
	vector<int> temp;
	for (int i = 0; i < num; i++)
	{
		cin >> a;
		hap += a;
		temp.push_back(a);
	}

	int min = hap / div;
	int max = hap;
	int mid, cnt, sum, result = hap;
  
  /*
   합이 42인 배열을 3개로 나눈다고 하는 경우
   가장 예쁘게 잘리는 경우(모든 부분 집합의 합이 동일) 42 / 3 = 14
   최악의 경우 42이다
   따라서 [14 ~ 42]의 중간값인 (14 + 42) / 2 = 28을 확인해 본다
   28을 기준을 잡고 배열 처음부터 훑으면서 28의 합이 되는 부분의 개수 확인
   부분 개수가 3초과면 28이상의 숫자가 필요한 것이기에 [29 ~ 42]의 중앙값을 확인한다
   부분 개수가 3이하면 28으로 잡으면 3개로 나누어 진다는 것이며, 그 이상의 숫자는 모두 가능하다는 것이다 
   이때 28보다 작은 수로도 3개의 부분 집합을 만들수 있는지 확인해 봐야하기에 [14 ~ 27]의 중앙값을 확인한다
   이렇게 min <= max 가 될때 까지 반복
   */

	while (min <= max)
	{
		mid = (min + max) / 2;
		cnt = 0;
		sum = 0;

		for (int i = 0; i < num; i++)
		{
			sum += temp[i];
			if (sum > mid)	//sum >= mid로 하는 경우 마지막 집합이 mid 보다 작은 경우 count 세는 것이 어렵다, 따라서 마지막 집합이 작거나 같은 경우에는 count 되지 않도록 한다
			{
				cnt++;
				sum = temp[i];
			}
		}
		cnt += 1;	// 마지막 집합은 count되지 않았기 때문

		if (cnt <= div)
		{
			result = mid;
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
	}

	cout << result;


	
