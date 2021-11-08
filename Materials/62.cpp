#include <iostream>

using namespace std;

int n;
int* nums;

void merge(int left, int mid, int right)
{
	int temp[101] = { 0, };
	int index = left;
	int lIdx = left;
	int rIdx = mid + 1;

	while (lIdx <= mid && rIdx <= right)
	{
		if (nums[lIdx] <= nums[rIdx])
			temp[index++] = nums[lIdx++];
		else
			temp[index++] = nums[rIdx++];
	}

	while (lIdx <= mid)
		temp[index++] = nums[lIdx++];

	while (rIdx <= right)
		temp[index++] = nums[rIdx++];

	for (int i = left; i <= right; i++)
		nums[i] = temp[i];
}

void divide(int left, int right)
{
	int mid; 
	if (left < right)
	{
		mid = (left + right) / 2;
		divide(left, mid);
		divide(mid + 1, right);
		merge(left, mid, right);
	}
}

int main() 
{
	cin >> n;
	nums = new int[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	divide(0, n - 1);

	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";

	return 0;
}

/*
list : [3 1 4 2]
([3] [1]) ([4] [2])
list : [1 3 4 2]
list : [1 3 2 4]
([1 3] [2 4])
list : [1 2 3 4]
*/
