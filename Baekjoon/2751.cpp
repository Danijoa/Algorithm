#include <iostream>
#define MAX 1000000
using namespace std;

void merge(int array[], int start, int mid, int end)
{
	int j = 0;
	int leftArray[MAX / 2], rightArray[MAX / 2];

	for (int i = start; i < mid + 1; i++)
	{
		leftArray[j] = array[i];
		j++;
	}

	j = 0;
	for (int i = mid + 1; i <= end; i++)
	{
		rightArray[j] = array[i];
		j++;
	}

	//왼쪽 배열 오른 쪽 배열 맨 앞의 원소 비교 후 작은 것 선택
	int p = start;
	int l = 0, r = 0;
	int lLen = (mid + 1) - start, rLen = (end + 1) - (mid + 1);
	while (l <lLen && r < rLen)
	{
		if (leftArray[l] < rightArray[r])
		{
			array[p] = leftArray[l];
			l++;
		}
		else
		{
			array[p] = rightArray[r];
			r++;
		}
		p++;
	}

	//왼쪽 배열이 남아있는 경우
	while (l < lLen)
	{
		array[p] = leftArray[l];
		l++;
		p++;
	}

	//오른쪽 배열이 남아있는 경우
	while (r < rLen)
	{
		array[p] = rightArray[r];
		r++;
		p++;
	}

}

void mergeSort(int numArray[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(numArray, start, mid);
		mergeSort(numArray, mid + 1, end);
		merge(numArray, start, mid, end);
	}
}

int main()
{
	int cnt;
	cin >> cnt;

	int number[MAX];
	for (int i = 0; i < cnt; i++)
	{
		cin >> number[i];
	}

	//합병정렬
	mergeSort(number, 0, cnt - 1);

	for (int i = 0; i < cnt; i++)
	{
		cout << number[i] << "\n";
	}

	return 0;
}
