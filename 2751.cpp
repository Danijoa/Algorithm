#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

void merge(int array[], int left, int mid, int right)
{
	int leftArray[MAX / 2], rightArray[MAX / 2];
	int j = 0;
	for (int i = left; i < mid + 1; i++)
	{
		leftArray[j] = array[i];
		j++;
	}
	j = 0;
	for (int i = mid + 1; i < right + 1; i++)
	{
		rightArray[j] = array[i];
		j++;
	}
	
	int l = 0, r = 0, p = left;
	int leftLen = (mid + 1) - left;
	int rightLen = (right + 1) - (mid + 1);

	while (l < leftLen && r < rightLen) //왼쪽 배열 오른 쪽 배열 맨 앞의 원소 비교 후 작은 것 선택
	{
		if (leftArray[l] <= rightArray[r]) 
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

	while (l < leftLen) //왼쪽 배열이 남아있는 경우
	{
		array[p] = leftArray[l];
		l++;
		p++;
	}

	while (r < rightLen) //오른쪽 배열이 남아있는 경우
	{
		array[p] = rightArray[r];
		r++;
		p++;
	}

}

void mergeSort(int array[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

int main()
{
	int len;
	cin >> len;

	int number[MAX];
	for (int i = 0; i < len; i++)
	{
		cin >> number[i];
	}

	//합병정렬
	mergeSort(number, 0, len - 1);

	for (int i = 0; i < len; i++)
	{
		cout << number[i] << "\n";
	}
}
