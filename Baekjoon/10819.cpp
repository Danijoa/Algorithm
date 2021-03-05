#include <iostream>
#define MAX 9
using namespace std;

int num;	//받아오는 크기
int numArray[MAX];	//배열 크기가 작으니까 수열로 경우의 수를 모두 만든다
int isMax = -1;
int tempArray[MAX];

void findMax()
{
	int temp = 0;
	for (int i = 0; i < num - 1; i++)
	{
		temp += abs(tempArray[i] - tempArray[i + 1]);
	}
	if (temp > isMax)
	{
		isMax = temp;
	}
}

void swap(int* numArray, int startIndex, int i)
{
	int temp = numArray[startIndex];
	numArray[startIndex] = numArray[i];
	numArray[i] = temp;
}

void Permutation(int *numArray, int startIndex)	//numPnum 하여 배열에 저장 -> 값 계산 -> 최대값 비교
{
	if (startIndex == num - 1)
	{
		for (int i = 0; i < num; i++)
		{
			tempArray[i] = numArray[i];
		}
		findMax();
		return;
	}

	for (int i = startIndex; i < num; i++)
	{
		swap(numArray, startIndex, i);
		Permutation(numArray, startIndex + 1);
		swap(numArray, startIndex, i);
	}
}

int main()
{
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> numArray[i];	//-100~100
	}

	Permutation(numArray, 0);

	cout << isMax;

	return 0;
}
