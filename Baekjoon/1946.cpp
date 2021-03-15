#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(pair<int, int>a, pair<int, int>b)
	{
		return a.first > b.first;	//오름차순 정렬 + 동석차 없음
	}
};

int main()
{
	cin.tie(0); //실행속도 향상
	int testCase;
	cin >> testCase;

	for (int j = 0; j < testCase; j++)
	{
		int volunteer;
		cin >> volunteer;

		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> myQ;
		for (int i = 0; i < volunteer; i++)
		{
			int a, b;
			cin >> a >> b;
			myQ.push(make_pair(a, b));	
		}

		int cnt = 1;
		int curScore = myQ.top().second;
		myQ.pop();
		while(!myQ.empty())
		{
			if (curScore > myQ.top().second)
			{
				curScore = myQ.top().second;
				cnt++;
			}
			myQ.pop();
		}
		cout << cnt << endl;
	}

	return 0;
} 
