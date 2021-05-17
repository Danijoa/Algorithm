#include <vector>
#include <iostream>
using namespace std;

int checkPrime(int hap)
{
	for (int a = 2; a <hap; a++)
	{
		if (hap%a == 0)
			return 0;
	}
	return 1;
}

int solution(vector<int> nums) {
	int answer = 0;

	int leg = nums.size();
	int hap;
	for (int i = 0; i < leg-2; i++)
	{
		for (int j = i + 1; j < leg - 1; j++)
		{
			for (int k = j + 1; k < leg; k++)
			{
				hap = nums[i] + nums[j] + nums[k];
				answer += checkPrime(hap);
			}
		}
	}

	cout << answer << endl;
	return answer;
}
