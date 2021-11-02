#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;

	int front[10];
	for (int i = 0; i < size; i++)
		cin >> front[i];

	int right[10];
	for (int i = 0; i < size; i++)
		cin >> right[i];

	int block[10][10];
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			block[i][j] = front[j];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(block[i][j] > right[size - 1 - i])
				block[i][j] = right[size - 1 - i];
		}
	}

	int hap = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			hap += block[i][j];
		}
	}

	cout << hap;

	return 0;
}
