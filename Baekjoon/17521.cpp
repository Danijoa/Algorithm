#include <iostream>
using namespace std;

int day;
long long int myMoney;
long long int myCoin;
long long int graph[16] = { 0, };

int main()
{ 
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> day >> myMoney;
	for (int i = 0; i < day; i++)
	{
		cin >> graph[i];
	}

	bool turn = true; // 짝수면 매수 홀수면 매도
	for (int i = 0; i < day; i++)
	{
		if (turn && graph[i] < graph[i + 1])
		{
			myCoin = myMoney / graph[i];
			myMoney = myMoney % graph[i];
			turn = false;
		}
		else if(!turn && graph[i] > graph[i + 1])
		{
			myMoney = myMoney + myCoin * graph[i];
			turn = true;
		}
	}
	
	cout << myMoney;

	return 0;	
}
