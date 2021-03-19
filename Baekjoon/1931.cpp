#include <iostream>
#include <algorithm>
#include <deque>
#define MAX 100000
using namespace std;

int num;
deque<pair<int, int>> myQ;
int endT;
int answer = 0;

int main()
{
	cin >> num;

	int a, b;
	for (int i = 0; i < num; i++)
	{
		cin >> a >> b;
		myQ.push_back(pair<int, int>(b, a));
	}

	//끝나는 시간 기준 정렬: 최대한 짧게 사용하고 빠지는 것이 좋음
	sort(myQ.begin(), myQ.end());

	endT = myQ.front().first;
	myQ.pop_front();
	answer++;
	while (myQ.empty() != true)
	{
		if (endT <= myQ.front().second)
		{
			answer++;
			endT = myQ.front().first;
		}
		myQ.pop_front();
	}

	cout << answer;
}
