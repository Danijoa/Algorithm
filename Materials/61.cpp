#include <iostream>
#include <vector>

using namespace std;

int s;
int total;
int* nums;
int cnt = 0;
vector<int> myV;

void DFS(int index, int hap)
{
	// 경우의 수 다 확인 한 후에 count 해야함
	if (index >= s)
	{
		if (hap == total)
			cnt += 1;

		return;
	}

	DFS(index + 1, hap + nums[index]);
	DFS(index + 1, hap - nums[index]);
	DFS(index + 1, hap);
}

int main() 
{
	cin >> s >> total;
	
	nums = new int[s];
	for (int i = 0; i < s; i++)
		cin >> nums[i] ;

	DFS(0, 0);

	if (cnt == 0)
		cout << -1;
	else
		cout << cnt;
	
	return 0;
}
