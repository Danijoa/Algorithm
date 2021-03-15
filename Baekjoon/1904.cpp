#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int store[1000001];
	store[1] = 1;
	store[2] = 2;
	for (int i = 3; i <= num; i++)
	{
		store[i] = (store[i - 2] + store[i - 1]) % 15746;
	}

	cout << store[num];

	return 0;
} 
