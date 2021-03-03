#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int num;
	cin >> num;
	
	//algorithm: sort(time, time+num) → time[i] = time[i] + time[i-1];
	priority_queue<int, vector<int>, greater<int>> time;	//최소힙(오름차순 = 루트가 가장 작음)
	for (int i = 0; i < num; i++)
	{
		int temp;
		cin >> temp;
		time.push(temp);
	}

	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		int temp = time.top();
		cnt += (num - i) * temp;
		time.pop();
	}

	cout << cnt;

	return 0;
}
