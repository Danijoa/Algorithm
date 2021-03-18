#include <iostream>
using namespace std;

int podo;
int podoju[10001];
int drink[10001];

int DP()
{
	drink[1] = podoju[1];
	if (podo == 1)	//1잔만 있는 경우 최대
		return drink[1];

	drink[2] = podoju[1] + podoju[2];
	if (podo == 1)	//2잔 있는 경우 최대
		return drink[2];

	for (int i = 3; i <= podo; i++)
	{
		//3가지 경우
		//현재-3 현재-1 현재
		//현재-2 현재
		//현재 건너뛰기
		drink[i] = max(drink[i - 1], max(podoju[i] + drink[i - 2], podoju[i] + podoju[i-1] + drink[i - 3]));
	}
	return drink[podo];	//podo잔 있는 경우 최대
}

int main()
{
	cin >> podo;

	for (int i = 1; i <= podo; i++)
	{
		cin >> podoju[i];
	}

	cout << DP();	
}
