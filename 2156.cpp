#include <iostream>
#include <algorithm>
using namespace std;

int num;
int* wine;
int* store;

int DP()
{
	store = new int[num];

	store[0] = wine[0];
	if (num == 1)
	{
		return store[0];
	}

	store[1] = wine[1] + wine[0];
	if (num == 2)
	{
		return store[1];
	}
	
	for (int i = 2; i < num; i++)
	{
		store[i] = max(store[i - 1], max(wine[i] + wine[i - 1] + store[i - 3], wine[i] + store[i - 2]));
	}
	return store[num - 1];
}

int main()
{
	//입력 받기
	cin >> num;

	wine = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> wine[i];
	}

	//계산
	cout << DP();
}
