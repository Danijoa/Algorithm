#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int num;
int myArray[MAX];

int main()
{
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> myArray[i];
	}

	sort(myArray, myArray + num);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < num; j++)
		{
			myArray[j] = myArray[j] + myArray[j - 1];
		}
	}

	int answer = myArray[num - 1];
	cout << answer;
}
