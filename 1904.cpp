#include <iostream>
#include <algorithm>
using namespace std;

int num;
int* result;

int main()
{
	//입력 받기
	cin >> num;

	result = new int[num];
	result[0] = 1;
	result[1] = 2;
	for (int i = 2; i < num; i++)
	{
		result[i] = (result[i - 2] + result[i - 1]) % 15746;
	}

	//계산
	cout << result[num - 1];
}
